all: waveform_peak_find accGyrMag bubble_sort_norm waveform_feature_xcorr

waveform_peak_find: waveform_peak_find.c
	gcc -o waveform_peak_find waveform_peak_find.c -lm

accGyrMag: accGyrMag.c
	gcc -o accGyrMag accGyrMag.c -lm

bubble_sort_norm: bubble_sort_norm.c
	gcc -o bubble_sort_norm bubble_sort_norm.c -lm

waveform_feature_xcorr: waveform_feature_xcorr.c
	gcc -o waveform_feature_xcorr waveform_feature_xcorr.c -lm

magnitudeXCORR: magnitudeXCORR.c
	gcc -o magnitudeXCORR magnitudeXCORR.c -lm

clean:
	rm -rf waveform_peak_find *~
	rm -rf accGyrMag
	rm -rf bubble_sort_norm
	rm -rf waveform_feature_xcorr
	rm -rf magnitudeXCORR
