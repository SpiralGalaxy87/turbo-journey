task drivingTask()
{
	while(true)
	{
			motor[MLmotor8] = vexRT[Ch3];
			motor[TBLmotor9] = vexRT[Ch3];
			motor[MRmotor3] = vexRT[Ch2];
			motor[TBRmotor2] = vexRT[Ch2];

		if (vexRT[Btn6UXmtr2] == 1)
		{
			zeroMotors();
			forwardDistance(10, 100);
		}
		else if (vexRT[Btn6DXmtr2] == 1)
		{
			zeroMotors();
			backwardDistance(10, 100);
		}
	}
}
