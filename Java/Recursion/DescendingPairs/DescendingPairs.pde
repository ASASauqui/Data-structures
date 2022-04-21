void setup()
{
  int n=10;
  int m=2;
  pares(n,m);
}

void pares(int n,int m)
{
  if(m>=n+1)
  {
    return;
  }
  pares(n,m+2);
  println(m);
}
