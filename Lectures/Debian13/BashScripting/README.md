# Bash scripting

Goals:
arrays
-get num elements
-for loop over array elements
- bash arrays start at 0, zsh starts at 1. Verify this and include in lecture
- look at setopt KSH_ARRAYS, which I've read makes zsh behave like bash. How much does this change
  the behavior?
if
- diff ways to do if with [] [[]] flags like -z
- compare bash ifs vs ifs in diff shells. see some incompatibilites with diff shells

echo
- echo vs print. bash mostly uses echo, zsh has a more reliable built in print
- echo is inconsistent across systems, print in zsh is predictable
- printf "Hello\n" is consistent across platforms
- look at the portable echo in wicked cool shell scripts
