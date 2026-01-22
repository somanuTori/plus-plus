//
//  Document.h
//  
//
//  Created by Соломія Серант on 2026-01-22.
//

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
//
//У main документи мають створюватися так:


class Document{
   std::string m_content;

public:
    Document() : ptr(nullptr), count(nullptr) {}

    
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
    
    
    
    void insert(size_t pos, const std::string& str);
//        вставляє строку str в m_content на pos позицію
    
    void erase(size_t pos, size_t count);
    //   - видаляє строку count символів з m_content починаючи з pos позиції
    
    void replace(size_t pos, size_t count, const std::string& str);
    //замінює count символів, починаючи з pos на строку str в m_content
    
    const std::string& text() const;
    //- повертає m_content, тобто метод-гетер
};
