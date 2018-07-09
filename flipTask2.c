
task flipTask()
{
	while(true)
	{
		if(vexRT[Btn8R] == 1)
		{
			if(SensorValue[flipPotent] > 1100)
			{
				motor[coneFlip] = -127;
				wait1Msec(100);
				while(SensorValue[flipPotent] > 300)
				{
					motor[coneFlip] = -127;
					wait1Msec(10);
				}
				motor[coneFlip] = -20;
			}

			else
			{
				motor[coneFlip] = 127;
				wait1Msec(100);
				while(SensorValue[flipPotent] < 3200)
			  {
			  	motor[coneFlip] = 127;
			  	wait1Msec(10);
        }
				motor[coneFlip] = 20;
			}
		}
	}
}
