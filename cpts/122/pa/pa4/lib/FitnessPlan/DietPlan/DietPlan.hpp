#include <string>
#include "FitnessPlan.hpp"
class DietPlan : public FitnessPlan {

    private: 
        unsigned int m_totalCalories{0};

    public: 

        // Constructor
        DietPlan(std::string name, std::string date, unsigned int totalCalories) 
            : FitnessPlan(name, date), m_totalCalories(totalCalories) 
        {};

        // Copy constructor
        DietPlan(DietPlan &other) 
            : FitnessPlan(other), m_totalCalories(other.m_totalCalories)
        {};

        // Destructor
        // dumb
        ~DietPlan() {
            delete &m_totalCalories;
        }

        // Prompt the user for all new values
        void editGoal() override;

        // Getters
        int getTotalCalories() const { return m_totalCalories;}

        // Setters
        void setTotalCalories(int totalCalories) { m_totalCalories = totalCalories; }
};