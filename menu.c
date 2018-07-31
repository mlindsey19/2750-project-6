//David lidnsey
//cs 2750 pa6
//27-7-2018

#include <stdio.h>
#include <stdlib.h>

int menu(){
int selection;
	printf("\t\t0. Exit\n\t\t1. Deposit\n\t\t2. Withdrawal\n\t\t3. Add Account\n\t\t4. Remove Account\n\t\t5. Balance Inquiry\n\t\t6. View Accounts\n\tEnter 0, 1, 2, 3, 4, 5 or 6\n");
	scanf("%i", &selection);
	if (selection < 0 || selection > 6 ) {
		printf("did not enter 0-6");
		return -1;
	}

return selection;
}
	
	// 0. exit
// 1. deposit
// 2. withdrawal
// 3. add account
// 4. removed account
// 5. balance inquiry
// 6. view accounts

