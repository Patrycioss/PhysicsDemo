#pragma once

#include "FrogEngine.hpp"

namespace PhysicsDemo
{

 class Airplane : public fe::GameObject{
  private:
   static constexpr float FORCE = 300000;
   
   fe::AnimatedSprite* animatedSprite;
   
  protected:
   void Update(float _deltaTime) override;
   
  public:
   explicit Airplane(b2Vec2 _position);
  };

} // PhysicsDemo