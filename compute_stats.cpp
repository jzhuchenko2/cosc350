#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief compute the average of a list of values
 *
 * @param a_list the list for which to compute the average
 * @returns the average (arithmetic mean) of the values in the specified list
 */
template <typename T>
T compute_average(const std::list<T>& a_list) {
    // Compute and return the arithmetic mean of the values in a_list.
    // Hint: accumulation
    return std::accumulate(a_list.begin(), a_list.end(), static_cast<T>(0)) / static_cast<T>(a_list.size());
}
template <typename T>
T compute_median(const std::list<T>& a_list) {
    // Determine and return the median of the values in a_list.
    // Hint 1: Create a vector with the same values and sort it.
    // Hint 2: If the size of the vector is even, average the middle 2 values.
    // If the size of the vector is not even, return the middle value.

    // Using C++ Standard Library functions to compute the median
    std::vector<T> sorted_values(a_list.begin(), a_list.end());
    std::sort(sorted_values.begin(), sorted_values.end());

    size_t size = sorted_values.size();
    size_t middle = size / 2;

    // Checking if the size is even or odd and returning the appropriate value
    return (size % 2 == 0) ? (sorted_values[middle - 1] + sorted_values[middle]) / static_cast<T>(2) : sorted_values[middle];
}


/**
 * @brief output the values in the specified list
 *
 * Outputs the space separated elements of the list to the standard output
 *
 * @param a_list the list to output
 */
template <typename T>
void outputList(const std::list<T>& a_list) {
    std::cout << "list size: " << a_list.size() << std::endl;

    for (const T& item : a_list) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
