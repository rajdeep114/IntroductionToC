#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// This program uses char pointers to converter an int to binary
int main() {
	char s[4] = {'0', '0', '0', '\0'};
	int i = 6;
	char* p = s;
	p = p+2;
	while (i != 0) {
		*p = (i % 2) + '0';
		i = i / 2;
		p--;
	}
	p = s;
	int j = 0;
	for (j = 0; j < 3; j++) { 
		printf("%c", *p);
		p++;
	}
	printf("\n");
	return 0;

}

