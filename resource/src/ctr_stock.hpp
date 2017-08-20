#include "constraint.hpp"

using namespace ghost;

class Stock : public Constraint
{
  int _quantity;
  
  double required_cost() const override;

public:
  Stock( const vector< shared_ptr< Variable > > &variables, int quantity );
};
