
#include "barrys.h"
using namespace std;

// Prompting User to enter the date
string date() {
    string inputDate;
    cout << "Please enter your workout day (MM/DD/YYYY): ";
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

    // Return date in MM/DD/YYYY format
    return validMonth + "/" + validDay + "/" + validYear;
}

// Prompting User to add a day and its associated focus
pair<string, string> day() {
    string input;
    cout << "Please enter your workout day: ";
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
    // Key exists in the map
    } else {
        return make_pair(input, workoutDays[input]);
    }
}


// Prompting User to add the instructor's name
string workoutInstructor() {
    string inputWorkoutInstructor;
    cout << " Instructor name: ";
    getline(cin, inputWorkoutInstructor);
    return inputWorkoutInstructor;
}

// Prompting user to add Treadmill incline data
string data() {
    string inputIncline;
    cout << "Did you use incline? (Y/N only): ";
    cin >> inputIncline;
    if (inputIncline != "Y" && inputIncline != "y" && inputIncline != "n" && inputIncline != "N") {
        cout << "Invalid input. Please enter 'Y' or 'N' only. \n";
        exit(1);
    }

    // Ignore the newline character left by cin
    cin.ignore();
    return inputIncline;
}

// Prompting user to add Treadmill sprint data
int treadmillSprint() {
    int inputSprint;
    cout << "Fastest sprint? ";
    cin >> inputSprint;

    // Ignore the newline character left by cin
    cin.ignore();
    return inputSprint;
}

// Prompting user to add max weight
int weight() {
    int inputWeight;
    cout << "Max weight lifted? ";
    cin >> inputWeight;
    cin.ignore();
    // Ignore the newline character left by cin
    return inputWeight;
}

void deleteWorkout(string targetDate) {
    ifstream file("WorkoutData.txt");
    vector<string> lines;
    string line;
    // set flag
    bool deleteSection = false;

    while (getline(file, line)) {
        // If we find the data to delete, change Flag to true to start deleting
        // If the concantenation < size of the string, that it means it found the substring
        // within the string
        if (line.find("Workout Date: " + targetDate) < line.size()) {
            deleteSection = true;
        }

        // If we find a new workout while in delete mode - stop deleting (set flag to false)
        if (deleteSection && line.find("Workout Date: ") < line.size()
            && line.find(targetDate) >= line.size()) {
            deleteSection = false;
        }
        // deleteSection == false
        if (!deleteSection) {
            lines.push_back(line);
        }
    }

    file.close();

    // Write the data back to the file
    ofstream outFile("WorkoutData.txt");
    for (const auto &line : lines) {
        outFile << line << "\n";
    }
    outFile.close();
}

// Main function
int main() {
    string input;
    int choice;
    cout << "****************BARRY'S BASIC AF WORKOUT LOG****************\n";
    cout << "Enter your choice (1 for adding a workout, 2 for deleting a workout, 3 for exit): ";
    getline(cin, input);
    choice = stoi(input);

    if (choice == 1) {
        string workoutDate = date();
        pair<string, string> dayOfWorkout = day();
        string instructorName = workoutInstructor();
        string inclineData = data();
        int sprintData = treadmillSprint();
        int weightData = weight();

        ofstream outfile;
        outfile.open("WorkoutData.txt", ios::app); // Append to the existing file
        outfile << "Workout Date: " << workoutDate << "\n";
        outfile << "Day of the Week: " << dayOfWorkout.first << "\n";
        outfile << "Workout Focus: " << dayOfWorkout.second << "\n";
        outfile << "Instructor Name: " << instructorName << "\n";
        outfile << "Incline: " << inclineData << "\n";
        outfile << "Sprint (Max Speed): " << sprintData << "\n";
        outfile << "Max Weight: " << weightData << "\n";
        outfile << "==========\n";
        outfile.close();
        cout << "Workout successfully logged in WorkoutData.txt file. Check out the file created ";

    } else if (choice == 2) {
        string targetDate;
        cout << "Enter the date of the workout you want to delete (MM/DD/YYYY): ";
        getline(cin, targetDate);
        deleteWorkout(targetDate);
        cout << "Workout for" << targetDate << " successfully deleted.";
    } else if (choice == 3) {
        return 0;
    }

    return 0;
}
