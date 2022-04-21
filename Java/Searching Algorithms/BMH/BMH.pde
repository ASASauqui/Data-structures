void setup()
{
  String texto="ccaabcaabxaacaabcaabcaabcabdaa";
  String patron="caabcaabca";
  
  texto=texto.toLowerCase();
  patron=patron.toLowerCase();

  println("Busqueda BMH: ",busqueda_bmh(texto,patron));
}


void preBMH(char palabra[], int saltos[])
{
  for(int i=0;i<=255;i++)
  {
    saltos[i]=palabra.length;
  }
  
  for(int i=0;i<palabra.length-1;i++)
  {
    saltos[palabra[i]]=palabra.length - 1 - i;
    //println(saltos[palabra[i]]);
  }
}


ArrayList<Integer> busqueda_bmh(String texto, String patron)
{
   ArrayList<Integer> lista = new ArrayList<Integer>();
   char patronC[]=patron.toCharArray();
   int saltos[]=new int[256];
   int contador=0;
   preBMH(patronC,saltos);
   
   /*for(int i=0;i<saltos.length;i++)
   {
     println(i,saltos[i]);
   }*/
   
   //Búsqueda del patrón
   
   for(int i=0;i<texto.length();i++)
   {
     contador=0;
     if( i <= texto.length()-patronC.length )
     {
       for(int j=0;j<patronC.length;j++)
       {
         if( texto.charAt(i+j) != patronC[j] )
         {
           //println(texto.charAt(i+patronC.length-1));
           i = i + saltos[texto.charAt(i+patronC.length-1)]-1;
           break;
         }
         contador++;
       }
     }
     if( contador == patronC.length )
     {
       lista.add(i);
       break; //Quitar para más ocurrencias
     }
   }
   return lista;
}
