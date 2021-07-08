//Utilizando do while, que calcule la media aritmetica de 5 numeros positivos
//introducidos desde teclado
#include <stdio.h> 
#include <string.h>
#define maximoFila 6

			
int main (){
	printf("*** Edward Brito Diaz 2019-0823 ****\n\n");
	
	//ejercicio 01
	int opcion;
	int numero=0,suma=0, contador=0;
	float promedio;
	
//	ejercicio 03
	int suma1,suma2,suma3;
	int i,e,num, numero1,con,numero2;
	
	//ejercicio 05
	int x, total=1;
	
	//ejercicio 06
	int fila=1,culumna=1,num22=1;
	printf("opcion:  ");
	scanf("%d",&opcion);
	switch (opcion){
		case 1: 
		do{
			printf("Ingresa un numero:\n "); 
			scanf("%d",&numero); 
			if (numero>0){
				suma+=numero;
				contador++;
			}
			else{
			numero=0;	
			}
			promedio=suma/contador;
		}
		
		while(contador<5);
		printf("Has introducido %d numeros positivos. La  media es %.2f ",contador, promedio);
		break;	
		
		case 2:
		printf ("\n  ");
		printf("El 40 no va \n");
		for(numero= 50; numero>= 4; numero+= -4){
	printf("\nMultimos del numero 4 son %d",numero);
}
			break;
			
		case 3:
		
			printf("Ingresa un numero:\n "); 
			scanf("%d",&numero1); 
			
			for (i=0;i<=numero1; i++){
				if (i%2 !=0){
					suma1+=i;
				}
			}
			
			while (i<=numero1){
					numero1;
				if (i%2 !=0){
				suma2+=i;
				}
				i++;
			}
		
			do{
				numero1;
				if (i%2 !=0){
				suma3+=i;
				}
				i++;
			}
			while (i<=numero1);
			
		printf("La suma de los numeros impares con el bucle for es : %d \n",suma1);	
		printf("La suma de los numeros impares con el bucle While es : %d \n",suma2);
		printf("La suma de los numeros impares con el bucle DO While es : %d \n",suma3);	
		break;
		
		
		case 4:

			
		printf ("Introduzca un numero entero :");
		scanf("%d",&numero2);
		
		con = 0;
		
		while(numero2 !=0)
	{
		printf ("\n La mitad de %d es: %d\n", numero2,numero2 /2);
		con++;
		
		printf ("Introduzca un numero entero :");
		scanf("%d",&numero2);
	}
	    printf (" \n Ha introducido %d numeros distintos de cero", con);
			break;
			
		case 5:
			for( x=1;x<=12;x++){
			total = total * x;	
			}
			printf("El resultado total es: %d", total);	
		break;
		
		case 6:
			for (fila =1;fila<=maximoFila; fila++ )
			{
					fila-1;
					while (fila <= culumna ){
						printf("%d\t",num22);
						num++;
						fila++;
					}
					printf("\n");
					culumna++;
					fila--;
			}
		
			break;
		case 7:

	break;
		
}
	
	
}
