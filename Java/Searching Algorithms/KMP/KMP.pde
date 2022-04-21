void setup()
{
  String texto="ccaabcaabxaacaabcaabcaabcabdaa";
  //String texto="ccaabcaabxaacaabcaabcaabcabdaaccaabcaabxaacaabcaabcaabcabdaaccaabcaabxaacaabcaabcaabcabdaa";
  String patron="caabcaabca";
  
  texto=texto.toLowerCase();
  patron=patron.toLowerCase();
  println("Búsqueda KMP: ", busqueda_kmp(texto,patron));
  
}

ArrayList<Integer> busqueda_kmp(String texto, String patron)
{
   ArrayList<Integer> lista = new ArrayList<Integer>();
   
   int estado=0;
   int[] regreso=new int[patron.length()];
   
   //Paso 1-. Patrón
   regreso[0]= -1;
   for(int i=1;i<patron.length();i++)
   {
     estado = regreso[i-1]+1;
     while( patron.charAt(i) != patron.charAt(estado) )
     {
       if(estado == 0)
       {
         estado = -1;
         break;
       }
       
       estado = regreso[estado-1]+1;
     }
     
     regreso[i]=estado;
   }
   
   /*for(int i=0;i<patron.length();i++)
   {
     println(i,patron.charAt(i),regreso[i]);
   }*/
   
   //Paso 2-. Texto
   estado=-1;
   int in=0;
   for(int i=0;i<texto.length();i++)
   {
     //println(i,estado, texto.charAt(i));
     if(estado == -1)
     {
       in=i;
     }
     estado++;
     while( texto.charAt(i) != patron.charAt(estado) )
     {
       if(estado == 0)
       {
         estado = -1;
         break;
       }
       
       estado = regreso[estado-1]+1;
     }
     if( estado == patron.length()-1 )
     {
       lista.add(in);
       /*i=in;
       estado=-1;*/ // Quitar para ver todas las ocurrencias
       break;
     }
   }
   return lista;
}
