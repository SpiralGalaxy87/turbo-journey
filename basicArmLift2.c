
task basicArmLift()
{
	while(true)
	{
		if(vexRT[Btn5D] == 1)
		{
		  motor[armMotorR] = -120;
			motor[armMotorL] = -120;
		}
		else if(vexRT[Btn5U] == 1)
		{
			motor[armMotorR] = 120;
			motor[armMotorL] = 120;
		}
		else if( armOn == 1)
		{
			motor[armMotorR] = 120;
			motor[armMotorL] = 120;
		}
		else if( armOn == -1)
		{
			motor[armMotorR] = -120;
			motor[armMotorL] = -120;
		}
		else if(armOn == -2)
		{
			motor[armMotorR] = -100;
			motor[armMotorL] = -100;
		}
		else
		{
			motor[armMotorR] = 0;
			motor[armMotorL] = 0;
		}
	}
}
