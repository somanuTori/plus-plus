//
//  InsertTextCommand.hpp
//  
//
//  Created by Соломія Серант on 2026-01-24.
//
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
        doc->erase(m_position, m_count);
    }
