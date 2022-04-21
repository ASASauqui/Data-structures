class Estudiante
{
  String nombre;
  String apellido;
  int ID;
  String carrera;
  
  Estudiante()
  {
    String[] nombres={"Juan","Ana","Pedro","Raul","Gabriel","Alan","Javier","Mariana","Adriana","Natalia","Adalberto","Danna","Octavio","Miroslava","Denisse"};
    String[] apellidos={"Lopez","Chavez","Martinez","Perez","Leon","Salazar","Hernandez","Davalos","Paz","Reyes","Lovato","Smith","Aguirre","Olmos","Ceballos"};
    String[] carreras={"IIA","IN","IBE"};
    
    nombre=nombres[(int)random(nombres.length)];
    apellido=apellidos[(int)random(apellidos.length)];
    carrera=carreras[(int)random(carreras.length)];
    //ID=(int) random(1000,2000);
    ID=(int) random(1000,2000);
  }
  
  public String toString()
  {
    return Integer.toString(ID)+" "+carrera+" "+nombre+" "+apellido+"\n";
  }
}
