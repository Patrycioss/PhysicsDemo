﻿#include "WreckingBlock.hpp"

PhysicsDemo::WreckingBlock::WreckingBlock(const PhysicsDemo::Rope::Settings& _ropeSettings, float _ballRadius)
	:
	rope(_ropeSettings),
	ball(
		fe::Engine::Instantiate<SteelBlock>(
			rope.GetLastSegment()->GetBody().GetPosition() + b2Vec2{0, _ropeSettings.segmentLength + _ballRadius},
			_ballRadius
		)
	) {

  b2WeldJointDef weldJointDef = b2DefaultWeldJointDef();
  weldJointDef.bodyIdA = rope.GetLastSegment()->GetBody().ID();
  weldJointDef.bodyIdB = ball->GetBody().ID();
  weldJointDef.collideConnected = false;
  weldJointDef.linearHertz = 60;
  weldJointDef.angularHertz = 60;
  b2CreateWeldJoint(fe::Engine::GetWorld().ID(), &weldJointDef);

}
