#include <stdio.h>

// Template for struct 
struct point {			
	int x;
	int y;
};

struct rect {			// Nested struct 
	struct point p1;
	struct point p2;
};

struct apple {
	int length;
	char *str;
};
// Method prototypes
// This help us to dynamically initialize structs of type struct point
// It can also be passed as an parameter
struct point make_point (int, int);
struct point add_point (struct point, struct point);
void add_point_2 (struct point*, struct rect*);
int inside_rect (struct point, struct rect);

int main () {
							// This template does not occupy memory space
	// struct point p1;
	// p1.x = 2;
	// p1.y = 3;

	// //printf("(%d, %d)\n", p1.x, p1.y);
	// // Changing the new struct rec, does not change original point


	struct rect screen, *b = &screen;
	struct point middle, *a = &middle; // use the coordinate of the screen to calculate the middle
	screen.p1 = make_point (0, 0);
	screen.p2 = make_point (50, 50);
	middle = make_point((screen.p1.x + screen.p2.x) / 2, (screen.p1.y + screen.p2.y) / 2);
	// a = &middle;
	// b = &screen;
	add_point_2 (a, b);

	//middle = add_point (middle, screen.p2);
	//int exist = inside_rect (middle, screen);
	//printf("(%d, %d)\n", screen.p1.x, screen.p1.y);
	//printf("(%d, %d)\n", screen.p2.x, screen.p2.y);
	//printf("(%d, %d)\n", middle.x, middle.y);
	//printf("%d\n", exist);
	struct apple temp;
	struct apple *p;
	p = &temp;

	p->length = 4;
	p->str = "qhello";
	printf("%s\n", p->str);
	printf("%d\n", p->length);
	//(p++);		//25
	//(p++);		//0
	//(p++);		// 75
	//(p++);		// 0
	//(p++);
	printf("%d\n", p->length);




	return 0;

}

void add_point_2 (struct point *p, struct rect *q) {
	//(*p).x += (*q).p2.x;
	//(*p).y += (*q).p2.y;
	p->x += (q->p2).x;
	p->y += (q->p2).y;
	//int x = (*p).x;
	//printf("%d\n", x+1);
}

// Return true if the point exit in the rectangle (two points)
int inside_rect (struct point p, struct rect r) {
	return p.x > r.p1.x && p.x < r.p2.x && p.y > r.p1.y && p.y < r.p2.y;
}

// *************************************************************
// * Takes in two structs as argument and increment the member *
// * of first struct by the value of members of second struct. *
// * If we use void return type, the local copy in the Method  *
// * is updated not the one passed as the argument (middle).   *
// * So we return a struct. 								   *
// *************************************************************								 *
struct point add_point (struct point a, struct point b) {
	a.x += b.x;
	a.y += b.y;
	return a;
}
// Method takes in two int values, then use it in a struct and returns a struct 
struct point make_point (int x, int y) {

	struct point temp;					// create a struct of type "struct point"
	temp.x = x;							// Using arguement value to update members 
	temp.y = y;							// Using arguement value to update members 
	return temp;
}


	// screen.p1.x = 6;
	// screen.p1.y = 7;
	// screen.p2.x = 4;
	// screen.p2.y = 5;

	// printf("(%d, %d)\n", p1.x, p1.y);
	// printf("(%d, %d)\n", screen.p1.x, screen.p1.y);
	// printf("(%d, %d)\n", screen.p2.x, screen.p2.y);
	
