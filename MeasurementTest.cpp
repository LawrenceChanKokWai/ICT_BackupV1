
#include<iostream>

#include "Measurement.h"

using namespace std;

void Assert( bool condition, const string &message );
void TestInitialization( const Measurement &measurement );
void TestParameterizedConstructor( const Measurement &measurement );
void TestSettingMeasurement( const Measurement &measurement );

int main()
{
    Measurement myMeasurement;
    Measurement paramMeasurement( 12.5 );

    TestInitialization( myMeasurement );
    TestParameterizedConstructor( paramMeasurement );

    paramMeasurement.SetMeasurement( 14.5 );
    TestSettingMeasurement( paramMeasurement );

    return 0;
}

void Assert( bool condition, const string &message )
{
    if( condition )
    {
        cout << "\t[ PASS ] " << message << endl;
    }
    else
    {
        cout << "\t[ FAIL ] " << message << endl;
    }
}

void TestInitialization( const Measurement &measurement )
{
    cout << "Test on Default Measurement Object" << endl;
    Assert( measurement.GetMeasurement() == 0.0, "Default Measurement set as 0.0" );
    cout << endl;
}

void TestParameterizedConstructor( const Measurement &measurement )
{
    cout << "Test on Default Measurement Object" << endl;
    Assert( measurement.GetMeasurement() == 12.5, "Parameterized Measurement set as 12.5" );
    cout << endl;
}

void TestSettingMeasurement( const Measurement &measurement )
{
    cout << "Test on Setting Measurement on Object" << endl;
    Assert( measurement.GetMeasurement() == 14.5, "Setting 14.5 to Measurement Object" );
    cout << endl;
}
