#include <stdio.h>

int main()
{
	char name[20];
	float NhectareasF, operacion;
	int Nopcion;
printf("Edward Brito Diaz\n");
printf("2019-0823\n");
printf("\nNombre del agriucultor: ");
scanf("%s",name);
printf("Ingrese el numero de hectareas a furmigar: ");
scanf("%f",&NhectareasF);
printf("La campana cuenta con los siguientes servicios:\n ");
printf("1. Fumigacion contra las malas hierbas; $10 por hectareas.\n");
printf(" 2. Fumigacion contra langostas; $20 por hectareas.\n");
printf(" 3. Fumigacion contra gusanos; $30 por hectareas.\n");
printf(" 4. Fumigacion contra todo lo anterior; $50 por hectareas.\n");

printf("Elija una opcion del 1-4 : ");
scanf("%i",&Nopcion);
if (Nopcion==1){
	operacion=NhectareasF*10;
	printf("El senor %s debera cancelar %.2f",name,operacion);
}
else if (Nopcion==2){
	operacion=NhectareasF*20;
	printf("El senor %s debera cancelar %.2f",name,operacion);
}
else if (Nopcion==3){
	operacion=NhectareasF*30;
	printf("El senor %s debera cancelar %.2f",name,operacion);
}
else if (Nopcion==4){
	operacion=NhectareasF*50;
	printf("El senor %s debera cancelar %.2f",name,operacion);
}

else{
	printf("Fuera de rango");
}

}
