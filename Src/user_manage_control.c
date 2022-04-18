/* =======================================================================
 * 	user_manage_control.c
 * 	Source Code For User Management Control.
 *  Created on: April 17, 2022
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


/* =======================================================================
 * 	User Management Includes
 * ==================================================================== */

#include <string.h>
#include "Std_Types.h"
#include "user_manage_control.h"

/* ==================================================================== */





/* =======================================================================
 * 	User's Data
 * ==================================================================== */

UserManage user[USERS_NUM];

/* ==================================================================== */





/* =======================================================================
 * 	User Management APIs
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - User_Init
 * 	@ Brief 	 - Initialize User Management Control.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void User_Init(void){
	uint8 Idx;
	for(Idx = 0;Idx<USERS_NUM;Idx++){
		memset(user[Idx].username,'\0',15*sizeof(char));
		user[Idx].pass = 0;
		user[Idx].status = FREE;
	}
}


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
Std_Return User_Search(const char *username, uint16 pass, uint8 *userIdx){
	Std_Return Search_UserStatus = USER_NOT_FOUND;
	uint8 Idx;
	for(Idx = 0;Idx < USERS_NUM;Idx++){

		// Check if User Place is Taken
		if(user[Idx].status == TAKEN){
			if(strcmp(user[Idx].username, username) == 0) {

				// Username is found
				if(user[Idx].pass == pass) {

					// Password is Right
					Search_UserStatus = USER_FOUND;
					if(userIdx != NULL) *userIdx = Idx;
				}

				// Password is Wrong
				else Search_UserStatus = USER_WRONG_PASS;
				break;
			}
		}
	}
	return Search_UserStatus;
}


/* =======================================================================
 * 	@ Func  	 - User_Add
 * 	@ Brief 	 - Add New User To Memory.
 * 	@ Param [in] - username: Pointer to Username.
 * 	@ Param [in] - pass: User Password.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "USER_ADD_DONE" when user has been added to memory,
 *	  			   return "USER_NO_EMPTY_SPACE" when no empty spaces in memory,
 * ==================================================================== */
Std_Return User_Add(const char *username, uint16 pass){
	Std_Return Add_UserStatus = USER_NO_EMPTY_SPACE;
	Std_Return Local_Return;
	uint8 Idx;

	// Check if User is Already Existed in Memory
	Local_Return = User_Search(username,pass,NULL);

	if(Local_Return == USER_NOT_FOUND){
		for(Idx = 0;Idx < USERS_NUM;Idx++){

			// Chcek if User Place is Free
			if(user[Idx].status == FREE){
				strcpy(user[Idx].username,username);
				user[Idx].pass = pass;
				user[Idx].status = TAKEN;
				Add_UserStatus = USER_ADD_DONE;
				break;
			}
		}
	}
	return Add_UserStatus;
}


/* =======================================================================
 * 	@ Func  	 - User_Delete
 * 	@ Brief 	 - Delete New User From Memory.
 * 	@ Param [in] - username: Pointer to Username.
 * 	@ Param [in] - pass: User Password.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "USER_DELETED" when user has been deleted from memory,
 *	  			   return "USER_NOT_DELETED" when user not found so his data didn't delete from memory,
 * ==================================================================== */
Std_Return User_Delete(const char *username, uint16 pass){
	Std_Return Delete_UserStatus = USER_DELETED;
	Std_Return Local_Return;
	uint8 Idx = 0;

	// Check if User is Already Existed in Memory
	Local_Return = User_Search(username,pass,&Idx);

	if(Local_Return == USER_FOUND) {

		// User Found and Data is Deleted
		memset(user[Idx].username,'\0',15*sizeof(char));
		user[Idx].pass = 0;
		user[Idx].status = FREE;
	}
	else Delete_UserStatus = USER_NOT_DELETED;
	return Delete_UserStatus;
}

/* ==================================================================== */
