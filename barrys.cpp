#include "barrys.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
#include <chrono>
#include <iostream>

using namespace std;


// Prompting User to add a day and its associated focus
pair<string, string> day() {
    string input;
    cout << "Please enter the day: ";
    getline(cin, input);

    map<string, string> workoutDays {
            {"Monday", "Arms & Abs"},
            {"Tuesday", "Full Body-Lower Focus "},
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

// Prompting User to enter the date
string date() {
    string inputDate;
    cout << "Please enter the date of your workout: ";
    getline(cin, inputDate);

// Check if the input date has the correct format
// The size of 10 ==  format "DD/MM/YYYY"

    if (inputDate.size() != 10 || inputDate[3] != '/' || inputDate[6] != '/') {
        cout << "Invalid date. Please enter a date in the format YYYY/MM/DD. \n";
        exit(1);
    }
    // Basic Check for valid dates
    string validDay = inputDate.substr(0,2);
    string validMonth = inputDate.substr(3,2);
    string validYear = inputDate.substr(6,4);
    int day = stoi(validDay);
    int month = stoi (validMonth);
    int year = stoi(validYear);

    if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
        cout << "Invalid date. Please enter a valid date. \n";
        exit(1);
    }
    return inputDate;
}

// Prompting User to add the instructors name
string workoutInstructor() {
    string inputWorkoutInstructor;
    cout << "Please enter the name of your instructor: ";
    getline(cin, inputWorkoutInstructor);
    return inputWorkoutInstructor;
}

// Prompting user to add Treadmill data
string data() {
    string inputIncline;
    cout << "Was there an incline? (y/n only): ";
    cin >> inputIncline;
    if (inputIncline == "Y" || inputIncline == "y" || inputIncline == "n" || inputIncline == "N") {
    } else {
        cout << "Invalid input ";
    }
    cin.ignore();  // Ignore the newline character left by cin
    return inputIncline;
}

// Prompting user to add Treadmill data
int treadmillSprint() {
    string input;
    cout << "What was your fastest spring level at? ";
    getline(cin, input);
    return stoi(input);
}

void deleteWorkout(const string& targetDate) {
    ifstream file("WorkoutData.txt");
    ofstream tempFile("temp.txt");
    string line;
    vector<string> workout;

    while (getline(file, line)) {
        if (line.find("Day of the Week: ") == 0) {  // Start of a new workout
            // If the last workout doesn't contain the target date, write it to the temp file
            if (!workout.empty()) {
                string workoutStr = accumulate(workout.begin(), workout.end(), string(""));
                if (workoutStr.find(targetDate) == string::npos) {
                    for (const auto& l : workout) {
                        tempFile << l << "\n";
                    }
                }
                workout.clear();
            }
        }
        workout.push_back(line);
    }
    // Don't forget to handle the last workout
    if (!workout.empty()) {
        string workoutStr = accumulate(workout.begin(), workout.end(), string(""));
        if (workoutStr.find(targetDate) == string::npos) {
            for (const auto& l : workout) {
                tempFile << l << "\n";
            }
        }
    }

    file.close();
    tempFile.close();

    // Remove the original file and rename the temporary file
    remove("WorkoutData.txt");
    rename("temp.txt", "WorkoutData.txt");
}



// Main function
int main() {
    string input;
    int choice;
    cout << "Enter your choice (1 for adding a workout, 2 for deleting a workout, 3 for exit): ";
    getline(cin, input);
    choice = stoi(input);

    if(choice == 1) {
        pair<string, string> dayOfWorkout = day();
        string workoutDate = date();
        string instructorName = workoutInstructor();
        string inclineData = data();
        int sprintData = treadmillSprint();

        ofstream outfile;
        outfile.open("WorkoutData.txt", ios::app); // Append to the existing file

        outfile << "Day of the Week: " << dayOfWorkout.first << "\n";
        outfile << "Workout Focus: " << dayOfWorkout.second << "\n";
        outfile << "Workout Date: " << workoutDate << "\n";
        outfile << "Instructor Name: " << instructorName << "\n";
        outfile << "Incline Data: " << inclineData << "\n";
        outfile << "Sprint Data: " << sprintData << "\n";
        outfile << "==========\n";

        outfile.close();
    } else if (choice == 2) {
        string targetDate;
        cout << "Enter the date of the workout you want to delete: ";
        getline(cin, targetDate);
        deleteWorkout(targetDate);
    } else if (choice == 3) {
        return 0;
    }

    return 0;
}
