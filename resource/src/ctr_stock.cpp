#include <algorithm>
#include <exception>

#include "ctr_stock.hpp"

using namespace std;
using namespace ghost;

Stock::Stock( const vector< shared_ptr< Unit > > &variables, int quantity, ResourceType type )
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
      switch( _type )
      {
      case Mineral:
	costValue = v->get_mineral();
	break;
      case Gas:
	costValue = v->get_gas();
	break;
      case Supply:
	costValue = v->get_supply();
	break;
      default:
	throw 0;
      }

      sum += v->get_value() * costValue;
    }

  return std::min( 0., sum - _quantity );
}
