
//=====================================================================
//
// Class:      embsys310, Fall 2021
// Assignment: assignment04
//
// Student:    Marion 'Scott' Warner
//
// Problem:    4. Bonus: Using the power of pointers and type casting,
//                create a function that can determine if a computer
//                is big-endian -or- little-endian
//                
//                Test your function in the simulator by modifying
//                the Project Options to:
//                   a. Cortex M4 (Little Endian option)
//                   b. Cortex M4 (Big Endian option)
//=====================================================================


// Use pointers and type cast to determine if machine is
// Little Endian -or- Big Endian


char *which_endian(void)
{
    static char *BigEndian = "Big Endian";
    static char *LittleEndian = "Little Endian";
    static unsigned long stuff = 0xFFFF0000;
    static unsigned short instuff = 0xAAAA;
    
    instuff = *((unsigned short *)&stuff);
    if( instuff == 0xFFFF) {
        return BigEndian;
    }
    if( instuff == 0x0000){
        return LittleEndian;
    }
}

int main()
{
    char *TypeEndian;
    
    TypeEndian = which_endian();
    return 0;
}
