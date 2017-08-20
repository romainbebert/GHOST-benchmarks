#include <exception>

#include "factory_unit.hpp"

using namespace std; 

shared_ptr< Unit > make_unit( const UnitType& type )
{
  switch( type )
  {
    // Protoss
  case UnitType::Zealot:
    return make_shared< Unit >( "Zealot", "p_z", 100, 0, 2., (16.0/22)*24 );
  case UnitType::Dragoon:
    return make_shared< Unit >( "Dragoon", "p_d", 125, 50, 2., (20.0/30)*24 );
  case UnitType::DarkTemplar:
    return make_shared< Unit >( "DarkTemplar", "p_dt", 125, 100, 2., (40.0/30)*24 );
  case UnitType::Reaver:
    return make_shared< Unit >( "Reaver", "p_r", 200, 100, 4., (100.0/60)*24 );
  case UnitType::Scout:
    return make_shared< Unit >( "Scout", "p_s", 275, 125, 3., (8.0/30)*24 );

    // Terran
  case UnitType::Marine:
    return make_shared< Unit >( "Marine", "t_m", 50, 0, 1., (6.0/15)*24 );
  case UnitType::Firebat:
    return make_shared< Unit >( "Firebat", "t_f", 50, 25, 1., (16.0/22)*24 );
  case UnitType::Ghost:
    return make_shared< Unit >( "Ghost", "t_gh", 25, 75, 1., (10.0/22)*24 );
  case UnitType::Vulture:
    return make_shared< Unit >( "Vulture", "t_v", 75, 0, 2., (20.0/30)*24 );
  case UnitType::SiegeTankTankMode:
    return make_shared< Unit >( "SiegeTankTankMode", "t_tm", 150, 100, 2., (30.0/37)*24 );
  case UnitType::SiegeTankSiegeMode:
    return make_shared< Unit >( "SiegeTankSiegeMode", "t_sm", 150, 100, 2., (70.0/75)*24 );
  case UnitType::Goliath:
    return make_shared< Unit >( "Goliath", "t_go", 100, 50, 2., (12.0/22)*24 );
  case UnitType::Wraith:
    return make_shared< Unit >( "Wraith", "t_w", 150, 100, 2., (8.0/30)*24 );
  case UnitType::BattleCruiser:
    return make_shared< Unit >( "BattleCruiser", "t_b", 400, 300, 6., (25.0/30)*24 );

    // Zerg
  case UnitType::Zergling:
    return make_shared< Unit >( "Zergling", "z_z", 25, 0, 0.5, (5.0/8)*24 );
  case UnitType::Hydralisk:
    return make_shared< Unit >( "Hydralisk", "z_h", 75, 25, 1., (10.0/15)*24 );
  case UnitType::Lurker:
    return make_shared< Unit >( "Lurker", "z_l", 75, 25, 2., (20.0/37)*24 );
  case UnitType::Ultralisk:
    return make_shared< Unit >( "Ultralisk", "z_u", 200, 200, 4., (20.0/15)*24 );
  case UnitType::Mutalisk:
    return make_shared< Unit >( "Mutalisk", "z_m", 100, 100, 2., (9.0/30)*24 );
  case UnitType::Guardian:
    return make_shared< Unit >( "Guardian", "z_g", 100, 100, 2., (20.0/30)*24 );

  default:
    throw 0;
  }
}
