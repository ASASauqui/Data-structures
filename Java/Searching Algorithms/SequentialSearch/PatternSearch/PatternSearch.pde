void setup()
{
  String texto="ccaabcaabxaacaabcaabcaabcabdaa";
  //String texto="ccaabcaabxaacaabcaabcaabcabdaaccaabcaabxaacaabcaabcaabcabdaaccaabcaabxaacaabcaabcaabcabdaa";
  String patron="caabcaabca";
  
  texto=texto.toLowerCase();
  patron=patron.toLowerCase();
  println("Búsqueda secuencial: ", busqueda_secuencial(texto,patron));
  
}

ArrayList<Integer> busqueda_secuencial(String texto, String patron)
{
  ArrayList<Integer> lista = new ArrayList<Integer>();
  int contador=0;
  
  for(int i=0;i<texto.length();i++)
  {
    contador=0;
    for(int j=0;j<patron.length();j++)
    {
      if( (i+j<texto.length())  &&  (texto.charAt(i+j)   ==   patron.charAt(j)) )
      {
        contador++;
      }
      else
      {
        break;
      }
    }
    if( contador == patron.length() )
    {
      lista.add(i);
    }
  }
  
  return lista;
}
