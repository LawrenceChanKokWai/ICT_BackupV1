#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include<iostream>
#include<sstream>
#include<iomanip>
#include<conio.h>
#include<cstdlib>

#include "Processor.h"
#include "Constant.h"

using namespace std;

class Client
{
public:
    void Run( Vector<WindRecType> &recordVec, WindRecType &windRecType );


private:
    void MenuList();
    void EnterRequired();
    void ClearScreen();

    bool IsMonthInputValid( unsigned &inputMonth ) const;
    unsigned ClientMonthInputValidation( unsigned &inputMonth, string &input );

    bool IsYearInputValid( unsigned &inputYear ) const;
    unsigned ClientYearInputValidation( unsigned &inputYear, string &input );

    void OptionOne( Vector<WindRecType> &windRecTypeVector, WindRecType &windRecType );
    void OptionTwo( Vector<WindRecType> &windRecTypeVector, WindRecType &windRecType );
    void OptionThree( Vector<WindRecType> &windRecTypeVector, WindRecType &windRecType );



};

#endif // CLIENT_H_INCLUDED
