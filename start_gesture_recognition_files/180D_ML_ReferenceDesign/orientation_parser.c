/*
Usage: ./orientation_parser <input_file> <output_file> <orientation_number>
*/



#include <stdio.h>
#include <stdlib.h>

int convertNumbers(int x0, int x1)
{
	int returnVal = 0;
	returnVal += x0;
	returnVal += x1 * 256;
	return returnVal;
}

int main(int argc, char **argv)
{
	if (argc != 4) {
                fprintf(stderr,"Error - check usage\n");
		exit(EXIT_FAILURE);
	}
	if (*argv[3] > 53 || *argv[3] < 49)
	{
		fprintf(stderr,"argv[3] out of bounds\n");
		exit(EXIT_FAILURE);
	}

	FILE* inputFile = fopen(argv[1], "r");
	FILE* outputFile = fopen(argv[2],"w");

	if (inputFile == NULL || outputFile == NULL)
	{
		printf("Error opening file!\nExit\n");
		return 1;
	}
	printf("Opened files successfully!\n");

	fpos_t inputFilePos;
	//getfilepos(inputFile,&inputFilePos);
	char tempChar;
	int tempInt;
	int lineCount = 0;
	int outputValues[9];
	while (1)
	{
		tempChar = fgetc(inputFile);
		while(tempChar != ':'&& tempChar != '@'){
			tempChar = fgetc(inputFile);
		}
		if (tempChar == '@')
		{
			break;
		}
		++lineCount;
		int k;
		int hexValues[20];
		for(k=0;k<20;++k)
		{
			fscanf(inputFile," %x",hexValues+k);
//			fprintf(outputFile," %x",*hexValues+k);
		}
		int n;
		for (n = 0; n < 9; ++n)
		{
			outputValues[n] = hexValues[2*n+2] + 256*hexValues[2*n + 3];
			if (outputValues[n] > 32768)
			{
				outputValues[n] = outputValues[n]-65536;
			}
			printf("Inputs:%d %d Output:%d\n",hexValues[2*n + 2],hexValues[2*n + 3],outputValues[n]);
		}/*
		outputValues[0] = hexValues[2] + 256*hexValues[3];
		printf("Inputs:%d %d Output:%d\n",hexValues[2],hexValues[3],outputValues[0]);
		outputValues[1] = hexValues[3] + 256*hexValues[4];
		convertNumbers(hexValues[4],hexValues[5]);
		printf("Inputs:%d %d Output:%d\n",hexValues[4],hexValues[5],outputValues[1]);
		outputValues[2] = convertNumbers(hexValues[6],hexValues[7]);
		printf("Inputs:%d %d Output:%d\n",hexValues[6],hexValues[7],outputValues[2]);
		outputValues[3] = convertNumbers(hexValues[8],hexValues[9]);
		printf("Inputs:%d %d Output:%d\n",hexValues[8],hexValues[9],outputValues[3]);
		outputValues[4] = convertNumbers(hexValues[10],hexValues[11]);
		printf("Inputs:%d %d Output:%d\n",hexValues[10],hexValues[11],outputValues[4]);
		outputValues[5] = convertNumbers(hexValues[12],hexValues[13]);
		printf("Inputs:%d %d Output:%d\n",hexValues[12],hexValues[13],outputValues[5]);
		outputValues[6] = convertNumbers(hexValues[14],hexValues[15]);
		printf("Inputs:%d %d Output:%d\n",hexValues[14],hexValues[15],outputValues[6]);
		outputValues[7] = convertNumbers(hexValues[16],hexValues[17]);
		printf("Inputs:%d %d Output:%d\n",hexValues[16],hexValues[17],outputValues[7]);
		outputValues[8] = convertNumbers(hexValues[18],hexValues[19]);
		printf("Inputs:%d %d Output:%d\n",hexValues[18],hexValues[19],outputValues[8]);*/
		//getfilepos(inputFile,&inputFilePos);
		switch(*argv[3])
		{
			case 49:	
				fprintf(outputFile,"%d %d %d\n1 0 0 0 0\n",outputValues[0],outputValues[1], outputValues[2]);
			case 50:
				fprintf(outputFile,"%d %d %d\n0 1 0 0 0\n",outputValues[0],outputValues[1], outputValues[2]);
			case 51:
				fprintf(outputFile,"%d %d %d\n0 0 1 0 0\n",outputValues[0],outputValues[1], outputValues[2]);
			case 52:
				fprintf(outputFile,"%d %d %d\n0 0 0 1 0\n",outputValues[0],outputValues[1], outputValues[2]);
			case 53:
				fprintf(outputFile,"%d %d %d\n0 0 0 0 1\n",outputValues[0],outputValues[1], outputValues[2]);
			default:
				fprintf(outputFile,"Error in inputs.\n");
		}
	}
	printf("Exited while loop!\nFile contained %d lines.\n",lineCount);

	//Testing file output...
	/*int i;
	for (i = 0; i < 10; ++i)
	{
	{
		fprintf(outputFile, "Line%d...\n",i);
	}*/
	
	fclose(inputFile);
	fclose(outputFile);
	printf("Files closed!\n");

	return 0;
}
