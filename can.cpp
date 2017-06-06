/*
 * can.cpp
 *
 *  Created on: May 9, 2015
 *      Author: Avees Lab.
 */
#include "mcp_can.h"
#include "can.h"
#include "serial.h"

extern MCP_CAN CAN;

/*******************************************************************************
CAN_initialize()

Baudrate :

CAN_100KBPS, CAN_125KBPS, CAN_200KBPS, CAN_250KBPS, CAN_500KBPS, CAN_1000KBPS
********************************************************************************/

byte CAN_initialize(byte Baudrate)
{
	return CAN.begin(Baudrate);
}



/*******************************************************************************
CAN_write()

ID : CC = 0x0A5 // LKAS = 0x0B5
********************************************************************************/

byte CAN_write(unsigned long id, byte len, unsigned char *buf)
{
	return CAN.sendMsgBuf(id, 0, len, buf);
}


/*******************************************************************************
CAN_read()

Read the message of buffer.

ID for LKAS : 0x0B0~0x0B3 ,  CC : 0x0A0~0x0A1
********************************************************************************/

byte CAN_read( unsigned long *id, unsigned char *len, unsigned char *buf)
{
	return CAN.readMsgBufID(id, len, buf);
}

/*******************************************************************************
CAN_checkReceive()

Check if got something
********************************************************************************/

byte CAN_checkReceive(void)
{
	return CAN.checkReceive();
}

/*******************************************************************************
CAN_checkError()

Check if something error
********************************************************************************/

byte CAN_checkError(void)
{
	return CAN.checkError();
}




