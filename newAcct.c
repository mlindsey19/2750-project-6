//David Linsdsey
//cs2750 pa6
//30-7-1028


#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

//struct acctInfo {
//	char firstName[30];
//	char middleI[2]; //middle initial
//	char lastName[30];
//	long int acctNum;  //6dig account number
//	long double acctBal; //account balance
//		};


struct acctInfo newAcct(){
	struct acctInfo user;

	char temp[200]; //for extra input after middle I
	
		//ask user for info
	printf( "Enter first name:\n" );
	scanf( "%s\0", user.firstName );

	printf("middle initial:\n" );
	scanf( "%s", temp);
	user.middleI[0] = temp[0];
	user.middleI[1] = '\0';


	
	printf( "lastname:\n" );
	scanf( "%s\0", user.lastName );
	
	printf( "Choose 6 digit account number: \n" );
	scanf( "%li", &user.acctNum);
	

	printf( "Enter account balance: \n" );
	scanf( "%Lf", &user.acctBal );

	printf( "\n%li\n", user.acctNum );
	printf( "%.2Lf\n", user.acctBal );
	printf( "%s\n", user.firstName );
	printf( "%s\n", user.lastName );
	printf( "%s\n", user.middleI );

return user;
}
