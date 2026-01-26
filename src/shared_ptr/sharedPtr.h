//
//  shared_ptr.h
//  
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

class SharedPtrInt {
private:
    int* ptr;
    size_t* count;
    
public:
    //**Constructor
    // 1) Конструктор за замовчуванням
    SharedPtrInt() : ptr(nullptr), count(nullptr) {}
    
    // 2) Конструктор від сирого вказівника
    SharedPtrInt(int* p) : ptr(p)
    {
        if (p) count = new size_t(1);
        else count = nullptr;
    }
    
    // 3) Конструктор від значення (сам виділяє пам'ять)
    SharedPtrInt(int value)
    : ptr(new int(value))
    {
        count = new size_t(1);
    }
    // 3. Зробити конструктор копіювання
    SharedPtrInt(const SharedPtrInt& other)
    {
        ptr = other.ptr;
        count = other.count;
        if (count) ++(*count);
    }
    // та операцію присвоєння
    SharedPtrInt& operator=(const SharedPtrInt& other)
    {
        if (this == &other) return *this;
        // Спершу звільняємо поточний ресурс
        release();
        // Потім беремо ресурс іншого об'єкта
        ptr = other.ptr;
        count = other.count;
        
        if (count) {
            ++(*count);
            std::cout << "[SharedPtrInt] copy assign, count=" << *count << "\n";
        } else {
            std::cout << "[SharedPtrInt] copy assign (null)\n";
        }
        return *this;
    }
    
    //** Destructor
    // /- автоматично звільняє ресурс у деструкторі(RAII)
    ~SharedPtrInt()
    {
        release();
    }
    void release()
    {
        //- використовує лічильник для менеджменту пам'яті
        if (count)
        {
            std::cout << "Release: count = " << *count << "\n";
            --(*count);
            if (*count == 0)
            {
                std::cout << "Deleting resource\n";
                delete ptr;
                delete count;
            }
        }
        ptr = nullptr;
        count = nullptr;
    }
    
    // 4. Заборонити переміщення промаркувавши відповідні конструктори та оператори прирівнювання як delete:
    
    SharedPtrInt(const SharedPtrInt&&) = delete;
    SharedPtrInt& operator=(const SharedPtrInt&&) = delete;
    
    
    // 5. Додати public методи які дозволять перевіряти чи наша динамічна пам'ять є виділенною. Можна зробити метод isValid або/і приведення до bool
    
    bool isValid() const {
        return ptr != nullptr;
    }
    operator bool() const {
        return ptr != nullptr;
    }
    
    //6.Перевантажуємо public  operator* і operator->
    int& operator*() const {
        return *ptr;
    }
    int* operator->() const {
        // operator->() дозволяє класу поводитися як сирий вказівник,
        // але з контролем життя об’єкта (RAII).
        return ptr;
    }
    
    // 10) Сервісні методи
    int* get() const {
        return ptr;
    }
    
    std::size_t useCount() const {
        return count ? *count : 0;
    }
    
};
