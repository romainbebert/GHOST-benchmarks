#include <algorithm>
#include <exception>

#include "ctr_stock.hpp"

using namespace std;
using namespace ghost;

Stock::Stock( vector< Unit > *variables, int quantity, ResourceType type )
  : Constraint<Unit>	( variables ),
    _quantity		( quantity ),
    _type		( type )
{ }

double Stock::required_cost() const 
{
  double sum = 0.;
  double costValue;

  for( auto& v : *variables )
  {
    switch( _type )
    {
    case Mineral:
      costValue = v.get_mineral();
      break;
    case Gas:
      costValue = v.get_gas();
      break;
    case Supply:
      costValue = v.get_supply();
      break;
    default:
      throw 0;
    }
    
    sum += ( v.get_value() * costValue );
  }

  return std::max( 0., sum - _quantity );
}

