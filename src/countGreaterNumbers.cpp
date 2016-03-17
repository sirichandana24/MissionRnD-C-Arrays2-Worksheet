/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stddef.h>
#include<string.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0, count = 0, j,k=0,l=0,index=0;
	if (Arr == NULL)
		return -1;
	if (len <= 0)
		return -1;
	for (i = 0; i < len; i++)
	{
		count = 0;
		for (j = 0; j <= 9; j++)
		{
			if (Arr[i].date[j] == date[j])
				count++;
		}
		if (count == 10)
		{
			index = i;
			l = 1;
		}
			
	}	
	if (l == 1)
		return len - index - 1;
	else
		return 0;
}

