#include "FitnessApp.hpp"
class FitnessAppWrapper {
    private:
        static FitnessApp *fitnessApp = nullptr;
    public:
        static void initialize() { fitnessApp = new FitnessApp(); }

        static void destroy() { delete fitnessApp; }
}