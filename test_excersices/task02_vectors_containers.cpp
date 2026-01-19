//
//  vectors_containers.cpp
//  hello
//
//  Created by Соломія Серант on 16.12.2025.
//

#include <stdio.h>
#include <iostream>
#include <vector>

void run_task02_vectors_containers() {
    std::vector<std::string> cars = {"Vovo", "BMW", "Ford"};
    cars.push_back("Renault");
    
    for (auto i: cars){
        // i = '_';
        std::cout << i << ' ';
    }
    
    // Iterator
    
//    for (std::vector<std::string>::const_iterator i = cars.begin(); i != cars.end(); ++i)
//        std::cout << *i << ' '<< std::endl;
    
    // Create an array of strings
//    std::string Acars[5] = {"Volvo", "BMW", "Ford", "Mazda", "Tesla"};
//    for (std::string num : Acars) {
//      std::cout << num << "\n";
//    }
    
    return 0;
}

