#include <numeric>
#include <iostream>

#include "obj_maxgrounddps.hpp"

using namespace std;

MaxGroundDPS::MaxGroundDPS()
  : Objective( "Max Ground DPS" )
{ }

double MaxGroundDPS::required_cost( vector< Unit > *vecVariables ) const 
{
  double total = 0.;
  
  for( auto& v : *vecVariables )
    total += ( v.get_value() * v.get_dps() );
  
  return -total;

  // return std::accumulate( begin( vecVariables ),
  // 			  end( vecVariables ),
  // 			  0,
  // 			  []( auto& v ){
  // 			    Unit* u = dynamic_cast<Unit*>( v.get() );
  // 			    return v.is_assigned() ? v.get_value() * v.get_dps() : 0;
  // 			  } ); 
}

Unit* MaxGroundDPS::expert_heuristic_variable( vector< Unit* > variables ) const
{
  Unit *bestVariable = variables[0];
  double best = 0.;
  double heuristic = 0.;
    
  for( auto& v : variables )
  {
    heuristic = ( v->get_dps() / v->get_mineral() ) + ( v->get_dps() / v->get_gas() ) + ( v->get_dps() / v->get_supply() );
    if( best < heuristic )
    {
      best = heuristic;
      bestVariable = v;
    }
  }

  return bestVariable;
}
