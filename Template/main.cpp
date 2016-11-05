#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "Cube.h"

int main(int argc, char *argv)
{
	bool keyheld = false;

	sf::RenderWindow window(sf::VideoMode(400, 400), "Template", sf::Style::Titlebar | sf::Style::Close);

	sf::Image purpleImage;
	purpleImage.loadFromFile("res/purple.jpg");
	sf::Image greenImage;
	greenImage.loadFromFile("res/green.jpg");

	glEnable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LESS);

	glEnable(GL_CULL_FACE);

	glFrontFace(GL_CW);

	GLuint purpleTextureID;
	glGenTextures(1, &purpleTextureID);

	glBindTexture(GL_TEXTURE_2D, purpleTextureID);

	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGBA,
		purpleImage.getSize().x,
		purpleImage.getSize().y,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		purpleImage.getPixelsPtr()
		);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);



	float positionZ = 0.5f;
	float angle = 0.0f;
	GLenum mode = GL_QUADS;

	Cube purpCube = Cube(purpleTextureID);

	int rotation = 0; 

	sf::Event evt;
	sf::Clock appTimer;
	while (window.isOpen()) {
		float deltaTime = appTimer.restart().asSeconds();

		while (window.pollEvent(evt)) {
			switch (evt.type){
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyReleased:
				keyheld = false;
				break;
			case sf::Event::KeyPressed:
				keyheld = true;

				switch (evt.key.code){
				case sf::Keyboard::Num1:
					mode = GL_TRIANGLES;
					break;
				case sf::Keyboard::Num2:
					mode = GL_TRIANGLE_STRIP;
					break;
				case sf::Keyboard::Num3:
					mode = GL_QUADS;
					break;
				case sf::Keyboard::Num4:
					mode = GL_QUAD_STRIP;
					break;
				case sf::Keyboard::Up:
					rotation = 1;
					break;
				case sf::Keyboard::Down:
					rotation = -1;
					break;
				default:
					mode = GL_QUADS;
					break;
				}

			}
		}


		angle += 90.0f * deltaTime;


		purpCube.Update(deltaTime, keyheld, rotation);
		purpCube.Draw(mode, true);

		window.display();

	}

	return 0;
}