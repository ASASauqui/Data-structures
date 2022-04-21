import java.util.Arrays;

void setup()
{
  int arr[]={2,5,6,1,10,45,122,3};
  /*for(int i=0;i<10;i++)
  {
    arr[i]=(int)Math.random()*100;
  }*/
  int m=0;
  funcion(arr,m);
}

void funcion(int arr[],int m)
{
  if(m>=arr.length)
  {
    return;
  }
  println(arr[m]);
    funcion(arr,m+1);
}
