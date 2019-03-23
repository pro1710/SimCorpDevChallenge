/**
 * @file TripletZeroSum.hpp
 * @author Roman Pykhnivskyi (pro1710@gmail.com)
 * @brief TripletZeroSum class declaration
 * @version 0.1
 * @date 2019-03-23
 * 
 * @copyright Copyright (c) 2019 Roman Pykhnivskyi
 * @license This project is released under the MIT License.
 */

#ifndef TRIPLETZEROSUM_HPP
#define TRIPLETZEROSUM_HPP

#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

/**
 * @brief Class for solving Triplet Sum Problem
**/


class TripletZeroSum {
public:
    using value_t = int;
    using input_t = std::vector<value_t>;

public:
    /**
     * @brief Solving algorithm
     * 
     * @return std::vector<std::vector<value_t>> 
     */
    std::vector<std::vector<value_t>> Solve();

    /**
     * @brief Read the input data from file
     * 
     * @param inFileName 
     */
    void readData(const std::string& inFileName);

    /**
     * @brief Get the input Data 
     * 
     * @return const input_t& 
     */
    const input_t& getInputData() const;

private:
    input_t input_ = {};

};

#endif // TRIPLETZEROSUM_HPP
