//Después de consultar el texto básico de la asignatura y otros documentos sugeridos por
// su facilitador, en el contenido de la Unidad VII, realiza las actividades sugeridas:
//
//1- Realiza un programa utilizando las funciones de manejo de caracteres en Lenguaje C ,
// que determine si una palabra es palíndromo. El usuario digita una palabra, y el programa
//  emite un mensaje diciendo si es o no palíndromo.
//
//Nota: Se entienden como palíndromo o palíndromos, a las palabras o frases que se leen de
// igual manera hacia adelante o hacia atrás.
//
//Ejemplo:
//Aba
//Arañara
//Sometemos
//Reconocer
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
 char palabra[80];
 int x,y,z;
   printf("\n\nEscribe una palabra: ");
   scanf(" %s",palabra);
   x=strlen(palabra);
   x=x-1;
 for(y=0,z=x;y<=x/2;y++,z--)
  	if(palabra[y]==palabra[z])
     	printf("Es palindromo");
 	else
   		 printf("No es palindromo");
 getch();
}
