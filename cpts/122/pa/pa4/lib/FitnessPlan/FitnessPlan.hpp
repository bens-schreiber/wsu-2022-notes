#include <string>

// Private base class 
class FitnessPlan {

    protected:
        std::string m_name{0};
        std::string m_date{0};

        // Constructor
        FitnessPlan(std::string name, std::string date)
            : m_name(name), m_date(date)
        {};

        // Copy constructor
        FitnessPlan(FitnessPlan &other) 
            : m_name(other.m_name), m_date(other.m_date)
        {}

        // Destructor
        // dumb, not really needed
        ~FitnessPlan() {
            delete &m_name;
            delete &m_date;
        }

    public: 

        // Prompt the user for all new values
        virtual void editGoal();

        // Getters
        const std::string &getName() const { return m_name; }
        const std::string &getDate() const { return m_date; }

        // Setters
        void setDate(std::string &date) { m_date = date; }
        void setName(std::string &name) { m_name = name; }
};