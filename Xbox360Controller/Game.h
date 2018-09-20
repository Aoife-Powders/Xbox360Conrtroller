// author: Aoife Powders
// Time Taken:
// Date Started:
// Date Finished:

#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Xbox360Controller.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

	Xbox360Controller m_xboxController;

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	

	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

	

};

#endif // !GAME

