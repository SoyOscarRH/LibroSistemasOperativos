/*=======================================================================
=================       EXEC SYSTEM CALL    =============================
=========================================================================
    USE: $ C99 Exec.c && reset && ./a.out
*/

#include <stdio.h>                                                  //We will need this
#include <stdlib.h>                                                 //We will need this        
#include <sys/wait.h>                                               //We will need this  
#include <unistd.h>                                                 //We will need this        
#include <string.h>                                                 //We will need this        
#include "SuperSimpleErrorHandling.c"                               //My simple code :p

int main(int argc, char *argv[]) {                                  //Fucking main
    printf("Hello World \t\t\t(PID %i)\n", getpid());               //Show me your ID

    int ChildID = fork();                                           //Now create a new process
    if (ChildID < 0) ShowErrorAndGo("Error at Fork", 1);            //Go an show it

    if (ChildID == 0) {                                             // === YOU ARE THE CHILD =====
        printf("I am Child \t\t\t(PID %i)\n", getpid());            //Show me your ID then kid

        char *Arguments[3];                                         //Create an array of strings :D
        Arguments[0] = strdup("wc");                                //New program: "wc" (word count)
        Arguments[1] = strdup("Exec.c");                            //Argument to wc: file to count
        Arguments[2] = NULL;                                        //End of array
        execvp(Arguments[0], Arguments);                            //Run word count & 'exit' process
        
        printf("This shouldn't print out ever :o");                 //Now all this code stop existing
    }
    else {                                                          // ==== YOU ARE THE PARENT ====
        int WCID = wait(NULL);                                      //This return the pid of the child
        printf("I'm Parent of %i aka wc-%i", ChildID, WCID);        //Show me your ID then old man
        printf("\t(PID %i)\n", getpid());                           //Show me your ID then old man
    }
    return 0;
}
