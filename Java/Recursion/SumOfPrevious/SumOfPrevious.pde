void setup()
{
  int n=10;
  System.out.printf("La suma de los antecesores de %d es igual a %d",n,sucesion(n));
}

int sucesion(int n)
{
  if(n==0)
  {
    return 0;
  }
  else if(n==1)
  {
    return 1;
  }
  else
  {
    return n+sucesion(n-1);
  }
}
