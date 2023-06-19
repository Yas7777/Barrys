//
// Created by Yasmeen Abdul Azeem on 6/18/23.
//

#include "barrys.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


// Prompting User to add a day
    string day() {
        string input;
        cout << "Please enter the day: ";
        getline(cin, input);

        if (input == "Monday" || input == "Tuesday" || input == "Wednesday" || input == "Thursday"
            || input == "Friday" || input == "Saturday" || input == "Sunday") {
        } else {
            cout << "Invalid input. Please enter a valid day of the week. \n";
        }

        return input;
    }

// Prompting User to enter the date
    string date() {
        string inputDate;
        cout << "Please enter the date of your workout: ";
        getline(cin, inputDate);
        return inputDate;
    }

// Prompting User to add the instructors name
    string workoutInstructor() {
        string inputWorkoutInstructor;
        cout << "Please enter the name of your instructor";
        getline(cin, inputWorkoutInstructor);
        return inputWorkoutInstructor;
    }

// Prompting user to add Treadmill data
    string TreadmillData() {
        string inputIncline;
        cout << "Was there an incline? (y/n only): ";
        cin >> inputIncline;
        if (inputIncline == "Y" || inputIncline == "y" || inputIncline == "n" || inputIncline == "N") {
        } else {
            cout << "Invalid input ";
        }
        return inputIncline;
    }

// Prompting user to add Treadmill data
int treadmillDatatwo() {
    int inputSprint;
    cout << "What was your fastest spring level at?";
    cin >> inputSprint;
    return inputSprint;
}
int main() {
    string dayOfTheWeek = day();
    string workoutDate = date();
    string instructorName = workoutInstructor();
    string inclineData = TreadmillData();
    // Open a file in write mode.
    ofstream outfile;
    outfile.open("WorkoutData.txt");

    // Write the data to the file.
    outfile << "Day of the Week: " << dayOfTheWeek << "\n";
    outfile << "Workout Date: " << workoutDate << "\n";
    outfile << "Instructor Name: " << instructorName << "\n";
    outfile << "Incline Data: " << inclineData << "\n";

    // Close the file
    outfile.close();
    return 0;

}