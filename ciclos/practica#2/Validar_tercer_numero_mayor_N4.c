//4. Escriba un programa en C que lea tres números enteros positivos validando
//de acuerdo con lo siguiente: el tercer número deberá ser mayor o igual al
//mayor de los otros dos y menor o igual a la suma de los dos primeros. 
//PARA REALIZAR CON EL CICLO: DO WHILE

#include<stdio.h>
int main()
{     
	 int a=0,b=0,c=0,suma=0,mayor=0;
	do{
		printf("\n\n Ingrese el primer valor: ");
 		scanf("%d",&a);
		printf("\n Ingrese el segundo valor: ");
		scanf("%d",&b);
		printf("\n Ingrese el tercer valor: ");
		scanf("%d",&c);
		fflush(stdin);
		suma=a+b;
		if(a>b){
			mayor+=a;
		}
		else{
			mayor+=b;
		}
		
		if ( c>= mayor && c <= suma ){
        printf( "\nEl mayor de los dos primeros valores es:  %d ", mayor );
        printf( "\nEl tercer valor es %d por ende es mayor o igual que %d ", c,mayor );
        printf( "\nLa suma de los dos primeros valores es:  %d ", suma );
         printf( "\nEl tercer valor es %d por ende es menor o igual que %d ",c, suma );
		}	
		else{
			printf("No se cumplio la condicion.");
			break;
		}	

}
while(c>=mayor && c<=suma );
		printf("\nFIN");

}


