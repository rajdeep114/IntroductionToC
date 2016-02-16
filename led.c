#include <stdio.h>
#include <unistd.h>


// fflush :	forces all input/output to completer
// 		    since the writing and reading operation
// 			is much slower than the processor speed  

void writeValue(FILE* value, int i);
void writeDir(FILE* dir, char* s);
void flush(FILE *value44, FILE *value26, FILE *value65); 
void closefile(FILE* dir, FILE* value);


int main() {

	FILE *dir44, *dir26, *dir65;
	FILE *value44, *value26, *value65;
	



	dir44 = fopen("/sys/class/gpio/gpio44/direction", "w");
	value44 = fopen("/sys/class/gpio/gpio44/value", "w");
	dir26 = fopen("/sys/class/gpio/gpio26/direction", "w");
	value26 = fopen("/sys/class/gpio/gpio26/value", "w");
	dir65 = fopen("/sys/class/gpio/gpio65/direction", "w");
	value65 = fopen("/sys/class/gpio/gpio65/value", "w");

	writeDir(dir44, "out");
	writeDir(dir26, "out");
	writeDir(dir65, "out");
	flush(dir44, dir26, dir65);
	
	int i = 0;
	int num = 0;
	char s[4] = {'0', '0', '0', '\0'};
	char* p = s;

	while(1) {
		if (num == 8) {
			num = 0;
			*s = '0';
			*(s + 1) = '0';
			*(s + 2) = '0';
			printf("here....\n");
		}
		i = num;

		while (i != 0) {
			*p = (i % 2) + '0';
			i = i / 2;
			p++;
		}
		p = s;

		printf("%s\n", p);
		//printf("%d", *p - '0');
		//printf("%d", *(p + 1) - '0');
		writeValue(value44, *p - '0');
		writeValue(value26, *(p + 1) - '0');
		writeValue(value65, *(p + 2) - '0');
		flush(value44, value26, value65);

		usleep(100000);
		
		writeValue(value44, 0);
		writeValue(value26, 0);
		writeValue(value65, 0);
		flush(value44, value26, value65);
	
		usleep(100000);
		num++;
		
		
	}
	closefile(dir44, value44);
	closefile(dir26, value26);
	closefile(dir65, value65);

	return 0;
}

void writeValue(FILE* value, int i) {
	fprintf(value, "%d", i);
	
}

void writeDir(FILE* dir, char* s) {
	fprintf(dir, "%s", s);
}

void flush(FILE *value44, FILE *value26, FILE *value65) {
	fflush(value44);
	fflush(value26);
	fflush(value65);
}

void closefile(FILE* dir, FILE* value) {
	fclose(dir);
	fclose(value);
}









