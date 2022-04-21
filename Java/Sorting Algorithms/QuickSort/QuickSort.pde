void setup()
{
  int[] arr=new int[20];
  //Ordenamiento
  for(int i=0;i<arr.length;i++)
  {
    arr[i]=(int)random(0,100);
  }
  //Lamadas
  print_array(arr);
  quicksort(arr);
  print_array(arr);
}

//Método principal
void quicksort(int[] arr)
{
  quicksortR(arr,0,arr.length-1);
}

//Método complementario
void quicksortR(int[] arr,int inicio,int fin)
{
  if(inicio>=fin)
  {
    return;
  }
  if(fin-inicio==1)
  {
    if(arr[inicio]>arr[fin])
    {
      swap(arr,inicio,fin);
    }
    return;
  }
  int p = arr[inicio];
  int i = inicio;
  int d = fin;
  
  do
  {
    while((arr[i]<=p)&&(i<d))
    {
      i++;
    }
    while(arr[d]>p)
    {
      d--;
    }
    if(i<d)
    {
      swap(arr,i,d);
    }
    //print_array(arr);
  }while(i<d);
  
  arr[inicio]=arr[d];
  arr[d]=p;
  if(inicio<d-1)
  {
    quicksortR(arr,inicio,d-1);
  }
  if(d+1<fin)
  {
    quicksortR(arr,d+1,fin);
  }
  
}


//Métodos de rutina
void swap(int[] arr,int i,int j)
{
  int cebo=arr[i];
  arr[i]=arr[j];
  arr[j]=cebo;
}

void print_array(int[] arr)
{
  print("[");
  for (int i=0; i<arr.length; i++) 
  {
    if(i<arr.length-1)
    {
      print(arr[i]);print(",");
    }
    else
    {
      print(arr[i]);
    }
  }
  print("]");
  println();
  
}
