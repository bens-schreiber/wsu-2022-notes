#include <string>
#include "FitnessPlan.hpp"
class ExcercisePlan : FitnessPlan {

    private: 
        unsigned int m_steps{0};

    public: 

        // Constructor
        ExcercisePlan(std::string name, std::string date, unsigned int totalCalories) 
            : FitnessPlan(name, date), m_steps(totalCalories) 
        {};

        // Copy constructor
        ExcercisePlan(ExcercisePlan &other) 
            : FitnessPlan(other), m_steps(other.m_steps)
        {};

        // Destructor
        // dumb
        ~ExcercisePlan() {
            delete &m_steps;
        }

        // Prompt the user for all new values
        void editGoal();

        // Getters
        int getSteps() const { return m_steps;}

        // Setters
        void setTotalCalories(int steps) { m_steps = steps; }
};