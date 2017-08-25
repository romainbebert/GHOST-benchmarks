#include <algorithm>
#include <exception>

#include "ctr_stock.hpp"

using namespace std;
using namespace ghost;

Stock::Stock( const vector< shared_ptr< Variable > >& variables, int quantity, ResourceType type )
  : Constraint	( variables ),
    _quantity	( quantity ),
    _type	( type )
{ }

double Stock::required_cost() const 
{
  double sum = 0.;
  int costValue;

  for( auto& v : variables )
    if( v->is_assigned() )
    {
      Unit* u = dynamic_cast<Unit*>( v.get() );
      switch( _type )
      {
      case Mineral:
	costValue = u->get_mineral();
	break;
      case Gas:
	costValue = u->get_gas();
	break;
      case Supply:
	costValue = u->get_supply();
	break;
      default:
	throw 0;
      }

      sum += ( u->get_value() * costValue );
    }

  debug_cost = ( sum - _quantity );
  return std::max( 0., sum - _quantity );
}
