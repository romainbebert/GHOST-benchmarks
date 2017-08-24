#include <numeric>
#include <iostream>

#include "obj_maxgrounddps.hpp"

using namespace std;

MaxGroundDPS::MaxGroundDPS()
  : Objective( "Max Ground DPS" )
{ }

double MaxGroundDPS::required_cost( const vector< shared_ptr< Variable > >& vecVariables ) const 
{
  double total = 0.;
  
  for( auto& v : vecVariables )
    if( v->is_assigned() )
    {
      Unit* u = dynamic_cast<Unit*>( v.get() );
      total += u->get_value() * u->get_dps();
    }
  
  return -total;

  // return std::accumulate( begin( vecVariables ),
  // 			  end( vecVariables ),
  // 			  0,
  // 			  []( auto& v ){
  // 			    Unit* u = dynamic_cast<Unit*>( v.get() );
  // 			    return u->is_assigned() ? u->get_value() * u->get_dps() : 0;
  // 			  } ); 
}

shared_ptr< Variable > MaxGroundDPS::expert_heuristic_variable( const vector< shared_ptr< Variable > >& vecVariables ) const
{
  vector< shared_ptr< Variable > > bestVars;
  double currentDPS;
  double bestDPS = 0.;
  
  for( auto& v : vecVariables )
  {
    Unit* u = dynamic_cast<Unit*>( v.get() );
    currentDPS = u->get_dps();
    if( bestDPS < currentDPS )
    {
      bestDPS = currentDPS;
      bestVars.clear();
      bestVars.push_back( v );
    }
    else
      if( bestDPS == currentDPS )
	bestVars.push_back( v );
  }
  
  return bestVars[ random.get_random_number( bestVars.size() ) ];      
}
