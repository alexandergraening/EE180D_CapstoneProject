// This program truncates SensorTile Outputs to remove
// garbage data acquired after the freethrow motion.
// The cutoff point is 2 seconds after the freethrow motion
// found by examining peaks of the ACC Magnitude csv

// USAGE: ./computeRiemannSum <mdo_INPUT> <OUTPUT_FILE>

#include <stdio.h>
#include <stdlib.h>



// Find the maximum peak within the freethrow motion and cutoff time for truncation
void max_vector(float vector[], float* max, int n, float timeVector[], float* cutoffTime)
{

	int i;
	*max = -999;
	
	for (i = 0; i < n; i++) {
		if ( *max < vector[i]){
			*max = vector[i];
			*cutoffTime = timeVector[i]+1;
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Check Usage of computeRiemannSum.c\nCorrect usage: ./computeRiemannSum <input_mdo> <output_file>\n");
		return 1;
	}
	FILE* iFile;
	FILE* oFile;
	char* inputFileName = argv[1]; // main file input
	char* outputFileName = argv[2]; // secondary file input to find time of peak
	char* line = NULL;
	ssize_t read;
	size_t len = 0;
	int lineCount = 0;
	
	// storage for values in Peak File
	float *timeVec;
	float *ampVec;
	float *axVec;
	float *ayVec;
	float *azVec;
	int rv; 	// count number of variables read with sscanf

	float maxPeak;
	float cutOff;
	

	// Count the number of lines in the Peaks File
	iFile = fopen(peaksFileName, "r");
	if (iFile == NULL) {
		fprintf(stderr, "computeRiemannSum: failed to read from input_file\n");
		exit(EXIT_FAILURE);
	}

	read = getline(&line, &len, iFile); // disregard header of file
	while((read = getline(&line, &len, iFile)) != -1)
		lineCount++;
	
	rewind(iFile); // back to top
	read = getline(&line, &len, iFile); // disregard header of file
	timeVec = (float*) malloc(sizeof(float) * lineCount);
	ampVec = (float*) malloc(sizeof(float) * lineCount);
	axVec = (float*) malloc(sizeof(float) * lineCount);
	ayVec = (float*) malloc(sizeof(float) * lineCount);
	azVec = (float*) malloc(sizeof(float) * lineCount);
	int i;
	i = 0;
	while((read = getline(&line, &len, iFile)) != -1) 
	{
		rv = sscanf(line, "%f,%f,%f,%f\n", &timeVec[i], &ampVec[i]);
		if (rv != 2) {
	//	fprintf(stderr, "truncData: skipping line %d in peaks file; %d variables read in %s\n", i, rv, peaksFileName);
			continue;
		}
		i++;
	}


	max_vector(ampVec, &maxPeak, lineCount, timeVec, &cutOff); 
	printf("cutoff time for %s : %f and maxpeak is: %f\n", inputFileName, cutOff, maxPeak);	
	fclose(iFile);
	free (timeVec);
	free (ampVec);
	free (axVec);
	free (ayVec);
	free (azVec);

	// Open and truncate the csv file
	oFile = fopen(truncFileName, "w");

	if (oFile == NULL) {
		fprintf(stderr, "truncData: failed to open output file\n");
		exit(EXIT_FAILURE);
	}
	lineCount = 0;
	while((read = getline(&line, &len, iFile)) != -1)
		lineCount++;
	rewind(iFile);
		
	read = getline(&line, &len, iFile); // disregard header of file
	read = getline(&line, &len, iFile); // disregard the sometimes blank first line of data
	float time, amp1, amp2, amp3, amp4, amp5, amp6, amp7, amp8, amp9;
	i = 0;		
	while((read = getline(&line, &len, iFile)) != -1) 
	{
		rv = sscanf(line, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", &time, &amp1, &amp2, &amp3, &amp4, 
								&amp5, &amp6, &amp7, &amp8, &amp9);
		
	//	printf("Line %d: %f, %f, %f, %f, %f, %f, %f, %f, %f, %f\n", i, time, amp1, amp2, amp3, amp4, amp5, amp6, amp7, amp8, amp9);
//		if (rv != 10) {
//			fprintf(stderr, "truncData: skipping line %d in trunc file\n", i);
//			//continue;
//		}

		if (timeVec[i] < cutOff)
			fprintf(oFile, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", time, amp1, amp2, amp3, amp4,
									amp5, amp6, amp7, amp8, amp9);
		i++;
	}

	fclose(iFile);
	fclose(oFile);

	return 0;
}

