#include "SteelBlock.hpp"

PhysicsDemo::SteelBlock::SteelBlock(const b2Vec2& _position, float _radius)
	: fe::GameObject(b2_dynamicBody, _position) {
  
  b2Vec2 size = {100,50};
  AddComponent<fe::Sprite>(fe::AssetManager::LoadTexture("resources/textures/steel_block.png"), false, size);

  shapeDef.density = 0.5f;
  
  b2Body_SetFixedRotation(body, true);
  b2Polygon polygon = b2MakeBox(size.x/2.0f, size.y/2.0f);
  AddShape(polygon);
}
