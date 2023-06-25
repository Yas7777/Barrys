#include "barrys.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
#include <chrono>
#include <iostream>

using namespace std;

// Prompting User to enter the date
string date() {
    string inputDate;
    cout << "Please enter the date of your workout (MM/DD/YYYY): ";
    getline(cin, inputDate);

    // Check if the input date has the correct format (MM/DD/YYYY)
    if (inputDate.size() != 10 || inputDate[2] != '/' || inputDate[5] != '/') {
        cout << "Invalid date. Please enter a date in the format MM/DD/YYYY. \n";
        exit(1);
    }

    // Extract month, day, and year from the input date
    string validMonth = inputDate.substr(0, 2);
    string validDay = inputDate.substr(3, 2);
    string validYear = inputDate.substr(6, 4);

    // Convert extracted components to integers
    int month = stoi(validMonth);
    int day = stoi(validDay);
    int year = stoi(validYear);

    // Perform additional checks for valid dates
    if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
        cout << "Invalid date. Please enter a valid date. \n";
        exit(1);
    }

    return validMonth + "/" + validDay + "/" + validYear;  // Return date in MM/DD/YYYY format
}

// Prompting User to add a day and its associated focus
pair<string, string> day() {
    string input;
    cout << "Please enter the day: ";
    getline(cin, input);

    map<string, string> workoutDays {
            {"Monday", "Arms & Abs"},
            {"Tuesday", "Full Body-Lower Focus"},
            {"Wednesday", "Chest, Back, & Abs"},
            {"Thursday", "Abs & Ass"},
            {"Friday", "Total Body"},
            {"Saturday", "Full Body-Upper Focus"},
            {"Sunday", "Total Body"}
    };

    // Error Check else return the pair
    if (workoutDays.count(input) == 0) {
        cout << "Invalid input. Please enter a valid day of the week. \n";
        exit(1);
    } else {
        // Key exists in the map
        return make_pair(input, workoutDays[input]);
    }
}

// Prompting User to add the instructor's name
string workoutInstructor() {
    string inputWorkoutInstructor;
    cout << "Please enter the name of your instructor: ";
    getline(cin, inputWorkoutInstructor);

    // Check if the name is empty
    if (inputWorkoutInstructor.empty()) {
        cout << "Invalid input. Please enter a valid instructor name. \n";
        exit(1);
    }

    // Check if the name contains any non-alphabetic characters
    for (char ch : inputWorkoutInstructor) {
        if (!isalpha(ch) && !isspace(ch)) {
            cout << "Invalid input. Please enter a valid instructor name. \n";
            exit(1);
        }
    }
    return inputWorkoutInstructor;
}

// Prompting user to add Treadmill data
string data() {
    string inputIncline;
    cout << "Was there an incline? (y/n only): ";
    cin >> inputIncline;
    if (inputIncline != "Y" && inputIncline != "y" && inputIncline != "n" && inputIncline != "N") {
        cout << "Invalid input. Please enter 'Y' or 'N' only. \n";
        exit(1);
    }
    cin.ignore();  // Ignore the newline character left by cin
    return inputIncline;
}

// Prompting user to add Treadmill data
int treadmillSprint() {
    string input;
    cout << "What was your fastest sprint level at? ";
    getline(cin, input);
    return stoi(input);
}

void deleteWorkout(string targetDate) {
    ifstream file("WorkoutData.txt");
    ofstream tempFile("temp.txt");
    string line;
    bool deleteSection = false;

    while (getline(file, line)) {
        // If we find the date to delete, set flag to true to start deleting
        if (line.find("Workout Date: " + targetDate) < line.size()) {
            deleteSection = true;
        }

        // If we find a new workout while in delete mode, stop deleting
        if (deleteSection && line.find("Workout Date: ") < line.size() && line.find(targetDate) >= line.size()) {
            deleteSection = false;
        }

        // If not in delete mode, write the line to the temp file
        if (!deleteSection) {
            tempFile << line << "\n";
        }
    }

    file.close();
    tempFile.close();

    // Delete the original file and rename the temporary file
    remove("WorkoutData.txt");
    rename("temp.txt", "WorkoutData.txt");
}


int main() {
    string input;
    int choice;
    cout << "Enter your choice (1 for adding a workout, 2 for deleting a workout, 3 for exit): ";
    getline(cin, input);
    choice = stoi(input);

    if (choice == 1) {
        string workoutDate = date();
        pair<string, string> dayOfWorkout = day();
        string instructorName = workoutInstructor();
        string inclineData = data();
        int sprintData = treadmillSprint();

        ofstream outfile;
        outfile.open("WorkoutData.txt", ios::app); // Append to the existing file
        outfile << "Workout Date: " << workoutDate << "\n";
        outfile << "Day of the Week: " << dayOfWorkout.first << "\n";
        outfile << "Workout Focus: " << dayOfWorkout.second << "\n";
        outfile << "Instructor Name: " << instructorName << "\n";
        outfile << "Incline Data: " << inclineData << "\n";
        outfile << "Sprint Data: " << sprintData << "\n";
        outfile << "==========\n";

        outfile.close();
    } else if (choice == 2) {
        string targetDate;
        cout << "Enter the date of the workout you want to delete (MM/DD/YYYY): ";
        getline(cin, targetDate);
        deleteWorkout(targetDate);
    } else if (choice == 3) {
        return 0;
    }

    return 0;
}