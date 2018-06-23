/*=======================================================================
=================       WHERE IS MEMORY     =============================
=========================================================================
    USE: $ C99 CodeStackAndHeap.c && reset && ./a.out                  */
#include <stdio.h>                                                  //We will need this
#include <stdlib.h>                                                 //We will need this        

int main(int argc, char *argv[]) {									//Fucking main
	int LocalVariable;												//A var in stack
	printf("Location of Code:  %p\n", (void *) main);				//Show direction for code
	printf("Location of Heap:  %p\n", (void *) malloc(1));			//Show direction for heap
	printf("Location of Stack: %p\n", (void *) &LocalVariable);		//Show direction for stack
	
	return 0;														//Go little program
}
