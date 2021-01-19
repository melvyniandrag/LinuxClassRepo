$ grep "$" grepnumbers.txt
a1
a
A
aA
AA
123A
1a
^a
5
6
7
B
C
Z
$a
$b
$
+
+a

$ grep "^[0-9]+" grepnumbers.txt
$ grep "^[a-z]" grepnumbers.txt
a1
a
aA
$ grep "^[A-Z]" grepnumbers.txt
A
AA
B
C
Z
$ grep "^{5,}" grepnumbers.txt
$ grep "{5,}" grepnumbers.txt
