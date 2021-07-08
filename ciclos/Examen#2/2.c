#include <stdio.h>
struct clientes{
  char nombre[50];
  char apellido[50]; int telefono;
  char direccion[50]; int cedula;
  char estado[50]; }; //mis estructuras
int main(){
  int opcion;
  printf("ELiga una opcion:");
  printf("1\n Mostrar 2\nSalir "); scanf("%d",&opcion);
  if(opcion==1){
   struct clientes clientes1={"Edward","Brito",8498564014, "La Vega",93938261819,"Soltero"};
    puts(clientes1.nombre);
    puts(clientes1.apellido);
    printf("\Telefono: %d\n",clientes1.telefono); puts(clientes1.direccion);
    printf("\Cedula: %d\n",clientes1.cedula); puts(clientes1.estado);
  }
else{
  printf("Salir"); }
}
