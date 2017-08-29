#include <vector>

#include <ghost/solver.hpp>

#include "var_unit.hpp"
#include "ctr_stock.hpp"
#include "obj_maxgrounddps.hpp"
#include "factory_unit.hpp"

using namespace ghost;
using namespace std;

int main(int argc, char **argv)
{
  // Create variables
  auto variables = make_terran( 380 );    

  // Define constraints 
  Stock mineral( &variables, 20000, ResourceType::Mineral );
  Stock gas( &variables, 14000, ResourceType::Gas );
  Stock supply( &variables, 380, ResourceType::Supply );
  
  vector< Stock > constraints { mineral, gas, supply };

  // Define objective
  shared_ptr<MaxGroundDPS> objective = make_shared<MaxGroundDPS>();

  // Define solver
  Solver<Unit, Stock> solver( variables, constraints, objective );

  double cost = 0.;
  vector<int> solution( variables.size(), -1 );
  
  // bool found = solver.solve( cost, solution, 1000, 15000 );
  bool found = solver.solve( cost, solution, 20, 130 );
  // bool found = solver.solve( cost, solution, 100, 1500 );

  if( found )
  {
    cout << "Cost: " << cost
    	 << "\nVia Variables\n";
    for( auto& v : variables )
      cout << v.get_name() << ":" << v.get_value() << "\n";
    
    cout << "Cost: " << cost << "\n*********\n";
    for( auto& v : variables )
      cout << v.get_name() << ":" << solution[ v.get_id() ] << "\n";
  }
  else
    cout << "No solutions found\n";
}

