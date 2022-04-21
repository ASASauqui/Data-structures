void setup()
{
  //int arr[]={3,8,2,3,7,6,5,0,1,4};
  int n=20;
  int arr[]=new int[n];
  
  for(int i=0;i<n;i++)
  {
    arr[i]=(int)random(0,100);
  }
  
  print_array(arr);
  mergesort(arr);
  println();
  print_array(arr);
  
}

void mergesort(int[] arr) //Merge Sort original
{
  int[] arr1 = new int[arr.length];
  mergesortR(arr,arr1,0,arr.length-1);
}
void mergesortR(int[] arr,int[] arr1,int inicio,int fin) //Método recursivo
{
  if(inicio<fin)
  {
    int medio=inicio+(fin-inicio)/2;
    /*println();
    println(medio); //Testeo del punto medio
    println();*/
    mergesortR(arr,arr1,inicio,medio);
    mergesortR(arr,arr1,medio+1,fin);
    ijk(arr,arr1,inicio,medio+1,fin);
    //print_array(arr); //Testeo general
  }
}

void ijk(int[] arr,int[] arr1,int izquierda,int derecha,int topeSecundario) //Método i, j, k
{
  //Variables auxiliares
  int topePrimario=derecha-1;
  int k=izquierda;
  int cebo=izquierda;
  
  while( (izquierda<=topePrimario)  &&  (derecha<=topeSecundario)  ) // i, j, k
  {
    if( arr[izquierda]<arr[derecha]   )
    {
      arr1[k]=arr[izquierda];
      izquierda++;
    }
    else
    {
      arr1[k]=arr[derecha];
      derecha++;
    }
    k++;
  }
  //Whiles para rellenar cuando a una parte le "sobraron" valores
    while(izquierda<=topePrimario) //Sobraron en la izquierda
    {
      arr1[k]=arr[izquierda];
      k++; izquierda++;
    }
    while(derecha<=topeSecundario) //Sobraron en la derecha
    {
      arr1[k]=arr[derecha];
      k++; derecha++;
    }
  //Copia al arreglo original de los movimientos realizados
    for(int i=cebo;i<=topeSecundario;i++)
    {
      arr[i]=arr1[i];
      //print(arr1[i]+", "); Testeo de cambios graduales
    }
  //println();
}


void print_array(int[] arr)
{
  for(int i=0;i<arr.length;i++)
  {
    if(i<arr.length-1)
    {
      print(arr[i]);
      print(", ");
    }
    else
    {
      print(arr[i]);
    }
  }
  println();
}
