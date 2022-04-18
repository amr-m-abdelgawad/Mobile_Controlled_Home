/* =======================================================================
 * 	frame.h
 * 	Header File For Bluetooth Frame.
 *  Created on: April 17, 2021
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */

#ifndef INCLUDES_FRAME_H_
#define INCLUDES_FRAME_H_

/* =======================================================================
 * 	Bluetooth Received Frame Macros
 * ==================================================================== */

#define BLUETOOTH_DATA_MAX_BYTES	(15)
#define BLUETOOTH_PASS_MAX_BYTES	(5)
#define BLUETOOTH_FRAME_START		0b01111110
#define BLUETOOTH_FRAME_STOP		0b01111110
#define BLUETOOTH_USER_LOGIN		0b00000001
#define BLUETOOTH_MASTER_ACCESS		0b00000010
#define BLUETOOTH_USER_ADD			0b00000011
#define BLUETOOTH_USER_REMOVE		0b00000100
#define BLUETOOTH_SIREN_ALARM		0b00000101
#define BLUETOOTH_DOOR_LOCK			0b00000110
#define BLUETOOTH_ROOM1_LIGHT		0b00000111
#define BLUETOOTH_ROOM2_LIGHT		0b00001000
#define BLUETOOTH_PASS_IND			0b01100000
#define FRAME_TYPE_IDX				0

/* ==================================================================== */





/* =======================================================================
 * 	Bluetooth Received Frame
 * ==================================================================== */
typedef struct {
	UART_8BitDataType Type;
	UART_8BitDataType Data[BLUETOOTH_DATA_MAX_BYTES];
	UART_8BitDataType Pass[BLUETOOTH_PASS_MAX_BYTES];
} Frame;

/* ==================================================================== */

#endif /* INCLUDES_FRAME_H_ */
