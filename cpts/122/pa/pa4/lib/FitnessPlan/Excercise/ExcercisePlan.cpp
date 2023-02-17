#include "ExcercisePlan.hpp"
#include <iostream>

void ExcercisePlan::editGoal() {
    FitnessPlan::editGoal();
    std::cout << "Enter your total calories: ";
    unsigned int totalCalories;
    std::cin >> totalCalories;
    setTotalCalories(totalCalories);
}