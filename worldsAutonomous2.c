task matchAuton()
{
	switch(autonChoosen)
	{
	case 0:
		{
			//Left (Red): MB Goal Auton
			//Picks up MB Goal on the left and
			//drops it in the 20pt zone
			deployRobot();

			noSensor = 1;

			wait1Msec(1000);

			//mGoalDown(127);

			forwardDistance(47,100);

			//forwardDistance(5,40);

			mGoalUp(127);

			wait1Msec(100);

			stack = 1;

			backwardDistance(44,65);

			turnGyros(140, 55, -1);

			forwardDistance(4, 127);

			turnGyros(220, 55, -1);

			forwardDistance(35, 127);

			mGoalDown(127);

			backwardDistance(16, 127);

			SensorValue[turnGyro] = 0;
			wait1Msec(500);

			turnGyros(100, 127, -1);

			forwardDistance(10, 127);

			turnGyros(200, 127, -1);

			forwardDistance(25, 127);

			break;
		}

	case 1:
		{
			//Right (blue): MB Goal Auton
			//Picks up MB Goal on the left and
			//drops it in the 20pt zone

			deployRobot();

			noSensor = 1;

			//mGoalDown(127);

			forwardDistance(47,100);

			//forwardDistance(3,40);

			mGoalUp(127);

			wait1Msec(100);

			stack = 1;

			backwardDistance(48,65);

			turnGyros(140, 55, 1);

			forwardDistance(4, 127);

			turnGyros(220, 55, 1);

			forwardDistance(35, 127);

			mGoalDown(127);

			backwardDistance(14, 127);

			SensorValue[turnGyro] = 0;
			wait1Msec(500);

			turnGyros(100, 127, 1);

			forwardDistance(10, 127);

			turnGyros(200, 127, 1);

			forwardDistance(25, 127);

			break;
		}

	case 2:
		{
			//FORWARD: 20pt Autonomous
			//Faces forward to pick up either MB Goal
			//Refer to EN entry for clearer plan

			speedStack = 1;

			forwardDistance(2, 120);

			armOn = 1;
			wait1Msec(500);

			armOn = -1;
			waitUntil(SensorValue[armPotent] > 3350);
			armOn = -2;
			stackerOn = -2;
			wait1Msec(1300);

			noSensor = 1;

			backwardDistance(1, 120);

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

			//mGoalDown(120);

			forwardDistance(37, 120);

			//mGoalUp(120);

			//turnGyros(60, 120, -1);

			motor[MRmotor3] = -120;
			motor[TBRmotor2] = -120;
			motor[MLmotor8] = 120;
			motor[TBLmotor9] = 120;
			wait1Msec(1000);

			zeroMotors();

			forwardDistance(10, 120);

			//mGoalDown(120);

			backwardDistance(10, 120);

			motor[MRmotor3] = 120;
			motor[TBRmotor2] = 120;
			motor[MLmotor8] = -120;
			motor[TBLmotor9] = -120;
			wait1Msec(275);

			zeroMotors();

			//turnGyros(10, 60, 1);

			forwardDistance(7, 120);

			mGoalUp(120);

			stack = 1;

			backwardDistance(50, 60);

			turnGyros(210, 60, 1);

			forwardDistance(32, 120);

			mGoalDown(120);

			backwardDistance(22,60);

			break;
		}

	case 3:
		{
			deployRobot();

			forwardDistance(35, 127);

			mGoalUp(127);//grab mobile goal

			wait1Msec(100);

			backwardDistance(40,127);//was 50

			turnGyros(140, 50, 1);

			forwardDistance(4, 127);

			turnGyros(230, 50, 1);

			forwardDistance(35, 127); //forward into 10 point zone

			mGoalDown(127);

			backwardDistance(14, 127);

			SensorValue[turnGyro] = 0;
			wait1Msec(500);

			turnGyros(100, 127, 1);

			forwardDistance(10, 127);

			turnGyros(200, 127, 1);

			forwardDistance(25, 127);

			break;
		}

	case 4:
		{
			//SKILLS: 62 point program

			//startTask(auton);

			mGoalDown(120);

			forwardDistance(33,60);

			mGoalUp(120);

			wait1Msec(1000);

			backwardDistance(12,45);

			turnGyros(210, 60, 1);

			forwardDistance(39, 120);

			mGoalDown(120);

			backwardDistance(20,60);

			straightenUp(2000);

			backwardDistance(3,60);

			turnGyros(100, 60, -1);

			forwardDistance(2, 60);

			turnGyros(202, 50, -1); //205

			forwardDistance(55, 80);

			mGoalUp(120);

			turnGyros(211, 60, -1);

			forwardDistance(50, 120);

			mGoalDown(120);

			backwardDistance(21, 60);

			straightenUp(1500);

			backwardDistance(1, 60);

			turnGyros(100, 60, -1);

			forwardDistance(18, 60);//9

			turnGyros(200, 60, -1);

			forwardDistance(30, 70);

			mGoalUp(120);

			backwardDistance(12,45);

			SensorValue[turnGyro] = 0;
			wait1Msec(500);

			turnGyros(195, 60, 1);

			forwardDistance(22, 70);

			mGoalDown(120);

			backwardDistance(15,60);

			straightenUp(1500);

			backwardDistance(1, 60);

			turnGyros(200, 60, -1);

			forwardDistance(60, 80);

			mGoalUp(120);

			//turnGyros(211, 60, -1);

			forwardDistance(35, 100);

			mGoalDown(120);

			backwardDistance(20, 60);

			SensorValue[turnGyro] = 0;
			wait1Msec(500);

			turnGyros(120, 100, 1);

			forwardDistance(20, 120);
			break;
		}

	case 5:
		{
			//Right (Red) W/ CONES: MB Goal Auton
			//Picks up MB Goal on the left and
			//drops it in the 20pt zone

			deployRobot();

			noSensor = 1;

			//mGoalDown(127);

			forwardDistance(47,100);

			//forwardDistance(3,40);

			mGoalUp(127);

			wait1Msec(100);

			stack = 1;

			turnGyros(10, 55, -1);

			backwardDistance(48,65);

			turnGyros(140, 55, 1);

			forwardDistance(4, 127);

			turnGyros(220, 55, 1);

			forwardDistance(35, 127);

			mGoalDown(127);

			backwardDistance(14, 127);

			SensorValue[turnGyro] = 0;
			wait1Msec(500);

			turnGyros(100, 127, 1);

			forwardDistance(10, 127);

			turnGyros(200, 127, 1);

			forwardDistance(25, 127);

			break;
		}
	}
}
