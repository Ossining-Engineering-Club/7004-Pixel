#include "Robot.h"

Robot::Robot() {
}

void Robot::RobotInit()

{
    camera= CameraServer::GetInstance()->StartAutomaticCapture();
    camera.SetResolution(480,640);
    camera.SetExposureAuto();
    camera.SetFPS(30);
    camera.SetBrightness(20);
    smartDashboard->init();
}

void Robot::Autonomous() {
}

void Robot::OperatorControl() {
     Wait(1);
     while(IsOperatorControl() && IsEnabled()) {
         if (stick2.GetRawButton(2) ){
             m_left.Set(-0.65*stick2.GetY());
             m_right.Set(-0.79*stick2.GetY());
         }
         else {
            m_left.Set(-0.65*stick1.GetY()); //left wheels
            m_right.Set(-0.79*stick2.GetY()); //right wheels
            m_updown.Set(0.65*stick3.GetY()); //arm controls
            while(stick3.GetRawButton(1)) { //arm wheels
                if (stick3.GetRawButton(2)) {
                    wheels.Set(0.99); //outake
                }
                else {
                    wheels.Set(-0.25); //intake
                }
            }

            wheels.Set(0);
            //smartDashboard -> PutNumber("Stick 3", stick3.GetZ());
        }
     }
}

void Robot::Test() {}

#ifndef RUNNING_FRC_TESTS
START_ROBOT_CLASS(Robot)
#endif