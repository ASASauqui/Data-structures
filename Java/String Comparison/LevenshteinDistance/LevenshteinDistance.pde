void setup() {
  String s1 = "escuela";
  String s2 = "estudiante";
  
  s1 = s1.toLowerCase();
  s2 = s2.toLowerCase();

  println("Cadena 1:", s1);
  println("Cadena 2:", s2); println();
  println("Distancia Levenshtein",distancia_levenshtein(s1,s2));
}

int distancia_levenshtein(String s1,String s2)
{
  // Codificar
  
  /*if( s2.length() > s1.length() )  //Prueba a la inversa
  {
    String aux=s1;
    s1=s2;
    s2=aux;
  }*/
  
  int arr[][] = new int[s1.length()+1][s2.length()+1];
  
  //Rellenado principal (laterales)
    for(int i=0;i<=s1.length();i++)  //Rellenado de números base verticales
    {
      arr[i][0]=i;
    }
    for(int j=0;j<=s2.length();j++)  //Rellenado de números base horizontales
    {
      arr[0][j]=j;
    }
  
  //Cálculo
    println("---------------------------------------");
    for(int i=1;i<=s1.length();i++)
    {
      for(int j=1;j<=s2.length();j++)
      {
        arr[i][j]=minimo(  arr[i-1][j]+1, arr[i][j-1]+1,  (arr[i-1][j-1] + diagonal(s1.toCharArray(),s2.toCharArray(),i-1,j-1))  );
        print(arr[i][j]+" ");
      }
      println();
    }
    println("---------------------------------------");
    
  return arr[s1.length()][s2.length()];
}

int minimo(int a,int b, int c)
{
  return Math.min(a,Math.min(b,c));
}

int diagonal(char s1[],char s2[],int i,int j)
{
  if(s1[i]==s2[j])
  {
    return 0;
  }
  return 1;
}
