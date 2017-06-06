#include "ee.h"
#include "Arduino.h"
#include "can.h"

short CC_trigger;
short LKAS_trigger;
float current_speed;

float target_speed;
float accel;
float brake ;

float road_direction;
float yaw;

float toLeft;
float toRight;

float toMiddle;
float width;

float angle;
float lookahead;

float speed_error;
float lateral_error;

float left_steer ;
float right_steer ;
float steer_value;
float steer_lock = 0.366519; // Do not Edit.


ISR (isr){
	static int count = 1;
	if (count == 4){
		IncrementCounter(SysTimerCnt);
		count = 0;
	}
	count++;
}

TASK(RCV){

	unsigned char buf[8]={0};
	unsigned long id;
	unsigned char len;

	while(1)
	{
		CAN_read(&id, &len, buf);
		if(len != 0){
			switch(id)
			{
				case 0x0A0:
					memcpy(&CC_trigger, buf, sizeof(short));
					memcpy(&LKAS_trigger, buf+2, sizeof(short));
					memcpy(&current_speed, buf+4, sizeof(float));
					break;

				case 0x0A1:
					memcpy(&target_speed, buf, sizeof(float));
					memcpy(&accel, buf+4, sizeof(float));
					break;

				case 0x0B0:
					memcpy(&road_direction, buf, sizeof(float));
					memcpy(&yaw, buf+4, sizeof(float));
					break;

				case 0x0B1:
					memcpy(&toLeft, buf, sizeof(float));
					memcpy(&toRight, buf+4, sizeof(float));
					break;

				case 0x0B2:
					memcpy(&toMiddle, buf, sizeof(float));
					memcpy(&width, buf+4, sizeof(float));
					break;
				case 0x0C0:
					memcpy(&speed_error, buf, sizeof(float));
					memcpy(&lateral_error, buf+4, sizeof(float));
					break;
				default:
					break;
			}
		}
		else
			break;
	}
	TerminateTask();

};


TASK(CC) {

	unsigned char buf[8];

	if(CC_trigger>0.5)
	{


		if(current_speed < 99.5)
			accel = 0.224;
		else if(current_speed <= 100.0)
			accel = 0.225;
		else if(current_speed <= 100.7)
			accel = 0.212;
		else if(current_speed <= 100.9)
			accel = 0.205;
		else
			accel = 0.207;

	}
	else
	{
		accel = 0;
	}

	memcpy(buf, &accel, sizeof(float));
	memcpy(buf+4, &brake, sizeof(float));

	CAN_write(0x0A5, 8, buf);
	TerminateTask();

};

TASK(LKAS){

	unsigned char buf[8];
	float angle;

	if(LKAS_trigger>0.5)
	{

		if(toLeft < 3.5)
			angle = road_direction - yaw - 0.017;
		else if(toLeft <= 6.5)
			angle = road_direction - yaw + 0.015;
		else
			angle = road_direction - yaw + 0.032;
		/* Don't Edit This Function */
		Calculate_Steer_Value(angle);
        /****************************/

	}

	else
	{
		left_steer = right_steer = 0.0;
	}

	memcpy(buf, &left_steer, sizeof(float));
	memcpy(buf+4, &right_steer, sizeof(float));

	CAN_write(0x0B5, 8, buf);

	TerminateTask();
};



   /* Do NOT Edit This Function */
void Calculate_Steer_Value(float angle)
{
	steer_value = angle/steer_lock;

	if(steer_value>0.0)
	{
		if(steer_value > 1.0)
		{
			steer_value = 1.0;
		}

		left_steer = steer_value;
		right_steer = 0.0;
	}

	else if(steer_value < 0.0)
	{
		if(steer_value < -1.0)
		{
			steer_value = -1.0;
		}

		right_steer = -(steer_value);
		left_steer = 0.0;
	}

}





