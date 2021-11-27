

int main(void)
{
    char Char1 = 'A';
    char Char2 = 'Z';
    
    char *Char1_ptr = &Char1;
    char *Char2_ptr = &Char2;
    
    char Char1_Start = *Char1_ptr;
    char Char2_Start = *Char2_ptr;
    
    swapCharsAsm(Char1_ptr,Char2_ptr);
    
    char Char1_End = *Char1_ptr;
    char Char2_End = *Char2_ptr;
    return 0;
}

