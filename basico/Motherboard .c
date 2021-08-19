//1) La empress ABC, dedicada a la producción de Motherboard, lo contrata a usted, 
//para que elabore un programa en Lenguaje C, que depediendo de la cantidad de
// Motherboar producido, se la pague un incentivo al empleado, dependiendo de lo
//siguiente:
//
//El precio que se paga por cada Motherboard es de 100 pesos, en caso de que la
//persona realice más de 3 Motheboard, entonces los 3 primeros se pagan y los
//demás a 125.
//
//El programa debe determinar el total a pagar.
//Datos de entrada:
//Cantidad de Motherboard producidos..:
//
//Datos de Salida:
//Total a pagar..:
	
#include <stdio.h>
int main()
{
    int producto1,producto2,incentivo,acomulador,precio;
    printf("Cantidad de Motherboard producidos..: ");
	scanf("%d",&producto1);
	
	producto2=producto1;
	producto2=3;
	precio=producto2*100;
  	if (producto1>3)
	  {
	  	
	  	producto1-=3;
	  	incentivo=producto1*125;
	  	acomulador =precio+incentivo;
  		printf("Total a pagar.. %d: ",acomulador);
	  }
	else{
		precio=producto1*100;
		printf("Total a pagar.. %d: ",precio);
	  }
	  return 0;
}
