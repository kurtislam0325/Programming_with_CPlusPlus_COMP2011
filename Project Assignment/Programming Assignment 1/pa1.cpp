#include <iostream>
using namespace std;

const int Dates[31] = {1,2,3,4,5,6,7,
                      8,9,10,11,12,13,14,
                      15,16,17,18,19,20,21,
                      22,23,24,25,26,27,28,
                      29,30,31};
const char weekdays[7][3] = {"Su","Mo","Tu","We","Th","Fr","Sa"};
const char Months[12][10] = {"January","February","March","April","May","June","July", 
                        "August","September","October","November","December"};
enum weekday {SUN,MON,TUE,WED,THU,FRI,SAT};
enum month {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};
enum month_type {Big,Small,Feb};

const int NUM_DATES[3] = {31,30,28};
const int NUM_WEEKDAYS = 7;
const int NUM_MONTHS = 12;
const int NUM_CAL_SLOTS = 42;

void print_horizontal_calendar(int year, int month, char first_day_of_week)
{
    int index_of_first_weekdays = 0;
    int first_weekdays_of_month = WED;
    int type_of_month = 0;

    int count = 0; 
    int index = 0;

    cout << Months[month-1] << " " << year << endl;
    for (int i = 0; i < NUM_WEEKDAYS; i++)
        if (weekdays[i][0] == first_day_of_week)
        {
            index_of_first_weekdays = i;
            // cout << index_of_first_weekdays << endl;
            break;
        }

    // Print Weekdays
    index = index_of_first_weekdays;
    while (count < NUM_WEEKDAYS)
    {
        if (index > NUM_WEEKDAYS - 1)
            index = 0;
        cout << weekdays[index] << " ";
        index++; count++;
    }

    // Print Dates
    count = 0;
    for (int i = 0; i < NUM_CAL_SLOTS; i++)
    {
        if (i % 7 == 0)
            cout << endl;
        if ((i < first_weekdays_of_month - index_of_first_weekdays) || (count >= NUM_DATES[type_of_month]))
        {
            cout << "  " << " ";
            continue;
        }
        if (Dates[count]/10 < 1)
            cout << " " << Dates[count] << " ";
        else
            cout << Dates[count] << " ";
        count++;
    }
}

void print_vertical_calendar(int year, int month, char first_day_of_week)
{
    int index_of_first_weekdays = 0;
    int first_weekdays_of_month = WED;
    int type_of_month = 0;

    int count = 0;
    int index = 0;

    cout << Months[month-1] << " " << year << endl;
    for (int i = 0; i < NUM_WEEKDAYS; i++)
        if (weekdays[i][0] == first_day_of_week)
        {
            index_of_first_weekdays = i;
            // cout << index_of_first_weekdays << endl;
            break;
        }

    // Print Whole
    index = index_of_first_weekdays;
    int row = 0;
    while (count < NUM_CAL_SLOTS && row < 7)
    {
        if (index > NUM_WEEKDAYS - 1)
            index = 0;
        cout << weekdays[index] << "  ";

        for (int i = 0, j = 0; j < NUM_DATES[Big] && i < 5; j++)
        {
            if ((row+index_of_first_weekdays) < first_weekdays_of_month && i < 1)
            {
                cout << "  " << " ";
                i++;
                count++;
            }
            int x = index + (first_weekdays_of_month+1);
            x = (x>6)? index - first_weekdays_of_month: x;
            if (j % NUM_WEEKDAYS == x)
            {
                if (Dates[j]/10 < 1)
                    cout << " " << Dates[j] << " ";
                else if (Dates[j] >= 1)
                    cout << Dates[j] << " ";
                i++;
                count++;
            }
            else continue;
        }

        row++;
        index++;
        cout << endl;
    }
}

int find_week_day(int day, int month, int year)
{
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= (month < 3);
    return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

void print_calendar_of_a_year(int year, char first_day_of_week)
{
    int first_weekday_of_month = find_week_day (1, 1, year); 
    int type_of_month = Big;

    for (int i = 0; i < 12; i++)
    {
        int type_of_month = 0;
        int starting_weekday = 0;
        int count = 0; 

        cout << Months[i] << " " << year << endl;
        // Print Weekdays
        switch (first_day_of_week)
        {
            case 'S': case 's':
                cout << "Su Mo Tu We Th Fr Sa" << endl;
                starting_weekday = 0;
                break;
            case 'M': case 'm':
                cout << "Mo Tu We Th Fr Sa Su" << endl;   
                starting_weekday = 1;
                break;            
        }

        switch (i)
        {
            case FEB:
                type_of_month = Feb; 
                break;
            case APR: case JUN: case SEP: case NOV: 
                type_of_month = Small; 
                break;
            default:
                type_of_month = Big;
        }
 
        // Print appropriate spaces
        for (count = 0; count < first_weekday_of_month - starting_weekday; count++)
            cout << "  " << " ";
 
        for (int j = 1; j <= NUM_DATES[type_of_month]; j++)
        {
            if (j/10 < 1)
                cout << " " << j << " ";
            else
                cout << j << " ";
            
            // cout << count;
            if (++count > 6)
            {
                count = 0;
                cout << endl;
            }
        }
 
        if (count)
            cout << endl;
 
        first_weekday_of_month = count + starting_weekday;
        cout << first_weekday_of_month << endl;
    }
}

int main (void)
{
    int year = 0;
    int month = 0;
    char first_day_of_week;
    char direction;

    cout << "Enter year (in range 1800-9999): ";
    cin >> year; 
    cout << "Enter month (in range 1-12): ";
    cin >> month; 
    cout << "Enter the first day of week ('S' for Sunday, 'M' for Monday): ";
    cin >> first_day_of_week; 
    if (month == -1)
        print_calendar_of_a_year(year, first_day_of_week);
    else 
    {

        cout << "Print horizontally (H) or vertically (V): "; 
        cin >> direction;

        if (direction == 'h' || direction == 'H')
            print_horizontal_calendar(year, month, first_day_of_week);
        else if (direction == 'v' || direction == 'V')
            print_vertical_calendar(year, month, first_day_of_week);
    }

    return 0;
}