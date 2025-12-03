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