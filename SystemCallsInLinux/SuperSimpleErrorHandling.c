/*=======================================================================
=================      SUPER SIMPLE ERROR HANDLING   ====================
=========================================================================
    USE: Just to not write to much
*/


// ==========================================
// ======     AN SIMPLE ERROR      ==========
// ==========================================
int ShowError (char* Message, int ErrorID) {                        //Wrap what happens at an error
    fprintf(stdout, "Error %i: %s", ErrorID, Message);              //Show it by screen
    return ErrorID;                                                 //Return the Error
}
