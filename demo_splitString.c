/* This script aims to split a string using particular char
*  and print all the the non-char included strings and number
*  This shows how to use **. may not handle mem leaking or checking
*  yuxuan.yuan@outlook.com
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX 32

int splitString(const  char *p, char delim, char **tmp, int *ncount)
{
	//if (p == NULL || tmp == NULL || ncount == NULL) return -1;
	
	int i = 0, j = 0;
	int start = 0, end = 0;

	tmp = (char **)malloc(sizeof(char *) * MAX);
	if (tmp == NULL) return -2;

	for (i = 0; i < MAX; ++i)
	{
		tmp[i] = (char *)malloc(sizeof(char) * MAX);
		if (tmp[i] == NULL) return -3;
		*tmp[i] = '\0';
	}

	for (i = 0; i < strlen(p); ++i)
	{
		if (*(p + i) == delim)
		{
			end = i;
			strncpy(tmp[j], p + start, end - start);
			*(tmp[j] + end - start) = '\0';
			start = end + 1;
			j++;
		}
	}

	for (i = 0; i < MAX; i++)
	{
		if (*(tmp[i]) != '\0')
		{
			(*ncount)++;
			printf("the %d substring is: '%s' \n", *ncount, tmp[i]);
			free(tmp[i]);
		}
	}
	free(tmp);

	return 0;
}


int main(void)
{
	int ret = 0; 
	int ncount = 0;
	char string[] = ",,abc,112,,,,333dds,";
	char **tmp = NULL;
	int num = 32;
	char delim = ',';
	printf("The original string is: '%s' \n", string);
	printf("After split using '%c' \n", delim);
	ret = splitString(string, delim, tmp, &ncount);
	printf("the total number of substring is: %d \n", ncount);
	return ret;
}
