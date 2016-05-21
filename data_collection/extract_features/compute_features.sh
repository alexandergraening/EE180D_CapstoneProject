echo "Beginning Feature Computation"
echo ""

for i in $(seq 1 1);
do
./accGyrMag ../raw/mdo_${i}w.csv ../raw/accMag_${i}w.csv ../raw/gyrMag_${i}w.csv
./accGyrMag ../raw/mdo_${i}e.csv ../raw/accMag_${i}e.csv ../raw/gyrMag_${i}e.csv

./compute_cross_correlation_peaks.sh ../raw/mdo_${i}e.csv
cp waveform_peaks_output_x.csv ../raw/mdo_${i}_Px.csv
cp waveform_peaks_output_y.csv ../raw/mdo_${i}_Py.csv
cp xcorr_waveform_peaks_output_x.csv ../raw/mdo_${i}_xcorr_Pxy.csv
cp xcorr_waveform_peaks_output_y.csv ../raw/mdo_${i}_xcorr_Pyx.csv
cp xcorr_extrema.dat ../raw/mdo_${i}_xcorr_extrema.dat
./bubble_sort_norm ../raw/mdo_${i}_xcorr_Pxy.csv ../raw/mdo_${i}_xcorr_Pyx.csv ../raw/mdo_${i}_xcorr_Pxy_sortnorm.csv ../raw/mdo_${i}_xcorr_Pyx_sortnorm.csv
./bubble_sort_norm ../raw/mdo_${i}_Px.csv ../raw/mdo_${i}_Py.csv ../raw/mdo_${i}_Px_sortnorm.csv ../raw/mdo_${i}_Py_sortnorm.csv
done

echo ""
echo "Feature Extraction Complete"
echo ""