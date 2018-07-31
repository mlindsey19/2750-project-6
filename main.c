//David Lindsey
//CS2750
//24-07-18

#include <stdio.h>
#include <stdlib.h>
#include "newAcct.h"
#include "menu.h"

int checkForAcctNum(long int const *, long int);

int main( int argc, char **argv ) {



	FILE *acct_fptr = fopen( "accounts.dat", "w+" ); //accounts.dat file pointer
	if ( acct_fptr ==  NULL )
		{
		  printf( "ERROR: the File accounts.dat could not be opened!\n");
		  return 1;
		}
	
	
	//properties
	int numberOfAccts = 0;

	struct acctInfo user[50];
	long int acctNumArray[50];
	for ( int i = 0; i < 50; i++ ) {
		acctNumArray[i] = 0;
	}
	

	while (numberOfAccts < 50 ){
	switch ( menu() ){

		case 0: 
			return 0;
		case 1: 
			//deposit
			break;
		case 2:
			//withdrawal
			break;
		case 3: 
			newAcct(&user[numberOfAccts]);
			acctNumArray[numberOfAccts] = &(user[numberOfAccts++].acctNum);
			
			break;
		case 4:
			//remove accounts
			break;
		case 5: 
			//ballance inquiry
			break;
		case 6: 
			//view accounts
			break;
		default:
			break;
		}
	}
	
	
	struct acctInfo userTest;



printf("%li\t%i", acctNumArray[numberOfAccts -1], numberOfAccts);
	//print to file
		
	
	fwrite(user, sizeof(struct acctInfo),sizeof(user)/sizeof(user[0]), acct_fptr);
	
	
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



int checkForAcctNum(long int const *arr, long int x){
	int position = -1;

	for ( int i = 0; i < 50; i++){
		position = ( arr[i] == x ) ? i : position;
	}

	return position;
}

