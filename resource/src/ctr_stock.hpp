#pragma once

#include <vector>
#include <memory>

#include <constraint.hpp>

#include "unit.hpp"

using namespace std;
using namespace ghost;

enum ResourceType { Mineral, Gas, Supply };

class Stock : public Constraint
{
  int		_quantity;
  ResourceType	_type;
  
  double required_cost() const override;

public:
  StockMinerals( const vector< shared_ptr< Unit > > &variables, int quantity, ResourceType type );
};
