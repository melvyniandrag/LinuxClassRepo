#Fork bombs

A bit of fun stuff to get your feet wet with how processes are created in Linux. You can create processes with teh exec() function or with the fork() function. A popular funny little "hack" thing to do to your friends is to fork bomb their machine. 

We've already seen forks wehn we run a process with & sending it to the background. We've also seen forks when we have a terminal open and type 'bash'. 

Fork bomb in bash 

Fork bomb in Python


bash fork bomb

:(){ :|: & };:

func(){ func|func & };func
