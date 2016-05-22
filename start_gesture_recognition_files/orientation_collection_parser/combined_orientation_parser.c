#include <stdio.h>

int main()
{
	FILE* inputFile1 = fopen("orientation1_parsed.txt", "r");
	FILE* outputFile = fopen("combined_orientations_parsed.txt","w");
	if (inputFile1 == NULL || outputFile == NULL)
	{
		printf("Error opening file!\nExit\n");
		return 1;
	}
	printf("Opened files successfully!\n");

//	fpos_t inputFilePos;
	//getfilepos(inputFile,&inputFilePos);

	int outputValues1;
	int outputValues2;
	int outputValues3;
	int outputValues4;
	int outputValues5;
	printf("Successfully created storage ints!\n");
	
	printf("About to read from files.\n");
	fprintf(outputFile,"250 3 5\n");
	int k;
	for (k = 0; k < 50;++k)
	{
		fscanf(inputFile1,"%d %d %d",&outputValues1,&outputValues2,&outputValues3);
		fprintf(outputFile,"%d %d %d\n",outputValues1,outputValues2,outputValues3);
		fscanf(inputFile1,"%d %d %d %d %d",&outputValues1,&outputValues2,&outputValues3,&outputValues4,&outputValues5);
		fprintf(outputFile,"%d %d %d %d %d\n",outputValues1,outputValues2,outputValues3,outputValues4,outputValues5);
	}
	fclose(inputFile1);

	FILE* inputFile2 = fopen("orientation2_parsed.txt", "r");

	if (inputFile2 == NULL)
	{
		printf("Error opening file!\nExit\n");
		return 1;
	}
	printf("Opened files successfully!\n");
	for (k = 0; k < 100;++k)
	{
		fscanf(inputFile2,"%d %d %d",&outputValues1,&outputValues2,&outputValues3);
		fprintf(outputFile,"%d %d %d\n",outputValues1,outputValues2, outputValues3);
		fscanf(inputFile1,"%d %d %d %d %d",&outputValues1,&outputValues2,&outputValues3,&outputValues4,&outputValues5);
		fprintf(outputFile,"%d %d %d %d %d\n",outputValues1,outputValues2,outputValues3,outputValues4,outputValues5);
	}
	fclose(inputFile2);

	FILE* inputFile3 = fopen("orientation3_parsed.txt", "r");

	if (inputFile3 == NULL)
	{
		printf("Error opening file!\nExit\n");
		return 1;
	}
	printf("Opened files successfully!\n");
	for (k = 0; k < 100;++k)
	{
		fscanf(inputFile3,"%d %d %d",&outputValues1,&outputValues2,&outputValues3);
		fprintf(outputFile,"%d %d %d\n",outputValues1,outputValues2, outputValues3);
		fscanf(inputFile1,"%d %d %d %d %d",&outputValues1,&outputValues2,&outputValues3,&outputValues4,&outputValues5);
		fprintf(outputFile,"%d %d %d %d %d\n",outputValues1,outputValues2,outputValues3,outputValues4,outputValues5);
	}
	fclose(inputFile3);

	FILE* inputFile4 = fopen("orientation4_parsed.txt", "r");

	if (inputFile4 == NULL)
	{
		printf("Error opening file!\nExit\n");
		return 1;
	}
	printf("Opened files successfully!\n");
	for (k = 0; k < 100;++k)
	{
		fscanf(inputFile3,"%d %d %d",&outputValues1,&outputValues2,&outputValues3);
		fprintf(outputFile,"%d %d %d\n",outputValues1,outputValues2, outputValues3);
		fscanf(inputFile1,"%d %d %d %d %d",&outputValues1,&outputValues2,&outputValues3,&outputValues4,&outputValues5);
		fprintf(outputFile,"%d %d %d %d %d\n",outputValues1,outputValues2,outputValues3,outputValues4,outputValues5);
	}
	fclose(inputFile4);
	
	FILE* inputFile5 = fopen("orientation5_parsed.txt", "r");

	if (inputFile5 == NULL)
	{
		printf("Error opening file!\nExit\n");
		return 1;
	}
	printf("Opened files successfully!\n");
	for (k = 0; k < 100;++k)
	{
		fscanf(inputFile5,"%d %d %d",&outputValues1,&outputValues2,&outputValues3);
		fprintf(outputFile,"%d %d %d\n",outputValues1,outputValues2, outputValues3);
		fscanf(inputFile1,"%d %d %d %d %d",&outputValues1,&outputValues2,&outputValues3,&outputValues4,&outputValues5);
		fprintf(outputFile,"%d %d %d %d %d\n",outputValues1,outputValues2,outputValues3,outputValues4,outputValues5);
	}
	fclose(inputFile5);

	fclose(outputFile);
	printf("Files closed!\n");

	return 0;
}
