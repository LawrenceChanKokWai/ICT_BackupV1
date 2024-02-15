#ifndef SOLARRADIATION_H_INCLUDED
#define SOLARRADIATION_H_INCLUDED

#include<iostream>

#include "Measurement.h"

using namespace std;

class SolarRadiation: public Measurement
{
public:
    SolarRadiation();
    SolarRadiation( const float &measurement );
};

ostream &operator << ( ostream &output, const SolarRadiation &SR );
istream &operator >> ( istream &input, SolarRadiation &SR );

#endif // SOLARRADIATION_H_INCLUDED
