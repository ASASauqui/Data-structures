void setup()
{
  int n=15;
  int m=2;
  
  System.out.printf("La division de %d/%d es igual a %d",n,m,division(n,m));
}

int division(int n,int m)
{
  if(m>n)
  {
    return 0;
  }
  else
  {
    return 1+division(n-m,m);
  }
}
