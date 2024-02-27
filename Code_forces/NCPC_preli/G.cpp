#include <iostream>
#include <string>

using namespace std;

unsigned day_of_week(unsigned year, unsigned month, unsigned day)
{
    unsigned adjustment, y, m;
    adjustment = (14 - month) / 12;
    y = year - adjustment;
    m = month + (12 * adjustment) - 2;
    // Gregorian:
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7 + 1;
}

bool checkYear(int year)
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    if (year % 4 == 0)
        return true;

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int day, month, year;

        cin >> day >> month >> year;
        // Skip the day of the week string
        string day_of_week_str;
        getline(cin, day_of_week_str);

        int start_day = day_of_week(year, month, 1);
        int days_in_month = (month == 2 && checkYear(year)) ? 29 : 28;
        int current_day = 1;

        cout << "|---------------------------|" << endl;
        cout << "|Sun |Mon |Tue |Wed |Thu |Fri |Sat |" << endl;
        cout << "|---------------------------|" << endl;

        for (int week = 0; week < 6; week++)
        {
            for (int day = 0; day < 7; day++)
            {
                if (week == 0 && day < start_day)
                {
                    cout << "|    ";
                }
                else if (current_day <= days_in_month)
                {
                    printf("|%4d", current_day);
                    current_day++;
                }
                else
                {
                    cout << "|    ";
                }
            }
            cout << "|" << endl;
        }
        cout << "|---------------------------|" << endl;
    }
    return 0;
}