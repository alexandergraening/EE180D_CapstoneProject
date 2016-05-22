all: waveform_peak_find accGryMag

waveform_peak_find: waveform_peak_find.c
	gcc -o waveform_peak_find waveform_peak_find.c -lm

accGyrMag: accGyrMag.c
	gcc -o accGyrMag accGyrMag.c -lm

clean:
	rm -rf waveform_peak_find *~
	rm -rf accGyrMag
