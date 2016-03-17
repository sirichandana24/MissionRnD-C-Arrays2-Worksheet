/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
}transaction1;

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i, j, k, count = 0,index=0;
	struct transaction *temp;
	if (A == NULL || B == NULL)
		return NULL;
	if (ALen < 0 || BLen < 0)
		return NULL;
	temp = (struct transaction*)malloc(10 * sizeof(transaction1));
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			count = 0;
			for (k = 0; k <= 9; k++)
				if (A[i].date[k] == B[j].date[k])
					count++;
			if (count == 10)
			{
				temp[index] = A[i];
				index++;
			}
		}
	}
	realloc(temp, index);
	if (index == 0)
		return NULL;
	
	return temp;
}
