#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <string.h>
#include "mystring.h"
#include <time.h>

#define DELIM " \t"
#define PROMPT "> "
#define VOWELS "AaEeIiOoUuYy"

int countVowels(const char *word);
char *process(const char *str);

int main() {
	char *input = getStr(PROMPT);
	while (input != NULL) {
		printf("\"%s\"\n", input);
		clock_t start = clock();
		char *output = process(input);
		clock_t end = clock();
		float t = (float)(end - start) / CLOCKS_PER_SEC;
		printf("\"%s\"\n", output);
		free(input);
		free(output);
		input = getStr(PROMPT);
	}
	return 0;
}

char *process(const char *str) {
	char *s = strDup(str);
	int s_len = strLen(s);
	char *res = calloc(s_len + 1, sizeof(char));
	int len = 0;
	char *word = strtok(s, DELIM);
	while (word != NULL) {
		printf("Word: \"%s\"\n", word);
		int w_len = strLen(word);
		int k = countVowels(word);
		if (w_len > 0 && (k % 2 != 0 || k == 0)) {
			memcpy(res + len, word, w_len * sizeof(char));
			len += w_len;
			res[len] = ' ';
			len++;
		} //printf("len=%d strlen(res)=%d\n",len,strlen(res));
		//printf("Result: \"%s\"\n", res);
		word = strtok(NULL, DELIM);
	}
	free(s);
	if (len > 0) {
		--len;
	}
	res[len] = '\0';
	res = realloc(res, (len + 1) * sizeof(char));
	return res;
}

int countVowels(const char *word) {
	int count = 0;
	int len = strLen(word);
	for (int i = 0; i < len; i++) {
		if (strchr(VOWELS, (char)word[i])) {
			//printf("%c\n", word[i]);
			count++;
		}
	} 
	//printf("Vowels count: %d\n", count);
	return count;
}
