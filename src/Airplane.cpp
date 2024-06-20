#include "Airplane.hpp"

namespace PhysicsDemo
{
  void Airplane::Update(float _deltaTime) {
	if (fe::Input::GetKey(fe::Key::DOWN)){
	  b2Body_ApplyForceToCenter(body,{0,FORCE}, true);
	}

	if (fe::Input::GetKey(fe::Key::UP)){
	  b2Body_ApplyForceToCenter(body,{0,-FORCE}, true);
	}
	if (fe::Input::GetKey(fe::Key::LEFT)){
	  b2Body_ApplyForceToCenter(body,{-FORCE,0}, true);
	}
	if (fe::Input::GetKey(fe::Key::RIGHT)){
	  b2Body_ApplyForceToCenter(body,{FORCE,0}, true);
	}
	
	animatedSprite->FlipHorizontal(b2Body_GetLinearVelocity(body).x < 0);
  }

  Airplane::Airplane(b2Vec2 _position) : fe::GameObject(b2_dynamicBody, _position) {

	b2Body_SetFixedRotation(body,true);
	b2Body_SetGravityScale(body,0);

	shapeDef.friction = 1.0f;
	shapeDef.density = 0.5f;


	fe::Texture* yellowPlaneSheet = fe::AssetManager::LoadTexture("resources/spritesheets/yellow_plane/sheet.png");
	fe::AnimationSettings animationSettings{3, 1};
	animationSettings.fps = 10;
	animatedSprite = AddComponent<fe::AnimatedSprite>(yellowPlaneSheet, animationSettings);
  }
} // PhysicsDemo