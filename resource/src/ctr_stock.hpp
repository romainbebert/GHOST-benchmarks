#pragma once

#include <vector>

#include <ghost/constraint.hpp>
#include <ghost/variable.hpp>

#include "var_unit.hpp"

using namespace std;
using namespace ghost;

enum ResourceType { Mineral, Gas, Supply };

class Stock : public Constraint<Unit>
{
  int		_quantity;
  ResourceType	_type;

  double required_cost() const override;

public:
  Stock( vector< Unit > *variables, int quantity, ResourceType type );

  inline int get_resource() { return _quantity; }
};
