#include <vector>

#include <solver.hpp>

#include "var_unit.hpp"
#include "ctr_stock.hpp"
#include "obj_maxgrounddps.hpp"
#include "factory_unit.hpp"

using namespace ghost;
using namespace std;

int main(int argc, char **argv)
{
  // Create variables
  auto variables = make_terran();    
    
  // Define constraints 
  shared_ptr< Constraint > mineral = make_shared<Stock>( variables, 20000, ResourceType::Mineral );
  shared_ptr< Constraint > gas = make_shared<Stock>( variables, 14000, ResourceType::Gas );
  shared_ptr< Constraint > supply = make_shared<Stock>( variables, 200, ResourceType::Supply );
  
  vector< shared_ptr< Constraint > > constraints { mineral, gas, supply };

  // Define objective
  shared_ptr<Objective> objective = make_shared<MaxGroundDPS>();

  // Define solver
  Solver solver( variables, constraints, objective );

  double cost = 0.;
  vector<int> solution;
  
  solver.solve( cost, solution, 30, 1000 );  
}
