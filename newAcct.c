//David Linsdsey
//cs2750 pa6
//30-7-1028


#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>
#include <math.h>

void newAcct(acctInfo *user){

		//ask user for info

	printf( "Enter first name:\n" );
	scanf( "%21s", user->firstName );

	printf("middle initial:\n" );
	scanf( "%1s", user->middleI);

	printf( "lastname:\n" );
	scanf( "%31s", user->lastName);

	printf( "Choose 6 digit account number: \n" );

	char numstr [55];
	long int num = 0;
	
	scanf("%54s", numstr);
	int x = strlen(numstr);

	if (x == 6){

		
		num += atol(&numstr[0]);
	//	num += atol(&numstr[1]) * 10; 
		
	//	num += atol(&numstr[2]) * 100;
	//	num += atol(&numstr[3]) * 1000;
	//	num += atol(&numstr[4]) * 100000;
	//	num += atol(&numstr[5]) * 1000000;
		
	user->acctNum = num;
	printf( "Enter account balance: \n" );
	scanf( "%Lf", &(user->acctBal) );
	}
	else {
		user->acctNum = -1;
	printf("\n\t*** Expected 6 digit number, starting with '1-9' ***\n");
	}
	
}

