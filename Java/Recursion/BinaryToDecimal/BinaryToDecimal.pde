void setup()
{
  int binario=1010;
  int i=0;
  int suma=0;
  System.out.printf("%d a decimal es igual a %d",binario,decimal(binario,suma,i));
}

int decimal(int binario,int suma,int i)
{
  if(binario==0)
  {
    return suma;
  }
  else
  {
    suma=suma+((binario%10)*((int)Math.pow(2,i)));
    return decimal(binario/10,suma,i+=1);
  }
}
