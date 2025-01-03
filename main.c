#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef FLAG
#include "string.h"
#else
#include <string.h>
#include <readline/readline.h>
#endif

#define DELIM " \t"
#define PROMPT "> "
#define VOWELS "AaEeIiOoUuYy"

int countVowels(const char *word);
char *process(const char *str);

int main() {
	char *input = readline(PROMPT);
	while (input != NULL) {
		printf("\"%s\"\n", input);
		clock_t start = clock();
		char *output = process(input);
		clock_t end = clock();
		double t = (float)(end - start) / CLOCKS_PER_SEC;
		printf("Answer: \"%s\"\n", output);
		printf("Time: %lf\n", t);
		free(input);
		free(output);
		input = readline(PROMPT);
		int x = 0; 
	}
	return 0;
}

char *process(const char *str) {
	char *s = strdup(str);
	int s_len = strlen(s);
	char *res = calloc(s_len + 1, sizeof(char));
	int len = 0;
	char *word = strtok(s, DELIM);
	while (word != NULL) {
		printf("Word: \"%s\"\n", word);
		int w_len = strlen(word);
		int k = countVowels(word);
		if (w_len > 0 && (k % 2 != 0)) {
			memcpy(res + len, word, w_len * sizeof(char));
			len += w_len;
			res[len] = ' ';
			len++;
		}
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
	int len = strlen(word);
	for (int i = 0; i < len; i++) {
		if (strchr(VOWELS, (char)word[i])) {
			count++;
		}
	} 
	return count;
}
