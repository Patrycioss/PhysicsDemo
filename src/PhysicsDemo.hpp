#pragma once
#include "FrogEngine.hpp"

#include <grand.h>

#include "Rope.hpp"
#include "Zombie.hpp"

namespace PhysicsDemo
{
 class PhysicsDemo : public fe::GameTemplate {
  private:
   GRand random{};
   
   
  public:
   PhysicsDemo();
   void Start() override;
   void Update(float _deltaTime) override;
   void Stop() override;
  };
}