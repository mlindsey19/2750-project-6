//David Lindsey
//CS2750
//24-07-18

#include <stdio.h>
#include <stdlib.h>
#include "newAcct.h"


int main( int argc, char **argv ) {

	
	FILE * acct_fptr = fopen( "accounts.dat", "w+" ); //accounts.dat file pointer
	

	if ( acct_fptr ==  NULL )
		{
		  printf( "ERROR: the File accounts.dat could not be opened!\n");
		  return 1;
		}

	struct acctInfo user;

	struct acctInfo userTest;

	newAcct(&user);

	//print to file
		
		fwrite(&user, sizeof(struct acctInfo),1 /*sizeof(user)/sizeof(user[0])*/, acct_fptr);
	while ( !feof (acct_fptr) )
	{
	int result = fread(&userTest, sizeof(struct acctInfo), 1, acct_fptr);
	printf( "%-6s %-15s %10.2Lf\n", userTest.firstName, userTest.lastName, userTest.acctBal);
	
printf("result: %i", result);}

	printf( "\n%s\n", userTest.acctNum );
	printf( "%.2Lf\n", userTest.acctBal );
	printf( "%s\n", userTest.firstName );
	printf( "%s\n", userTest.lastName );
	printf( "%s\n", userTest.middleI );


	

	fclose(acct_fptr);
	
return 0;
}
