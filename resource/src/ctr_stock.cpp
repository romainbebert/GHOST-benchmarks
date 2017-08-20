#include <algorithm>

#include "ctr_stock.hpp"

using namespace ghost;

Stock::Stock( const vector< shared_ptr< Variable > > &variables, int quantity )
  : Constraint( variables ),
    _quantity(quantity)
{ }

double Stock::required_cost() const 
{
  double sum = 0.;

  for( auto& v : variables )
    if( v->is_assigned() )
      sum += v->get_value();
  
  return std::min( 0., sum - _quantity );
}
