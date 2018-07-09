int autonChoosen = 0;
float encodercountperRotation = 360.0;
int coneCount = 0;
int pick = 0;
int place = 0;
int raiseArm = 0;
int lowerArm = 0;

int hoopOn = 0;
int armOn = 0;
int stackerOn = 0;

//ALL MEASUREMENTS ARE IN INCHES//

float wheelDiameter = 4;
float wheelCircumference = wheelDiameter*(PI);
float distanceBetweenWheels = 15.0;

void zeroMotors()
{
	motor[MRmotor3] = 0;
	motor[TBRmotor2] = 0;
	motor[MLmotor8] = 0;
	motor[TBLmotor9] = 0;
}

void powerAllMotors(int speed, int waitTime)
{
	//Power Base Motors Using Time
	motor[MRmotor3] = speed;
	motor[TBRmotor2] = speed;
	motor[MLmotor8] = speed;
	motor[TBLmotor9] = speed;

	wait1Msec(waitTime);
	zeroMotors();
}

void forwardDistance (int distance, int speed)
{
	//Power Base Motors Using Encoders
	SensorValue[left] = 0;
	SensorValue[right] = 0;

	float encodercount = (distance/wheelCircumference)*encodercountperRotation;

	int straightening = 0;
	if (speed < 80)
	{
		straightening = 15;
	}
	if (speed == 80 || speed > 80)
	{
		straightening = 20;
	}

	while (abs(SensorValue[left]) < encodercount)
	{
		if(abs(SensorValue[left]) == abs(SensorValue[right]))
		{
			motor[MRmotor3] = speed;
			motor[TBRmotor2] = speed;
			motor[MLmotor8] = speed;
			motor[TBLmotor9] = speed;
		}

		else if(abs(SensorValue[left]) > abs(SensorValue[right]))
		{
			motor[MRmotor3] = speed - straightening;
			motor[TBRmotor2] = speed - straightening;
			motor[MLmotor8] = speed;
			motor[TBLmotor9] = speed;
		}

		else if(abs(SensorValue[left]) < abs(SensorValue[right]))
		{
			motor[MRmotor3] = speed;
			motor[TBRmotor2] = speed;
			motor[MLmotor8] = speed - straightening;
			motor[TBLmotor9] = speed - straightening;
		}
		wait1Msec(50);
	}
	zeroMotors();
}

void backwardDistance (int distance, int speed)
{
	//Power Base Motors Using Encoders
	SensorValue[left] = 0;
	SensorValue[right] = 0;

	speed = speed * -1;

	float encodercount = (distance/wheelCircumference)*encodercountperRotation;

	int straightening = 0;
	if (speed < 80)
	{
		straightening = 15;
	}
	if (speed == 80 || speed > 80)
	{
		straightening = 20;
	}

	while (abs(SensorValue[left]) < encodercount)
	{
		if(SensorValue[left] == SensorValue[right])
		{
			motor[MRmotor3] = speed;
			motor[TBRmotor2] = speed;
			motor[MLmotor8] = speed;
			motor[TBLmotor9] = speed;
		}

		else if(abs(SensorValue[left]) > abs(SensorValue[right]))
		{
			motor[MRmotor3] = speed + straightening;
			motor[TBRmotor2] = speed + straightening;
			motor[MLmotor8] = speed;
			motor[TBLmotor9] = speed;
		}

		else if(abs(SensorValue[left]) < abs(SensorValue[right]))
		{
			motor[MRmotor3] = speed;
			motor[TBRmotor2] = speed;
			motor[MLmotor8] = speed + straightening;
			motor[TBLmotor9] = speed + straightening;
		}
		wait1Msec(50);
	}

	zeroMotors();
}

float encClicks = 0;
void turnEncoders (float angle, int speed, int direction)
{
	wait1Msec(100);
	SensorValue[left] = 0;

	float circumference2;
	float rotat;
	circumference2 = distanceBetweenWheels * PI;
	rotat = circumference2/wheelCircumference;
	encClicks = (rotat * (angle/360.0)) * 360.0;
	wait1Msec(20);

	motor[MRmotor3] = (-speed) * direction;
	motor[TBRmotor2] = (-speed) * direction;
	motor[MLmotor8] = speed * direction;
	motor[TBLmotor9] = speed * direction;
	waitUntil(abs(SensorValue [left]) > (encClicks * 0.4));

	speed = 50;

	motor[MRmotor3] = (-speed) * direction;
	motor[TBRmotor2] = (-speed) * direction;
	motor[MLmotor8] = speed * direction;
	motor[TBLmotor9] = speed * direction;
	waitUntil(abs(SensorValue [left]) > (encClicks * 0.7));

	speed = 40;

	motor[MRmotor3] = (-speed) * direction;
	motor[TBRmotor2] = (-speed) * direction;
	motor[MLmotor8] = speed * direction;
	motor[TBLmotor9] = speed * direction;
	waitUntil(abs(SensorValue [left]) > (encClicks));

	zeroMotors();

	//Note:
	//If you input an angle of 180 into this
	//function the output will be:
	//float encClicks = 675;
}

