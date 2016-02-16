#include <stdio.h>

int power (int base, int p);
int string_length (char* s);
int string_length_2 (char* s);
int string_length_3 (char* s);
int string_length_i (int* s);
void string_copy (char* s, char* t);
void string_copy_2 (char* s, char* t);
void string_copy_3 (char* s, char* t);
void string_copy_4 (char* s, char* t);
int convert_to_number (char* s);
void toLower (char* s);
void toUpper (char* s);
void squeeze (char* s, char c);
void squeeze_non_alpha (char* s);
void cat_string (char* dest, char* s);
void remove_matches (char* dest, char* s);
int first_match (char* d, char* s);
int multiple_power_2 (int two, int power);
void bit_wise_oper (unsigned int i, int j);
int binary_ones (int n);
void convert_binary (int n);
void reverse_string (char* s);
int binary_search (int* s, int match, int size_arr);
void swap (int** a, int** b);
void Pointers_Arrays (int* num, char* string);
char* month_name (int);

// Enumeration constant to use booleans in C
//enum boolean { 
 //  false, true
//};

int main() {
   //char arr[] = "hello";
   //char arr2[10];
   //printf("%s\n%s\n", arr, arr2);
   //string_copy_3 (arr2, arr);
   //printf("%s\n%s\n", arr, arr2);
  // 

   int a = 2;
   int b = 4;
   int* x = &a;
   int* y = &b;
   int** xx = &x;
   int** yy = &y;
   printf ("a = %d  a = %d\n", a, b);
   swap(xx, yy);
   printf ("a = %d  a = %d\n", a, b);
   // char *s = "hello";
   // char *p = " World!!";      
   // //char *p = &test[0];
   // char *arr[] = {s, p};
   
   // char** argv = arr;
   // //printf("%s\n", argv[0]);

   // //char happy[] = "hello";
   // char *happy = "hello";
   // char **hap = &happy;
   // printf("%s\n", *hap);
   // //char **pp = &s;         // We need address of p in order of **pp to point to it 
   // //printf("%c\n", *((*pp)+ 1));
   // //printf("%s\n", *pp);
   //int i;
   //for (i = 0; name[i] != '\0'; i++)
    //  printf("%s\n", *name);
  // char* p = month_name(name, 2);
   //printf("%s\n", p);

   return 0;
}

// Array of pointer pointing to char *s
// Passing char **name and char *name[] as a parameter is the same thing
// Passing char *name and char name[] as a parameter is the same thing too.
char* month_name (int n) {
   // This is a array of pointers that points to char
   char *name[] = {"Illegal month", "Jan", "Feb", "March", "April",
                   "May", "June", "July", "August", "Sep", "October",
                   "November", "December", 0};
   if (n <= 0 || n > 12) 
      return name[0];
   else
      return name[n];
}


// Pointers and Array Implementation
void Pointers_Arrays (int* num, char* string) {
   int i;
   for (i = 0; num[i] != '\0'; i++) 
      printf("%d --- %d\n", num[i], *num);


   for (i = 0; string[i] != '\0'; i++) 
      printf("%c --- %c\n", string[i], *string);  
}

// Swap integer a and b
void swap(int** a, int** b) {
   int temp;
   temp = **a;
   **a = **b;
   **b = temp;
}

// Fix this using array subscripts
// Binary search: Alright!! Does not calculate index
int binary_search (int* s, int match, int size_arr) {
   int* L = s;
   int size = (size_arr - 1);
   int* R = size + s;
   int diff = R - L;
   printf("%d\n", diff); 
   if (*L == match)
      return 0;
   else if (*R == match)
      return size;
   else {
      while (L != R) {
        // char* M = (&L + &R) / 2;
         size = size / 2;
         int* M = L + size;
         if (match < *M) 
            R = M - 1;
           // printf("Update R\n");
         else if (match > *M) 
            L = M + 1;
            //printf("Update L\n");
         else 
            return *M;
           // return *M;
      }
      return -1;
   }
} 

