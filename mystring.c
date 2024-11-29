#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strLen(const char *str) {
	int len = 0;
	int p = 0;
	if (str == NULL) {
		printf("String is empty!\n");
		return 0;
	}
	while (str[p] != '\0') {
		++len;
		++p;
	} return len;
}

char *memCpy(char *destination, const char *source, int n) {
	for (int i = 0; i < n; i++) {
		destination[i] = source[i];
	} return destination;
}

char *getStr(const char *str){
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
			int chunk_len = strLen(buf);
			int str_len = len + chunk_len;
			res = realloc(res, str_len + 1);
			memCpy(res + len, buf, chunk_len);
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

char *strDup(const char *str) {
	int len = strLen(str);
	char *duplicate = malloc(len * sizeof(char) + 1); 
	for (int i = 0; i <= len; ++i) {
		duplicate[i] = str[i];
	}
	return duplicate;
}

char *strTok(char *s, const char *ct) {
	static char *ptr = NULL;

	static int lenS = strLen(s);
	static int lenCt = strLen(ct);
	static int last = 0;

	if (s != NULL) {
		ptr = s;
	}
	if (lenS == 0) {
		return NULL;
	}
	
	char *start = ptr;
	int flag;
	while (last < lenS) {
		flag = 0;
		for (int j = 0; j < lenCt; ++j) {
			if (s[last] == ct[j]) {
				flag = 1;
				break;
			}
		}
		if (flag != 1) {
			break;
		} 
		start == s[i];
	} 

	if (*start == '\0') {
		return NULL;
	} 

	char *end = start;
	while (last < lenS) {
		flag = 0;
		for (int j = 0; j < lenCt; ++j) {
			if (s[last] == ct[j]) {
				flag = 1;
				break;
			}
		}
		if (flag != 1) {
			break;
		}
		end == s[i];
	}
	
	if (*end != NULL) {
		*end = '\0';
		ptr = end + 1;
	}
	else {
		ptr = NULL;
	}

	return ptr;
}
