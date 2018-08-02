//David Linsdsey
//cs2750 pa6
//30-7-1028


#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>

void newAcct(acctInfo *user){

		//ask user for info

	printf( "Enter first name:\n" );
	scanf( "%21s", user->firstName );

	printf("middle initial:\n" );
	scanf( "%1s", user->middleI);

	printf( "lastname:\n" );
	scanf( "%31s", user->lastName);

	printf( "Choose 6 digit account number: \n" );
	scanf( "%li", &(user->acctNum) );

	printf( "Enter account balance: \n" );
	scanf( "%Lf", &(user->acctBal) );
}