// Reverse string
void reverse_string (char* s) {
   char temp;
   char* R = s + (string_length(s) - 1);
   char* L = s;
   while (R != L) {
      temp = *L;
      *L = *R;
      *R = temp;
      L++; R--;
   }
}
// Prints binary from of a number, does not store it !!!
void convert_binary (int n) {
   int bit;
   int number;
   for (bit = 31; bit >= 0; bit--) {
      number = n >> bit;
      if (number & 1)
         printf("1");
      else
         printf("0");
   }
   printf("\n");
}
// Count number of 1's in a number in its binary form: Using Masking
int binary_ones (int n) {
   int i;
   for (i = 0; n != 0; n >>= 1) {
      if (n & 1)
         i++;
   }
   return i;
}
// Bitwise operations
void bit_wise_oper (unsigned int i, int j) {
   // AND for masking
   int x = (i >> 3) & j;         // MASKING
   printf("%d\n", x);

   // OR for getting all 1's
   int y = i | j;                // TO OBTAIN ALL 1's
   printf("%d\n", y);

   // XOR 
   int z = i ^ j;                // TO OBTAIN ALL 1's
   printf("%d\n", z);

   // NOT
   int q = ~ 1;
   printf("%d\n", q);
   //int 
   //return x;
}

// Compare two strings and delete matches from the first string
void remove_matches (char* dest, char* s) {
   char* p = dest;               // Create a temp pointer to traverse through the string and remove matching character
   char* initial = dest;         // Temporary pointer to reset pointers dest and p to beginning of the string.
   while (*s != '\0') {          // Test for string s
      dest = initial;            // Reset pointer dest to its original position
      p = initial;               // Reset pointer p to its original position
      // ------------------------>> Algorithm to remove matching character from the string ***
      while (*dest != '\0') {    
         if (*dest != *s) {
            *p = *dest;
            p++;
            dest++;
         } else {
            dest++;
         }
      }
      s++;
      *p = '\0';
   }
   // --------------------------->>
}

// Compares two strings and returns the comman character if Match exits, else -1
int first_match (char* d, char* s) {
   char* p = d;
   int i = 0;
     while (*s != '\0' && i == 0) { 
         p = d;               
      while (*p != '\0' && i == 0) {    
         if (*p == *s) 
            i = 1;
         else
            p++;
      }
      s++;
   }
   // Return the matching character if matched else -1 
   if (i == 1)
      return *p;
   else
      return -1;
}

// Concatinate two strings
void cat_string (char* dest, char* s) {
   char* p = dest;                           // Create a temp pointer
   int dest_length = string_length(dest);    // Calculate the length of first string
   p = p + dest_length;                      // Offset the temp pointer to that location in order to start copying new string
   while (*s != '\0') {                      // When the second string reaches null character
      *p = *s;                               // Set temp pointer to value of the second string
      p++;
      s++;
   }
   *p = '\0'; 
}

// power method
int power(int base, int p) {
   int result = 1;
   while(p != 0) {
      result = result * base;
      p--;
   }
   return result;
} 

// Multiple a number 2^power using <<
int multiple_power_2 (int two, int power) {
   //
      return two << power;
}

//****************************************
//****** STRING COPY VERSIONS ************
//****************************************

// Version 1
void string_copy (char* s, char* t) {
   while ((*s = *t) != '\0') {
      s++;
      t++;
   }
 }

 // Version 2 
 // Value of *t is given to *s and then both pointers increments
 void string_copy_2 (char* s, char* t) {
   while ((*s++ = *t++) != '\0') 
      ;
 }
  // Version 3 (Preferred !!!)
 // Value of *t is given to *s and then both pointers increments
 // '\0' is ommited since after traversing expression (*s++ = *t++) becomes zero
 void string_copy_3 (char* s, char* t) {
   while ((*s++ = *t++)) 
      ;
 }

 // Version 4
 void string_copy_4 (char* s, char* t) {
   int i = 0;
   while ((s[i] = t[i]) != '\0') 
      i++;
 }

//***************************************
//***************************************
//***************************************

//***************************************
//****** STRING LENGTH VERSIONS *********
//***************************************
// Calculate size of string

// Version 1
int string_length (char* s) {
   int i = 0;
   // exit loop when 
   while(*s != '\0') {     
      i++;
      s++;
   }
   return i;
}

