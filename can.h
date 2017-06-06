/*
 * can.h
 *
 *  Created on: May 9, 2015
 *      Author: Avees Lab.
 */

#ifndef CAN_H_
#define CAN_H_

#ifdef __cplusplus
	extern "C" {
#endif

		byte CAN_initialize(byte Baudrate);  // to initialize CAN
		byte CAN_write(unsigned long id, byte len, unsigned char *buf);  // to write CAN Message
		byte CAN_read(unsigned long *id, unsigned char *len, unsigned char *buf); // to read CAN Message
		byte CAN_checkReceive(void); // to check if something is gotten.
		byte CAN_checkError(void); // to check if something is error.


#ifdef __cplusplus
	}
#endif

#endif /* CAN_H_ */
