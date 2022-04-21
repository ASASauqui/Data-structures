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
  
  //Búsqueda del ID con búsqueda secuencial
  int id=1201;
  Estudiante e;
  e=busqueda_secuencial(lista,id);
  println("---Búsqueda secuencial---");
  println("Estudiante con el id:",id);
  if(e == null)
  {
    println("No se encontró el registro");
  }
  else
  {
    println(e);
  }
}




Estudiante busqueda_secuencial(Estudiante[] lista,int id)
{
  for(int i=0;i<lista.length;i++)
  {
     if( lista[i].ID == id )
     {
         return lista[i];
     }
  }
  return null;
}


void print_estudiantes(Estudiante[] lista)
{
  for(int i=0;i<lista.length;i++)
  {
    print(lista[i]);
  }
}
