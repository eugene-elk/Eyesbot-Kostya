#pragma config(Sensor, S1,     s1,             sensorTouch)
#pragma config(Sensor, S3,     ,               sensorSONAR)
#pragma config(Sensor, S4,     ,               sensorSONAR)
#pragma config(Motor,  motorA,          mA,            tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          mB,            tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          mC,            tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*/


void rotate_left()
{
	motor[mA] = -50;
	motor[mB] = -50;
	motor[mC] = -50;
}

void rotate_right()
{
	motor[mA] = 50;
	motor[mB] = 50;
	motor[mC] = 50;
}

void omni_stop()
{
	motor[mA] = 0;
	motor[mB] = 0;
	motor[mC] = 0;
}

void drive_right()
{
	motor[mA] = -25;
	motor[mB] = 50;
	motor[mC] = -50;
}


void drive_left()
{
	motor[mA] = 50;
	motor[mB] = -50;
	motor[mC] = 25;
}

task main()
{
	ubyte joystick[4];
	while(true) {
		if(cCmdMessageGetSize(mailbox1) != 0) {
			cCmdMessageRead(joystick, 4, mailbox1);
			ClearMessage();
		}
		int rotate = joystick[1];
		if (joystick[0] == 0) rotate *= -1;

		int speed = joystick[3];
		if (joystick[2] == 0) speed *= -1;

		nxtDisplayBigTextLine(2, "%d", rotate);
		nxtDisplayBigTextLine(4, "%d", speed);

		motor[mA] = rotate + speed;
		motor[mB] = rotate - speed;
		motor[mC] = rotate;

		wait1Msec(10);

	}
}
