#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define BSZ '\0'
const char* keys = {"char", "int", "double", "string", "bool"};

void parser(char *word, char character)
{
	if(character == '0') {
		printf("bu word\n");
		for(int i = 0;i < strlen(word);i++) {
			printf("%c\n", word[i]);
		}
	} else if (character!= '0') {
		printf("bu character\n");
		printf("%c\n", character);
	}
}


void init_lexer(char *code) {
	char* word = (char*)malloc(200 * sizeof(char*));
	int word_len = 0;
	char for_char = 'd';
	int i =0;
	while(code[i] != BSZ) {
		if(!isspace(code[i])) {x
			word[word_len] = code[i];
			word_len++;
		} else if(isspace(code[i])) {
			if (word_len == 1) {
				for_char = code[i];
				printf("%c", code[i]);
				parser(word, for_char);
			} else if(word_len != 1) {
				parser(word, '0');
			}
			for_char = BSZ;
			word = (char*)malloc(100 * sizeof(char*));
			word_len = 0;
		}
		++i;
	}
}

int main()
{
	init_lexer("int shabbat = shalom; \0");
}