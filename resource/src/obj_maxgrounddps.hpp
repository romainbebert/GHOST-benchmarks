#pragma once

#include <string>
#include <vector>

#include <ghost/objective.hpp>
#include <ghost/variable.hpp>

#include "var_unit.hpp"

using namespace std;
using namespace ghost;

class MaxGroundDPS : public Objective<Unit>
{
  double required_cost( vector< Unit > *vecVariables ) const override;
  // Unit expert_heuristic_variable( const vector< Unit >& vecVariables ) const override;

public:
  MaxGroundDPS();
};
