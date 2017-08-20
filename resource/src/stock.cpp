#include <algorithm>

#include "stock.hpp"

using namespace ghost;

double Stock::required_cost() const override
{
  double sum = 0.;

  for( auto& v : variables )
    if( v->is_assigned() )
      sum += v->get_value();
  
  return std::min( 0., sum - _quantity );
}
