int capacidad=4;
int nobjetos=4;
int[] ganancia={1,4,2,5};
int[] peso={4,3,2,1};
int[] mochila=new int[nobjetos];
int[] mochila_optima=new int[nobjetos];

void setup()
{
  for(int i=0;i<nobjetos;i++)
  {
    mochila[i]= -1;
    mochila_optima[i]=-1;
  }
  backtracking(0);
  
  println("Solución:");
  print_mochila(mochila_optima);
}

int ganancia(int[] mochila)
{
  int g=0;
  for(int i=0;i<nobjetos;i++)
  {
    if(mochila[i]==1)
    {
      g+=ganancia[i];
    }
  }
  return g;
}


int peso(int[] mochila)
{
  int p=0;
  for(int i=0;i<nobjetos;i++)
  {
    if(mochila[i]==1)
    {
      p+=peso[i];
    }
  }
  return p;
}





void backtracking(int v)
{
  //print_array();
  if((peso(mochila)>capacidad))
  {
    return;
  }
  if(v>=mochila.length)
  {
    print_mochila(mochila); //Solución completa
    if(ganancia(mochila)>ganancia(mochila_optima))
    {
      for(int i=0;i<nobjetos;i++)
      {
        mochila_optima[i]=mochila[i];
      }
    }
    return;
  }
  else
  {
    for(int i=0;i<2;i++)
    {
      mochila[v]=i;
      backtracking(v+1);
    }
    mochila[v]=-1;
  }
  //sol[v]=-1;
}

void print_mochila(int[] mochila)
{
  print("[");
  for(int i=0;i<mochila.length;i++)
  {
    print(mochila[i]);
    print(",");
  }
  print("] ");
  print("peso: ");
  print(peso(mochila));
  print(" ganancia: ");
  print(ganancia(mochila));
  println();
}
