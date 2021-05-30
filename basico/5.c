#include <stdio.h>

int main()
{
	int elegir;
	printf("Listado de Discupulo:\n ");
	printf("1. Simon Pedro\n 2. Andres, Hermano de Pedro\n 3. Juan\n 4. Santiago, Hermano de Juan\n 5. Bartolome\n 6. Felipe\n 7. Tomas\n 8. Mateo\n 9. Santiago\n 10. Judas\n 11. Judas Iscariote\n 12. Simon\n ");
	printf("\nIntroduzca el numero del discipulo: ");
	scanf("%d",&elegir);
	if (elegir >=1 && elegir <=12){
		switch (elegir){
			case 1:
				printf("Murio crucificado. ");
				break;
			case 2: 
				printf("La causa de muerte de Andres y el sitio en que murio son inciertos.");
				break;
			case 3:
				printf("Murio por causas naturales en la Isla de Patmos.");
				break;
			case 4: 
				printf("El primer apostol en morir por la fe cristiana.");
				break;
			case 5:
				printf("Se conoce muy poco sobre la muerte de Bartolome. Algunas fuentes simplemente afirman que fue martirizado, mientras otras dicen que fue despellejado vivo y decapitado. Una fuente dice que fue -desollado con cuchillos.-");
				break;
			case 6:
				printf("Una fuente afirma que fue ahorcado hasta morir. Otra, dice que Felipe fue crucificado durante su ministerio en Egipto.");
				break;
			case 7: 
				printf("Fue apuñalado con una lanza en algún lugar durante su ministerio en la India.");
				break;
			case 8:
				printf("Se convirtio en misionero y fue arrestado en Etiopia. En ese lugar, fue apedreado o atravesado con lanzas y luego, decapitado.");
				break;
			case 9:
				printf("\nTeoria 1: Santiago fue crucificado durante su ministerio en Egipto (Wikipedia).");
				printf("\nTeoria 2: Murio como martir y su cuerpo fue cortado en pedazos.");
				printf("\nTeoria 3: A una edad avanzada fue golpeado, apedreado y finalmente asesinado con el golpe de un garrote en la cabeza.");
				printf("\nTeoría 4: Santiago estaba predicando sobre un muro cuando lideres religiosos judios decidieron empujarlo. Aparentemente, sobrevivio.  Por eso, de manera similar a la teoria tres sobre como murio este hombre de los doce apostoles, lo apedrearon y golpearon con un garrote hasta la muerte.");
				break;
			case 10: 
				printf("Segun la Iglesia Ortodoxa en America, Judas estaba en Armenia cuando fue crucificado y atravesado por flechas, aproximadamente 45 años despues de la muerte de Cristo.");
				break;
			case 11:
				printf("La muerte de Judas Iscariote fue un suicidio que el cometio luego de sentir mucho remordimiento por haber traicionado a Jesis");
				break;
			case 12:
				printf("\nTeoria 1: Murio “pacíficamente en Edessa”, que ahora se encuentra en algun lugar de la actual Turquia.");
				printf("\nTeoria 2: Este sitio web católico también alega que Simon el Cananita murio en Edessa, pero fue crucificado. Una muerte menos pacifica que en nuestra primera teoria. ");
				printf("\nTeoria 3: Era misionero en Africa y luego, en Inglaterra, donde fue crucificado aproximadamente en el 74 d.C.");
				break;
			default: 
			break;
		}
	}
	else{
		printf("ERROR: %d no esta asociado a ningun discipulo de Jesucristo",elegir);
	}
} 
