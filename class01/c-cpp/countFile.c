#include <stdio.h>

// stdout, stdin, stderr

int main(int argc, char** argv)
{
	FILE *entrada;

    int c, countLower, countUpper, countDigit, countSpace, countLine;
	

	if(argc != 2)
	{
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM].\n", argv[0]);
		return 1;
	}

	entrada = fopen(argv[1],"r");
	if(!entrada)
	{
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}


	c = fgetc(entrada);

    countLower = 0;
    countUpper = 0;
    countDigit = 0;
    countSpace = 0;
    countLine = 0;

	while(c != EOF)
	{
        if( 64 < c && c < 91)
        {
            countUpper++;
        }
        if( 96 < c && c < 123)
        {
            countLower++;
        }
         if( 47 < c && c < 58)
        {
            countDigit++;
        }
         if( c == 32)
        {
            countSpace++;
        }
        if( c == '\n')
        {
            countLine++;
        }

		c = fgetc(entrada);
	}

	fclose(entrada);

    printf("Maiusculas: %i\n", countUpper);
    printf("Minusculas: %i\n", countLower);
    printf("Digitos: %i\n", countDigit);
    printf("Espaço em branco: %i\n", countSpace);
    printf("Quebra de linha: %i\n", countLine);

	return 0;
}