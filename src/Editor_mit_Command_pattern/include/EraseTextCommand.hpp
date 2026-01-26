//
//  InsertTextCommand.hpp
//
#pragma once

#include "Document.hpp" 
#include "Command.hpp"
#include <memory>
#include <cstddef>

class Document;

class EraseTextCommand : public Command {
    std::weak_ptr<Document> m_doc;
    std::size_t m_position;
    std::size_t m_count;
    
public:
    EraseTextCommand(std::shared_ptr<Document> doc, std::size_t position, std::size_t count)
    : m_doc(doc), m_position(position), m_count(count) {}
    
    void execute() override {
        auto doc = m_doc.lock();
        if (!doc) {
            std::cout << "Document no longer exists. Skipping Erase.\n";
            return;
        }
        std::cout << "execute(): use_count = " << doc.use_count() << "\n";
        doc->erase(m_position, m_count);
    }
};
