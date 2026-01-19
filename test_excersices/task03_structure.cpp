//
//  run_test03_structure.cpp
//  hello
//
//  Created by Соломія Серант on 17.12.2025.
//

#include "run_test03_structure.hpp"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


// Declare a structure named "car"
struct Student {
  string name;
  int age;
  int grade;
};

void run_task03_struct() {
  // Create a car structure and store it in myCar1;
  Student Student1;
  Student1.name = "Liam";
  Student1.age = 45;
  Student1.grade = 2;

  // Create another car structure and store it in myCar2;
    Student Student2;
    Student2.name = "Liam";
    Student2.age = 32;
    Student2.grade = 1;
    
    
  // Print the structure members
  cout << Student1.name << " " << Student1.age << " " << Student1.grade << "\n";
  cout << Student2.name << " " << Student2.age << " " << Student2.grade << "\n";
 
    
    enum Level{
        LOW = 25,
        MEDIUM = 50,
        HIGH = 75
    };
    
  return 0;
}
