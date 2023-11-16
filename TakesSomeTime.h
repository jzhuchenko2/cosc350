#pragma once

#include <chrono>
#include <iostream>
#include <random>
#include <thread>

/**
 * @class TakesSomeTime class template
 * @brief A class that takes a while to do some things
 *
 * Used to demonstrate how to gather timing information
 */
template <typename T>
class TakesSomeTime {
   private:
    /**
     * @brief keeps track of how many times we've called slow_function
     */
    unsigned int num_calls_to_slow_function;

    /**
     * @brief keeps track of the number of "operations" we do in slow_function
     */
    unsigned int num_operations_in_slow_function;

    /**
     * @brief keeps track of how many nanoseconds we've spent in the
     * slow_function
     */
    unsigned long nanoseconds_in_slow_function;

    /**
     * @brief value operated on by this class
     */
    T my_value;

   public:
    /**
     * @brief report the timing statistics for the instance
     */
    void report_stats() {
        std::cout << "-------------------------" << std::endl;
        std::cout << " Begin Performance Stats " << std::endl << std::endl;

        std::cout << "           # calls to slow_function: "
                  << num_calls_to_slow_function << std::endl;
        std::cout << "             # ops in slow_function: "
                  << num_operations_in_slow_function << std::endl;
        std::cout << " Total time in slow_function: "
                  << nanoseconds_in_slow_function << " nanoseconds"
                  << std::endl;

        double ave_num_ops_per_call =
            static_cast<double>(num_operations_in_slow_function) /
            static_cast<double>(num_calls_to_slow_function);

        double ave_time_per_call =
            static_cast<double>(nanoseconds_in_slow_function) /
            static_cast<double>(num_calls_to_slow_function);

        std::cout << " Average # ops per call to slow_function: "
                  << ave_num_ops_per_call << std::endl;
        std::cout << " Average time in slow_function: " << ave_time_per_call
                  << " nanoseconds" << std::endl;

        std::cout << std::endl << "  End Performance Stats  " << std::endl;
        std::cout << "-------------------------" << std::endl;
    }

    /**
     * @brief Constructor
     */
    TakesSomeTime(T initial_value) {
        // initialize values used for performance statistics
        num_calls_to_slow_function = 0;
        num_operations_in_slow_function = 0;
        nanoseconds_in_slow_function = 0;

        // initialize value to operator on
        my_value = initial_value;
    }
  
   /**
     * @brief Destructor
     */
    ~TakesSomeTime() { report_stats(); }

    /**
     * @brief this is the slow_function
     */
    void slow_function(int delay_nanoseconds, int num_operations) {
        // ask the clock what time it is when this function starts
        auto start = std::chrono::high_resolution_clock::now();

        // increment the number of calls to this function
        num_calls_to_slow_function++;

        // To simulate "slowness" we will pause pause the execution of
        // this function for num_operations times. Each pause will last
        // the specified number of seconds
        for (int i = 0; i < num_operations; ++i) {
            std::chrono::nanoseconds delay_duration(delay_nanoseconds);
            std::this_thread::sleep_for(delay_duration);
            std::cout << "slow_function operation # " << i << " paused for "
                      << delay_duration.count() << " nanoseconds" << std::endl;
            
            // update the number of operations we've performed in the slow_function
            num_operations_in_slow_function++;
        }

        // ask the clock what time it is when this function is about to end
        auto stop = std::chrono::high_resolution_clock::now();

        // compute the duration between start and stop
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

        // Add this duration to the overall time we've spent in this function
        nanoseconds_in_slow_function += duration.count();

        return;
    }
};
