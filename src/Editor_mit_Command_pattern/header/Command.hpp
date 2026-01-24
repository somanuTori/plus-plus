//
//  Command.h
//  

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;   // абстрактний (віртуальний) метод
    };
    
    class ReplaceTextCommand : public Command {
        std::weak_ptr<Document> m_doc;
        std::size_t m_position;
        std::size_t m_count;
        std::string m_text;
        
    public:
        ReplaceTextCommand(std::shared_ptr<Document> doc,
                           std::size_t position,
                           std::size_t count,
                           std::string text)
        : m_doc(doc), m_position(position), m_count(count), m_text(std::move(text)) {}
        
        void execute() override {
            auto doc = m_doc.lock();
            if (!doc) {
                std::cout << "Document no longer exists. Skipping Replace.\n";
                return;
            }
            doc->replace(m_position, m_count, m_text);
        }
    };
    
};
