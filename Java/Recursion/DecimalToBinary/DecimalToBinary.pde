import java.util.Arrays;

void setup()
{
  int n=980;
  int arr[]=new int[20];
  int i=0;
  
  binario(n,arr,i);
  
  for(int j=arr.length-1;j>=0;j--)
  {
    if((arr[j]==1)&&(i==0))
    {
      i=1;
      System.out.printf("%d",arr[j]);
    }
    else if(i==1)
    {
      System.out.printf("%d",arr[j]);
    }
  }
}

void binario(int n,int arr[],int i)
{
  if(n==0)
  {
    return;
  }
  else
  {
    arr[i]=n%2;
    binario(n/2,arr,i+=1);
  }
}
