#include <numeric>

#include "obj_maxgrounddps.hpp"

using namespace std;

MaxGroundDPS::MaxGroundDPS()
  : Objective( "Max Ground DPS" )
{ }

double MaxGroundDPS::required_cost( const vector< shared_ptr< Unit > > &vecVariables ) const 
{
  return std::accumulate( cbegin( vecVariables ),
			  cend( vecVariables ),
			  0,
			  []( auto& v ){ return v->is_assigned() ? v->get_value() * v->get_dps() : 0; } ); 
}
  
