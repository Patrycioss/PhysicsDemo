
#include <FrogEngine.hpp>

#include "PhysicsDemo.hpp"

int main() {
  
  
  fe::Engine::Initialize();
  PhysicsDemo::PhysicsDemo physicsDemo{};
  fe::Engine::Start(physicsDemo);
  return 0;
}