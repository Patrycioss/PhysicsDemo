#include "Rope.hpp"

namespace PhysicsDemo
{
  Rope::Rope(const Settings& _settings) :
	  segments(), jointDefs() {

	segments.reserve(_settings.length);
	jointDefs.reserve(_settings.length);

	float halfSegmentLength = _settings.segmentLength / 2.0f;

	for (int i = 0; i < _settings.length; i++) {
	  
	  b2WeldJointDef& weldJointDef = jointDefs.emplace_back(b2DefaultWeldJointDef());
	  RopeSegment* anchorSegment =
		  fe::Engine::Instantiate<RopeSegment>(b2Vec2(_settings.ropeWidth, _settings.segmentLength), b2Body_GetPosition(_settings.anchorBody) + _settings.anchorPosition);
	  segments.push_back(anchorSegment);

	  if (i == 0) {
		weldJointDef.bodyIdA = _settings.anchorBody;
		weldJointDef.localAnchorA = _settings.anchorPosition;
	  } else {
		weldJointDef.bodyIdA = segments[i - 1]->GetBody().ID();
		weldJointDef.localAnchorA = b2Vec2(0, halfSegmentLength);
	  }

	  weldJointDef.localAnchorB = b2Vec2(0, -halfSegmentLength);
	  weldJointDef.bodyIdB = anchorSegment->GetBody().ID();
	  weldJointDef.collideConnected = true;
	  weldJointDef.angularHertz = 60;
	  weldJointDef.linearHertz = 60;
	  weldJointDef.linearDampingRatio = 1;

	  b2CreateWeldJoint(fe::Engine::GetWorld().ID(), &weldJointDef);
	}
  }
  
  RopeSegment* Rope::GetLastSegment() const {
	return segments.back();
  }
};