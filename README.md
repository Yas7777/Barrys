# Barry's Workout Log

This project idea combined my desire to learn C++ and a way to catalog my Barry's workouts. This is a CLI tool written in C++ where the user can enter specific stats related to the workout. (see Using the Program for more info). It allows users to log their workouts in a separate .txt file. If needed, the user can also delete a workout related to a specific day.

Barry is not a man (in this scenario) - Barry's refers to a 60 min HIIT workout focused on running and floor exercises. In case this piqued your interest - https://www.barrys.com

## Table of Contents

1. Features

2. Using the Program

3. My Hot Takes

4. Future Improvements

## Features

The program stores the workout data in a text file called `WorkoutData.txt.` Each workout is written as a block of lines, including the date, day, workout focus, instructor name, incline, sprint speed, and max weight lifted.

1. **Date Entry**: Prompts the user to enter the date of their workout in the `MM/DD/YYYY` format. It performs a check on the format and validates the date.

2. **Day and Focus Entry**: Asks the user to input the day of the week and returns the workout's focus for that day. For instance, if the user enters "Monday," the focus is "Arms & Abs."

3. **Instructor Entry**: Requests the user to enter the name of their workout instructor. It ensures that the name is not empty and contains only alphabetic characters and spaces.

4. **Incline Data**: Asks the user to input whether there was an incline in their workout (Yes/No).

5. **Sprint Speed Entry**: Prompts users to input their fastest sprint speed. This should be an integer value.

6. **Max Weight Entry**: Asks the user to enter the maximum weight they lifted during their workout.

7. **Delete Workout**: If the user deletes a workout, it prompts them to enter the workout date they wish to delete and removes that workout's data from the log.

## Using the Program

1. Open up your Terminal (On Mac – go to your finder and type `Terminal`)

2. Please check your relevant O/S to find your specific terminal instructions

3. Make sure you have the g++ compiler installed on your Mac. You can check this by typing `g++ --version` in your terminal.

4. Navigate to the directory containing the cpp file using the cd command. For example, if your code is in a folder on your desktop called "Project," you should type `cd Desktop/Project/`.

5. To compile the code, you can use the `g++` command. If your source file is named barrys.cpp, type `g++ -std=c++11 barrys.cpp -o barrys`. This will compile barrys.cpp into an executable named barrys.

6. Congrats! If there were no compilation errors, your code has been successfully compiled. Now, you can run the program by typing `./barrys`.

## CLI Tool Menu Options

### Option 1:  Add a workout
readme_assets/Option_1.png

### Option 2:  Delete a workout
readme_assets/Option_2.png

### Option 3: Exit !

## 🔥My Hot Takes🔥

The delete function was a hassle and is still not clean as I like it to be – but it works.

In the same vein, I wanted the user to be able to edit the workout, but that was like quicksand.

## Future Improvements
My primary motivation was to understand  C++ and *make stuff work*

- [ ] Ability for the user to be able to edit a workout in addition to be able to delete a workout seamlessly
- [ ] A better interface
- [ ] Comprehensive test suite


