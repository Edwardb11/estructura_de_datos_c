//PARA REALIZAR CON: STRUCT 
//7. Defina una estructura para guardar información sobre clientes de un banco.
//Incluya miembros para el nombre, dirección, teléfono, número de cuenta,
//tipo de cuenta y saldo de la cuenta.
#include <stdio.h>
#include <string.h>
struct clientes{
	char nombre[50];
	char direccion[50];
	int telefono;
	int numero_cuenta;
	char tipo_cuenta[50] ;
	int saldo_cuenta;
	
}clientes1; //mis estructuras 
int main(){
	//printf("--Datos personales del cliente-- ");
	printf("\nNombre: ");
	gets(clientes1.nombre);
	fflush(stdin);
	
	printf("Direccion: ");
	gets(clientes1.direccion);
	fflush(stdin);

	printf("Telefono: ");
	scanf("%d",&clientes1.telefono);
	
	printf("Numero de cuenta: ");
	scanf("%d",&clientes1.numero_cuenta);
	fflush(stdin);
	
	printf("Tipo de cuenta: ");
	gets(clientes1.tipo_cuenta);
	fflush(stdin);
	
	printf("Saldo: ");
	scanf("%d",&clientes1.saldo_cuenta);

	
		printf("\n________________________\n");
	
	printf("Nombre: %s\n",clientes1.nombre);
	printf("Direccion: %s\n",clientes1.direccion);
	printf("Telefono: %i\n",clientes1.telefono);
	printf("Numero de la cuenta: %i\n",clientes1.numero_cuenta);
	printf("Tipo de cuenta: %s\n",clientes1.tipo_cuenta);
	printf("Saldo: %i\n",clientes1.saldo_cuenta);
		printf("________________________\n");

}

