#ifndef _NEWACCT_H_
#define _NEWACCT_H_

struct acctInfo {
	char firstName[30];
	char middleI[2]; //middle initial
	char lastName[30];
	char acctNum[7];  //6dig account number
	long double acctBal; //account balance
		};

void newAcct(struct acctInfo *);

#endif
