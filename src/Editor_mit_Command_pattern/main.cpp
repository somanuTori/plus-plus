#include <iostream>
#include <memory>

#include "include/Document.hpp"
#include "include/CommandScheduler.hpp"
#include "include/InsertTextCommand.hpp"
#include "include/EraseTextCommand.hpp"
#include "include/ReplaceTextCommand.hpp"

int main() {
    auto doc1 = std::make_shared<Document>("Hello");
    auto doc2 = std::make_shared<Document>("World");

    CommandScheduler scheduler;

    std::cout << "Initial:\n";
    std::cout << "doc1: \"" << doc1->text() << "\"\n";
    std::cout << "doc2: \"" << doc2->text() << "\"\n\n";

    // Команди для doc1
    scheduler.schedule(std::make_unique<InsertTextCommand>(doc1, " world", doc1->text().size()));
    scheduler.schedule(std::make_unique<ReplaceTextCommand>(doc1, 6, 5, "C++")); // "world" -> "C++"

    // Команди для doc2
    scheduler.schedule(std::make_unique<InsertTextCommand>(doc2, " framework", doc2->text().size()));

    // Тимчасовий документ, який буде знищений ДО виконання команд | weak_ptr
    {
        auto tempDoc = std::make_shared<Document>("Temporary document");
        scheduler.schedule(std::make_unique<ReplaceTextCommand>(tempDoc, 0, 9, "ShouldNotAppear"));
    } // tempDoc знищений тут, команди мають це “побачити” через weak_ptr

    std::cout << "Running commands...\n\n";
    scheduler.runAll();

    std::cout << "\nFinal:\n";
    std::cout << "doc1: \"" << doc1->text() << "\"\n";
    std::cout << "doc2: \"" << doc2->text() << "\"\n";
}