void turnGyros (int angle, int speed, int direction)
{
	wait1Msec(100);
	SensorValue[left] = 0;

	int gyroClick = angle * 10;
	wait1Msec(20);

	motor[MRmotor3] = speed * direction;
	motor[TBRmotor2] = speed * direction;
	motor[MLmotor8] = (-speed) * direction;
	motor[TBLmotor9] = (-speed) * direction;
	waitUntil(abs(SensorValue[turnGyro]) > gyroClick );

	speed = 30;

	motor[MRmotor3] = speed * (-direction);
	motor[TBRmotor2] = speed * (-direction);
	motor[MLmotor8] = (-speed) * (-direction);
	motor[TBLmotor9] = (-speed) * (-direction);
	waitUntil(abs(SensorValue [turnGyro]) < gyroClick );

	zeroMotors();
}

void straightenUp(int time)
{
	powerAllMotors(30, time);

	motor[MRmotor3] = 0;
	motor[TBRmotor2] = 0;
	motor[MLmotor8] = 50;
	motor[TBLmotor9] = 50;
	wait1Msec(800);

	zeroMotors();

	motor[MRmotor3] = 50;
	motor[TBRmotor2] = 50;
	motor[MLmotor8] = 0;
	motor[TBLmotor9] = 0;
	wait1Msec(800);

	zeroMotors();

	SensorValue[turnGyro] = 0;
	wait1Msec(500);
}

void mGoalDown(int speed)
{
	motor[mGoalIntake] = speed;
	waitUntil(SensorValue[oranges] > 4000);//was 100
	motor[mGoalIntake] = 0;
}

void mGoalUp(int speed)
{
	motor[mGoalIntake] = -speed;
	waitUntil(SensorValue[oranges] < 2200); //was 2200
	motor[mGoalIntake] = 0;
}

void armDown(int speed, int sensorVal)
{
	motor[coneStack] = -speed;
	waitUntil(SensorValue[stackPotent] < sensorVal);
	motor[coneStack] = 0;
	wait1Msec(100);
}

void armUp(int speed, int sensorVal)
{
	motor[coneStack] = speed;
	waitUntil(SensorValue[stackPotent] > sensorVal);
	motor[coneStack] = 0;
	wait1Msec(100);
}

void moveLift(int height)
{
	if(height > SensorValue[armPotent])
	{
		armOn = -1;
		waitUntil(SensorValue[armPotent] > height);
		armOn = 0;
		wait1Msec(100);
	}
	else
	{
		armOn = 1;
		waitUntil(SensorValue[armPotent] < height);
		armOn = 0;
		wait1Msec(100);
	}

}
void flipCone ()
{
	if(SensorValue[flipPotent] > 1100)
	{
		motor[coneFlip] = -127;
		while(SensorValue[flipPotent] > 400)
		{
			motor[coneFlip] = -127;
			wait1Msec(10);
		}
		motor[coneFlip] = -20;
		wait1Msec(10);
	}

	else
	{
		motor[coneFlip] = 127;
		while(SensorValue[flipPotent] < 3200)
		{
			motor[coneFlip] = 127;
			wait1Msec(10);
		}
		motor[coneFlip] = 20;
		wait1Msec(10);
	}
}

void retract (int level)
{
	raiseArm = SensorValue[armPotent];

	//driver load level
	if(level == 1)
	{
		if(SensorValue[armPotent] > 4000)
		{
			//	motor[armMotor] = 127;
			waitUntil(SensorValue[armPotent] > raiseArm + 5);
			//			motor[armMotor] = 0;
			wait1Msec(10);
		}

		armDown(70, 900);

		//		motor[armMotor] = -127;
		waitUntil(SensorValue[armPotent] < 10); //driver load level
		//		motor[armMotor] = 0;
		wait1Msec(10);
	}

	//ground level
	else
	{
		if(SensorValue[armPotent] < 3700)
		{
			//		motor[armMotor] = 127;
			waitUntil(SensorValue[armPotent] > raiseArm + 5);
			//		motor[armMotor] = 0;
			wait1Msec(10);
		}

		armDown(70, 900);

		//motor[armMotor] = -127;
		waitUntil(SensorValue[armPotent] < 10); //driver load level
		//motor[armMotor] = 0;
		wait1Msec(10);
	}
}

void stackCone()
{
			stackerOn = 1;
		  waitUntil(SensorValue[stackPotent] > 3700 );
		  stackerOn = 0;

		  wait1Msec(700);

		  stackerOn = -1;
		  waitUntil(SensorValue[stackPotent] < 700 && SensorValue[stackPotent] > 500);
		  stackerOn = 0;
}

void deployRobot()
{
	armOn = 1;
	wait1Msec(500);

	armOn = -1;
	waitUntil(SensorValue[armPotent] > 3350);
	armOn = -2;
	stackerOn = -2;
	wait1Msec(1300);
	hoopOn = 1;
	armOn = 0;
	stackerOn = 0;
	wait1Msec(200);
	stackerOn = 1;
	waitUntil(SensorValue[stackPotent] > 200);
	stackerOn = 0;
	wait1Msec(500);

	/*motor[coneStack] = -127;
	waitUntil(SensorValue[stackPotent] < 400);
	motor[coneStack] = 0;
	wait1Msec(10);*/

	/*motor[armMotor] = 127;
	waitUntil(SensorValue[armPotent] > 3400); //driver load level
	motor[armMotor] = 0;
	wait1Msec(10);*/

	//motor[coneStack] = -127;
	//waitUntil(SensorValue[stackPotent] < 500);
	//motor[coneStack] = 0;
	//wait1Msec(1000);

	//flipCone();

	//	motor[armMotor] = 0;
	wait1Msec(100);
}
