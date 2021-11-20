
int func1(int thing1, int thing2, int thing3, int thing4, int thing5 )
{
    return thing1 + thing2 + thing3 + thing4 + thing5;
}

int func2(void)
{
    int total;
    total = func1( 1,34,5,67,2 );
}

int main(void)
{
    func2();
}
