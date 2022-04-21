void setup()
{
  int n=5;
  int m=1;
  funcion(n,m);
}

void funcion(int n,int m)
{
  if(n+1==m)
  {
    return;
  }
  println(m);
  funcion(n,m+1);
}
