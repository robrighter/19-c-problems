#include <stdio.h>
#include <string.h>

#define	FALSE 0

int compareStrings(const char *str1, const char *str2, char noise){
	while(str1[0] == noise) str1++;
	while(str2[0] == noise) str2++;
	
	if(str1[0] == '\0'){
		return (str2[0] == '\0');
	}
	else if(str2[0] == '\0'){
		return FALSE; 
	}
	else if(str1[0] == str2[0]){
		return compareStrings(++str1, ++str2, noise);
	}
	return FALSE;
}

int main(int argc, char *argv[]){
	if(argc < 4){
		fprintf(stdout,"Usage: compare-strings [string 1] [string 2] [noise character]\n");
		return 1;
	}
	
	fprintf(stdout, compareStrings(argv[1],argv[2],argv[3][0]) ? "The strings are equal.\n":"The strings are NOT equal.\n");
	return 0;
}
