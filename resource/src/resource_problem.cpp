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

  // Define objective
  shared_ptr<MaxGroundDPS> objective = make_shared<MaxGroundDPS>();

  ////////////
  // Terran //
  ////////////
  
  // Create variables
  auto variables_t = make_terran( 380 );    

  // Define constraints 
  Stock mineral_t( &variables_t, 20000, ResourceType::Mineral );
  Stock gas_t( &variables_t, 14000, ResourceType::Gas );
  Stock supply_t( &variables_t, 380, ResourceType::Supply );
  
  vector< Stock > constraints_t { mineral_t, gas_t, supply_t };

  // Define solver
  Solver<Unit, Stock> solver_t( variables_t,
  				constraints_t,
  				objective );

  double cost_t = 0.;
  vector<int> solution_t( variables_t.size(), 0 );

  // bool found_t = solver_t.solve( cost_t, solution_t, 20, 130 );
  // bool found = solver_t.solve( cost_t, solution_t, 100, 1500 );
  // bool found = solver_t.solve( cost_t, solution_t, 1000, 15000 );

  int count = 0;
  double total = 0.;
  
  for(int i = 0 ; i < 100 ; ++i )
    if( solver_t.solve( cost_t, solution_t, 20, 130 ) )
    {
      ++count;
      total += cost_t;
    }

  cout << "*** Terran ***\n"
       << "Success rate: " << count << "%\n"
       << "Mean score: " << total/count << "\n\n";  
  
  // if( found_t )
  // {
  //   cout << "Cost: " << cost_t << "\n*********\n";
  //   for( auto& v : variables_t )
  //     cout << v.get_name() << ":" << solution_t[ v.get_id() ] << "\n";
  // }
  // else
  //   cout << "No solutions found\n";

  /////////////
  // Protoss //
  /////////////
  
  // Create variables
  auto variables_p = make_protoss( 380 );    

  // Define constraints 
  Stock mineral_p( &variables_p, 20000, ResourceType::Mineral );
  Stock gas_p( &variables_p, 14000, ResourceType::Gas );
  Stock supply_p( &variables_p, 380, ResourceType::Supply );
  
  vector< Stock > constraints_p { mineral_p, gas_p, supply_p };

  // Define solver
  Solver<Unit, Stock> solver_p( variables_p,
  				constraints_p,
  				objective );

  double cost_p = 0.;
  vector<int> solution_p( variables_p.size(), 0 );
  
  // bool found_p = solver_p.solve( cost_p, solution_p, 20, 130 );
  // bool found = solver_p.solve( cost_p, solution_p, 100, 1500 );
  // bool found = solver_p.solve( cost_p, solution_p, 1000, 15000 );

  count = 0;
  total = 0.;
  
  for(int i = 0 ; i < 100 ; ++i )
    if( solver_p.solve( cost_p, solution_p, 20, 130 ) )
    {
      ++count;
      total += cost_p;
    }

  cout << "*** Protoss ***\n"
       << "Success rate: " << count << "%\n"
       << "Mean score: " << total/count << "\n\n";  

  // if( found_p )
  // {
  //   cout << "Cost: " << cost_p << "\n*********\n";
  //   for( auto& v : variables_p )
  //     cout << v.get_name() << ":" << solution_p[ v.get_id() ] << "\n";
  // }
  // else
  //   cout << "No solutions found\n";

  //////////
  // Zerg //
  //////////
  
  // Create variables
  auto variables_z = make_zerg( 380 );    

  // Define constraints 
  Stock mineral_z( &variables_z, 20000, ResourceType::Mineral );
  Stock gas_z( &variables_z, 14000, ResourceType::Gas );
  Stock supply_z( &variables_z, 380, ResourceType::Supply );
  
  vector< Stock > constraints_z { mineral_z, gas_z, supply_z };

  // Define solver
  Solver<Unit, Stock> solver_z( variables_z,
  				constraints_z,
  				objective );

  double cost_z = 0.;
  vector<int> solution_z( variables_z.size(), 0 );
  
  // bool found_z = solver_z.solve( cost_z, solution_z, 20, 130 );
  // bool found = solver_z.solve( cost_z, solution_z, 100, 1500 );
  // bool found = solver_z.solve( cost_z, solution_z, 1000, 15000 );

  count = 0;
  total = 0.;
  
  for(int i = 0 ; i < 100 ; ++i )
    if( solver_z.solve( cost_z, solution_z, 20, 130 ) )
    {
      ++count;
      total += cost_z;
    }
  
  cout << "*** Zerg ***\n"
       << "Success rate: " << count << "%\n"
       << "Mean score: " << total/count << "\n\n";  

  // if( found_z )
  // {
  //   cout << "Cost: " << cost_z << "\n*********\n";
  //   for( auto& v : variables_z )
  //     cout << v.get_name() << ":" << solution_z[ v.get_id() ] << "\n";
  // }
  // else
  //   cout << "No solutions found\n";
}

