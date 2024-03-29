
#include<iostream>
#include<fstream>

#include "Processor.h"
#include "Client.h"

using namespace std;

int main()
{

    // Initialize required variables
    const string file = "data/data_source.txt";
    ifstream inFile( file );
    WindRecType windRecType;
    Vector<string> csvFilePath;
    Vector<WindRecType> windRecTypeVector;
    Client menu;

    // routines
    Processor::GetInstance();                                                                       // create singleton instance
    Processor::GetInstance().LoadCSVFilePathToVector( csvFilePath, inFile, file );                  // Loading csv file path from txt file
    Processor::GetInstance().LoadCSVDataToVector( csvFilePath, windRecTypeVector, windRecType );    // Loading data into vector

    menu.Run( windRecTypeVector, windRecType );


    return 0;
}
