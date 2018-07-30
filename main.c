//David Lindsey
//CS2750
//24-07-18

#include <stdio.h>
#include <stdlib.h>

int main( int argc, int *argv[] ) {

	struct acctInfo {
		char firstName[30];
		char middleI; //middle initial
		char lastName[30];
		char acctNum[7];  //6dig account number
		long double acctBal; //account balance
	
		};


	FILE * acct_fptr = fopen( "accounts.dat", "r" ); //accounts.dat file pointer
	

	if ( acct_fptr ==  NULL )
		{
		  printf( "ERROR: the File accounts.dat could not be opened!\n");
		  return 1;
		}

	struct acctInfo user;


		//ask user for info
	printf( "Enter first name:\n" );
	scanf( "%s",user.firstName );
	printf("middle initial:\n" );
	scanf( "%s", user.middleI );
	printf( "lastname:\n" );
	scanf( "%s", user.lastName );
	printf( "Choose 6 digit account number: \n" );
	scanf( "%s", user.acctNum ); 
	printf( "\n%s\n", user.acctNum );
	printf( "%s", user.firstName );
		//write to file
		fwrite(&user, sizeof(user), 1, acct_fptr);



	fclose(acct_fptr);
	
return 0;
}
