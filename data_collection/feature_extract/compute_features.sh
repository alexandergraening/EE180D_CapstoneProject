echo "Beginning Feature Computation"
echo ""

for i in $(seq 1 16);
do
cp waveform_peaks_output_x.csv ../data_files/mdo_${i}_Px.csv
cp waveform_peaks_output_y.csv ../data_files/mdo_${i}_Py.csv
cp xcorr_waveform_peaks_output_x.csv ../data_files/mdo_${i}_xcorr_Pxy.csv
cp xcorr_waveform_peaks_output_y.csv ../data_files/mdo_${i}_xcorr_Pyx.csv
cp xcorr_extrema.dat ../data_files/mdo_${i}_xcorr_extrema.dat
./bubble_sort_norm ../data_files/mdo_${i}_xcorr_Pxy.csv ../data_files/mdo_${i}_xcorr_Pyx.csv ../data_files/mdo_${i}_xcorr_Pxy_sortnorm.csv ../data_files/mdo_${i}_xcorr_Pyx_sortnorm.csv
./bubble_sort_norm ../data_files/mdo_${i}_Px.csv ../data_files/mdo_${i}_Py.csv ../data_files/mdo_${i}_Px_sortnorm.csv ../data_files/mdo_${i}_Py_sortnorm.csv
done

echo ""
echo "Feature Extraction Complete"
echo ""
