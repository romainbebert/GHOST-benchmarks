#pragma once

#include <string>
#include <ghost/variable.hpp>

using namespace std;
using namespace ghost;

class Unit : public Variable
{
  int		_mineral;
  int		_gas;
  double	_supply;
  double	_dps;

public:
  Unit( const string& name,
	const string& shortName,
	int supplyAvailable,
	int m,
	int g,
	double s,
	double dps);

  inline int	get_mineral()	const { return _mineral; }
  inline int	get_gas()	const { return _gas; }
  inline double get_supply()	const { return _supply; }
  inline int	get_dps()	const { return _dps; }
};
