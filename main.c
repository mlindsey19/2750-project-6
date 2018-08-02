//David Lindsey
//CS2750
//24-07-18

#include <stdio.h>
#include <stdlib.h>
#include "newAcct.h"
#include "menu.h"
#include "struct.h"
#include <errno.h>
#include "getAccts.h"

int checkForAcctNum(long int const *, long int);
void writeToFile(FILE *, acctInfo *, const int);
void deposit(acctInfo *,const long double);
void readFile( FILE *, const int);
void withdrawal( acctInfo *, const long double);
void displayAcct(acctInfo *);


int main( int argc, char **argv ) {
	
	
	FILE *acct_fptr = fopen( "accounts.dat", "rb+" ); //accounts.dat file pointer
	if ( acct_fptr ==  NULL) 
		{
		  printf( "ERROR: the File accounts.dat could not be opened!\n");
		  return 1;
		}
	//properties
	int numberOfAccts = 0;	long int number;	long double value;

	acctInfo user; 		acctInfo *user_ptr = &user;

	long int acctNumArray[50];
	for ( int i = 0; i < 50; i++ ) {
		acctNumArray[i] = 0;
	}
	
	numberOfAccts = getAccts(acct_fptr, acctNumArray);

	for ( int i = 0; i < 9; i++)
		printf("%li ", acctNumArray[i]);
	
	printf("\n\t\t\t\tnumber of accts:%i\n\n", numberOfAccts);

	while (numberOfAccts < 50 ){
	switch ( menu() ){

		case 0:
			fclose(acct_fptr);
			return 0;
		case 1: 
			//deposit
			printf("enter account number:\n");
			scanf("%li", &number);
			int p =	checkForAcctNum(acctNumArray, number);
			if (p != -1){
				printf("enter ammount : $");
				scanf ("%Lf", &value);
				deposit(user_ptr, value);
			}			
			break;
		case 2:
			//withdrawal	
			printf("enter account number:\n");
			scanf("%li", &number);
			int k =	checkForAcctNum(acctNumArray, number);
			if (k != -1){
				printf("enter ammount : $");
				scanf ("%Lf", &value);
				withdrawal(user_ptr, value);
			}
			break;
		case 3: 
			newAcct(&user);
			acctNumArray[numberOfAccts] = user.acctNum;
			for (int i = 0; i < 5; i++){
				printf("\t%i:   %li\n", i,  acctNumArray[i]);
				}

			writeToFile(acct_fptr, &user, numberOfAccts);
			readFile(acct_fptr, numberOfAccts );
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
			fseek(acct_fptr, 0L, SEEK_END);
			int nrec = ftell(acct_fptr) / sizeof(acctInfo);
			for (int i = 0; i < nrec; i++)	{
				
				}			
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
	fseek( acct_fptr, (N * sizeof(acctInfo)), SEEK_SET );		
	fwrite(user, sizeof(acctInfo), 1, acct_fptr);
}

void readFile(FILE *acct_fptr, const int N){
	acctInfo userTest;
	fseek(acct_fptr, ( (N) * sizeof(acctInfo)), SEEK_SET);
	fread(&userTest, sizeof(acctInfo), 1, acct_fptr);
	displayAcct(&userTest);
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
void displayAcct(acctInfo *user){
	printf("\t%s %s %s \naccount number: %li\nbalance:%.2Lf", user->firstName, user->middleI, 
			user->lastName, user->acctNum, user->acctBal);

}
