// This program truncates SensorTile Outputs to remove
// garbage data acquired after the freethrow motion.
// The cutoff point is 2 seconds after the freethrow motion
// found by examining peaks of the ACC Magnitude csv

// Input1: Peaks Output of ACC X axis Magnitude
// Input2: Original Motion CSV File
// Output: Truncated CSV File


// USAGE: ./truncateData <INPUT Motion Data> <Peaks File>  <OUTPUT Trunced Data>

#include <stdio.h>
#include <stdlib.h>



// Find the maximum peak within the freethrow motion and cutoff time for truncation
void max_vector(float vector[], float* max, int n, 
		float timeVector[], float timeThreshold,
		float* cutoffTime)
{

	int i;
	//printf("%f, %f, %f\n", vector[0], vector[1], vector[2]);
	*max = vector[1];
	
	//printf("for loop iteration : %d\n", 4);
	for (i = 1; i < n; i++) {
		if ( *max < vector[i] && timeVector[i] < timeThreshold){
	
			*max = vector[i];
			*cutoffTime = timeVector[i]+ 15;
		}
	}
}
int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		fprintf(stderr, "Check Usage of truncateData.c\n");
		return 1;
	}
	FILE* iFile;
	FILE* oFile;
	char* inputFileName = argv[1];
	char* peaksFileName = argv[2];
	char* truncFileName = argv[3];
	char* line = NULL;
	ssize_t read;
	size_t len = 0;
	int lineCount = 0;
	
	// storage for values in Peak File
	float* timeVec;
	float* ampVec;
	int rv; 	// count number of variables read with sscanf

	float maxPeak;
	float cutOff;
	

	// Count the number of lines in the Peaks File
	iFile = fopen(peaksFileName, "r");
	if (iFile == NULL) {
		fprintf(stderr, "truncData: failed to read from peaks file\n");
		exit(EXIT_FAILURE);
	}

	read = getline(&line, &len, iFile); // disregard header of file
	while((read = getline(&line, &len, iFile)) != -1)
		lineCount++;
	
	rewind(iFile); // back to top
	read = getline(&line, &len, iFile); // disregard header of file
	timeVec = (float*) malloc(sizeof(float) * lineCount);
	ampVec = (float*) malloc(sizeof(float) * lineCount);
	
	int i = 0;		
	while((read = getline(&line, &len, iFile)) != -1) 
	{
		rv = sscanf(line, "%f,  %f\n", &timeVec[i], &ampVec[i]);
		if (rv != 2) {
		//	fprintf(stderr, "truncData: skipping line %d in peaks file \n", i);
			continue;
		}
		i++;
	}
	max_vector(ampVec, &maxPeak, lineCount, timeVec, 3, &cutOff); 
//printf("cutoff time is : %f\n", cutOff);	
	fclose(iFile);
	free (timeVec);
	free (ampVec);

	// Open and truncate the csv file
	iFile = fopen(inputFileName, "r");
	oFile = fopen(truncFileName, "w");

	if(iFile == NULL) {
		fprintf(stderr, "truncData: failed to read from input motion file\n");
		exit(EXIT_FAILURE);
	}
	lineCount = 0;
	while((read = getline(&line, &len, iFile)) != -1)
		lineCount++;
	rewind(iFile);
		
	read = getline(&line, &len, iFile); // disregard header of file
	
	float time, amp1, amp2, amp3, amp4, amp5, amp6, amp7, amp8, amp9;
	i = 0;		
	while((read = getline(&line, &len, iFile)) != -1) 
	{
		rv = sscanf(line, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", &time, &amp1, &amp2, &amp3, &amp4, 
								&amp5, &amp6, &amp7, &amp8, &amp9);
		
	//	printf("Line %d: %f, %f, %f, %f, %f, %f, %f, %f, %f, %f\n", i, time, amp1, amp2, amp3, amp4, amp5, amp6, amp7, amp8, amp9);
		if (rv != 10) {
			fprintf(stderr, "truncData: skipping line %d in trunc file\n", i);
			continue;
		}

		if (timeVec[i] < cutOff)
			fprintf(oFile, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", time, amp1, amp2, amp3, amp4,
									amp5, amp6, amp7, amp8, amp9);
		i++;
	}

	fclose(iFile);
	fclose(oFile);

	return 0;
}

