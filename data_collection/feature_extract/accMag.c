// USAGE: ./accMag <input csv> <output csv>

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("check usage\n");
		return 1;
	}
	FILE* inFile;
	FILE* outFile;
	float timestamp, accX, accY, accZ, accMag;

	// the following is a dummy variable used only to skip lines when reading files
	char full_line_storage[999];	
	
	outFile = fopen(argv[2], "w");
	//outFile = fopen("../features/acc_magnitudes.csv", "w");
	fprintf(outFile, "Timestamp    Acc Mags\n");
	
	inFile = fopen(argv[1],"r");
	//inFile = fopen("../collect_raw/motion_data_output_1.csv","r");
	if(!inFile)
	{
		printf("FAILURE TO FIND MOTION DATA OUTPUT FILE\n");
		printf("ABORTING\n");
		return 1;
	}

	// skip the first header line when reading the csv
	while(fgets(full_line_storage, 999, inFile)!=NULL)
	{
	fscanf(inFile, "%f,%f,%f,%f", &timestamp, &accX, &accY, &accZ);
	accMag = sqrt(accX*accX + accY*accY + accZ*accZ);
	fprintf(outFile, "%f,%f\n",timestamp, accMag);
	}

	fclose(outFile);
	fclose(inFile);
	return 0;
}
