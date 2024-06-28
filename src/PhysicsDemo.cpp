#include "PhysicsDemo.hpp"

#include <grand.h>


#include "Airplane.hpp"
#include "WreckingBlock.hpp"
#include "Ball.hpp"


namespace PhysicsDemo
{
  PhysicsDemo::PhysicsDemo() {
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);
	
	fe::Engine::GetWorld().GetDef().gravity = {0, 100};
	fe::Engine::SetBackgroundColour(fe::Colour{173, 216, 230});
	fe::Engine::SetWindowSize(1600, 900);
	
	fe::Box2DDebug::Enable();

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

	fe::Body& body =  Instantiate<Airplane>(b2Vec2{300,200})->GetBody();

	{
	 
	}
	
	Rope::Settings ropeSettings{body.ID(), b2Vec2{0,5},20,10,10};
	WreckingBlock wreckingBall(ropeSettings, 5);
	Zombie* zombie = Instantiate<Zombie>(fe::Key::A, fe::Key::D, b2Vec2{305, 500});
	
//	b2WeldJointDef weldJointDef = b2DefaultWeldJointDef();
//	weldJointDef.bodyIdA = wreckingBall.GetLastSegment()->GetBody();
//	weldJointDef.bodyIdB = zombie->GetBody();
//	b2CreateWeldJoint(fe::Engine::GetWorldId(), &weldJointDef);

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
	b2Vec2 windowSize = fe::Engine::GetWindowSize();
	b2Vec2 halfWindowSize = {windowSize.x/2.0f, windowSize.y/2.0f};
	
	for (int i = 0; i < 20; i++){

	  b2Vec2 position = halfWindowSize;
	  position.x += random.i(100) * (random.i(1) == 1? 1 : -1);
	  Instantiate<Ball>( position, random.d(100) + 1);
	}
	
	Ball* bullet = Instantiate<Ball>(halfWindowSize + b2Vec2{0, - 200}, 100);
	bullet->GetShapeDef().density = 1000000;
	b2Body_ApplyLinearImpulseToCenter(bullet->GetBody(), b2Vec2{0, 10000000000}, true);
  }

  void PhysicsDemo::Update(float _deltaTime) {
//	printf("_deltaTime: %f\n", _deltaTime);
	
	float radius = (float) random.d(100) + 1;

	if (fe::Input::GetKeyDown(fe::Key::BACKSPACE)){
	  b2Vec2 windowSize = fe::Engine::GetWindowSize();
	  Instantiate<Ball>(b2Vec2{windowSize.x/2.0f, windowSize.y/2.0f}, radius);
	}
  }

  void PhysicsDemo::Stop() {

  }
}