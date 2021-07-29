/* PROGRAMA QUE SE PIDAN 8 NUMEROS QUE SE ALMACENARAN EN UNA MATRIZ 2X3, SE VA A CALCULAR LA SUMA DE CADA FILA Y 
AL FINAL EL PROGRAMA DEBERA DECIR CUAL FILA TIENE MAYOR SUMA */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int matriz[3][3], suma = 0, cont, cont2, fila = 3, col = 3, mayor = 0;
	
	for(cont = 0; cont < fila; cont++ ){
		
		suma = 0;
		
		for(cont2 = 0; cont2 < col; cont2++ ){
			
			printf("\n%d. Introduzca un numero: ", cont+1);
			scanf("%d", &matriz[cont][cont2]);
			
			suma = suma + matriz[cont][cont2];
		}	
		
		printf("\n\n La suma actualmente es: %d\n\n", suma);
		
		if(mayor < suma ){
			mayor = suma;
		}
	}printf("\nLa fila con mayor suma es %d", mayor);
	
	
	
	return 0;
}
