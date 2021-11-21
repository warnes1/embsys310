int counter = 0x0;

int main()
{
  int *P_int = (int *)0x20000000;
  ++(*P_int);
  ++(*P_int);
  ++(*P_int);
  counter ++;
  return 0;
}
