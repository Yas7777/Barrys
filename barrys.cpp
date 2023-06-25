#include "barrys.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// Prompting User to add a day
pair<string, string> day() {

    string input;
    cout << " Please enter the day";
    map<string, string> workoutDays {
            {"Monday", "Arms & Abs"},
            {"Tuesday", "Full Body-Lower Focus "},
            {"Wednesday", "Chest, Back, & Abs"},
            {"Thursday", "Abs & Ass"},
            {"Friday", "Total Body"},
            {"Saturday", "Full Body-Upper Focus"},
            {"Sunday", "Total Body"}
    };

    if (input == "Monday" || "Tuesday" || "Wednesday" || "Thursday" || "Friday" || "Saturday" || "Sunday") {
        return make_pair(input, workoutDays[input]);
    } else {
        cout << "Invalid input. Please enter a valid day of the week. \n";
        return make_pair("", "");
    }
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
    string data() {
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
int treadmillSprint() {
    int inputSprint;
    cout << "What was your fastest spring level at?";
    cin >> inputSprint;
    return inputSprint;
}
// Delete workout
void deleteWorkout(const string& targetDate) {
    ifstream file("WorkoutData.txt");
    ofstream tempFile("temp.txt");
    string line;
    bool deleteLines = false;

    while (getline(file, line)) {
        // Detect start of a workout
        if (line.substr(0, 15) == "Day of the Week") {
            if (line.find(targetDate) != string::npos) {
                deleteLines = true;
            }
        }
        // Detect end of a workout
        if (line.substr(0, 10) == "==========") {
            deleteLines = false;
        }
        // Write lines not marked for deletion to the temp file
        if (!deleteLines) {
            tempFile << line << "\n";
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
    string dayOfTheWeek = day();
    string workoutDate = date();
    string instructorName = workoutInstructor();
    string inclineData = data();
    int sprintData = treadmillSprint();

    // Open a file in write mode.
    ofstream outfile;
    outfile.open("WorkoutData.txt");

    // Write the data to the file.
    outfile << "Day of the Week: " << dayOfTheWeek << "\n";
    outfile << "Workout Date: " << workoutDate << "\n";
    outfile << "Instructor Name: " << instructorName << "\n";
    outfile << "Incline Data: " << inclineData << "\n";
    outfile << "Sprint Data: " << sprintData << "\n";

    if(choice == 1) {
        // Your existing code to add a workout
    } else if (choice == 2) {
        string targetDate;
        cout << "Enter the date of the workout you want to delete: ";
        cin >> targetDate;
        deleteWorkout(targetDate);
    } else if (choice == 3) {
        return 0;
    }

    // Close the file
    outfile.close();
    return 0;

}

