//
//Мета: Опанувати RAII та основи менеджменту пам’ятті
//
//Для цього створимо класс який:
//
//- володіє динамічно виділеним ресурсом (пам’яттю під int),
//
//  +  - автоматично звільняє ресурс у деструкторі(RAII),
//
//  +  - використовує лічильник для менеджменту пам'яті
//
//- забороняє покищо переміщення (move-семантика),
//
//- надає зручні методи get(), release(),
//
//- перевантажує оператори *, -> та operator bool().
//
//1.Створіть новий консольний проєкт C++ через CMAKE, main.cpp.
//
//2.Створити класс, який огортає вказівник на виділену динамічну пам'ять у RAII.


#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "sharedPtr.h"


int main() {
    std::cout << "=== Demo start ===\n";

    SharedPtrInt a(10);
    std::cout << "a: *a=" << *a << ", useCount=" << a.useCount() << "\n";

    {
        std::cout << "\n--- Copy construct b from a ---\n";
        SharedPtrInt b = a; // copy ctor
        std::cout << "a.useCount=" << a.useCount() << "\n";
        std::cout << "b.useCount=" << b.useCount() << "\n";
        std::cout << "a.get()=  " << a.get() << "\n";
        std::cout << "b.get()=  " << b.get() << "\n";

        
        std::cout << "\n--- Copy assign c = b ---\n";
        SharedPtrInt c;
        c = b; // copy assign
        std::cout << "a.useCount=" << a.useCount() << "\n";
        std::cout << "b.useCount=" << b.useCount() << "\n";
        std::cout << "c.useCount=" << c.useCount() << "\n";
        
        
        std::cout << "\n--- Modify through c ---\n";
        *c = 42;
        std::cout << "*a=" << *a << ", *b=" << *b << ", *c=" << *c << "\n";

        std::cout << "\n--- Release b (b stops owning) ---\n";
        b.release();
        std::cout << "After b.release():\n";
        std::cout << "a.useCount=" << a.useCount() << "\n";
        std::cout << "b.useCount=" << b.useCount() << ", b.isValid=" << std::boolalpha << b.isValid() << "\n";
        std::cout << "c.useCount=" << c.useCount() << "\n";

        std::cout << "\n--- End inner scope (c will be destroyed) ---\n";
    }

    std::cout << "\nAfter inner scope:\n";
    std::cout << "a.useCount=" << a.useCount() << ", *a=" << *a << "\n";

    std::cout << "\n--- Now destroy a at end of main ---\n";
    std::cout << "=== Demo end ===\n";
    return 0;
}
      
