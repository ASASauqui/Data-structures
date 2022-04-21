void setup()
{
  int n=10;
  int par=2;
  System.out.printf("La suma de los números naturales antecesores pares de %d es igual a %d",n,sucesion(n,par));
}

int sucesion(int n,int par)
{
  if(par==n)
  {
    return par;
  }
  else if(par+1==n)
  {
    return par;
  }
  else
  {
    return par+sucesion(n,par+=2);
  }
}
