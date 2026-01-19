//
//  unique_ptr.cpp
//  hello
//
//  Created by Соломія Серант on 05.12.2025.
//
#include <iostream>
#include <stdexcept>

class uniquePtr {
    int* ptr = nullptr;

public:
    // Конструктор від сирого вказівника
    uniquePtr(int* p = nullptr)
        : ptr(p)
    {
        std::cout << "[uniquePtr] constructor from pointer, ptr = " << ptr << "\n";
    }

    // Конструктор, який сам виділяє памʼять
    uniquePtr(int value)
        : ptr(new int(value))
    {
        std::cout << "[uniquePtr] constructor with value " << value
                  << ", ptr = " << ptr << "\n";
    }

    // Заборона копіювання
    uniquePtr(const uniquePtr&) = delete;
    uniquePtr& operator=(const uniquePtr&) = delete;

    // Заборона переміщення (поки що)
    uniquePtr(uniquePtr&&) = delete;
    uniquePtr& operator=(uniquePtr&&) = delete;

    // Деструктор (RAII — тут відбувається delete)
    ~uniquePtr() {
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



