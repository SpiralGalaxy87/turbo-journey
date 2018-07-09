int speedStack = 0;
int armLevel = 0;

task basicStackerLift()
{
	while(true)
	{
		if(vexRT[Btn8U] == 1)
		{
			armLevel = SensorValue[armPotent];

		  motor[coneStack] = 127;
		  waitUntil(SensorValue[stackPotent] > 3700 );
		  motor[coneStack] = 0;

		  armOn = 1;
		  wait1Msec(200);
		  armOn = 0;
		  wait1Msec(700);

		  motor[coneStack] = -127;
		  waitUntil(SensorValue[stackPotent] < 700 && SensorValue[stackPotent] > 500);
		  motor[coneStack] = 0;

		  wait1Msec(100);

		  //hoopOn = 1;
	  }

	  else if((vexRT[Btn7UXmtr2] == 1 || stackerOn == 1) || vexRT[Btn6D])
		{
			motor[coneStack] = 127;
		}
		else if(vexRT[Btn7DXmtr2] == 1 || stackerOn == -1)
		{
			motor[coneStack] = -127;
		}
		else if( stackerOn == -2 )
		{
			if(speedStack == 0)
			{
				motor[coneStack] = -95;
			}

			else if(speedStack == 1)
			{
				motor[coneStack] = -127;
			}
		}
		else
		{
			motor[coneStack] = 0;
		}
	}
}
