#include "Ball.hpp"

Ball::Ball(const b2Vec2& _position, float _radius)
	: fe::GameObject(b2_dynamicBody, _position) {
	
  fe::Texture* ballTexture = fe::AssetManager::LoadTexture("resources/textures/circle.png", true);
  AddComponent<fe::Sprite>(ballTexture, false, b2Vec2{_radius * 2, _radius * 2})->SetColour(fe::Colour::RED);
  
  shapeDef.density = 0.001f;
  b2Circle circle{{0,0}, _radius};
//  circle.center = {_radius, _radius};
  b2CreateCircleShape(body, &shapeDef, &circle);
}
