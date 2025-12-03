
0. First install dependencies `apt install gnuplot`

0. https://en.wikipedia.org/wiki/Datasaurus_dozen

1. Download the data file
wget https://github.com/melvyniandrag/LinuxClassRepo/blob/master/FunStuff/DatasaurusDozen.tsv


2. First talk about awk.
Awk works lik


awk and the datasaurus dozen
```
  320  gnuplot -p -e 'set terminal dumb size 60,60; set datafile separator "\t"; set size ratio 1; plot "< awk -F\"\t\" '\''$1 ~ /^bullseye/ {print} '\'' DatasaurusDozen.tsv" using 2:3 with points'
  321  gnuplot -p -e 'set terminal dumb size 60,60; set datafile separator "\t"; set size ratio 1; plot "< awk -F\"\t\" '\''$1 ~ /^bullseye/ {print} '\'' DatasaurusDozen.tsv" using 2:3 with points'
  322  gnuplot -p -e 'set terminal dumb size 60,60; set datafile separator "\t"; set size ratio 1; plot "< awk -F\"\t\" '\''$1 ~ /^dino/ {print} '\'' DatasaurusDozen.tsv" using 2:3 with points'
  325  gnuplot -p -e 'set terminal dumb size 60,60; set datafile separator "\t"; set size ratio 1; plot "< awk -F\"\t\" '\''$1 ~ /^dino/ {print} '\'' DatasaurusDozen.tsv" using 2:3 with points'
  326  gnuplot -p -e 'set terminal dumb size 60,60; set datafile separator "\t"; set size ratio 1; plot "< awk -F\"\t\" '\''$1 ~ /^x_shape/ {print} '\'' DatasaurusDozen.tsv" using 2:3 with points'
```


BEGIN 
{ 
	total_x = 0
	total_y = 0
}
{
	x[NR] = $2
	y[NR] = $3

	total_x += $2
	total_y += $3
}
END
{
	mean_x = total_x / NR
	mean_y = total_y / NR

	sum_sq_diff_x = 0
	sum_sq_diff_y = 0
	covariance_x_y_products = 0

	for (i = 1; i <= NR; i++)
	{
		diff_x = x[i] - mean_x
		sum_sq_diff_x += diff_x * diff_x

		diff_y = y[i] - mean_y
		sum_sq_diff_y += diff_y * diff_y

		covariance_x_y_products = diff_x * diff_y
	} 

	variance_x = sum_sq_diff_x / NR
	variance_y = sum_sq_diff_y / NR

	std_dev_x = sqrt(variance_x)
	std_dev_y = sqrt(variance_y)

	covariance_x_y = covariance_x_y_products / (std_dev_x * std_dev_y)

	print "Avg x: ", mean_x
	print "Avg y: ", mean_y
	print "std dev x: ", std_dev_x
	print "std dev y: ", std_dev_y
	print "covariance: ", covariance_x_y 
}



plot_dataset.gp
```
# set terminal dumb size 60,60
set terminal dumb
set datafile separator "\t"
set size ratio 1

dataset = ARG1
filename = ARG2

cmd = sprintf("awk -F'\t' '$1 == \"%s\" {print}' %s", dataset, filename)
plot "<".cmd using 2:3 with points title dataset
```

wrapper.sh
```
tail -n +2 $1 | cut -f1 | sort -u | while read ds; do
        grep "^$ds" $1 > /tmp/dataset
        echo -e "\n\n****************************************************"
        echo -e "\n\nComputing statistics for dataset $ds"
        awk -f datasaurus_stats.awk /tmp/dataset
        gnuplot -p -c plot_dataset.gp $ds $1
        echo -e "\n\n****************************************************"
done
```

datasaurus_stats.awk
```
BEGIN {
        total_x = 0
        total_y = 0
}
{
        x[NR] = $2
        y[NR] = $3

        total_x += $2
        total_y += $3
}
END {
        mean_x = total_x / NR
        mean_y = total_y / NR

        sum_sq_diff_x = 0
        sum_sq_diff_y = 0
        covariance_x_y_products = 0

        for (i = 1; i <= NR; i++)
        {
                diff_x = x[i] - mean_x
                sum_sq_diff_x += diff_x * diff_x

                diff_y = y[i] - mean_y
                sum_sq_diff_y += diff_y * diff_y

                covariance_x_y_products += diff_x * diff_y
        }

        variance_x = sum_sq_diff_x / NR
        variance_y = sum_sq_diff_y / NR

        std_dev_x = sqrt(variance_x)
        std_dev_y = sqrt(variance_y)

        correlation = covariance_x_y_products / (NR * std_dev_x * std_dev_y)

        print "Avg x: ", mean_x
        print "Avg y: ", mean_y
        print "std dev x: ", std_dev_x
        print "std dev y: ", std_dev_y
        print "covariance: ", correlation
}

```

alternatively

```

{
    sx += $2
    sy += $3
    sxx += $2 * $2
    syy += $3 * $3
    sxy += $2 * $3
}
END {
    mx = sx / NR
    my = sy / NR
    varx = sxx / NR - mx * mx
    vary = syy / NR - my * my
    cov = sxy / NR - mx * my
    corr = cov / sqrt(varx * vary)

    print "Avg x:", mx
    print "Avg y:", my
    print "Std dev x:", sqrt(varx)
    print "Std dev y:", sqrt(vary)
    print "Covariance:", cov
    print "Correlation:", corr
}
```