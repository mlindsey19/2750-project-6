//David Lindsey
//CS2750
//24-07-18

#include <stdio.h>
#include <stdlib.h>
#include "newAcct.h"
#include "menu.h"
#include "struct.h"
#include <errno.h>


int checkForAcctNum(long int const *, long int);
void writeToFile(FILE *, acctInfo *, const int);
void readFile( FILE *, const int);
void deposit(acctInfo *,const long double);
void withdrawal( acctInfo *, const long double);
int main( int argc, char **argv ) {


	FILE *acct_fptr = fopen( "accounts.dat", "rb+" ); //accounts.dat file pointer
	if ( acct_fptr ==  NULL )
		{
		  printf( "ERROR: the File accounts.dat could not be opened!\n");
		  return 1;
		}


	
	//properties
	int numberOfAccts = 0;

	acctInfo user[50];
	
	long int acctNumArray[50];
	for ( int i = 0; i < 50; i++ ) {
		acctNumArray[i] = 0;
	}
	

			long int number;
			long double value;
	while (numberOfAccts < 50 ){
	switch ( menu() ){

		case 0: 
			return 0;
		case 1: 
			//deposit
			printf("enter account number:\n");
			scanf("%li", &number);
			int p =	checkForAcctNum(acctNumArray, number);
			if (p != -1){
				printf("enter ammount : $");
				scanf ("%Lf", &value);
				deposit(&user[p], value);
			}			
			break;
		case 2:
			//withdrawal
			break;
		case 3: 
			user[numberOfAccts] = newAcct();
			acctNumArray[numberOfAccts] = user[numberOfAccts].acctNum;
			printf("%li\n", user[numberOfAccts].acctNum);
			for (int i = 0; i < 15; i++){
				printf("\t%i:   %li\n", i,  acctNumArray[i]);
				}

			writeToFile(acct_fptr, user, numberOfAccts);
			readFile(acct_fptr, (numberOfAccts + 1));
			numberOfAccts++;
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
	
	

	fclose(acct_fptr);

return 0;
}
	//print to file
void writeToFile(FILE *acct_fptr, acctInfo *user, const int N){		
		

	acctInfo *ptr = &user[N];
	int result;
	result = fwrite(ptr, sizeof(acctInfo), 1, acct_fptr);
	printf("result: %i", result);
}

void readFile(FILE *acct_fptr, const int N){
	acctInfo userTest[50];
	int result = fread(&userTest, sizeof(acctInfo), 1, acct_fptr);

	printf( "%-6s %-15s %10.2Lf\n", userTest->firstName, userTest->lastName, userTest->acctBal);

	printf("result: %i", result);

	printf( "\n%li\n", userTest->acctNum );
	printf( "%.2Lf\n", userTest->acctBal );
	printf( "%s\n", userTest->firstName );
	printf( "%s\n", userTest->lastName );
	printf( "%s\n", userTest->middleI );

	
}



int checkForAcctNum(long int const *arr, long int x){
	int position = -1;

	for ( int i = 0; i < 50; i++){
		position = ( arr[i] == x ) ? i : position;
	}
return position;
}
void deposit (acctInfo * user, const long double X){
	user->acctBal += X;
}
void withdrawal (acctInfo * user, const long double X){
	if (user->acctBal > X){
	user->acctBal -= X;
	} else {
	printf("not enought funds");
	}
	
}
