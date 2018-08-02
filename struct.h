#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct acctInfo {
	char firstName[22];
	char middleI[2]; //middle initial
	char lastName[32];
	long int acctNum;  //6dig account number
	long double acctBal; //account balance
		} acctInfo;


#endif
