/* =======================================================================
 * 	user_manage_control.h
 * 	Header File For User Management Control.
 *  Created on: April 17, 2022
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */

#ifndef INCLUDES_USER_MANAGE_CONTROL_H_
#define INCLUDES_USER_MANAGE_CONTROL_H_

/* =======================================================================
 * 	User Management Includes
 * ==================================================================== */

#include "Std_Types.h"

/* ==================================================================== */




/* =======================================================================
 * 	User Management Data Type
 * ==================================================================== */

typedef struct {
	char username[15];
	uint16 pass;
	uint8 status;
} UserManage;

/* ==================================================================== */





/* =======================================================================
 * 	User Management Macros
 * ==================================================================== */

enum {
	USER_NO_EMPTY_SPACE = 0,
	USER_ADD_DONE,
	USER_NOT_FOUND,
	USER_FOUND,
	USER_WRONG_PASS,
	USER_DELETED,
	USER_NOT_DELETED
};

#define FREE		  0
#define TAKEN		  1
#define USERS_NUM	  10

/* ==================================================================== */





/* =======================================================================
 * 	User Management APIs
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - User_Init
 * 	@ Brief 	 - Initialize User Management Control.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void User_Init(void);


/* =======================================================================
 * 	@ Func  	 - User_Search
 * 	@ Brief 	 - Search for User in the Memory.
 * 	@ Param [in] - username: Pointer to Username.
 * 	@ Param [in] - pass: User Password.
 * 	@ Param [out]- userIdx: Return User Index in the Memory.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "USER_FOUND" when the username & password found,
 *	  			   return "USER_WRONG_PASS" when username is found but password is wrong,
 *	  			   return "USER_NOT_FOUND"	when username not found.
 * ==================================================================== */
Std_Return User_Search(const char *username, uint16 pass, uint8 *userIdx);


/* =======================================================================
 * 	@ Func  	 - User_Add
 * 	@ Brief 	 - Add New User To Memory.
 * 	@ Param [in] - username: Pointer to Username.
 * 	@ Param [in] - pass: User Password.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "USER_ADD_DONE" when user has been added to memory,
 *	  			   return "USER_NO_EMPTY_SPACE" when no empty spaces in memory,
 * ==================================================================== */
Std_Return User_Add(const char *username, uint16 pass);


/* =======================================================================
 * 	@ Func  	 - User_Delete
 * 	@ Brief 	 - Delete New User From Memory.
 * 	@ Param [in] - username: Pointer to Username.
 * 	@ Param [in] - pass: User Password.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "USER_DELETED" when user has been deleted from memory,
 *	  			   return "USER_NOT_DELETED" when user not found so his data didn't delete from memory,
 * ==================================================================== */
Std_Return User_Delete(const char *username, uint16 pass);

/* ==================================================================== */

#endif /* INCLUDES_USER_MANAGE_CONTROL_H_ */
