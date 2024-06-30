#pragma once
#include <FrogEngine.hpp>

class Ball : public fe::GameObject {
 public:
  explicit Ball(const b2Vec2& _position, float _radius);
};
