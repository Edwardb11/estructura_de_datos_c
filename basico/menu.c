#include <stdio.h>


int main()
{
int  a, b;
int op = 1;

  do{
  	printf("\n1.- Cargar dos Valores");
  	printf("\n2.- Mostrar la Suma");
  	printf("\n3.- Mostrar la Resta");
  	printf("\n4.- Mostrar la Nultiplicacion");
  	printf("\n5.- Mostrar la Division");
  	printf("\n6.- FInalizar");
  	printf("\n\nSu opcion..: ");scanf("%d",&op);
 switch (op)
    {
    	case 1: 
    			
	 			printf("Introduce el valor del primer numero: ");
    			scanf("%i", &a);
   				printf("Introduce el valor del segundo numero: ");
   				scanf("%i", &b);
    		break;
    	case 2: 
    			suma(a,b);
    			break;
    	case 3:
    	    	resta(a,b);
    			break;
		case 4: 
		    	producto(a,b);
				break;	
		case 5: 
				division(a,b);
				break;		
	}
	}while(op!=6);
		Salir();
}

int suma(int a, int b)
{
	int suma = a+b;
   	printf("\n La suma es: %i ",suma);
}
 
 int resta(int a, int b)
{
	int resta= a-b;
    printf("\n La resta es: %i", resta);
}

int producto(int a, int b)
{
	int producto =a*b;
	printf("\n El producto es: %i", producto);
}

int division(int a, int b)
{
	int division = a/b;
 	printf("\n La division es: %i", division);
 }
 
 void Salir(){
	printf("%cGracias, regrese pronto!\n\n\n\n", 173);
    getch();
    
}
