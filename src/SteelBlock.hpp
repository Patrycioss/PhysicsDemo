#pragma once

#include <FrogEngine.hpp>

namespace PhysicsDemo
{
 class SteelBlock : public fe::GameObject{
  public:
   explicit SteelBlock(const b2Vec2& _position, float _radius);

  };
}