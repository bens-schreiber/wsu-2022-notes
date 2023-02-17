#include <iostream>
#include "DietPlan.hpp"
#include "ExcercisePlan.hpp"

namespace std {

    std::ostream& operator<<(std::ostream& os, const DietPlan& dietPlan) {
            os << dietPlan.getDate() << dietPlan.getName() << dietPlan.getTotalCalories();
            return os;
    }

    std::ostream& operator<<(std::ostream& os, const ExcercisePlan& excercisePlan) {
            os << excercisePlan.getDate() << excercisePlan.getName() << excercisePlan.getSteps();
            return os;
    }
}