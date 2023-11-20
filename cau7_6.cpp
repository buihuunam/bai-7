#include <iostream>
#include <fstream>
using namespace std;

const int NUM_MONTHS = 3;
const int NUM_DAYS = 30;

// Function to count the occurrences of a specific weather condition in a month
int countWeather(char weatherData[], char condition) {
    int count = 0;
    for (int i = 0; i < NUM_DAYS; i++) {
        if (weatherData[i] == condition) {
            count++;
        }
    }
    return count;
}

int main() {
    char weatherData[NUM_MONTHS][NUM_DAYS];
    ifstream inputFile("RainOrShine.txt");

    // Check if the file was successfully opened
    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    // Read weather data from the file into the array
    for (int month = 0; month < NUM_MONTHS; month++) {
        for (int day = 0; day < NUM_DAYS; day++) {
            inputFile >> weatherData[month][day];
        }
    }

    // Display the weather report
    char conditions[] = {'R', 'C', 'S'};
    string months[] = {"June", "July", "August"};

    for (int month = 0; month < NUM_MONTHS; month++) {
        cout << "Weather report for " << months[month] << ":\n";
        for (char condition : conditions) {
            int count = countWeather(weatherData[month], condition);
            cout << "  " << count << " days were " << (condition == 'R' ? "rainy" : (condition == 'C' ? "cloudy" : "sunny")) << endl;
        }
        cout << endl;
    }

    // Find the month with the largest number of rainy days
    int maxRainyDays = 0;
    int maxRainyMonth = -1;

    for (int month = 0; month < NUM_MONTHS; month++) {
        int rainyDays = countWeather(weatherData[month], 'R');
        if (rainyDays > maxRainyDays) {
            maxRainyDays = rainyDays;
            maxRainyMonth = month;
        }
    }

    cout << "the largest month is " << maxRainyMonth << endl;

    inputFile.close();
    return 0;
}
