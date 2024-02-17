#ifndef PROCESSOR_H_INCLUDED
#define PROCESSOR_H_INCLUDED

#include<iostream>
#include<fstream>
#include<string>

#include "WindRecType.h"
#include "Vector.h"
#include "Constant.h"

using namespace std;

class Processor
{
public:
    static Processor &GetInstance();

    void LoadCSVFilePathToVector( Vector<string> &csvFilePath, ifstream &input, const string &filename );
    void LoadCSVDataToVector( Vector<string> &csvFilePath, Vector<WindRecType> &windRecTypeVec, WindRecType &windRecType );

private:
    static Processor *s_instance;
    unsigned m_dataRead;
    unsigned m_dataInserted;

    Processor();
    void LoadDisplayCount();
};

#endif // PROCESSOR_H_INCLUDED
