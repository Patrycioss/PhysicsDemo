#pragma once

#include "Rope.hpp"
#include "SteelBlock.hpp"

namespace PhysicsDemo{
  class WreckingBlock {
   private:
	Rope rope;
	SteelBlock* ball;
	
   public:
	WreckingBlock(const Rope::Settings& _ropeSettings, float _ballRadius);
	
		
  };
}