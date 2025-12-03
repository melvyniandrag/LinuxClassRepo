# set terminal dumb size 60,60
set terminal dumb
set datafile separator "\t"
set size ratio 1

dataset = ARG1
filename = ARG2

cmd = sprintf("awk -F'\t' '$1 == \"%s\" {print}' %s", dataset, filename)
plot "<".cmd using 2:3 with points title dataset