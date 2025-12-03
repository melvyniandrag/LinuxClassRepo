tail -n +2 $1 | cut -f1 | sort -u | while read ds; do
        grep "^$ds" $1 > /tmp/dataset
        echo -e "\n\n****************************************************"
        echo -e "\n\nComputing statistics for dataset $ds"
        awk -f datasaurus_stats.awk /tmp/dataset
        gnuplot -p -c plot_dataset.gp $ds $1
        echo -e "\n\n****************************************************"
done