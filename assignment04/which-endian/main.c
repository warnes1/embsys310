


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