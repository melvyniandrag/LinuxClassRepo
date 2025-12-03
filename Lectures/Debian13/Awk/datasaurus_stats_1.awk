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