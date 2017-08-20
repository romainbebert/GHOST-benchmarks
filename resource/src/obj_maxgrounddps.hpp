#pragma once

#include <string>
#include <vector>
#include <memory>

#include <objective.hpp>

#include "unit.hpp"

using namespace std;
using namespace ghost;

class MaxGroundDPS : public Objective
{
  double required_cost( const vector< shared_ptr< Unit > > &vecVariables ) const override;
  
public:
  MaxGroundDPS();
}
