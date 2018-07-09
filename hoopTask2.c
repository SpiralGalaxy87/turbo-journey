
task hoopTask()
{
	while(true)
	{
		if(vexRT[Btn8R] == 1 || hoopOn == 1)
		{
			if(SensorValue[flipPotent] > 1700)
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
				while(SensorValue[flipPotent] < 2500)
			  {
			  	motor[coneFlip] = 127;
			  	wait1Msec(10);
        }
				motor[coneFlip] = 20;
			}
			hoopOn = 0;
		}
	}
}
