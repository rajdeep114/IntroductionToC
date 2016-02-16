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
	flush(value44, value26, value65);

	while(1) {
				// corner turn on
	
	// // corner turn on
		writeValue(value44, 1);
		writeValue(value26, 0);
		writeValue(value65, 1);
		flush(value44, value26, value65);

		usleep(300000);

		writeValue(value44, 0);
		writeValue(value26, 1);
		writeValue(value65, 0);
		flush(value44, value26, value65);

		usleep(300000);



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


		// writeValue(value44, 1);
		// writeValue(value26, 0);
		// writeValue(value65, 0);
		// flush(value44, value26, value65);

		// usleep(400000);

		// writeValue(value44, 1);
		// writeValue(value26, 1);
		// writeValue(value65, 0);
		// flush(value44, value26, value65);

		// usleep(400000);

		// writeValue(value44, 1);
		// writeValue(value26, 1);
		// writeValue(value65, 1);
		// flush(value44, value26, value65);

		// usleep(400000);


		// writeValue(value44, 0);
		// writeValue(value26, 0);
		// writeValue(value65, 0);
		// flush(value44, value26, value65);

		// usleep(400000);