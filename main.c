//David Lindsey
//CS2750
//24-07-18

#include <stdio.h>
#include <stdlib.h>
#include "newAcct.h"


int main( int argc, char **argv ) {

	
	FILE * acct_fptr = fopen( "accounts.dat", "r" ); //accounts.dat file pointer
	

	if ( acct_fptr ==  NULL )
		{
		  printf( "ERROR: the File accounts.dat could not be opened!\n");
		  return 1;
		}

	struct acctInfo user;

	newAcct(&user);

	//print to file
		
		fwrite(&user, sizeof(user), 1, acct_fptr);



	fclose(acct_fptr);
	
return 0;
}