// Version 2 (Preferred!!!)
int string_length_2 (char* s) {
   int i;
   for (i = 0; *s != '\0'; s++) 
      i++;
   return i;
}

// Version 3
int string_length_3 (char* s) {
   char* p = s;
   while(*p != '\0')
      p++;
   return p - s;                 // Subtract two pointers acting on the same string constant
}

// Version 4
int string_length_i (int* num) {
   int i;
   for (i = 0; *num != '\0'; num++) 
      i++;
   return i;
}

//***************************************
//***************************************
//***************************************

// Convert string to integer: 'atoi'
int convert_to_number (char* s) {
   int number = 0;            // for the units place 
   while(*s != '\0' && (*s >= '0' && *s <= '9')) {
      number = number * 10 + *s - '0';    // shift a place by multiplying by 10 
      s++;
   }
   return number;
}

// Converts a string to Lower case
void toLower (char* s) {
   while(*s != '\0') {
      if (*s >= 'A' && *s <= 'Z') 
         *s = 'a' + (*s - 'A');
      s++;
   }
}

// COnverts a string to upper case
void toUpper (char* s) {
   while (*s != '\0') {
      if (*s >= 'a' && *s <= 'z') 
         *s = (*s - 'a') + 'A';
      s++;
   }
}

// Remove all the occurence of the character
void squeeze (char* s, char c) {
   char* p = s;               // introduce temperory pointer
   while (*s != '\0') {       // Loop through the string
      if (*s != c) {          // If character does not match increment both pointers
         *p = *s;             // Update value of string when there is not a match
         p++;                 // Increment temp pointer
         s++;                 // Increment s pointer
      } else {
         s++;                 // If there is a match, increment original pointer
      }
   }
   *p = '\0';
}

// Remove all the non alphabetic characters fromm the string
void squeeze_non_alpha (char* s) {
   char* p = s;                                                         // introduce temperory pointer
   while (*s != '\0') {                                                 // Loop through the string
      if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))  {      // Test if it a letter or not
         *p = *s;                                                       // Update value of string when there is not a match
         p++;                                                           // Increment temp pointer
         s++;                                                           // Increment s pointer
      } else {
         s++;                                                           // If there is a match, increment original pointer
      }
   }
   *p = '\0';
}




   //int result = power(2, 5);
   //int result2 = power(-3, 5);   
   //printf("%d   %d\n", result, result2);
   //printf("I am working in sublime text\n");
   // char string [6] = "hello";
   //char* str = "hello world";
   //printf("%s\n", string);
   //int str_length = string_length(str);
   //printf("%d\n", str_length);
   //int num = convert_to_number ("123\n");
   //printf ("%d", num + 1);
   //char str[15] = "H12$)^o~*!s";
   //toLower(str);
   //toUpper(str);
   //printf("%s\n", str);
   //squeeze_non_alpha (str);
   //char string[20] = "Hello";
   //char str[10] = "w";
   //remove_matches(string, str);
   //int c = first_match (string, str);
   //int i = multiple_power_2(2, 5);
   //printf ("%d\n", i);
      //bit_wise_oper(0, 7);
   //char string[15];
  // int num = string_length(string);
   //convert_binary (2);
   //printf("%d\n", num);
   //int string[] = {1, 12, 31, 40, 41, 42};
  // int length = string_length(string);
   
   //int num = sizeof(string) / sizeof(int);  
   //printf("%d\n", num);                    // Calculate array size
   //int x = binary_search (string, 12, num);
   //int x = 2;
   //int y = 4;
   //printf ("x = %d  y = %d\n", x, y);
   //swap(&x, &y);
   //printf ("x = %d  y = %d\n", x, y);
   // int array1[] = {11, 22, 33, 44, 55, '\0'};
  // int* array2 = "123456788";
   //char array2[] = {'h', 'e', 'l', 'l', 'o', '\0'};
   //char* array3 = "hello\0";
   //Pointers_Arrays (array1, array2); 

   
   // printf("%d\n", string_length_2("Hello"));
   // printf("%d\n", string_length_3("World"));
   // printf("%d\n", string_length_i(array1));
  
   // printf("%s\n", a);
   























