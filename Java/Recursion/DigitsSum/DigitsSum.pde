void setup()
{
  int n=786;
  int add=0;
  System.out.printf("La suma de los dígitos de %d es igual a %d",n,suma(n,add));
}

int suma(int n,int add)
{
  if(n<=0)
  {
    return add;
  }
  else
  {
    add=(n%10)+add;
    return suma(n/10,add);
  }
}
