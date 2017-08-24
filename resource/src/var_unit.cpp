#include "var_unit.hpp"

Unit::Unit( const string& name,
	    const string& shortName,
	    int supplyAvailable,
	    int m,
	    int g,
	    double s,
	    double dps)
  : Variable( name, shortName, -1, supplyAvailable + 1, 0 ),
    _mineral	( m ),
    _gas	( g ),
    _supply	( s ),
    _dps	( dps )
{ }
