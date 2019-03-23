/**
 * @file TripletZeroSum.cpp
 * @author Roman Pykhnivskyi (pro1710@gmail.com)
 * @brief TripletZeroSum class implementation
 * @version 0.1
 * @date 2019-03-23
 * 
 * @copyright Copyright (c) 2019 Roman Pykhnivskyi
 * @license This project is released under the MIT License.
 * 
 */
#include "TripletZeroSum.hpp"

#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

std::vector<std::vector<TripletZeroSum::value_t>> TripletZeroSum::Solve() {

    std::vector< std::vector<value_t> > res = {};
    if (input_.size() < 3) {
        return res;
    }

    sort(input_.begin(), input_.end());

    for (size_t i = 0; i < input_.size() - 2; ++i) { 
        int iLeft = i + 1; 
        int iRight = input_.size() - 1; 

        while (iLeft < iRight) { 
            int tmp = input_[i] + input_[iLeft] + input_[iRight];
            bool iterateLeft = false, iterateRight = false;
            
            if (tmp == 0) { 
                res.push_back({input_[i], input_[iLeft], input_[iRight]});
                iterateLeft = true;
                iterateRight = true;
            } else if (tmp < 0) {
                iterateLeft = true;
            } else {
                iterateRight = true;
            }
            
            // skip duplicates
            if (iterateLeft) {
                do {
                    ++iLeft;
                } while (input_[iLeft-1] == input_[iLeft] && iRight > iLeft);
            }
            
            // skip duplicates
            if (iterateRight) {
                do {
                    --iRight;     
                } while (input_[iRight+1] == input_[iRight] && iRight > iLeft);
            }
        } 
        while (input_[i] == input_[i+1] && i < input_.size() - 2) ++i;
    }  
    return res;
}

void TripletZeroSum::readData(const std::string& inFileName) {
    std::ifstream iFile(inFileName);
    
    input_t tmpInput = {};

    if (iFile.is_open()) {
        std::string line;
        while (std::getline(iFile, line)) {
            std::stringstream ss(line);

            int i{0};
            while (ss >> i) {
                tmpInput.push_back(i);
                while (ss.peek() == ',') {
                    ss.ignore();
                }
            }
        }
        iFile.close();
    } else {
        throw std::runtime_error("Cound not open file: " + inFileName);
    }

    std::swap(input_, tmpInput);

}

const TripletZeroSum::input_t& TripletZeroSum::getInputData() const {
    return input_;
}

