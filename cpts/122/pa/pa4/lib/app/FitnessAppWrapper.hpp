#include "FitnessApp.hpp"
class Application {
    private:
        static FitnessApp *m_fitnessApp = nullptr;
    public:
        static void initialize() { 
            fitnessApp = new FitnessApp(); 
        }

        static void destroy() { delete m_fitnessApp; }

        const FitnessApp &instance() {return m_fitnessApp;}
}