//#ifndef Document_h
//#define Document_h
//
//
//#endif /* Document_h */


#pragma once

//Реалізуйте мінімальний набір методів, наприклад:
//
//    void insert(size_t pos, const std::string& str); - вставляє строку str в m_content на pos позицію
//    void erase(size_t pos, size_t count); - видаляє строку count символів з m_content починаючи з pos позиції
//    void replace(size_t pos, size_t count, const std::string& str); замінює count символів, починаючи з pos на строку str в m_content
//    const std::string& text() const; - повертає m_content, тобто метод-гетер

#include <string>
#include <stdexcept>
#include <memory>
#include <iostream>


class Document{
   std::string m_content; //зберігає весь текст документа

public:
    Document() = defautl;
    Document(const std::string& initial) : mcontent(initial){}
    
    //Document() : ptr(nullptr), count(nullptr) {}
    
    ~Document(){
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
    
    void insert(size_t pos, const std::string& str){
        //вставити str у m_content починаючи з позиції pos
        if (pos> m_content.size()){
            throw std::out_of_range("insert: pos out of range");
        }
        m_content.insert(pos, str);
    }
    
    void erase(size_t pos, size_t count){
        //   - видаляє строку count символів з m_content починаючи з pos позиції
        
        if (pos > m_content.size()) {
            throw std::out_of_range("erase: pos out of range");
        }
        m_content.erase(pos, count);
    }

    void replace(size_t pos, size_t count, const std::string& str){
        //замінює count символів, починаючи з pos на строку str в m_content
        if (pos > m_content.size()) {
            throw std::out_of_range("replace: pos out of range");
        }
        m_content.replace(pos, count, str);
    }
    
    const std::string& text() const{ //getter
        return m_content;
    }
};
