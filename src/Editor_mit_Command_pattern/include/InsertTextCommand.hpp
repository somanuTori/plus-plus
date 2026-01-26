//
//  InsertTextCommand.hpp
//  
//
//  Created by Соломія Серант on 2026-01-24.
//
#pragma once

#include "Document.hpp" 
#include "Command.hpp"
#include <memory>
#include <string>
#include <cstddef>

class Document; // forward declaration

class InsertTextCommand : public Command { //Наслідування
    std::weak_ptr<Document> m_doc;
    std::string m_text;
    std::size_t m_position;
    
public:
    InsertTextCommand(std::shared_ptr<Document> doc, std::string text, std::size_t position)
    : m_doc(doc), m_text(std::move(text)), m_position(position) {}
    
    void execute() override {// override щоб перевизначати віртуальний метод базового класу
        auto doc = m_doc.lock();             // weak_ptr -> shared_ptr
        if (!doc) {
            std::cout << "Document no longer exists. Skipping Insert.\n";
            return;
        }
        std::cout << "execute(): use_count = " << doc.use_count() << "\n";
        doc->insert(m_position, m_text);
    }
};
