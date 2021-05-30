#include <stdio.h>

int main()
{
int Ndia;
printf("Edward Brito Diaz\n");
printf("\n2019-0823\n");
printf("\n*Muestra el dia de la semana segun el numero*\n");
printf("Introduzca un numero: ");
scanf("%d",&Ndia);
if (Ndia == 1){
	 printf("Es Lunes");
	}
else if (Ndia == 2){
 printf("Es Martes");
}	
else if (Ndia == 3){
	 printf("Es Miercoles");
}
else if (Ndia == 4){
	printf("Es Jueves");
}
else if (Ndia == 5){
 printf("Es Viernes");
}
else if (Ndia == 6){
printf("Es Sabado");
}	
else if (Ndia == 7){	 
printf("Es Domingo");
}	
else{
printf("El dia no existe");
} 
}

