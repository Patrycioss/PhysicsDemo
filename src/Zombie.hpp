#pragma once

#include "FrogEngine.hpp"

namespace PhysicsDemo
{
 class Zombie : public fe::GameObject {
  private:
   enum class State{
	 Walking,
	 Standing
   }; 
   
   static constexpr float FORCE = 40000;
   static constexpr float JUMPFORCE = 6000000;
   
   State currentState;
   fe::AnimatedSprite* sprite;
   
   fe::Key leftKey;
   fe::Key rightKey;
   
   void SetState(State _state);
   
  protected:
   void Update(float _deltaTime) override;
   
  public:
   Zombie(fe::Key _leftKey, fe::Key _rightKey, b2Vec2 _position);
  };
}