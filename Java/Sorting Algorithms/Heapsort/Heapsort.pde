void setup()
{
  int N=20;
  int[] arr=new int[N];
  //int[] arr={9,2,5,1,3,7,6,4,8};
  for(int i=0;i<N;i++)
  {
    arr[i]=(int)random(0,100);
  }
  print_array(arr);
  heap_sort(arr);
  println();
  print_array(arr);
}



void heap_sort(int[] arr)
{
  //Inserción
  for(int i=0;i<arr.length;i++)
  {
    insercion(arr,i);
  }
  
  //Eliminación
  int longitud=arr.length-1;
  while(longitud>0)
  {//Cambia el último por el primero y va disminuyendo el campo de acción para dejar ese número bloqueado y "sacarlo" del arreglo
    eliminacion(arr,0,longitud);
    swap(arr,0,longitud);
    longitud--;
  }
  
}


//Va checando los valores del arreglo y verificando si es mayor o no que el padre para hacer el intercambio y dejar hecha la primera parte
void insercion(int arr[],int i)
{
  while(i>0)
  {
    int j=(i+1)/2;
    if(arr[j-1]<arr[i])
    {
      swap(arr,i,j-1);
      i=j-1;
    }
    else
    {
      break;
    }
  }
}


//Va checando si uno de los dos hijos es mayor que el padre y deja el arreglo acomodado después de todos los cambios
void eliminacion(int arr[],int i,int longitud)
{
  while(i<longitud)
  {
    int a1=(i+1)*2;
    int a2=(i+1)*2+1;
    if((a1-1>longitud)&&(a2-1>longitud))
    {
      break;
    }
    else if(a2-1>longitud)
    {
      if(arr[a1-1]>arr[i])
      {
        swap(arr,i,a1-1);
        i=a1-1;
      }
      else
      {
        break;
      }
    }
    else
    {
      int max[]=mayor(arr,a1,a2);
      if(max[0]>arr[i])
      {
        swap(arr,i,max[1]);
        i=max[1];
      }
      else
      {
        break;
      }
    }
  }
}


//Compara cúal de los dos valores es el mayor para que ese mismo sea comparado con el padre
int[] mayor(int arr[],int a1,int a2)
{
  int max[]=new int[2];
  if(arr[a1-1]>arr[a2-1])
  {
    max[0]=arr[a1-1];
    max[1]=a1-1;
  }
  else
  {
    max[0]=arr[a2-1];
    max[1]=a2-1;
  }
  return max;
}




void swap(int[] arr, int i,int j)
{
  int aux=arr[i];
  arr[i]=arr[j];
  arr[j]=aux;
}

void print_array(int[] arr)
{
  print("[");
  int N=arr.length;
  for(int i=0;i<N;i++)
  {
    if(i<N-1)
    {
      print(arr[i]);
      print(",");
    }
    else
    {
      print(arr[i]);
    }
  }
  println("]");
}
