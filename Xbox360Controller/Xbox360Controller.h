#pragma once
#include <SFML\Graphics.hpp>
#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER

//data to store current state of controller
struct  GamePadState
{
	bool A;
	bool B;
	bool X;
	bool Y;
	bool LB;
	bool RB;
	bool LeftThumbStickClick;
	bool RightThumbStickClick;
	bool DpadUp;
	bool DpadDown;
	bool DpadRight;
	bool DpadLeft;
	bool Start;
	bool Back;
	bool Xbox;
	float RTrigger;
	float LTrigger;
	sf::Vector2f RightThumbStick;
	sf::Vector2f LeftThumbStick;
};

//xbox controller class to query current state of controller
//to mimic the controller states like XNA
class Xbox360Controller
{
private:
	//deadzone for dpad(really joystick)
	const int dpadThreshold = 50;

public:
	//index count for multiple controllers if connected
	int sf_Joystick_index;
	//the current state of all the buttons 
	GamePadState m_currentState;
	// check for the moment a button is pressed
	GamePadState m_previousState;

	sf::Text m_textArray[19]; // text used for message on screen
	Xbox360Controller();
	~Xbox360Controller();
	void Xbox360Controller::update();
	bool isConnected();
	bool connect();
	//checks which button has been pressed
	bool m_Pressed[19];
	//creates texts and text arrays
	sf::Text m_previousStateString;
	sf::Text m_connected;
};

#endif