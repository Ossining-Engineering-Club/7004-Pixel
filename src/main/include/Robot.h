#pragma once

#include <frc/WPIlib.h>
using namespace frc;

class Robot : public frc::SampleRobot {
 public:
  Robot();

  cs::UsbCamera camera{}; 

  SmartDashboard *smartDashboard;
  
  Joystick stick1{0}; //left
  Joystick stick2{1}; //right
  Joystick stick3{2}; //arm

  Spark m_left{0};
  Spark m_right{1};
  Spark m_updown{3};

  Talon wheels{2};
  

  void RobotInit() override;
  void Autonomous() override;
  void OperatorControl() override;
  void Test() override;

 private:
};
class GyroSample : public SampleRobot
{
	RobotDrive myRobot; // robot drive system
	AnalogGyro gyro;
	const float kP = 0.03;
	
public:
	GyroSample():
		myRobot(1, 2), // initialize the sensors in initilization list
		gyro(1)
	{
		myRobot.SetExpiration(0.1);
	}
	
	void Autonomous()
	{
		gyro.Reset();
		while (IsAutonomous())
		{
			float angle = gyro.GetAngle(); // get heading
			myRobot.Drive(-1.0, -angle * kP); // turn to correct heading
			Wait(0.004);
		}
		myRobot.Drive(0.0, 0.0); // stop robot
	}
};
