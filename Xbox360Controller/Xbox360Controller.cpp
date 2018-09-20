#include "Xbox360Controller.h"
#include <iostream>


Xbox360Controller::Xbox360Controller()
{
}


Xbox360Controller::~Xbox360Controller()
{
}

void Xbox360Controller::update()
{
	//sets the previous state to the current state
	m_previousState = m_currentState;

	//sets the pressed array to false
	for (int i = 0; i < 19; i++)
	{
		m_Pressed[i] = false;
	}

	connect();

	//checks which button was pressed 
		if (sf::Joystick::isButtonPressed(0, 0))
		{
			//sets the bool in pressed array to true when pressed
			m_Pressed[0] = true;
			//sets the current state of the button being pressed to true
			m_currentState.A = true;
			//updates the position and strings in the text array
			m_textArray[0].setPosition(750.0f, 430.0f);
			m_textArray[0].setString("Pressed A");

			//if it stopped being pressed then the last button string is updated
			if (m_previousState.A == false)
			{
				m_previousStateString.setString("Last Button Pressed is A");
			}

		}
		else
		{
			//otherwise the current state of the button pressed is set to false
			m_currentState.A = false;
		}

		if (sf::Joystick::isButtonPressed(0, 1))
		{
			m_Pressed[1] = true;
			m_currentState.B = true;
			m_textArray[1].setPosition(750.0f, 370.0f);
			m_textArray[1].setString("Pressed B");


			if (m_previousState.B == false)
			{
				m_previousStateString.setString("Last Button Pressed is B");
			}
		}
		else
		{

			m_currentState.B = false;
		}

		if (sf::Joystick::isButtonPressed(0, 2))
		{
			m_Pressed[2] = true;
			m_currentState.X = true;
			m_textArray[2].setPosition(750.0f, 310.0f);
			m_textArray[2].setString("Pressed X");


			if (m_previousState.X == false)
			{
				m_previousStateString.setString("Last Button Pressed is X");
			}
		}
		else
		{
			m_currentState.X = false;
		}

		if (sf::Joystick::isButtonPressed(0, 3))
		{
			m_Pressed[3] = true;
			m_currentState.Y = true;
			m_textArray[3].setPosition(750.0f, 250.0f);
			m_textArray[3].setString("Pressed Y");


			if (m_previousState.Y == false)
			{
				m_previousStateString.setString("Last Button Pressed is Y");
			}
		}
		else
		{
			m_currentState.Y = false;
		}

		//lb rb start and thumb stick button dont theed the previous state updated
		if (sf::Joystick::isButtonPressed(0, 4))
		{
			m_Pressed[4] = true;
			m_currentState.LB = true;
			m_textArray[4].setPosition(50.0f, 140.0f);
			m_textArray[4].setString("Pressed LB");
		}
		else
		{
			m_currentState.LB = false;
		}
	

		if (sf::Joystick::isButtonPressed(0, 5))
		{
			m_Pressed[5] = true;
			m_currentState.RB = true;
			m_textArray[5].setPosition(700.0f, 140.0f);
			m_textArray[5].setString("Pressed RB");

		}
		else
		{
			m_currentState.RB = false;
		}

		if (sf::Joystick::isButtonPressed(0, 8))
		{
			m_Pressed[6] = true;
			m_currentState.LeftThumbStickClick = true;
			m_textArray[6].setPosition(10.0f, 330.0f);
			m_textArray[6].setString("Pressed Left Thumb");
		}
		else
		{
			m_currentState.LeftThumbStickClick = false;
		}

		if (sf::Joystick::isButtonPressed(0, 9))
		{
			m_Pressed[7] = true;
			m_currentState.RightThumbStickClick = true;
			m_textArray[7].setPosition(530.0f, 560.0f);
			m_textArray[7].setString("Pressed Right Thumb");
		}
		else
		{
			m_currentState.RightThumbStickClick = false;
		}

		if (sf::Joystick::isButtonPressed(0, 7))
		{
			m_Pressed[8] = true;
			m_currentState.Start = true;
			m_textArray[8].setPosition(760.0f, 505.0f);
			m_textArray[8].setString("Pressed Start");
		}
		else
		{
			m_currentState.Start = false;
		}

		//sets the vector left thumb stick to the position of the joystick x and y
		m_currentState.LeftThumbStick.x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
		m_currentState.LeftThumbStick.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);

		//checks if the vector is less than or greater than 15
		if (m_currentState.LeftThumbStick.x > 15.f || m_currentState.LeftThumbStick.x < -15.f || m_currentState.LeftThumbStick.y > 15.f || m_currentState.LeftThumbStick.y < -15.f)
		{
			m_Pressed[9] = true;
			//sets the string to the vector value
			m_textArray[9].setString(std::to_string(m_currentState.LeftThumbStick.x));
			m_Pressed[10] = true;
			m_textArray[10].setString(std::to_string(m_currentState.LeftThumbStick.y));
		}

		m_currentState.RightThumbStick.x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R);
		m_currentState.RightThumbStick.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);

		if (m_currentState.RightThumbStick.x > 15.f || m_currentState.RightThumbStick.x < -15.f || m_currentState.RightThumbStick.y > 15.f || m_currentState.RightThumbStick.y < -15.f)
		{
			m_Pressed[11] = true;
			m_textArray[11].setString(std::to_string(m_currentState.RightThumbStick.x));
			m_Pressed[12] = true;
			m_textArray[12].setString(std::to_string(m_currentState.RightThumbStick.y));
		}

		//checks if the poition of the right d pad button id greater than the threshold
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) > dpadThreshold)
		{
			m_Pressed[13] = true;
			//sets the string 
			m_textArray[13].setString("Right");
			//sets the current state to true
			m_currentState.DpadRight = true;
		}
		

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) < (dpadThreshold * -1))
		{
			m_Pressed[14] = true;
			m_textArray[14].setString("Left");
			m_currentState.DpadLeft = true;
		}
		

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) > dpadThreshold)
		{
			m_Pressed[15] = true;
			m_textArray[15].setString("Up");
			m_currentState.DpadUp = true;
		}
	

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) < (dpadThreshold * -1))
		{
			m_Pressed[16] = true;
			m_textArray[16].setString("Down");
			m_currentState.DpadDown = true;
		}
		

		//checks if the position of the z axis id less than zero
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) < -15.f)
		{
			m_Pressed[17]  = true;
			//changes the current state to the axis position
			m_currentState.RTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Z);
			//sets the string to the currentstate value
			m_textArray[17].setString(std::to_string(m_currentState.RTrigger * -1));
		}

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) > 15.f)
		{
			m_Pressed[18] = true;
			m_currentState.LTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Z);
			m_textArray[18].setString(std::to_string(m_currentState.LTrigger));
		}



}

//checks how many controllers are connected
bool Xbox360Controller::isConnected()
{
	for (int i = 0; i <= 8; i++)
	{
		if (sf::Joystick::isConnected(i))
		{
			sf_Joystick_index = i;
			return true;
		}
		else
		{
			return false;
		}
	}
}

//calls the isconnected function
bool Xbox360Controller::connect()
{
	//checks of the joystick is connected
	if (isConnected())
	{
		return true;
	}
	else
	{
		return false;
	}
	
}


