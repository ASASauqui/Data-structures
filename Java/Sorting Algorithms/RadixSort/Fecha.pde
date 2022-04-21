class Fecha
{
  int dia, mes, anio;
  Fecha()
  {
    this.anio=(int)random(1950,2020+1);
    this.mes=(int)random(1,12+1);
    this.dia=(int)random(1,diaXmes(this.mes)+1);
  }
  
  private int diaXmes(int m)
  {
    if( m==1 || m==3 || m==5 || m==7 || m==10 | m==12 ) return 31;
    else if( m==4 || m==6 || m==9 || m==11 ) return 30;
    else if( m==2 ) return 28;
    else return 0;
  }
  
  public String toString()
  {
    return dia +"/" + mes2string(mes) + "/" +anio + "\n";
  }
  
  private String mes2string(int m)
  {
    if(m==1) return "Ene";
    else if(m==2) return "Feb";
    else if(m==3) return "Mar";
    else if(m==4) return "Abr";
    else if(m==5) return "May";
    else if(m==6) return "Jun";
    else if(m==7) return "Jul";
    else if(m==8) return "Ago";
    else if(m==9) return "Sep";
    else if(m==10) return "Oct";
    else if(m==11) return "Nov";
    else if(m==12) return "Dic";
    else return "ERROR";
  }
  
  public int parte(int s)
  {
    if(s==1) return dia%10; //Unidad del día
    else if(s==2) return dia/10; //Decena del día
    else if(s==3) return mes%10; //Unidad del mes
    else if(s==4) return mes/10; //Decena del mes
    else if(s==5) return anio%10;//Unidad del año
    else if(s==6) return (anio/10)%10; //Decena del año
    else if(s==7) return (anio/100)%10; //Centena del año
    else if(s==8) return anio/1000; //Milla del año
    else return 0;
  }
}
