void setup()
{
  int N=100;
  Estudiante[] lista=new Estudiante[N];
  
  for(int i=0;i<N;i++)
  {
    lista[i]=new Estudiante();
  }
  
  print_estudiantes(lista);
  println();
  
  int id=1201;

  //Búsqueda del ID con búsqueda binaria
  Estudiante e1;
  e1=busqueda_binaria(lista,id);
  println();
  println("---Búsqueda binaria---");
  println("Estudiante con el id:",id);
  if(e1 == null)
  {
    println("No se encontró el registro");
  }
  else
  {
    print(e1);
  }
  
  
  //Ordenamiento quicksort visualización
   /*println();
   print_estudiantes(lista);*/
}


Estudiante busqueda_binaria(Estudiante[] lista,int id)
{
  //Ordenamiento
    quicksort(lista,0,lista.length-1);
  //Busqueda binaria
  int i=0,d=lista.length-1,m=0;
  while(i<=d)
  {
    m=(int)(i+d)/2;
    if(lista[m].ID==id)
    {
      return lista[m];
    }
    else if(lista[m].ID>id)
    {
      d=m-1;
    }
    else if(lista[m].ID<id)
    {
      i=m+1;
    }
  }
  return null;
  
}



//Método Quicksort
void quicksort(Estudiante[] arr,int inicio,int fin)
{
  int p = inicio;
  int i = inicio+1;
  int d = fin;
  do
  {
    while((arr[i].ID<=arr[p].ID)&&(i<d))
    {
      i++;
    }
    while(arr[d].ID>arr[p].ID)
    {
      d--;
    }
    if(i<d)
    {
      swap(arr,i,d);
    }
  }while(i<d);
  
  swap(arr,p,d);
  
  if(inicio<d-1)
  {
    quicksort(arr,inicio,d-1);
  }
  if(d+1<fin)
  {
    quicksort(arr,d+1,fin);
  }
}




//Métodos de rutina
void swap(Estudiante[] arr,int i,int j)
{
  Estudiante cebo=arr[i];
  arr[i]=arr[j];
  arr[j]=cebo;
}

void print_estudiantes(Estudiante[] lista)
{
  for(int i=0;i<lista.length;i++)
  {
    print(lista[i]);
  }
}
