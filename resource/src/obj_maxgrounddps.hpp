#include <string>

#include "objective.hpp"

using namespace ghost;

class MaxGroundDPS : public Objective
{
  double required_cost( const vector< shared_ptr< Variable > > &vecVariables ) const override;
  
public:
  MaxGroundDPS( const string& name );
}
