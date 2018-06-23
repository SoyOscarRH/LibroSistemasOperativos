/*=======================================================================
=================       PIPE SYSTEM CALL    =============================
=========================================================================
    USE: $ C99 Pipe.c && reset && ./a.out
*/

#include <stdio.h>                                                  //We will need this
#include <stdlib.h>                                                 //We will need this  
#include <unistd.h>                                                 //We will need this  
#include <string.h>                                                 //We will need this  
#include "SuperSimpleErrorHandling.c"                               //My simple code :p


// ==========================================
// ======      MAIN FUNCTION       ==========
// ==========================================
int main(void) {                                                    //This is fucking main

    int PipesID[2];
    char Buffer[100];

    if (pipe(PipesID) != 0) return ShowError("Error at Pipe", 1);   //Go an show it

    if (fork() == 0) {                                              // == CHILDREN WORK ==
            while (1) {                                             //Do it forever
            read(PipesID[0], Buffer, sizeof(Buffer));               //Read the buffers
            printf("I have seen: %s\n", Buffer);                    //Show me
        }
    }
    else {                                                          // == PARENT WORK ==
        while(1) {                                                  //Do it forever
            gets(Buffer);                                           //Get me the buffer
            write(PipesID[1], Buffer, strlen(Buffer)+1);            //Write in the pipe
        }
    }

    return 0;
}
