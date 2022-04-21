void setup()
{
  int n=5568;
  invertir(n);
}

void invertir(int n)
{
  if(n<=0)
  {
    return;
  }
  else
  {
    System.out.printf("%d",n%10);
    invertir(n/10);
  }
}
