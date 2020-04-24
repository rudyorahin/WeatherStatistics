// Weather Statistics
#include <iostream>
#include <iomanip>

using  namespace std;


struct Month{   // Declaration of the WeatherInfo structure
    double totalRainfall, highTemp, lowTemp, averageTemp;
};
enum Months {
    january, february, march, april,
    may, june, july, august,
    september, october, november, december
};

int main() {

    Month thisYear[12];
    double totalRain = 0;
    double averageRain;
    double highestTemp = 0;
    double lowestTemp = 0;
    int monthHighestTemp = 0, monthLowestTemp = 0;
    double totalTemp = 0, averageTemp;
    int index;

    cout << "Enter values for following data for each month: " << endl;
    for (index = january; index <= december; index = static_cast<Months>(january + 1)){
        cout << "Month : " << (index + 1) << endl;
        cout << "Total rainfall: " << endl;
        cin >> thisYear[index].totalRainfall;
        cout << "High Temperature: " << endl;
        cin >> thisYear[index].highTemp;
        // Validate the high temperature.
        while (thisYear[index].highTemp < -100 || thisYear[index].highTemp > 140){
            cout << "ERROR: Temperature must be in the range "
                 << "of -100 through 140.\n";
            cout << "\tHigh Temperature: ";
            cin >> thisYear[index].highTemp;
        }
        cout << "Low Temperature: " << endl;
        cin >> thisYear[index].lowTemp;
        // Validate the low temperature.
        while (thisYear[index].lowTemp < -100 || thisYear[index].lowTemp > 140){
            cout << "ERROR: Temperature must be in the range "
                 << "of -100 through 140.\n";
            cout << "\tLow Temperature: ";
            cin >> thisYear[index].lowTemp;
        }
        thisYear[index].averageTemp = (thisYear[index].lowTemp + thisYear[index].highTemp) / 2;
        cout << "Average Temperature: " << thisYear[index].averageTemp << endl;
    }

    for (index = january; index <= december; index = static_cast<Months>(january + 1)){
        totalRain += thisYear[index].totalRainfall;
    }

    for (index = january; index <= december; index = static_cast<Months>(january + 1)){

        if (thisYear[index].highTemp > highestTemp) {
            highestTemp = thisYear[index].highTemp;
            monthHighestTemp = index + 1;
        }
        if (thisYear[index].lowTemp < lowestTemp) {
            lowestTemp = thisYear[index].lowTemp;
            monthLowestTemp = index + 1;
        }
    }

    for (index = january; index <= december; index = static_cast<Months>(january + 1)){
        totalTemp += (thisYear[index].lowTemp + thisYear[index].highTemp);
    }

    averageTemp = totalTemp / 24;
    averageRain = totalRain / 12;

    // Display findings.
    cout << fixed << showpoint << setprecision(2);
    cout << "The average monthly rainfall is " << averageRain << endl;
    cout << "The total rainfall for the year is " << totalRain << endl;
    cout << "The highest temperature was " << highestTemp << " on month of " << monthHighestTemp << endl;
    cout << "The lowest temperature was " << lowestTemp << " on month of " << monthLowestTemp << endl;
    cout << "The average temperature of the year is " << averageTemp << endl;

    return 0;
}
