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
    total += v.get_value() * v.get_dps();
  
  return -total;

  // return std::accumulate( begin( vecVariables ),
  // 			  end( vecVariables ),
  // 			  0,
  // 			  []( auto& v ){
  // 			    Unit* u = dynamic_cast<Unit*>( v.get() );
  // 			    return v.is_assigned() ? v.get_value() * v.get_dps() : 0;
  // 			  } ); 
}

// Unit MaxGroundDPS::expert_heuristic_variable( const vector< Unit >& vecVariables ) const
// {
//   vector< Unit > bestVars;
//   double currentDPS;
//   double bestDPS = 0.;
  
//   for( auto& v : vecVariables )
//   {
//     currentDPS = v.get_dps();
//     if( bestDPS < currentDPS )
//     {
//       bestDPS = currentDPS;
//       bestVars.clear();
//       bestVars.push_back( v );
//     }
//     else
//       if( bestDPS == currentDPS )
// 	bestVars.push_back( v );
//   }
  
//   return bestVars[ random.get_random_number( bestVars.size() ) ];      
// }
