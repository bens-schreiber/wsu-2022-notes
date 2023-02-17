#include "FitnessPlan.hpp"
#include <iostream>
void FitnessPlan::editGoal() {

    std::cout << "Enter the name of your Fitness Plan: ";
    std::string name;
    std::cin >> name;

    std::cout << "Enter the date of your Fitness Plan: ";
    std::string date;
    std::cin >> date;

    setName(name);
    setDate(date);
}