//David Lindsey
//cs2750
//1-8-2018
//


#include <stdio.h>
#include "struct.h"

int getAccts(FILE *acct_fptr,  long int acctNumArray[]){

	
	fseek(acct_fptr, 0L, SEEK_END);
	long int size = ftell(acct_fptr);
int number = 1;
	
	if (size == 0L ) {
			return 0;
			}
	
	 number = size / sizeof(acctInfo);

	fseek(acct_fptr, 0L, SEEK_SET);
	acctInfo user;

	for (int i = 0; i < number; i++){
		fread( &user, sizeof(acctInfo), 1, acct_fptr);		
		acctNumArray[i] = user.acctNum;
	}
return number;
}
