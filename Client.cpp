
#include "Client.h"

// ++++++++++++++++++++ PRIVATE ++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Client::MenuList()
{
    cout   << Constant::MENU_OPTIONS_MSG
           << Constant::MENU_OPTION_ONE_MSG
           << Constant::MENU_OPTION_TWO_MSG
           << Constant::MENU_OPTION_THREE_MSG
           << Constant::MENU_OPTION_FOUR_MSG
           << Constant::MENU_OPTION_FIVE_MSG << endl;
}

void Client::EnterRequired()
{
    cout << Constant::INFO( Constant::PRESS_ENTER_TO_CONTINUE_MSG ) << endl;
    while( getch() != 13 );
}

void Client::ClearScreen()
{
    system("cls");
}

// VALIDATIONS

bool Client::IsMonthInputValid( unsigned &inputMonth ) const
{
    return ( inputMonth <= 0 || inputMonth > 12 );
}

unsigned Client::ClientMonthInputValidation( unsigned &inputMonth, string &input )
{
    while( IsMonthInputValid( inputMonth ) )
    {
        cout   << Constant::INFO( Constant::MONTH_RANGE_MSG ) << '\n'
               << Constant::SELECTION_INPUT;
        cin >> input;
        try
        {
            inputMonth = stoi( input );
        }
        catch( ... )
        {
            cout << Constant::STATUS( !IsMonthInputValid(inputMonth), Constant::INVALID_NUMERIC_ENTRY_MSG ) << '\n';
        }
    }
    return inputMonth;
}

bool Client::IsYearInputValid( unsigned &inputYear ) const
{
    return ( inputYear <= 2010 || inputYear > 2030 );
}

unsigned Client::ClientYearInputValidation( unsigned &inputYear, string &input )
{
    while( IsYearInputValid(inputYear) )
    {
        cout   << Constant::INFO( Constant::YEAR_RANGE_MSG ) << '\n'
               << Constant::SELECTION_INPUT;
        cin >> input;
        try
        {
            inputYear = stoi( input );
        }
        catch( ... )
        {
            cout << Constant::STATUS( !IsYearInputValid(inputYear), Constant::INVALID_NUMERIC_ENTRY_MSG ) << '\n';
        }
    }
    return inputYear;
}

void Client::OptionOne( Vector<WindRecType> &windRecTypeVector, WindRecType &windRecType )
{
    unsigned clientInputMonth = 0;
    unsigned clientInputYear = 0;
    float sum = 0.0;
    unsigned count = 0;
    float windSpeedMean = 0.0;
    float squareDistanceForEachElement = 0.0;
    float sumSquareDistance = 0.0;
    float variance = 0.0;
    float ssD = 0.0;
    string clientInput;

    unsigned monthInput = ClientMonthInputValidation( clientInputMonth, clientInput );
    unsigned yearInput = ClientYearInputValidation( clientInputYear, clientInput );

    for( unsigned i(0); i<windRecTypeVector.GetUsed(); i++ )
    {
        bool IsClientMonthInputFound = monthInput==windRecTypeVector[i].GetRecordDate().GetMonth();
        bool IsClientYearInputFound = yearInput==windRecTypeVector[i].GetRecordDate().GetYear();

        if( IsClientMonthInputFound && IsClientYearInputFound )
        {
            sum +=windRecTypeVector[i].GetRecordWindSpeed().GetMeasurement();
            count ++;
        }
    }
    windSpeedMean = windRecType.GetRecordWindSpeed().GetMean( sum, count );

    if( count > 0 )
    {
        string monthInString = windRecType.GetRecordDate().GetMonthInStr( monthInput );

        for( unsigned i(0); i<windRecTypeVector.GetUsed(); i++ )
        {
            squareDistanceForEachElement = windRecTypeVector[i].GetRecordWindSpeed().GetMeasurement();
            sumSquareDistance = windRecType.GetRecordWindSpeed().GetVariance( variance, squareDistanceForEachElement, windSpeedMean );
        }
        ssD = windRecType.GetRecordWindSpeed().GetStandardDeviation( sumSquareDistance, count );

        cout    << Constant::OUTPUT << endl;
        cout << setw(5) << " " << windRecType.GetRecordDate().GetMonthInStr(monthInput) << " " << yearInput << ":" << endl;
        cout << setw(8) << " " << Constant::AVERAGE_WINDSPEED << setprecision(3) << windSpeedMean << endl;
        cout << setw(8) << " " << Constant::WINDSPEED_STANDARD_DEVIATION << setprecision(3) << ssD << '\n' << endl;
    }
    else
    {
        cout    << Constant::OUTPUT << endl;
        cout << setw(5) << " " << windRecType.GetRecordDate().GetMonthInStr(monthInput) << " " << yearInput << ": NO DATA" << '\n' << endl;
    }
}

