/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int check_date(char*,char*);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B==NULL)
		return NULL;
	if (ALen < 0 || BLen < 0)
		return NULL;
	int i = 0, j = 0, k = 0,res;
	struct transaction *temp;
	char *temp1=NULL, *temp2=NULL;
	temp = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));
	while (i < ALen && j < BLen)
	{
		res = check_date(A[i].date, B[j].date);
		if (res == -1)
			temp[k++] = A[i++];
		else
			temp[k++] = B[j++];
	}
	while (i < ALen)
		temp[k++] = A[i++];
	while (j < BLen)
		temp[k++] = B[j++];
	return temp;

}
int check_date(char *temp1, char *temp2)
{
	int d1=0, m1=0, y1=0, d2=0, m2=0, y2=0;
	d1 = (temp1[0] - '0') * 10 + (temp1[1]-'0');
	d2 = (temp2[0] - '0') * 10 + (temp2[1]-'0');
	m1 = (temp1[3] - '0') * 10 + (temp1[4]-'0');
	m2 = (temp2[3] - '0') * 10 + (temp2[4]-'0');
	y1 = (temp1[6] - '0') * 1000 + (temp1[7] - '0') * 100 + (temp1[8] - '0') * 10 + (temp1[9] - '0');
	y2 = (temp2[6] - '0') * 1000 + (temp2[7] - '0') * 100 + (temp2[8] - '0') * 10 + (temp2[9] - '0');
	if (y1 == y2 && m1 == m2 && d1 == d2)
		return 1;
	if (y1 < y2)
		return -1;
	if (y1 > y2)
		return 1;
	if (y1 == y2)
	{
		if (m1 < m2)
			return -1;
		else if (m1 == m2)
		{
			if (d1 < d2)
				return -1;
			else
				return 1;
		}
		else
			return 1;
	}
}