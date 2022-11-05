// PointerPlayground.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>

void StringArrayExample(void);
void IntegerArrayExample(void);
void StructArrayExample(void);
void ClassArrayExample(void);
void addressOfOp(void);
void addressOfChange(int&);
void addressToPointerChange(int*);

int main()
{
	/**************************************************/
	/* Note: arrays defind as i[10] are allocated on  */
	/* the stack. Pointers that use malloc, realloc,  */
	/* etc. are allocated on the heap. Heap is much   */
	/* slower than the stack.                         */
	/**************************************************/
	int ans = 0;
	char c;
	while (ans < 99) {
		printf("This will show the result of the\n");
		printf("sample code for each of the following.\n");
		printf("\n");
		printf("Menu\n");
		printf("===================\n");
		printf("1. String Array\n");
		printf("2. Integer Array\n");
		printf("3. Struct Array\n");
		printf("4. Class Array\n");
		printf("5. Address of Operator\n");
		printf("===================\n");
		printf("9. Quit\n");

		printf("\nChoose a number: ");

		/* 'scanf_s' is quite stupid in that any      */
		/* character that doesn't match the format    */
		/* will cause an infinite loop. This code     */
		/* will prevent that from happening.          */
		c = getc(stdin);
		ans = (int(c) - 48);

		/* Flush buffer but, check if the user        */
		/* enter without an entry.                    */
		if (int(c) != 10) {
			while ((c = getchar()) != '\n' and c != EOF) {}
		}

		if (ans > 9) {
			printf("Invalid choice.\n\n");
			ans = 0;
		}

		switch (ans) {
		case 1:
			StringArrayExample();
			break;
		case 2:
			IntegerArrayExample();
			break;
		case 3:
			StructArrayExample();
			break;
		case 4:
			ClassArrayExample();
			break;
		case 5:
			addressOfOp();
			break;
		case 9:
			ans = 99;
			break;
		default:
			ans = 0;
			break;
		}
	}
}

