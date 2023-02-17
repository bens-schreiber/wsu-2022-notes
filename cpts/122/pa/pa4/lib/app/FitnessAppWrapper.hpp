#include "lib/app/FitnessApp/FitnessApp.hpp"
#include "consts.hpp"
class Application {
    private:
        static FitnessApp *m_fitnessApp;
    public:
        static void initialize() { 
            m_fitnessApp = new FitnessApp(FILE_DIET_PLAN, FILE_EXCERCISE_PLAN); 
        }

        static void destroy() { delete m_fitnessApp; }

        const FitnessApp &instance() {return *m_fitnessApp;}
};