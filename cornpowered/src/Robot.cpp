#include "WPILib.h"
class QuantumBuzzards9931RobotClassOfAwesomeness : public IterativeRobot
{
private:
RobotDrive m_robotDrive; // The drive train of the robot
Joystick m_rightStick; // The right joystick on our driver station
Joystick m_leftStick; // The left joystick on our driver station

public:
		BuiltinDefaultCode()
				: m_robotDrive(1,2);
				  m_leftStick(1);
				  m_rightStick(2);
	{
		myRobot.SetExpiration(0.1);
	}

	void RobotInit(void) {
	// Actions which would be performed once (and only once)
	// upon initialization of the robot would be put here.
	}
	void DisabledInit(void) {
	// This runs when the robot enters disabled mode
	}
	void AutonomousInit(void) {
	// This runs when the robot enters autonomous mode
	}
	void TeleopInit(void) {
	// This runs when the robot enters teleoperated mode
	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
		myRobot.SetSafetyEnabled(false);
		myRobot.Drive(-0.5, 0.0); 	// drive forwards half speed
		Wait(2.0); 				//    for 2 seconds
		myRobot.Drive(0.0, 0.0); 	// stop robot
	}

	/**
	 * Runs the motors with arcade steering.
	 */
	void OperatorControl()
	{
		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl() && IsEnabled())
		{
	m_robotDrive.ArcadeDrive(
			m_rightStick->GetX() ,
			m_rightStick->GetY() ); // drive with arcade style (use right stick)
			Wait(0.005);				// wait for a motor update time
		}
	};

	/**
	 * Runs during test mode
	 */
	void Test()
	{
	}
};

START_ROBOT_CLASS(QuantumBuzzards9931RobotClassOfAwesomeness);
