#include <iostream>
#include <fstream>
#include "lib/utils/list/SinglyLinkedList.hpp"
#include "lib/FitnessPlan/DietPlan/DietPlan.hpp"
#include "lib/FitnessPlan/Excercise/ExcercisePlan.hpp"

class FitnessApp {
    private:
        std::fstream m_dietPlanStream;
        std::fstream m_excercisePlanStream;
        Utils::SinglyLinkedList<DietPlan> m_dietPlans;
        Utils::SinglyLinkedList<ExcercisePlan> m_excercisePlans;

    public:
        FitnessApp(char const* dietPlanStream, char const* excercisePlanStream) 
            : m_dietPlanStream(dietPlanStream), m_excercisePlanStream(excercisePlanStream)
        {};

        FitnessApp &loadDailyPlan();
        FitnessApp &loadWeeklyPlan();
        FitnessApp &displayDailyPlan();
        FitnessApp &displayWeeklyPlan();
};