//Relaiza un programa que permita introducir la edad de 10 personas y
// determine cuantos son mayores  y menores de edad.
 #include <stdio.h>

int main() {
    int edad, totalmenores=0, totalmayores=0,i;
 
 for( i=0;i<=10;i++){
    printf("\nIngrese la edad de la persona: ");
    scanf("%d",&edad);
    if (edad<=17) {
       totalmenores=totalmenores+1;
       }
       else{
            totalmayores=totalmayores+1;
        }
	}
 
       printf("\nTotal de menores: %d",totalmenores);
       printf("\nTotal de mayores: %d", totalmayores);

getch();
return 0;
}
