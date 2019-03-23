/**
 * @file main.cpp
 * @author Roman Pykhnivskyi (pro1710@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-23
 * 
 * @copyright Copyright (c) 2019 Roman Pykhnivskyi
 * @license This project is released under the MIT License.
 */

#include "TripletZeroSum/TripletZeroSum.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <iostream>

/**
 * @brief Entry point
 *
 * Execution of the program
 * starts here.
 * 
 * @param argc Number of arguments
 * @param argv List of arguments
 * @return int Program exit status
 */
int main(int argc, char* argv[]) {

    std::string programName = basename(argv[0]);

    std::string inputFileName{};

    int opt;
    while ( (opt = getopt(argc, argv, "hi:")) != EOF ) {
        switch (opt)
        {
            case 'i':
                inputFileName = optarg;
                break;

            case 'h':
            std::cout << "Usage: " << programName << " [OPTION] -i INPUT_FILE" << std::endl
                      << "OPTIONS:" << std::endl
                      << std::left << std::setw(10) << std::setfill(' ') << "-i" << "input filename" << std::endl
                      << std::left << std::setw(10) << std::setfill(' ') << "-h" << "show this message and exit" << std::endl; 
                return 1;
            default:
                abort();
        }
    }
    
    if (inputFileName.empty()) {
        std::cout << programName <<": missing file operand" << std::endl
                  << "Try '" << programName << " -h' for more information." << std::endl;
    }

    try {

        TripletZeroSum s;
        s.readData(inputFileName);
        auto res = s.Solve();

        for (const auto& r: res) {
            for (const auto& val: r) {
                std::cout << val << ",";
            }
            std::cout << std::endl;
        }

    } catch ( std::exception& e ) {
        std::cerr << e.what() << std::endl;
        abort();
    }

    

    return 0;

}
