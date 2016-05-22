echo "Beginning Feature Computation"

if [ "$#" -ne 2 ]; then
		echo "Please enter a starting sample number and an ending sample number"
		exit
	fi

for i in $(seq $1 $2);
do

	./accGyrMag ../raw/mdo_${i}w.csv ../raw/accMag_${i}w.csv ../raw/gyrMag_${i}w.csv
	./accGyrMag ../raw/mdo_${i}e.csv ../raw/accMag_${i}e.csv ../raw/gyrMag_${i}e.csv
	./findAbsExtrema ../raw/mdo_${i}w.csv ../features/accMaxMin_${i}w.csv ../features/gyrMaxMin_${i}w.csv
	./findAbsExtrema ../raw/mdo_${i}e.csv ../features/accMaxMin_${i}e.csv ../features/gyrMaxMin_${i}e.csv

	./findMagnitudeExtrema ../raw/accMag_${i}e.csv ../features/accTimeFeature_${i}.csv
	./findMagnitudeExtrema ../raw/gyrMag_${i}e.csv ../features/gyrTimeFeature_${i}.csv
	
	./magnitudeXCORR ../raw/accMag_${i}e.csv ../raw/accMag_${i}w.csv ../features/accXCORR_${i}.csv 20
	./magnitudeXCORR ../raw/gyrMag_${i}e.csv ../raw/gyrMag_${i}w.csv ../features/gyrXCORR_${i}.csv 20
	./magnitudeXCORR ../raw/accMag_${i}e.csv ../raw/gyrMag_${i}e.csv ../features/eXCORR_${i}.csv 20
	./magnitudeXCORR ../raw/accMag_${i}w.csv ../raw/gyrMag_${i}w.csv ../features/wXCORR_${i}.csv 20

#./compute_cross_correlation_peaks.sh ../raw/mdo_${i}e.csv
#cp waveform_peaks_output_x.csv ../raw/mdo_${i}_Px.csv
#cp waveform_peaks_output_y.csv ../raw/mdo_${i}_Py.csv
#cp xcorr_waveform_peaks_output_x.csv ../raw/mdo_${i}_xcorr_Pxy.csv
#cp xcorr_waveform_peaks_output_y.csv ../raw/mdo_${i}_xcorr_Pyx.csv
#cp xcorr_extrema.dat ../raw/mdo_${i}_xcorr_extrema.dat
#./bubble_sort_norm ../raw/mdo_${i}_xcorr_Pxy.csv ../raw/mdo_${i}_xcorr_Pyx.csv ../raw/mdo_${i}_xcorr_Pxy_sortnorm.csv ../raw/mdo_${i}_xcorr_Pyx_sortnorm.csv
#./bubble_sort_norm ../raw/mdo_${i}_Px.csv ../raw/mdo_${i}_Py.csv ../raw/mdo_${i}_Px_sortnorm.csv ../raw/mdo_${i}_Py_sortnorm.csv
done

echo "Feature Extraction Complete"
echo ""
