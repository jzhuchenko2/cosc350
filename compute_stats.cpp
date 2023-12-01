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
