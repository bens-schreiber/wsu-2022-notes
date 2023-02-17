#include <iostream>
#include <fstream>

class FitnessApp {
    private:
        std::fstream m_dietPlanStream;
        std::fstream m_excercisePlanStream;
    public:
        FitnessApp(std::fstream dietPlanStream, std::fstream excercisePlanStream) 
            : m_dietPlanStream(dietPlanStream), m_excercisePlanStream(excercisePlanStream)
        {}

        FitnessApp &loadDailyPlan();
        FitnessApp &loadWeeklyPlan();
        FitnessApp &displayDailyPlan();
        FitnessApp &displayWeeklyPlan();
}