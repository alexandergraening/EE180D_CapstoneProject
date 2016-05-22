// USAGE: ./createTrainFile <OUTPUT FILE>

// TODO: Create a header line with number of inputs, outputs, training sets
#include <stdio.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Check usage! \n");
		return 1;
	}

	FILE* outFile;
	char userInput[60];
	char userInput2;
	int numFreeThrows;
	outFile = fopen(argv[1], "w");
	printf("Freethrow Result Encoding:\n");
	printf("r - RIGHT\n");
	printf("i - IN\n");
	printf("l - LEFT\n");
	printf("u - SHORT\n");
	printf("o - LONG\n");

	
	printf("Enter the number of freethrows to add to the system: ");
	scanf("%d", &numFreeThrows);

	for(int k = 0; k < numFreeThrows; k++)
	{
		printf("Enter the encoded result of freethrow %d: ", k);
		userInput2 = getchar();
		
		if(userInput2 == 'r')
			fputs("0 0 0 0 1\n", outFile);	
		
		else if (userInput2 == 'l')
			fputs("1 0 0 0 0\n", outFile);

		else if (userInput2 == 'i')
			fputs("0 0 1 0 0\n", outFile);

		else if (userInput2 == 'u')
			fputs("0 1 0 0 0\n", outFile);

		else if (userInput2 == 'o')
			fputs("0 0 0 1 0\n", outFile);

		else	
			printf("\n\nInvalid Input ... CHECK LINE %d\n\n", k);
		
		userInput2 = 0;
	
	}




	fclose(outFile);	
	return 0;
}
