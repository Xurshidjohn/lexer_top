#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define BSZ '\0'
#define tt TokenType
#define t Token
char *keys[100] = {"char", "int", "double", "string", "bool"};
typedef enum {
	UNKNOWN,
	TYPE,
	EQUAL
} TokenType;

typedef struct {
	char *token;
	tt tokenType;
} Token;

t*Tokens[100];

void tokenizer(char *word) {
	for(int i = 0;i < 10;i++) {
		if(strcmp(keys[i], word)) {
			printf("%s", word);	
		}
	}
	t token;
	strcpy(word, token.token);
	// token.tokenType = 
}

void parser(char *word)
{
	char support_char;
	if(word[0] == '=') {
		support_char = word[0];
	} else if(word[0] != '=') {
		tokenizer(word);
	}
}


void init_lexer(char *code) {
	char* word = (char*)malloc(200 * sizeof(char*));
	int word_len = 0;
	int i =0;
	while(code[i] != BSZ) {
		if(!isspace(code[i])) {
			word[word_len] = code[i];
			word_len++;
		} else if(isspace(code[i])) {
			if (word_len == 1) {
				printf("%c", code[i]);
				parser(word);
			} else if(word_len != 1) {
				parser(word);
			}
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
