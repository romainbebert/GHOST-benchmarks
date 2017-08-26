#pragma once

#include <string>
#include <vector>
#include <memory>

#include <objective.hpp>
#include <variable.hpp>

#include "var_unit.hpp"

using namespace std;
using namespace ghost;

class MaxGroundDPS : public Objective
{
  double required_cost( const vector< shared_ptr< Variable > >& vecVariables ) const override;
  // shared_ptr< Variable > expert_heuristic_variable( const vector< shared_ptr< Variable > >& vecVariables ) const override;

public:
  MaxGroundDPS();
};
