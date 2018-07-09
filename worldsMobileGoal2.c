task mobileGoalTask()
{
	int buttonToggleState = 0;
	int buttonPressed = 0;

	while(true)
	{
		if(vexRT[Btn7U] == 1 && SensorValue[oranges] > 1600)
		{
		  motor[mGoalIntake] = -40;
		}
		else if(vexRT[Btn7D] == 1 && SensorValue[oranges] < 4000)
		{
			motor[mGoalIntake] = 40;
		}
		else
		{
			motor[mGoalIntake] = 0;
		}

		if(vexRT[Btn6U] == 1)
		{
			if( buttonPressed == 0)
			{
				buttonToggleState = 1 - buttonToggleState;
				buttonPressed = 1;
			}
			else
			{
				buttonPressed = 0;
			}

			if(buttonToggleState == 1)
			{
				motor[mGoalIntake] = -120;
				wait1Msec(100);
				waitUntil(SensorValue[oranges] < 2000);
				motor[mGoalIntake] = 0;
			}

			else if(buttonToggleState == 0)
			{
				motor[mGoalIntake] = 120;
				wait1Msec(100);
				waitUntil(SensorValue[oranges] > 4000);
				motor[mGoalIntake] = 0;
			}
		}
	}
}
