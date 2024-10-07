#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX  1024
int numberofrows(const char*);

int main()
{

	int numofrows = 0;

	numofrows = numberofrows("imedat.txt");
	printf("Hello world\n");
	return 0;
	 
}

int numberofrows(const char*)
{
	FILE* fp = NULL;
	int numofrows = 0;
	char buffer[MAX] = {};
	fp = fopen(fileName, "r");
	if (!fp)
	{ 
		return -1;
	}

	while (!feof(fp))
	{
		fgets
		numofrows++;
	}

}
