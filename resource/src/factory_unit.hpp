#pragma once

#include <string>
#include <vector>

#include <ghost/variable.hpp>

#include "var_unit.hpp"

using namespace std; 

enum UnitType{ Zealot,
	       Dragoon,
	       DarkTemplar,
	       Reaver,
	       Scout,
	       Marine,
	       Firebat,
	       Ghost,
	       Vulture,
	       SiegeTankTankMode,
	       SiegeTankSiegeMode,
	       Goliath,
	       Wraith,
	       BattleCruiser,
	       Zergling,
	       Hydralisk,
	       Lurker,
	       Ultralisk,
	       Mutalisk,
	       Guardian };

Unit make_unit( const UnitType& type, int );

vector< Unit > make_protoss( int );
vector< Unit > make_terran( int );
vector< Unit > make_zerg( int );
