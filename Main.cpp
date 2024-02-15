
#include<iostream>
#include<fstream>

#include "WindRecType.h"
#include "Vector.h"

using namespace std;

int main()
{
    const string FILENAME( "data/data_source.txt" );
    Vector<WindRecType> records;

    ifstream inFile( FILENAME );
    if( !inFile )
    {
        return -1;
    }

    string line;
    while( inFile.peek() != EOF )
    {
        inFile >> line;

        string modifiedFile = "data/" + line;
        ifstream files( modifiedFile );
        if( !files )
        {
            return -1;
        }

        string line;
        WindRecType wrt;
        getline( files, line );
        while( files.peek() != EOF )
        {
            files >> wrt;
            records.InsertObject( wrt );
            //cout << wrt << endl;
        }

        cout << records[0] << endl;
    }

    return 0;
}
