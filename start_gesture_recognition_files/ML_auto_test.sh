#This is the primary shell script to run my automated machine learning project
#
#Hardware requirements:
#	1. Linux system with bluetoothctl and gatttool
#	2. SensorTile running the ALLMEMS1 software as shown in the tutorials found here:
#			iot.ee.ucla.edu/UCLA-STMicro/index.php/Home
#			iot.ee.ucla.edu/UCLA-BeagleBone/index.php/Home
#
#Important file dependencies:
#	1. wait_for_verification.c
#	2. <text parsers> (Replace this!!!)
#	3. fann library
#	4. LiquidDSP library

#First ensure the sensorTile is disconnected from bluetoothctl. (Note: It would be a good idea to figure out how to change the automatic connection settings.)

bluetoothctl << @
disconnect C0:83:2b:31:5a:48
exit
@
gcc -o wait_for_verification wait_for_verification.c
gcc -o orientation_parser orientation_parser.c
gcc -o combined_orientation_parser combined_orientation_parser.c
gcc -o train_nn train_nn.c -lfann
gcc -o test_nn test_nn.c -lfann
echo "Starting Automated Machine Learning Orientation Detection Test Program"
echo ""
echo "Press enter after completing each instruction to continue."
echo "Note that carefully moving the SensorTile through the range of positions you want to count as each position during data collection will improve robustness of results."
echo "Please move the SensorTile to position 1"
./wait_for_verification
echo "Please keep the SensorTile in position 1"
./motion_data.sh -t 5 -f collectedData/orientation1.txt
# Collect data and process it.
echo "Data for Position 1 recorded"
echo "Please move the SensorTile to position 2"
./wait_for_verification
echo "Please keep the SensorTile in position 2"
./motion_data.sh -t 5 -f collectedData/orientation2.txt
# Collect data and process it.
echo "Data for Position 2 recorded"
echo "Please move the SensorTile to position 3"
./wait_for_verification
echo "Please keep the SensorTile in position 3"
./motion_data.sh -t 5 -f collectedData/orientation3.txt
echo "Data collection complete"
echo ""
./orientation_parser 1
./orientation_parser 2
./orientation_parser 3
./combined_orientation_parser
./process_data_for_excel.sh
echo ""
echo "Data processed"
echo "Training net"
./train_nn
echo "Net trained"
echo "Testing:"
while :
do
	./motion_data.sh -t 1 -f collectedData/orientation0.txt
	./orientation_parser 0
	./test_nn
	echo "Press enter to continue"
	./wait_for_verification
done
