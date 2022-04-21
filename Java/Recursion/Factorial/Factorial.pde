void setup()
{
  int n=12;
  System.out.printf("El factorial de %d es igual a %d",n,factorial(n));
}

int factorial(int n)
{
  if(n==0)
  {
    return 1;
  }
  else if(n==1)
  {
    return 1;
  }
  else
  {
    return n*(factorial(n-1));
  }
}
