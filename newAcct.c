//David Linsdsey
//cs2750 pa6
//30-7-1028


#include <stdio.h>
#include <stdlib.h>

struct acctInfo {
	char firstName[30];
	char middleI[2]; //middle initial
	char lastName[30];
	char acctNum[7];  //6dig account number
	long double acctBal; //account balance
		};


void newAcct( struct acctInfo *user ){


		//ask user for info
	printf( "Enter first name:\n" );
	scanf( "%s\0",user->firstName );
	printf("middle initial:\n" );
	scanf( "%1s\0", user->middleI );
	printf( "lastname:\n" );
	scanf( "%s\0", user->lastName );
	printf( "Choose 6 digit account number: \n" );
	scanf( "%6s\0", user->acctNum );
	printf( "Enter account balance: \n" );
	scanf( "%Lf", &user->acctBal );

	printf( "\n%s\n", user->acctNum );
	printf( "%Lf\n", user->acctBal );
	printf( "%s\n", user->firstName );
	printf( "%s\n", user->lastName );
	printf( "%s\n", user->middleI );


}