void Client::OptionTwo( Vector<WindRecType> &windRecTypeVector, WindRecType &windRecType )
{
    unsigned clientInputYear = 0;
    string clientInput;
    float monthlySumTemperature[12] = {0.0};
    float monthlyCount[12] = {0};
    unsigned month = 0;
    float temperatureSum = 0.0;
    unsigned monthlyCountSum = 0;
    float temperatureMean = 0.0;
    float squareDistanceForEachElement = 0.0;
    float sumSquareDistance = 0.0;
    float variance = 0.0;
    float ssD = 0.0;

    unsigned yearInput = ClientYearInputValidation( clientInputYear, clientInput );

    for(unsigned i(0); i<windRecTypeVector.GetUsed(); i++ )
    {
        bool IsClientYearInputFound = yearInput==windRecTypeVector[i].GetRecordDate().GetYear();

        if( IsClientYearInputFound )
        {
            month = windRecTypeVector[i].GetRecordDate().GetMonth() -1;
            monthlySumTemperature[month] += windRecTypeVector[i].GetRecordTemperature().GetMeasurement();
            monthlyCount[month] ++;
        }
    }

    cout << Constant::OUTPUT << endl;
    cout << setw(5) << " " << yearInput << endl;
    for( unsigned month(0); month<12; month++ )
    {
        if( monthlyCount[month] > 0 )
        {
            temperatureSum = monthlySumTemperature[month];
            monthlyCountSum = monthlyCount[month];

            temperatureMean = windRecType.GetRecordTemperature().GetMean( temperatureSum, monthlyCountSum );

            for( unsigned i(0); i<windRecTypeVector.GetUsed(); i++ )
            {
                bool IsClientYearInputFound = yearInput==windRecTypeVector[i].GetRecordDate().GetYear();
                bool IsClientMonthEquals = (month + 1)==windRecTypeVector[i].GetRecordDate().GetMonth();

                if( IsClientYearInputFound && IsClientMonthEquals )
                {
                    squareDistanceForEachElement = windRecTypeVector[i].GetRecordTemperature().GetMeasurement();
                    sumSquareDistance = windRecType.GetRecordTemperature().GetVariance( variance, squareDistanceForEachElement, temperatureMean );
                }
            }
            ssD = windRecType.GetRecordTemperature().GetStandardDeviation( sumSquareDistance, monthlyCountSum );

            cout << setw(7) << " " << windRecType.GetRecordDate().GetMonthInStr(month + 1) << ": " << setprecision(3) << temperatureMean << " degrees C, stdev: "
                 << setprecision(3) << ssD << endl;
        }
        else
        {
            cout << setw(7) << " " << windRecType.GetRecordDate().GetMonthInStr(month + 1) << ": No Data" << endl;
        }
    }
    cout << endl;
}

void Client::OptionThree( Vector<WindRecType> &windRecTypeVector, WindRecType &windRecType )
{
    unsigned clientInputYear = 0;
    string clientInput;
    float monthlySumSolarRadiation[12] = {0.0};
    float monthlyCount[12] = {0};
    unsigned month = 0;
    float SolarRadiationSum = 0.0;

    unsigned yearInput = ClientYearInputValidation( clientInputYear, clientInput );

    for(unsigned i(0); i<windRecTypeVector.GetUsed(); i++ )
    {
        bool IsClientYearInputFound = yearInput==windRecTypeVector[i].GetRecordDate().GetYear();

        if( IsClientYearInputFound )
        {
            month = windRecTypeVector[i].GetRecordDate().GetMonth() -1;
            monthlySumSolarRadiation[month] += windRecTypeVector[i].GetRecordSolarRadiation().GetMeasurement();
            monthlyCount[month] ++;
        }
    }

    cout << Constant::OUTPUT << endl;
    cout << setw(5) << " " << yearInput << endl;
    for( unsigned month(0); month<12; month++ )
    {
        if( monthlyCount[month] > 0 )
        {
            SolarRadiationSum = monthlySumSolarRadiation[month];

            cout << setw(7) << " " << windRecType.GetRecordDate().GetMonthInStr(month + 1) << ": " << setprecision(4) << SolarRadiationSum/60000 << " kWh/m2" << endl;
        }
        else
        {
            cout << setw(7) << " " << windRecType.GetRecordDate().GetMonthInStr(month + 1) << ": No Data" << endl;
        }
    }
    cout << endl;
}





// ++++++++++++++++++++ PUBLIC ++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Client::Run( Vector<WindRecType> &recordVec, WindRecType &windRecType )
{
    char user_choice;

    do
    {
        MenuList();

        cout << Constant::SELECTION_INPUT;
        user_choice = getch();
        switch( user_choice )
        {
        case '1':
            cout << Constant::SELECTED_OPTION_ONE_MSG << endl;
            OptionOne( recordVec, windRecType );
            break;
        case '2':
            cout << Constant::SELECTED_OPTION_TWO_MSG << endl;
            OptionTwo( recordVec, windRecType );
            break;
        case '3':
            cout << Constant::SELECTED_OPTION_THREE_MSG << endl;
            OptionThree( recordVec, windRecType );
            break;
        case '4':
            cout << Constant::SELECTED_OPTION_FOUR_MSG << endl;
            break;
        case '5':
            cout << Constant::SELECTED_OPTION_FIVE_MSG << endl;
            exit(0);
            break;
        default:
            break;
        }
        EnterRequired();
        ClearScreen();
    }
    while( user_choice !=27 );
}




