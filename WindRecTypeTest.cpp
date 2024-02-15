
#include<iostream>

#include "WindRecType.h"

using namespace std;

void Assert( bool condition, const string &message );
void TestDefaultConstructor( WindRecType &windRecord, const string &title, const string &subTitleOne, const string &subTitleTwo );
void TestParameterizedObject( WindRecType &windRecord, const string &title, const string &subTitleOne, const string &subTitleTwo );
void TestSetDateTimeObject( WindRecType &windRecord, const string &title, const string &subTitleOne, const string &subTitleTwo );

int main()
{
    WindRecType windRecType;
    Date date(11,12,2010);
    Time time(11,22);
    WindRecType paramWindRecords( date, time );

    TestDefaultConstructor( windRecType, "Test On Default Constructor", "[ Date Object ] --> ", "[ Time Object ] --> " );
    TestParameterizedObject( paramWindRecords, "Test On Parameterized Constructor", "[ Date Object ] --> ", "[ Time Object ] --> " );

    paramWindRecords.SetRecordDate(Date(22,12,2021));
    paramWindRecords.SetRecordTime(Time(12,10));
    TestSetDateTimeObject( paramWindRecords, "Test On Setting Date And Time Object", "[ Date Object ] --> ", "[ Time Object ] --> " );

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

void TestDefaultConstructor( WindRecType &windRecord, const string &title, const string &subTitleOne, const string &subTitleTwo )
{
    cout << title << endl;
    cout << '\t' << subTitleOne << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetDay()==0,   "Date Object day as 0" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetMonth()==0, "Date Object month as 0" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetYear()==0,  "Date Object year as 0" );
    cout << '\t' << subTitleTwo << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTime().GetHour()==0,   "Time Object hour as 0" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTime().GetMinute()==0, "Time Object minute as 0" );
    cout << endl;
}

void TestParameterizedObject( WindRecType &windRecord, const string &title, const string &subTitleOne, const string &subTitleTwo )
{
    cout << title << endl;
    cout << '\t' << subTitleOne << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetDay()==11,   "Date Object day as 11" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetMonth()==12, "Date Object month as 12" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetYear()==2010,  "Date Object year as 2010" );
    cout << '\t' << subTitleTwo << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTime().GetHour()==11,   "Time Object hour as 11" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTime().GetMinute()==22, "Time Object minute as 22" );
    cout << endl;
}

void TestSetDateTimeObject( WindRecType &windRecord, const string &title, const string &subTitleOne, const string &subTitleTwo )
{
    cout << title << endl;
    cout << '\t' << subTitleOne << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetDay()==22,   "Date Object day has been set as 22" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetMonth()==12,   "Date Object month has been set as 12" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetYear()==2021,   "Date Object year has been set as 2021" );
    cout << '\t' << subTitleTwo << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTime().GetHour()==12,   "Time Object hour has been set as 12" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTime().GetMinute()==10,   "Time Object minute has been set as 10" );
    cout << endl;
}
