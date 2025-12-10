# Refactor Code With Vim projects

## Refactor switch expression -> switch
Many languages have something like a switch expression. It looks like this:
```
public ApplicationPage GetPageFromState(int state)
{
	return state switch
	{
		States.A => new PageA(),
		States.B1 => new PageB(),
		States.B2 => new PageB(),
		States.C => new PageC(),
		_ => throw new Exception("exception!")
	};
}
```

In the code above there may be 50 states. What if you need to refactor that code into a switch statement?

```
public void DoSomethingBasedOnState(int state)
{
	switch(state)
	{
		case States.A:
			//TODO
			break;
		case States.B1:
			//TODO
			break;

		<ETC>

		default:
			//TODO
			break;
	}
}
```

How would you do this refactor and be sure that you didn't make a typo? There could potentially be 200 states in your switch. You don't want to type out all those cases... it will take 2 hours and you'll make a mistake. Probably you'll forget a state or maybe make a bunch of annoying typos.