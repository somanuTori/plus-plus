#include <iostream>
#include <stdexcept>
#include "uniquePtr.h"



int main() {
    std::cout << "=== Start main ===\n";

    {
        std::cout << "--- Create p(10) ---\n";
        my_ptr::UniquePtr p(10); // тут виділяється памʼять під int(10)

        if (p.isValid()) {
            std::cout << "p is valid, *p = " << *p << "\n";
        }

        std::cout << "--- Change *p to 42 ---\n";
        *p = 42;
        std::cout << "Now *p = " << *p << "\n";

        std::cout << "--- Call reset(new int(100)) ---\n";
        p.reset(new int(100));
        std::cout << "*p after reset = " << *p << "\n";

        std::cout << "--- Call release() ---\n";
        int* raw = p.release();
        std::cout << "After release: p.isValid() = " << std::boolalpha << p.isValid() << "\n";
        std::cout << "raw points to value = " << *raw << "\n";

        std::cout << "--- Manually delete raw ---\n";
        delete raw;   // тепер відповідальність за памʼять перенесена на нас

        std::cout << "--- End of inner scope ---\n";
    }

    std::cout << "=== End main ===\n";
    return 0;
}
