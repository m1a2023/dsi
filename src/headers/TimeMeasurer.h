#include <iostream>
#include <functional>
#include <chrono>

namespace dsi {
    template <typename T>
    class TimeMeasurer {
    public:
        // Constructor and destructor
        TimeMeasurer();
        ~TimeMeasurer();

        // Core method
        double measure_action(std::function<T()> function);

    private:

        //data_structure
    };

    template <typename T>
    TimeMeasurer<T>::TimeMeasurer(/*data_struct*/) {
        //this->data_struct
    }

    template <typename T>
    TimeMeasurer<T>::~TimeMeasurer() {}

    template <typename T>
    double TimeMeasurer<T>::measure_action(std::function<T()> function) {
        auto start = std::chrono::high_resolution_clock::now();

        function();

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }
}