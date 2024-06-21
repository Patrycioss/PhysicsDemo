#pragma once

#include "RopeSegment.hpp"

namespace PhysicsDemo
{
  class Rope {
   public:
	struct Settings{
	  b2BodyId anchorBody;
	  b2Vec2 anchorPosition; 
	  int length; 
	  float ropeWidth;
	  float segmentLength;
	};
	
   private:
	std::vector<RopeSegment*> segments;
	std::vector<b2WeldJointDef> jointDefs;

   public:
	Rope(const Settings& _settings);
	
	RopeSegment* GetLastSegment() const;
  };
}

