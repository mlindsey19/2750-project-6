#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct acctInfo {
	char firstName[30];
	char middleI[2]; //middle initial
	char lastName[30];
	long int acctNum;  //6dig account number
	long double acctBal; //account balance
		} acctInfo;


#endif
