#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float angle;
	float speedx, speedy;
public:
	Player() {
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width/2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
	}
	void update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			angle -= 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			angle += 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			speed -= 1;
			if (speed <= -5) {
				speed = -5;
			}
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			speed += 1;
			if (speed >= 10) {
				speed=10;
			}
		}
		speedx = speed * sin(angle * 3.1415 / 180);
		speedy = -speed * cos(angle * 3.1415 / 180);
		sprite.move(speedx,speedy);
		sprite.setRotation(angle);
	}

	sf::Sprite getSprite() { return sprite; }
};