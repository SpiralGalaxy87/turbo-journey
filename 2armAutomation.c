task stackerLift()
{
	while (true)
	{
		if(moveStacker == 1)
		{
			motor[coneStack] = 127;
		}
		else if(moveStacker == -1)
		{
			motor[coneStack] = -127;
		}
		else
		{
			motor[coneStack] = 0;
		}
	}
}

task flipperLift()
{
	while (true)
	{
		if(moveFlipper == 1)
		{
			motor[coneFlip] = 127;
		}
		else if(moveFlipper == -1)
		{
			motor[coneFlip] = -127;
		}
		else
		{
			motor[coneFlip] = 0;
		}

	}
}

task lift()
{
	while(true)
	{
		if(vexRT[Btn8U] == 1 || moveArm == 1)
		{
			motor[armMotor] = 120;
		}
		else if(vexRT[Btn8D] == 1)
		{
			motor[armMotor] = -120;
		}
		else if(vexRT[Btn8R] == 1)
		{
			raiseArm = SensorValue[armPotent];

			while(SensorValue[armPotent] < raiseArm + 20)
			{
				motor[armMotor] = -127;
			}
		}
		else if (vexRT[Btn5U] != 1)
		{
			motor[armMotor] = 0;
		}
	}
}

int counter = 0;
task first ()
{
	while (true)
	{
		if(vexRT[Btn5U] == 1)
		{
			//flipCone();
			//|| SensorValue[armPotent] < 2200);
			if(coneCount == 5)
			{
				motor[armMotor] = 127;
				while(counter < 10)
				{
					if(SensorValue[coneSensor] > 14)
					{
						counter++;
					}
					else
					{
						counter = 0;
					}

				}
				counter = 0;
				motor[armMotor] = 0;
				wait1Msec(10);

				//lowerArm = SensorValue[armPotent];

				/*while(SensorValue[armPotent] > lowerArm - 5)
				{
				motor[armMotor] = -127;
				}*/

				motor[armMotor] = 0;
				wait1Msec(10);

				armUp(120, 4000);
				wait1Msec(1000);
				armDown(70, 900);

			}

			else
			{
				armUp(120, 4000);

				wait1Msec(1000);

				armDown(70, 900);

				moveArm = 1;
				waitUntil(SensorValue[armPotent] < 3100);
				moveArm = 0;
				wait1Msec(10);
			}
		}
	}
}

task countCones()
{
	while (true)
	{
		if (vexRT[Btn7R] == 1)
		{
			coneCount = 5;
			wait1Msec(50);
		}

		else if (vexRT[Btn7L] == 1)
		{
			coneCount = 0;
			wait1Msec(50);
		}

		else if (vexRT[Btn7D] == 1)
		{
			place = 0;
			wait1Msec(50);
		}

		else if (vexRT[Btn8R] == 1)
		{
			place = 1;
			wait1Msec(50);
		}
	}
}
