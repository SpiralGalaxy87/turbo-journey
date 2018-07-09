int armHeight = 3300;//lowest;
int toggle = 1;

void setArmHeight()
{
	switch(toggle)
	{
	case 1:
		{
			armHeight = 3300;//lowest
			break;
		}

	case 2:
		{
			armHeight = 2870;//auto loader
			break;
		}

	case 3:
		{
			armHeight = 2400;// stationary -- 25"
			break;
		}

	case 4:
		{
			armHeight = 1700;// max height
			break;
		}

	}
}

task armControl()
{
	while (true)
	{

		if(vexRT[Btn5UXmtr2] == 1 && toggle < 4)
		{
			toggle++;
			setArmHeight();
			moveLift(armHeight);
		}
		else if(vexRT[Btn5DXmtr2] == 1 && toggle > 0)
		{
			toggle--;
			setArmHeight();
			moveLift(armHeight);
		}
		else if(vexRT[Btn8UXmtr2] == 1 && toggle > 0)
		{
			toggle = 2;
			setArmHeight();
			moveLift(armHeight);
		}

	}
}
