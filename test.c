%{

	#include <string.h>

	static int wordCount = 0;
	static int chapter = 1;
	static char currentWords[11][100];

	void clearIndex(int);
	void printWords();
	void shiftLeft();
	void insertWord(char*); 

%}

Junk [ \-;.,\n\r]
Letters [^ \-,;\.\n\r]+
ChapterDelimeter _CHAPDELIM

%%

{ChapterDelimeter} {
	for (int i = 0; i < 5; i++) {
		insertWord("");
		printWords();
	}

	chapter++;
	wordCount = 0;
}

{Letters}(-{Letters})* {insertWord(yytext);

	if (wordCount > 5) {
		printWords();
	}
}

{Junk} {}

<<EOF>> {return 0;}

%%

int yywrap(){}

int main() {

	for (int i = 0; i < 11; i++) 
		clearIndex(i);

	yylex();

	return 0;
}

/**
 * This function inserts the input word into the currentWords array
 * 
 *  @param word - the word to insert
*/
void insertWord(char* word) {
	shiftLeft();
	strcpy(currentWords[10], word);
	wordCount++;
}

/**
 * This function shifts all values of the current words array left by 1
 * This function basicallly just frees the rightmost array element
*/
void shiftLeft() {
	char temp[100];
	char temp2[100];
	strcpy(temp, currentWords[10]);
	clearIndex(10);

	for (int i = 10; i > 0; i--) {
		strcpy(temp2, currentWords[i-1]);
		strcpy(currentWords[i-1], temp);
		strcpy(temp, temp2);
	}
}

/**
 * This function prints a row of the table based on the contents of the 
 * 	current words array
*/
void printWords() {
	printf("%s,%d,%d,", currentWords[5], chapter, wordCount-5);

	for (int i = 0; i < 11; i++) {
		if (i == 5) {
			printf(",");
			continue;
		}

		if (strlen(currentWords[i])) {
			printf("%s", currentWords[i]);
			if (i != 4 && i != 10)
				printf(" ");
		}
	}

	printf("\n");
}

/**
 * This function will blank whatever string is at the given index
 * 	of the current words array
*/
void clearIndex(int index) { 
	for (int j = 0; j < 100; j++)
		currentWords[index][j] = '\0';
}