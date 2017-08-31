#include <exception>

#include "factory_unit.hpp"

using namespace std; 

Unit make_unit( const UnitType& type, int supplyAvailable )
{
  switch( type )
  {
    // Protoss
  case UnitType::Zealot:
    return Unit( "Zealot", "p_z", supplyAvailable, 100, 0, 2., (16.0/22)*24 );
  case UnitType::Dragoon:
    return Unit( "Dragoon", "p_d", supplyAvailable, 125, 50, 2., (20.0/30)*24 );
  case UnitType::DarkTemplar:
    return Unit( "DarkTemplar", "p_dt", supplyAvailable, 125, 100, 2., (40.0/30)*24 );
  case UnitType::Reaver:
    return Unit( "Reaver", "p_r", supplyAvailable, 200, 100, 4., (100.0/60)*24 );
  case UnitType::Scout:
    return Unit( "Scout", "p_s", supplyAvailable, 275, 125, 3., (8.0/30)*24 );

    // Terran
  case UnitType::Marine:
    return Unit( "Marine", "t_m", supplyAvailable, 50, 0, 1., (6.0/15)*24 );
  case UnitType::Firebat:
    return Unit( "Firebat", "t_f", supplyAvailable, 50, 25, 1., (16.0/22)*24 );
  case UnitType::Ghost:
    return Unit( "Ghost", "t_gh", supplyAvailable, 25, 75, 1., (10.0/22)*24 );
  case UnitType::Vulture:
    return Unit( "Vulture", "t_v", supplyAvailable, 75, 0, 2., (20.0/30)*24 );
  case UnitType::SiegeTankTankMode:
    return Unit( "SiegeTankTankMode", "t_tm", supplyAvailable, 150, 100, 2., (30.0/37)*24 );
  case UnitType::SiegeTankSiegeMode:
    return Unit( "SiegeTankSiegeMode", "t_sm", supplyAvailable, 150, 100, 2., (70.0/75)*24 );
  case UnitType::Goliath:
    return Unit( "Goliath", "t_go", supplyAvailable, 100, 50, 2., (12.0/22)*24 );
  case UnitType::Wraith:
    return Unit( "Wraith", "t_w", supplyAvailable, 150, 100, 2., (8.0/30)*24 );
  case UnitType::BattleCruiser:
    return Unit( "BattleCruiser", "t_b", supplyAvailable, 400, 300, 6., (25.0/30)*24 );

    // Zerg
  case UnitType::Zergling:
    return Unit( "Zergling", "z_z", supplyAvailable, 25, 0, 0.5, 15.0 );
  case UnitType::Hydralisk:
    return Unit( "Hydralisk", "z_h", supplyAvailable, 75, 25, 1., (10.0/15)*24 );
  case UnitType::Lurker:
    return Unit( "Lurker", "z_l", supplyAvailable, 75, 25, 2., (20.0/37)*24 );
  case UnitType::Ultralisk:
    return Unit( "Ultralisk", "z_u", supplyAvailable, 200, 200, 4., (20.0/15)*24 );
  case UnitType::Mutalisk:
    return Unit( "Mutalisk", "z_m", supplyAvailable, 100, 100, 2., (9.0/30)*24 );
  case UnitType::Guardian:
    return Unit( "Guardian", "z_g", supplyAvailable, 100, 100, 2., (20.0/30)*24 );

  default:
    throw 0;
  }
}

vector< Unit > make_protoss( int supplyAvailable )
{
  vector< Unit > units;
  units.push_back( make_unit( UnitType::Zealot, supplyAvailable / 2 ) );
  units.push_back( make_unit( UnitType::Dragoon, supplyAvailable / 2 ) );
  units.push_back( make_unit( UnitType::DarkTemplar, supplyAvailable / 2 ) );
  units.push_back( make_unit( UnitType::Reaver, supplyAvailable / 4 ) );
  units.push_back( make_unit( UnitType::Scout, supplyAvailable / 3 ) );
  return units;
}

vector< Unit > make_terran( int supplyAvailable )
{
  vector< Unit > units;
  units.push_back( make_unit( UnitType::Marine, supplyAvailable ) );
  units.push_back( make_unit( UnitType::Firebat, supplyAvailable ) );
  units.push_back( make_unit( UnitType::Ghost, supplyAvailable ) );
  units.push_back( make_unit( UnitType::Vulture, supplyAvailable / 2 ) );
  units.push_back( make_unit( UnitType::SiegeTankTankMode, supplyAvailable / 2 ) );
  units.push_back( make_unit( UnitType::SiegeTankSiegeMode, supplyAvailable / 2 ) );
  units.push_back( make_unit( UnitType::Goliath, supplyAvailable / 2 ) );
  units.push_back( make_unit( UnitType::Wraith, supplyAvailable / 2 ) );
  units.push_back( make_unit( UnitType::BattleCruiser, supplyAvailable / 6 ) );
  return units;
}

vector< Unit > make_zerg( int supplyAvailable )
{
  vector< Unit > units;
  units.push_back( make_unit( UnitType::Zergling, supplyAvailable * 2 ) );
  units.push_back( make_unit( UnitType::Hydralisk, supplyAvailable ) );
  units.push_back( make_unit( UnitType::Lurker, supplyAvailable / 2 ) );
  units.push_back( make_unit( UnitType::Ultralisk, supplyAvailable / 4 ) );
  units.push_back( make_unit( UnitType::Mutalisk, supplyAvailable / 2 ) );
  units.push_back( make_unit( UnitType::Guardian, supplyAvailable / 2 ) );
  return units;
}
