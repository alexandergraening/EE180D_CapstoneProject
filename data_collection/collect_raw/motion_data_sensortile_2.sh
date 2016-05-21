#!/bin/sh
#

# Enter Device MAC Address and output file name as required
#
# Note 10 second acquisition period
#

gatttool -b C0:83:49:30:4B:4D -t random --char-write-req --handle=0x0012 --value=0100 --listen > sensor_data_stream_2.dat  &

echo 'remove C0:83:2B:31:5A:48' | bluetoothctl
echo 'remove C0:83:2B:31:5A:48' | bluetoothctl

sleep 10 

pkill gatttool

