/*=======================================================================
=================       FORK SYSTEM CALL    =============================
=========================================================================
    USE: $ C99 Fork.c && reset && ./a.out
*/

#include <stdio.h>                                                  //We will need this
#include <stdlib.h>                                                 //We will need this        
#include <unistd.h>                                                 //We will need this        
#include "SuperSimpleErrorHandling.c"                               //My simple code :p


// ==========================================
// ======      MAIN FUNCTION       ==========
// ==========================================
int main(int argc, char *argv[]) {                                  //This is fucking main
    printf("Hello World \t\t(PID %i)\n", getpid());                 //Show me your ID
    
    int ChildID = fork();                                           //Now create a new process
    if (ChildID < 0) return ShowError("Error at Fork", 1);          //Go an show it

    if (ChildID == 0)                                               //YOU ARE THE CHILD?
        printf("I am Child \t\t(PID %i)\n", getpid());              //Show me your ID then kid
    else                                                            //YOU ARE THE PARENT
        printf("I'm Parent of %d \t(PID %i)\n", ChildID, getpid()); //Show me your ID then old man

    return 0;
}
