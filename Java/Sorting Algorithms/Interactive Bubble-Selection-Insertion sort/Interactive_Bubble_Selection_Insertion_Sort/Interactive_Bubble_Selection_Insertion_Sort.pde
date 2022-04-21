import java.util.Random;
import java.awt.*;






//Variables controladoras
boolean bubble=true;
boolean seleccion=false;
boolean insercion=false;










//Variables algebraicas
int numNumeros=50;
int[] arr=new int[10000000];
int contador=-3;
int contador1=-1;
int numNumerosRest=1;
int relleno=-1;
int rac=0;
int cebo=0;
int cebo1=0;
int min=0;
int elegido=0;
Random rand=new Random(System.currentTimeMillis());
boolean repetido=false;

void setup()
{
  size(1600,800);
  background(0);
  //Rellenado de arreglo
  for(int i=0;i<numNumeros;i++)
  {
    arr[i]=(int)(Math.random()*(rand.nextInt(500)));
    //Filtro
    while(contador1!=0)
    {
      contador1=0;
      for(int j=0;j<numNumeros;j++)
      {
        if(j!=i)
        {
          if(arr[i]==arr[j])
          {
            arr[i]=(int)(Math.random()*(rand.nextInt(numNumeros+1)));
            contador1++;
            break;
          }
        }
      }
    }
    contador1=1;
    //System.out.printf("%d ",arr[i]);
  }
  
  
  
  rectangulos(arr,-1,false,-1);
  
}

void draw()
{
  background(0);
  if(contador<=numNumeros-1)
  {
    rectangulos(arr,-1,false,-1);
  }
  
  //Burbuja 
  if(bubble==true)
  {
    bubble_sort();
  }
  
  //Selección
  else if(seleccion==true)
  {
    selection_sort(); //<>//
  }
  
  //Insercion
  else if(insercion==true)
  {
    insertion_sort();
  }
  
  if((contador>=numNumeros-1)&&(relleno<numNumeros-1))
    {
      relleno++;
      fill(0,255,0);
      //rectangulos(arr,-1,false,-1);
      rect(rac,height-arr[relleno],(int)(width/numNumeros),arr[relleno]);
      rac+=width/numNumeros;
    }
   delay(0);
}




void bubble_sort()
{
  if(contador==-3)
    {
      contador=-1;
    }
    if(contador1!=0)
    {
      contador++;
      rectangulos(arr,contador,false,-1);
      if(contador<numNumeros-numNumerosRest)
      {
        if(contador==-1)
        {
          cebo1=0;
          contador1=0;
          repetido=false;
        }
        if(contador==numNumeros-2)
        {
          cebo1=contador1;
          contador1=0;
          repetido=false;
        }
        //println(contador1);
       if(arr[contador]>arr[contador+1])
       {
         rectangulos(arr,contador,true,-1);
         contador1++;
         repetido=true;
         cebo=arr[contador];
         arr[contador]=arr[contador+1];
         arr[contador+1]=cebo;
       }
       if((repetido==false)&&(cebo1>0)&&(contador<numNumeros-2))
       {
         contador1=1;
       }
       else if((repetido==false)&&(cebo1==1)&&(contador==numNumeros-2))
       {
         contador1=0;
       }
       else if((repetido==false)&&(cebo1>1)&&(contador==numNumeros-2))
       {
         contador1=1;
       }
      }
      else
      {
        contador=-1;
        numNumerosRest++;
      } 
    }
}

void selection_sort()
{
  if(contador==-3)
  {
    contador=-1;
  }
  if(contador<numNumeros-1)
  {
    contador++;
    min=arr[contador];
    for(int i=contador;i<numNumeros;i++)
    {
      if(arr[i]<min)
      {
        min=arr[i];
        elegido=i;
      }
    }
    if(arr[contador]!=min)
    {
      rectangulos(arr,contador,true,elegido);
      cebo=arr[contador];
      arr[contador]=min;
      arr[elegido]=cebo;
    }
    else
    {
      rectangulos(arr,contador,true,elegido);
    }
  }
}

void insertion_sort()
{
 if(contador==-3)
 {
   contador=0;
 }
 if(contador<numNumeros-1)
 {
   contador++; //Posición 2
   rectangulos(arr,-2,true,contador);
   cebo=arr[contador];
   for(int i=contador;i>0;i--)
   {
     if(arr[i-1]>cebo)
     {
       arr[i]=arr[i-1];
       arr[i-1]=cebo;
       min=i;
     }
   }
   
 } 
}





void rectangulos(int arr[],int localizacion,boolean mayor,int min)
{
  if(localizacion==-1)
  {
    for(int i=0,recX=0;i<numNumeros;i++,recX+=width/numNumeros)
    {
      fill(255);
      rect(recX,height-arr[i],(int)(width/numNumeros),arr[i]);
    }
  }
  else
  {
    for(int i=0,recX=0;i<numNumeros;i++,recX+=width/numNumeros)
    {
      fill(255);
      rect(recX,height-arr[i],(int)(width/numNumeros),arr[i]);
      
      if((localizacion==i)&&(mayor==true)&&(min==-1))
      {
      fill(255,0,0);
      rect((width/numNumeros)*localizacion,height-arr[localizacion],(int)(width/numNumeros),arr[localizacion]);
      fill(0,0,255);
      rect((width/numNumeros)*(localizacion+1),height-arr[localizacion+1],(int)(width/numNumeros),arr[localizacion+1]);
      i++;
      recX+=width/numNumeros;
      }
      else if((localizacion==i)&&(mayor==false)&&(min==-1))
      {
      fill(0,255,0);
      rect((width/numNumeros)*localizacion,height-arr[localizacion],(int)(width/numNumeros),arr[localizacion]);
      rect((width/numNumeros)*(localizacion+1),height-arr[localizacion+1],(int)(width/numNumeros),arr[localizacion+1]);
      i++;
      recX+=width/numNumeros;
      }
      else if((localizacion==i)&&(mayor==true)&&(min!=-1))
      {
      fill(255,0,0);
      rect((width/numNumeros)*localizacion,height-arr[localizacion],(int)(width/numNumeros),arr[localizacion]);
      }
      else if((min==i)&&(mayor==true)&&(min!=-1))
      {
      fill(0,0,255);
      rect((width/numNumeros)*(min),height-arr[min],(int)(width/numNumeros),arr[min]);
      }
      else if((localizacion==-2)&&(min==i)&&(mayor==true)&&(min!=-1))
      {
      fill(0,0,255);
      rect((width/numNumeros)*(min),height-arr[min],(int)(width/numNumeros),arr[min]);
      }
    }
  }
}

void mouseClicked()
{
  
}
