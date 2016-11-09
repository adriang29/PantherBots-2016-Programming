// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Fire.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Fire::Fire(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	SetTimeout(.2);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::catapult.get());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void Fire::Initialize() {
	//shoot the catapult
	Robot::catapult->Shoot();
}

// Called repeatedly when this Command is scheduled to run
void Fire::Execute() {
	//Robot::catapult->Retract();
}

// Make this return true when this Command no longer needs to run execute()
bool Fire::IsFinished() {
	//return Robot::catapult->GetAverageVoltage() > 4.000;
	return IsTimedOut();
}

// Called once after isFinished returns true
void Fire::End()
{
	Robot::catapult->STOP(); //retracts the solenoid so it can lock the catapult
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Fire::Interrupted() {
	End();
}
