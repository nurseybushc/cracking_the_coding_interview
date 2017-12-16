#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
Question1
Determine if a string has all unique characters
date		change
12-16-17	creation
*/

bool hasAllUniqueCharacters(char* userstring)
{	
	int i,j,count,len;
	len = strlen(userstring);
	for(i = 0; i < len; ++i) {
		char a = userstring[i];
		for(j = i+1; j < len; ++j) {
			if(a == userstring[j]) {
				return false;		
			}
		} 
	}	 
	return true;
}

int main()
{
	char userstring[20];

	printf("Please enter a string <= 20 characters:\n");
	fgets(userstring, 20, stdin);
	
	printf("String was %s\n", userstring);
	
	if(hasAllUniqueCharacters(userstring)) printf("Has all unique chars\n");
	else printf("Doesn't have all unique chars\n");
	
	return 0;
}
