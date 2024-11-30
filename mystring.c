#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strTok(char *s, const char *ct);
char *strDup(const char *str);
char *getStr(const char *str);
char *memCpy(char *destination, const char *source, int n);
int strLen(const char *str);

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

	if (s != NULL) {
		ptr = s;
	} if (ptr == NULL) {
		return NULL;
	}
	
	char *start = ptr;
	int n = strLen(ct);
	while (*start) {
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (*start == ct[j]) {
				flag = 1;
				break;
			}
		} 

		if (flag != 1) {
			break;
		} 
		++start;
	} 

	if (*start == '\0') {
		return NULL;
	} 

	char *end = start;
	while (*end) {
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (*end == ct[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
		++end;
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

/*
char *strTok(char *s, const char *ct) {
	
	static char *ptr = NULL;
	//static int static lenS;
	//static int lenCt;
	//static int last = 0;

	//int lenS = strLen(s);
	//int lenCt = strLen(ct);

	if (s != NULL) {
		ptr = s;
	} if (ptr == NULL) {
		return NULL;
	}
	
	char *start = ptr;
	int flag;
	while (last < lenS) {
		flag = 0;
		int j = 0;
		for (; j < lenCt; ++j) {
			if (s[last] == ct[j]) {
				flag = 1;
				break;
			}
		}
		if (flag != 1) {
			break;
		} 
		start = s + j - 1;
	} 

	if (*start == '\0') {
		return NULL;
	} 

	char *end = start;
	while (last < lenS) {
		flag = 0;
		int j = 0;
		for (; j < lenCt; ++j) {
			if (s[last] == ct[j]) {
				flag = 1;
				break;
			}
		}
		if (flag != 1) {
			break;
		}
		end = s + j - 1;
	}
	
	if (end != NULL) {
		*end = '\0';
		ptr = end + 1;
	}
	else {
		ptr = NULL;
	}

	return ptr;
} p */
