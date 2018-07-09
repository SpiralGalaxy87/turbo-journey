int noSensor = 0;
int stack = 0;
task theER()//these functions are for emergencies
{
	while(true)
	{
		if(vexRT[Btn8UXmtr2] == 1){
			noSensor = 0;
		}
		else if(vexRT[Btn8DXmtr2] == 1){
			noSensor = 1;
		}

		if(stack == 1)
		{
			stackCone();
			stack = 0;
		}
	}
}

task twistAndLift()
{
	while(true)
	{
		if(vexRT[Btn8L] == 1)
		{
			hoopOn = 1;
			wait1Msec(200);
			stackerOn = 1;
			waitUntil(SensorValue[stackPotent] > 1000);
			stackerOn = 0;
		}
		else if((SensorValue(coneTouch) == 1 && noSensor == 0) || vexRT[Btn7L] == 1)
		{
			armOn = -1;
			waitUntil(SensorValue[armPotent] > 3350);
			armOn = -2;
			stackerOn = -2;
			wait1Msec(450);
			hoopOn = 1;
			armOn = 0;
			stackerOn = 0;
			wait1Msec(200);
			stackerOn = 1;
			waitUntil(SensorValue[stackPotent] > 200);
			stackerOn = 0;
			wait1Msec(500);
		}
	}
}
