
#include "Measurement.h"

Measurement::Measurement()
{
    m_measurement = INITIAL_VALUE;
}

Measurement::Measurement( const float &measurement )
{
    m_measurement = measurement;
}

float Measurement::GetMeasurement() const
{
    return m_measurement;
}

void Measurement::SetMeasurement( const float &measurement )
{
    m_measurement = measurement;
}

float Measurement::GetMean( float &sum, unsigned &count ) {
    return (sum / count);
}

float Measurement::GetVariance( float &variance, float &squareDistance, float &mean )
{
    return variance += pow( (squareDistance - mean ), 2);
}

float Measurement::GetStandardDeviation( float &variance, unsigned &count )
{
    variance /= count;
    return sqrt( variance );
}

