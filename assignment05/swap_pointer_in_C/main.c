
int swap_pointer(int **Arg1, int **Arg2)
{
    //Swap the pointers that are being pointed to
    int *TmpPtr;
    TmpPtr = *Arg1;
    *Arg1 = *Arg2;
    *Arg2  = TmpPtr;
    return 0;
}

int main()
{
    int Value1 = 1024;
    int Value2 = 2048;
    
    int *Ptr1 = &Value1;
    int *Ptr2 = &Value2;
    
    int **PtrPtr1 = &Ptr1;
    int **PtrPtr2 = &Ptr2;
    
    int Value1_Start = **PtrPtr1;
    int Value2_Start = **PtrPtr2;
    
    
    swap_pointer(PtrPtr1, PtrPtr2);
    
    int Value1_End = **PtrPtr1;
    int Value2_End = **PtrPtr2;
    return 0;
}
