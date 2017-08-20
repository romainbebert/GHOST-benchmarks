#pragma once

#include <memory>
#include <string>
#include <vector>

#include <variable.hpp>

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

shared_ptr< Unit > make_unit( const UnitType& type );

vector< shared_ptr< Variable > > make_protoss();
vector< shared_ptr< Variable > > make_terran();
vector< shared_ptr< Variable > > make_zerg();