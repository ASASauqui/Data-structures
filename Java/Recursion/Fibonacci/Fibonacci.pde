void setup()
{
  //int n=(int)(Math.random()*15);
  int n=17;
  System.out.printf("La posición %d en la serie Fibonacci es igual a %d",n,fibonacci(n));
}

int fibonacci(int n)
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
    return fibonacci(n-1)+fibonacci(n-2);
  }
}
