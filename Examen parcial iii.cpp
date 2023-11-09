#include <stdio.h>

#define NUM_PALABRAS 3000

int main() 
{
    FILE *archivo;
    char linea[10000];
    char caracter;
    int conteo[NUM_PALABRAS] = {0};
    int miID = 181762;
    int ultimosTresDigitos = miID % 1000;

    archivo = fopen("emails.csv", "r");

    if (archivo == NULL) 
	{
        perror("Error al abrir el archivo");
        return 1;
    }

    int contadorFilas = 0;
    while (contadorFilas < 50) 
	{
        if (fgets(linea, sizeof(linea), archivo) == NULL) 
		{
            break;
        }

        int id;
        int columna = 0;
        while ((caracter = linea[columna]) != '\0') 
		{
            if (caracter == ',') 
			{
                conteo[columna / 2] += (linea[columna + 1] - '0');
            }
            columna++;
        }

        sscanf(linea, "%*d,%*d,%*d,%d", &id);

        if (id % 1000 == ultimosTresDigitos) 
		{
            contadorFilas++;
            for (int i = 1; i <= NUM_PALABRAS; i++) 
			{
                printf("Palabra%d: %d\n", i, conteo[i-1]);
            }
        }
    }

    fclose(archivo);

    return 0;
}