void StringArrayExample(void) {

	printf("/**************************************************/\n");
	printf("/*              Dynamic String Array              */\n");
	printf("/**************************************************/\n");

	/* Strings are just a pointer to an array of type */
	/* char with a NULL terminater. In this case, we  */
	/* need to have a pointer to a pointer as strings */
	/* are actually referenced by address.            */
	char** strArray = NULL;

	/* String we will put into dynamic array.         */
	char word0[] = "Hello World!";
	char word1[] = "Another Hello World!";
	char word2[] = "Yet Another Hello World!";

	/* Since this is a dynamic, we have to keep track */
	/* of what we are putting into the array.         */
	int numStrings = 0;

	/* This initializes the array to hold the first   */
	/* two strings. It is the count of bytes 'word0'  */
	/* and word1 plus both will have a NULL byte as   */
	/* a terminator (12+20+1+1) = 34.                 */
	strArray = (char**)malloc(sizeof(char) * 34);

	/* Put the first string at element 0. Increment   */
	/* numStrings counter by 1.                       */
	strArray[0] = (char*)malloc(sizeof(char) * 13);
	strcpy_s(strArray[0], 13, word0);
	numStrings++;

	/* Put the second string at element 1. Increment  */
	/* numStrings counter by 1.                       */
	strArray[1] = (char*)malloc(sizeof(char) * 21);
	strcpy_s(strArray[1], 21, word1);
	numStrings++;

	/* For the last string, we need to resize the     */
	/* array to be able to store it. The count of     */
	/* bytes (24+1) = 25. And, 25+34 = 59 which is    */
	/* the new size.                                  */
	strArray = (char**)realloc(strArray, 59);

	/* Put the last string at element 2. Increment    */
	/* numStrings Counter by 1.                       */
	strArray[2] = (char*)malloc(sizeof(char) * 25);
	strcpy_s(strArray[2], 25, word2);
	numStrings++;

	/* Print out the string array using element.      */
	printf("Element:\n");
	for (int a = 0; a < numStrings; a++) {
		printf("strArray[%d] - %s\n", a, strArray[a]);
	}
	printf("\n");

	/* Print out the string array using pointer.      */
	printf("Pointer math:\n");
	for (int a = 0; a < numStrings; a++) {
		printf("strArray[%d] - %s\n", a, *(strArray + a));
	}
	printf("\n");
	printf("Number of elements = %d\n", numStrings);

	free(strArray);
}
void IntegerArrayExample(void) {
	printf("/**************************************************/\n");
	printf("/*             Dynamic Integer Array              */\n");
	printf("/**************************************************/\n");

	/* Nothing special about integers. Just create a  */
	/* pointer to the header of the list.             */
	int* integerArray = NULL;

	/* Since this is created dynamically, we have to  */
	/* keep track of number of elements.              */
	int numIntegers = 0;

	/* Allocate enough memeory to hold one integer.   */
	integerArray = (int*)malloc(sizeof(int) * (numIntegers + 1));

	/* Set element 0 to some arbitrary number.        */
	integerArray[numIntegers] = 100;
	numIntegers++;

	/* To add the next integer, we need to allocate   */
	/* more memory.                                   */
	integerArray = (int*)realloc(integerArray, sizeof(int) * (numIntegers + 1));

	/* Set element 1 to some arbitrary number.        */
	integerArray[numIntegers] = 500;
	numIntegers++;

	/* To add the next integer, we need to allocate   */
	/* more memory.                                   */
	integerArray = (int*)realloc(integerArray, sizeof(int) * (numIntegers + 1));

	/* Set element 2 to some arbitrary number.        */
	integerArray[numIntegers] = 1000;
	numIntegers++;

	/* Print out the integer array using elements.    */
	printf("Element:\n");
	for (int a = 0; a < numIntegers; a++) {
		printf("integerArray[%d] - %d\n", a, integerArray[a]);
	}
	printf("\n");

	/* Print out the integer array using pointers     */
	printf("Pointer Math:\n");
	for (int a = 0; a < numIntegers; a++) {
		printf("integerArray[%d] - %d\n", a, *(integerArray + a));
	}
	printf("\n");

	printf("Number of elements = %d\n", numIntegers);

	free(integerArray);
}
void StructArrayExample(void) {
	printf("/**************************************************/\n");
	printf("/*              Dynamic Struct Array              */\n");
	printf("/**************************************************/\n");

	typedef struct data_t {
		char s1[50];
		int i1;
		int i2;
		int i3;
	};

	/* struct arrays are much like strings. It is a   */
	/* pointer of pointers to make an array.          */
	data_t** structArray = NULL;

	/* Since we are dynamically creating, we have to  */
	/* keep track of the elements.                    */
	int numStructs = 0;

	char word0[] = "Struct-1";
	char word1[] = "Struct-2";
	char word2[] = "Struct-3";

	/* Allocate the pointer to the struct.            */
	structArray = (data_t**)malloc(sizeof(data_t));

	/* Allocate memory for the first element for the  */
	/* struct and fill.                               */
	structArray[numStructs] = (data_t*)malloc(sizeof(data_t) * (numStructs + 1));
	strcpy_s(structArray[numStructs]->s1, 9, word0);
	structArray[numStructs]->i1 = 100;
	structArray[numStructs]->i2 = 200;
	structArray[numStructs]->i3 = 300;
	numStructs++;

	/* Allocate memory for the second element for the */
	/* struct and fill.                               */
	structArray[numStructs] = (data_t*)malloc(sizeof(data_t) * (numStructs + 1));
	strcpy_s(structArray[numStructs]->s1, 9, word1);
	structArray[numStructs]->i1 = 400;
	structArray[numStructs]->i2 = 500;
	structArray[numStructs]->i3 = 600;
	numStructs++;

	/* Allocate memory for the third element for the  */
	/* struct and fill.                               */
	structArray[numStructs] = (data_t*)malloc(sizeof(data_t) * (numStructs + 1));
	strcpy_s(structArray[numStructs]->s1, 9, word2);
	structArray[numStructs]->i1 = 700;
	structArray[numStructs]->i2 = 800;
	structArray[numStructs]->i3 = 900;
	numStructs++;

	printf("Elements:\n");
	for (int a = 0; a < numStructs; a++) {
		printf("structArray[%d]->s1 = %s\n", a, structArray[a]->s1);
		printf("structArray[%d]-i1 = %d\n", a, structArray[a]->i1);
		printf("structArray[%d]-i2 = %d\n", a, structArray[a]->i2);
		printf("structArray[%d]-i3 = %d\n", a, structArray[a]->i3);
		printf("\n");
	}

	printf("Number of elements = %d\n", numStructs);

	free(structArray);
}
void ClassArrayExample(void) {
	printf("/**************************************************/\n");
	printf("/*              Dynamic Class Array               */\n");
	printf("/**************************************************/\n");

	/* Define a class to use for this example.        */
	class dataClass {
	private:
		int i1;
		char s1[25];
	public:
		void m1(void) {
			printf("Class is %s. Varialble i1 is %d\n", s1, i1);
		}
		char* getS1(void) {
			return s1;
		}
		void setS1(char* s) {
			strcpy_s(s1, strlen(s) + 1, s);
		}
		int getI1(void) {
			return i1;
		}
		void setI1(int i) {
			i1 = i;
		}
	};

	/* Classes are pointers to an area in memory. We  */
	/* will need to use a pointe to a pointer.        */
	dataClass** classArray;

	/* Define an instance counter.                    */
	int numClasses = 0;

	char word0[] = "Class-1";
	char word1[] = "Class-2";
	char word2[] = "Class-3";

	/* Create the inital pointer to the array.        */
	classArray = (dataClass**)malloc(sizeof(dataClass));

	/* Create an element for the class array.         */
	classArray[numClasses] = (dataClass*)malloc(sizeof(dataClass) * (numClasses + 1));
	classArray[numClasses]->setS1(word0);
	classArray[numClasses]->setI1(100);
	//classArray[numClasses]->m1();
	numClasses++;

	/* Create an element for the class array.         */
	classArray[numClasses] = (dataClass*)malloc(sizeof(dataClass) * (numClasses + 1));
	classArray[numClasses]->setS1(word1);
	classArray[numClasses]->setI1(200);
	//classArray[numClasses]->m1();
	numClasses++;

	/* Create an element for the class array.         */
	classArray[numClasses] = (dataClass*)malloc(sizeof(dataClass) * (numClasses + 1));
	classArray[numClasses]->setS1(word2);
	classArray[numClasses]->setI1(300);
	//classArray[numClasses]->m1();
	numClasses++;

	for (int a = 0; a < numClasses; a++) {
		classArray[a]->m1();
	}
	printf("\n");

	/* Print out the number of classes created.       */
	printf("Number of elements %d\n", numClasses);

	/* Important to free the memory. */
	free(classArray);

	/* address of op stuff */
}

void addressOfOp(void) {
	int a = 0;
	printf("A before change %d\n", a);
	addressOfChange(a);
	printf("A ofter change %d\n",a);
	printf("---- Address and Pointer ....\n");
	addressToPointerChange(&a);
	printf("a after pointer change %d\n", a);
}

void addressOfChange(int& p) {
	printf("p in %d\n",p);
	p = 2;
	printf("p out %d\n", p);
	return;
}

void addressToPointerChange(int* p) {
	printf("pointer before %d\n", *p);
	*p = 4;
	printf("pointer after %d\n", *p);
}