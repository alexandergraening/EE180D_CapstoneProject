
echo "Get ready to practice your freethrows!"
echo ""

for i in $(seq 1 10);
do
echo "About to Acquire dataset $i, press Enter to start"
./wait_for_verification
echo "In progress..."
./Dual_SensorTile_Acquire.sh -t 3
sleep 13
cp motion_data_output_1.csv ../raw/mdo_${i}w.csv
cp motion_data_output_2.csv ../raw/mdo_${i}e.csv
echo "Done"
echo ""
done

echo "Please prepare to break the freethrow into multiple parts"
for i in $(seq 1 5);
do
echo "Press enter, then raise the ball above your head."
./wait_for_verification
./Dual_SensorTile_Acquire.sh -t 3
sleep 13
cp motion_data_output_1.csv ../raw/firstPartial_${i}w.csv
cp motion_data_output_2.csv ../raw/firstPartial_${i}e.csv
echo "Done"
echo ""
done

for i in $(seq 1 5);
do
echo "Raise the ball above your head, then press enter, then shoot."
./wait_for_verification
./Dual_SensorTile_Acquire.sh -t 3
sleep 13
cp motion_data_output_1.csv ../raw/secondPartial_${i}w.csv
cp motion_data_output_2.csv ../raw/secondPartial_${i}e.csv
echo "Done"
echo ""
done

echo "Data collection completed"
