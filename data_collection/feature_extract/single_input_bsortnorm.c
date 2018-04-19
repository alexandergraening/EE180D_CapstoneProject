/*
 *      Perform bubble sort on two vector pairs where
 *      first vector, time_vector value determine
 *      sort order from minimum to maximum value
 *
 *	Time values are normalized to difference between 
 *	maximum and minimum values
 *
 *      Amplitude values are normalized to difference between 
 *      maximum and minimum values
 *
 *	Usage:
 *	./bubble_sort_norm <INPUT_FILE> <OUTPUT_FILE>
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BUFF_SIZE 1024
 
void exchange(float *vec1, float *vec2)
{
    	float tmp = *vec1;
    	*vec1 = *vec2;
    	*vec2 = tmp;
}

void norm_vector(float vector[], float *norm, int n)
{
        int i;
        for (i = 0; i < n; i++){
		vector[i] = vector[i]/(*norm);
        }

}

void max_vector(float vector[], float timeVector[], float *max, float* maxTime, int n)
{
        int i;
	*max = vector[0];	
        for (i = 1; i < n; i++){
		if (*max < vector[i]){
			*max = vector[i];
			*maxTime = timeVector[i];
		}
        }

}

void min_vector(float vector[], float timeVector[], float *min, float* minTime, int n)
{	
       	int i;
        *min = vector[0];
        for (i = 1; i < n; i++){
                if (*min > vector[i]){
                        *min = vector[i];
			*minTime = timeVector[i];
                }
        }
}

int main(int argc, char **argv)
{
	FILE *fp;
        char *ifile_name, *ofile_name;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        int N_SAMPLES;

	int vector_length, rv, i;
	float norm, vec_min, vec_max;
	float minTime;
	float maxTime;
	float * time_vector;
	float * amplitude_vector_X;
	float * amplitude_vector_Y;
	float * amplitude_vector_Z;

	              if (argc != 3) {
                       fprintf(stderr, 
                              "Error - check usage\n"
                              );
                        exit(EXIT_FAILURE);
                }


	ifile_name = argv[1];
        ofile_name = argv[2];

        /* open the input file */
        printf(" Input file \'%s\'.\n", ifile_name);
        fp = fopen(ifile_name, "r");
        if (fp == NULL) {
                fprintf(stderr, 
                                "Failed to read from file \'%s\'.\n", 
                                ifile_name
                       );
                exit(EXIT_FAILURE);
        }

        /* count the number of lines in the file */
        read = getline(&line, &len, fp); //discard header of file
        N_SAMPLES = 0;
        while ((read = getline(&line, &len, fp)) != -1) {
                N_SAMPLES++;
        }

        /* go back to the start of the file so that the data can be read */
        rewind(fp);
        read = getline(&line, &len, fp); //discard header of file

	/* decrement N_SAMPLES to account for header line */

	N_SAMPLES--;

        i = 0;

        time_vector = (float *) malloc(sizeof(float) * N_SAMPLES);
        amplitude_vector_X  = (float *) malloc(sizeof(float) * N_SAMPLES);
        amplitude_vector_Y  = (float *) malloc(sizeof(float) * N_SAMPLES);
        amplitude_vector_Z  = (float *) malloc(sizeof(float) * N_SAMPLES);
        
	while ((read = getline(&line, &len, fp)) != -1) {
                /* parse the data */
                rv = sscanf(line, "%f,%f,%f,%f\n", &time_vector[i], &amplitude_vector_X[i], &amplitude_vector_Y[i], &amplitude_vector_Z[i]);
                i++;
        }
        fclose(fp);
	vector_length = N_SAMPLES;

	min_vector(amplitude_vector_X, time_vector, &vec_min,&minTime, vector_length);
	max_vector(amplitude_vector_X, time_vector, &vec_max,&maxTime, vector_length);
	float minX = vec_min; float minTimeX = minTime;
	float maxX = vec_max; float maxTimeX = maxTime;
	min_vector(amplitude_vector_Y, time_vector, &vec_min,&minTime, vector_length);
	max_vector(amplitude_vector_Y, time_vector, &vec_max,&maxTime, vector_length);
	float minY = vec_min; float minTimeY = minTime;
	float maxY = vec_max; float maxTimeY = maxTime;
	min_vector(amplitude_vector_Z, time_vector, &vec_min,&minTime, vector_length);
	max_vector(amplitude_vector_Z, time_vector, &vec_max,&maxTime, vector_length);
	float minZ = vec_min; float minTimeZ = minTime;
	float maxZ = vec_max; float maxTimeZ = maxTime;
	printf("X Minimum: %f at time: %f	X Maximum: %f at time %f\n", minX, minTimeX, maxX, maxTimeX);
	printf("Y Minimum: %f at time: %f	Y Maximum: %f at time %f\n", minY, minTimeY, maxY, maxTimeY);
	printf("Z Minimum: %f at time: %f	Z Maximum: %f at time %f\n", minZ, minTimeZ, maxZ, maxTimeZ);

    	return 0;
}

