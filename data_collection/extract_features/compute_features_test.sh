#This code is used to run feature extraction on a single set of data.

echo ""
echo "In compute_features_test.sh"
./compute_cross_correlation_peaks.sh ../data_files/mdo_0.csv
cp waveform_peaks_output_x.csv ../data_files/mdo_0_Px.csv
cp waveform_peaks_output_y.csv ../data_files/mdo_0_Py.csv
cp xcorr_waveform_peaks_output_x.csv ../data_files/mdo_0_xcorr_Pxy.csv
cp xcorr_waveform_peaks_output_y.csv ../data_files/mdo_0_xcorr_Pyx.csv
cp xcorr_extrema.dat ../data_files/mdo_0_xcorr_extrema.dat

./bubble_sort_norm ../data_files/mdo_0_xcorr_Pxy.csv ../data_files/mdo_0_xcorr_Pyx.csv ../data_files/mdo_0_xcorr_Pxy_sortnorm.csv ../data_files/mdo_0_xcorr_Pyx_sortnorm.csv

./bubble_sort_norm ../data_files/mdo_0_Px.csv ../data_files/mdo_0_Py.csv ../data_files/mdo_0_Px_sortnorm.csv ../data_files/mdo_0_Py_sortnorm.csv

echo ""
