#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Template of a single node
typedef struct node {
	char* word;
	struct node *children[9]; 
} trie_node;

// ADT
typedef struct node_point {
	trie_node *pointer;
} trie_node_adt;

// Method prototypes
int char_to_digit (char );
int string_to_digit (char *);
void read_file (char *, trie_node_adt *);
trie_node* initialize_node ();
void insert (trie_node_adt *, char *);
void init(trie_node_adt *n);

int main(int agrc, char **argv) {
	trie_node_adt root;
	init(&root);
	//read_file(argv[1], &root);
	//read_file(argv[1]);
	//trie_node *root;
	//root = initialize_node();
	//insert (&root, "hello");
	read_file(argv[1], &root);
	
	
}

// Initialize a trie node 
trie_node* initialize_node() {
	int i;
	trie_node *pointer;
	pointer = NULL;
	pointer = (trie_node *) malloc (sizeof(trie_node));
	if(pointer) {
		pointer->word = NULL;
		for (i = 0; i < 9; i++)
			pointer->children[i] = NULL;
	}
	printf("done Initialize\n");
	return pointer;
}

void init(trie_node_adt *n) {
	n->pointer = initialize_node();
}

void insert (trie_node_adt *root, char *word) {
	int i, digit;
	int length = strlen (word);
	//printf("%d", length);
	trie_node *node_pointer;
	node_pointer = root->pointer ;

	for (i = 0; i < length; i++) {
		digit = char_to_digit (*(word + i)) - 2;
		
		//printf("hello\n");
		if (node_pointer->children[digit] == NULL) {
			//printf("hey\n");
			node_pointer->children [digit] = initialize_node();
		}
		node_pointer = node_pointer->children[digit];
		//printf("%d\n", digit);
	}
	//printf("forloopend");
	node_pointer->word = word;		// Final node
	printf("%s\n", node_pointer->word);
}


// Reads the dictionary file
void read_file (char *filename, trie_node_adt *root) {
	FILE *read;
	read = fopen(filename, "r");
	//while (read == NULL ) {
		//printf("File does not exits. Try again or enter \"quit\":");
		//read = fopen(filename, "r");
	//}
	if(read != NULL) {
		char s[20];
		char *pointer;
		while(fscanf(read, "%s", s) != EOF) {
			int length = strlen(s) + 1;				// Length of string constant
			pointer = (char *) malloc (sizeof(length));		// Space assigned in heap
			strncpy(pointer, s, 20);						// Copy word in the heap location
			insert (root, pointer);							
		}
	} else
		exit(1);
} 
// Converts a string constant to digit squence 
int string_to_digit (char *s) {
	int digit = 0;
	while (*s != '\0') {
		digit = digit * 10 + char_to_digit(*s);
		s++;
	}
	return digit;
}

// Converts a char to its corresponding digit 
int char_to_digit (char s) {
	char letter[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6,
						7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
	int index = s - 'a';
	return letter[index];
}