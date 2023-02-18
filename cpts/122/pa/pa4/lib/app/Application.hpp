#include "lib/app/FitnessApp/FitnessApp.hpp"
#include "consts.hpp"

// Singleton for the fitness app
class Application {
    private:

        Application(FitnessApp *fitnessApp) 
            : m_fitnessApp(fitnessApp) 
        {}

        ~Application() {delete m_fitnessApp;}

        static Application *m_singleton;

        FitnessApp *m_fitnessApp;

    public:

        static Application &instance() {
            if (m_singleton == nullptr) {
                m_singleton = new Application(
                    new FitnessApp(FILE_DIET_PLAN, FILE_EXCERCISE_PLAN)
                );
            }
        return *m_singleton;
        }

        static FitnessApp &getFitnessApp() {return *instance().m_fitnessApp;}
};

// static init
Application *Application::m_singleton = nullptr;