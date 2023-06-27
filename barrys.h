#ifndef BARRYS_H
#define BARRYS_H

#include <iostream>
#include <algorithm>
#include <map>
#include <chrono>
#include <fstream>
#include <vector>

std::string date();
std::pair<std::string, std::string> day();
std::string workoutInstructor();
std::string data();
int treadmillSprint();
int weight();
void deleteWorkout(std::string targetDate);

#endif // BARRYS_H