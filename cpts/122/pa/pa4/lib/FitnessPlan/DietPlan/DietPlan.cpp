#include "DietPlan.hpp"
#include <iostream>

void DietPlan::editGoal() {
    FitnessPlan::editGoal();
    std::cout << "Enter your total calories: ";
    unsigned int totalCalories;
    std::cin >> totalCalories;
    setTotalCalories(totalCalories);
}