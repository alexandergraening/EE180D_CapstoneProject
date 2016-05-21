// USAGE: ./test_nn <formatted testing file>

#include <unistd.h>
#include <stdio.h>
#include "fann.h"

int main(int argc, char* argv [])
{
	if (argc != 2) {
		fprintf(stderr, "Check usage: ./test_nn <fann test file>\n");
		return 1;
	}
	FILE* iFile;
	char * iFileName;	
	iFileName = argv[1];
	iFile = fopen(iFileName, "r");
	if(!iFile) {
		fprintf(stderr, "./Fann_test failed to open file: %s\n", iFileName);
		return 1;
	}
	float feature1, feature2, feature3, feature4, feature5, feature6, feature7,
			feature8, feature9, feature10, feature11, feature12;

	fscanf(iFile, "%f %f %f %f %f %f %f %f %f %f %f %f\n", &feature1, &feature2, &feature3, &feature4, &feature5, &feature6,
								&feature7, &feature8, &feature9, &feature10, &feature11, &feature12);

	int i;
   	int location;
    	float max;
    	fann_type *calc_out;
    	fann_type input[12];
    	struct fann *ann;
    	ann = fann_create_from_file("../training_data/TEST.net");
        max = -100;
        input[0] = feature1;
        input[1] = feature2;
        input[2] = feature3;
	input[3] = feature4;
	input[4] = feature5;
	input[5] = feature6;
	input[6] = feature7;
	input[7] = feature8;
	input[8] = feature9;
	input[9] = feature10;
	input[10] = feature11;
	input[11] = feature12;
        calc_out = fann_run(ann, input);

        for (i = 0; i < 3; i++) {
		printf("for location %d: probability is: %f\n" , i, calc_out[i]);
            if (calc_out[i] > max) {
                max = calc_out[i];
                location = i;
            }
        }
	fclose(iFile);
        printf("Feature 1: %f, Feature 2: %f, Feature 3: %f -> Result: %d\n", feature1, feature2, feature3, location+1);
        sleep(1);

    
    	fann_destroy(ann);
    return 0;
}
