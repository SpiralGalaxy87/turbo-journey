int speedL = 0;
int speedR = 0;



task balanceArm()
{
	while(true)
	{
		if(vexRT[Btn7D] == 1)
		{
			speedL = -120;
			speedR = -120;
			if( 100 + SensorValue[armPotentL] <  SensorValue[armPotent])
			{
				speedR = speedR + 10;
				speedL = -120;
			}
			else if(100 + SensorValue[armPotentL] > SensorValue[armPotent])
			{
				speedR = - 120;
				speedL = speedL + 10;
			}
			else
			{
				speedR = -120;
				speedL = -120;
			}
			motor[armMotorL] = speedL;
			motor[armMotorR] = speedR;

		}
		if(vexRT[Btn7U] == 1)
		{
			speedL = 120;
			speedR = 120;
			if( 100 + SensorValue[armPotentL]  <  SensorValue[armPotent])
			{
				speedR = 120;
				speedL = speedL - 10;
			}
			else if(100 + SensorValue[armPotentL] > SensorValue[armPotent])
			{
				speedR = speedR - 10;
				speedL = 120;
			}
			else
			{
				speedR = 120;
				speedL = 120;

			}
			motor[armMotorL] = speedL;
			motor[armMotorR] = speedR;
		}
		else
		{
			motor[armMotorL] = 0;
			motor[armMotorR] = 0;
		}

		wait1Msec(200);
	}
}
