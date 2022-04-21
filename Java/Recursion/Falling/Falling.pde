void setup()
{
  int n=5;
  funcion(n);
}

void funcion(int n)
{
  if(n==0)
  {
    return;
  }
  println(n);
  funcion(n-1);
}
