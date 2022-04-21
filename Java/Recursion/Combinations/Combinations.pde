void setup()
{
  String[] str1="a b c".split(" ");
  combinaciones(str1,"",str1.length,str1.length);
}

void combinaciones(String[] str1, String str2, int cebo, int cebo1) 
{
  if(cebo<=0)
  {
    System.out.println(str2);
  }
  else if(cebo>0)
  {
    for(int i=0;i<cebo1;i++)
    {
      if(str2.contains(str1[i]))
      {
        continue;
      }
      else
      {
        combinaciones(str1,str2+str1[i],cebo-1,cebo1);
      }
    }
  }
}
