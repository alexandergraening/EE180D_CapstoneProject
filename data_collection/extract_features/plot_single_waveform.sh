if [ "$#" -ne 1 ]; then
		echo "Please enter the name of the file you wish to plot"
		exit
	fi

cp $1 test.csv
gnuplot testing_gnuplot_script
sudo cp test.png /var/www/html/graphics
rm test.csv
