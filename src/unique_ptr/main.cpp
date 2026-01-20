#include <iostream>
#include <stdexcept>
#include "uniquePtr.h"

namespace my_ptr{

class UniquePtr {
    int* ptr = nullptr;
    
public:
    // Конструктор від сирого вказівника
    explicit UniquePtr(int* p = nullptr)
    : ptr(p)
    {
        std::cout << "[uniquePtr] constructor from pointer, ptr = " << ptr << "\n";
    }
    
    // Конструктор, який сам виділяє памʼять
    explicit UniquePtr(int value)
    : ptr(new int(value))
    {
        std::cout << "[uniquePtr] constructor with value " << value
        << ", ptr = " << ptr << "\n";
    }
    
    // Заборона копіювання
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
    
    // Заборона переміщення (поки що)
    UniquePtr(UniquePtr&&) = delete;
    UniquePtr& operator=(UniquePtr&&) = delete;
    
    // 3. Деструктор (RAII — тут відбувається delete)
    ~UniquePtr() {
        std::cout << "[uniquePtr] destructor, deleting ptr = " << ptr << "\n";
        delete ptr;
    }
    
    // Перевірка, чи є виділений ресурс
    bool isValid() const {
        return ptr != nullptr;
    }
    
    operator bool() const {
        return ptr != nullptr;
    }
    // 5.Перевантажуємо public  operator* і operator->
    // Доступ до значення
    int& operator*() const {
        if (!ptr)
            throw std::runtime_error("Dereferencing null uniquePtr");
        return *ptr;
    }
    
    int* operator->() const {
        if (!ptr)
            throw std::runtime_error("Accessing null uniquePtr");
        return ptr;
    }
    
    // Отримати сирий вказівник (без зміни власності)
    int* get() const {
        return ptr;
    }
    
    // Віддати ресурс і «забути» про нього
    int* release() {
        int* tmp = ptr;
        ptr = nullptr;
        std::cout << "[uniquePtr] release, now ptr = nullptr, returned " << tmp << "\n";
        return tmp;
    }
    
    // 6. Додати public метод reset, який замінює поточний ресурс на новий або очищує його:
    // Заміна/очищення ресурсу
    void reset(int* p = nullptr) {
        if (ptr != p) {
            std::cout << "[uniquePtr] reset: deleting old ptr = " << ptr
            << ", new ptr = " << p << "\n";
            delete ptr;
            ptr = p;
        }
    }
};


} //namespace my_ptr


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
