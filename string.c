#include <stdio.h>
#include <stdlib.h>
#define DELIM " \t"

char *strchr(char *, char);
char *strtok(char *s, const char *ct);
char *strdup(const char *str);
char *readline(const char *str);
char *memcpy(char *destination, const char *source, int n);
int strlen(const char *str);

char *strchr(char *s, char c) {
	
	if (s == NULL) {
		printf("Empty string!\n");
		return NULL;
	}

	char *ptr = s;
	while (*ptr != '\0') {
		if (*ptr == c) {
			return ptr;
		}
		ptr++;
	} 
	
	return NULL;
}

int strlen(const char *str) {
	
	int len = 0;
	int p = 0;
	
	if (str == NULL) {
		printf("String is empty!\n");
		return 0;
	}
	
	while (str[p] != '\0') {
		++len;
		++p;
	} 

	return len;
}

char *memcpy(char *destination, const char *source, int n) {
	
	for (int i = 0; i < n; i++) {
		destination[i] = source[i];
	} 

	return destination;
}

char *readline(const char *str){
	char buf[81] = {0};
	char *res = NULL;
	int len = 0;
	int n = 0;
	
	do {
		printf("%s", str);
		n = scanf("%80[^\n]", buf);
		if (n < 0) {
			if (!res) {
				return NULL;
			}
		}
		else if (n > 0) {
			int chunk_len = strlen(buf);
			int str_len = len + chunk_len;
			res = realloc(res, str_len + 1);
			memcpy(res + len, buf, chunk_len);
			len = str_len;
		}
		else {
			scanf("%*c");
		} 
	} while (n > 0);

	if (len > 0) {
		res[len] = '\0';
	}

	else {
		res = calloc(1, sizeof(char));
	}

	return res;
}

char *strdup(const char *str) {
	int len = strlen(str);
	char *duplicate = malloc(len * sizeof(char) + 1); 
	
	for (int i = 0; i <= len; ++i) {
		duplicate[i] = str[i];
	}
	
	return duplicate;
}

char *strtok(char *s, const char *ct) {
	static char *ptr = NULL;

	if (s != NULL) {
		ptr = s;
	} 
	if (ptr == NULL) {
		return NULL;
	}
	
	char *start = ptr;
	while (strchr(DELIM, *start)) {
		start++;
	}
	
	if (*start == '\0') {
		return NULL;
	} 
	
	char *end = start;
	while (!strchr(DELIM, *end) && *end) {
		end++;
	}
	
	if (*end) {
		ptr = end + 1;
		*end = '\0';
	}
	else {
		ptr = NULL;
	}

	return start;
}
