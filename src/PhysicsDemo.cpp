#include "PhysicsDemo.hpp"
#include "Airplane.hpp"

namespace PhysicsDemo
{
  PhysicsDemo::PhysicsDemo() {
	fe::Engine::SetGravity({0, 100});
	fe::Engine::SetBackgroundColour(fe::Colour{173, 216, 230});
	
//	fe::Box2DDebug::Enable();

	b2Vec2 windowSize = fe::Engine::GetWindowSize();

	// Ground
	{
	  fe::GameObject* ground = Instantiate<fe::GameObject>(b2_staticBody, b2Vec2{windowSize.x / 2.0f, windowSize.y - 11});
	  fe::Texture* groundTexture = fe::AssetManager::LoadTexture("resources/textures/green_square.png");
	  b2Vec2 size = {windowSize.x, 40};
	  ground->AddComponent<fe::Sprite>(groundTexture, size);
	  b2Polygon groundPolygon = b2MakeBox(size.x / 2.0f, size.y/2.0f);
	  ground->AddShape(groundPolygon);
	}
	
	// Sun
	{
	  fe::GameObject* sun = Instantiate<fe::GameObject>(b2_staticBody, b2Vec2{200,200});
	  fe::Texture* sunTexture = fe::AssetManager::LoadTexture("resources/textures/happy_sun.png");
	  sun->AddComponent<fe::Sprite>(sunTexture, false, b2Vec2{300,300});
	  b2Polygon polygon = b2MakeBox(0.1f,0.1f);
	  sun->GetShapeDef().isSensor = true;
	  sun->AddShape(polygon);
	}

	b2BodyId bodyId =  Instantiate<Airplane>(b2Vec2{300,200})->GetBody();

	{
	 
	}
	
	Rope rope(bodyId, b2Vec2(0, 5), 20, 10, 15);
	Instantiate<Zombie>(fe::Key::A, fe::Key::D, b2Vec2{400, 500});

	b2Polygon horBoundBox = b2MakeBox(windowSize.x / 2.0f, 5);
	b2Polygon vertBoundBox = b2MakeBox(5, windowSize.y / 2.0f);

	// LBound
	{
	  fe::GameObject* leftBound = Instantiate<fe::GameObject>(b2_staticBody, b2Vec2{0, windowSize.y / 2.0f});
	  leftBound->AddShape(vertBoundBox);
	}

	// RBound
	{
	  fe::GameObject* rightBound = Instantiate<fe::GameObject>(b2_staticBody, b2Vec2{windowSize.x, windowSize.y / 2.0f});
	  rightBound->AddShape(vertBoundBox);
	}

	// CeilingBound
	{
	  fe::GameObject* ceilingBound = Instantiate<fe::GameObject>(b2_staticBody, b2Vec2{windowSize.x / 2.0f, 0});
	  ceilingBound->AddShape(horBoundBox);
	}
  }

  void PhysicsDemo::Start() {

  }

  void PhysicsDemo::Update(float _deltaTime) {

  }

  void PhysicsDemo::Stop() {

  }
}