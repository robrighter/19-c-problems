#include <stdio.h>
#include <string.h>

const int MAX_CHARS_PER_LINE = 300;

void recurseFile(const char *infile){
	//fprintf(stdout, "About to open file '%s'\n", infile);
	FILE *f = fopen(infile, "r");
	if(!f){
		fprintf(stderr,"COULD NOT OPEN THE FILE");
	}
	char line[MAX_CHARS_PER_LINE];
	int count = 0;
	while(fgets(line, MAX_CHARS_PER_LINE, f)){
		//fprintf(stdout, "Line %d: %d Characters\n", count++, (int)strlen(line));
		line[(int)strlen(line)-1] = '\0';
		if( ((int)strlen(line)) > 1  &&  line[0] == '@'){
			recurseFile( (const char*)(line+1) );
		} 
		else{
			fprintf(stdout, "> %s \n", line);
		}
	}
	fclose(f);
}

int main(int argc, char *argv[]){
	if(argc < 2){
		fprintf(stdout,"Usage: recurse-file [filename]\n");
		return 1;
	}
	recurseFile(argv[1]);
	return 0;
}
