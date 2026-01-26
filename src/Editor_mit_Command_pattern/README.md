Реалізувати спрощену систему текстового редактора.

Відпрацюємо:

 - патерн Command;

 - три типи розумних вказівників:

  std::unique_ptr, std::shared_ptr, std::weak_ptr;

Пишемо ядро простого текстового редактора, яке пізніше адаптуємо під Qt.

1. Створити клас Document, який відповідає за зберігання тексту.

Всередині використати std::string для збереження контенту



main створює doc1, doc2 як std::shared_ptr<Document>.

main створює CommandScheduler.

main створює команди через std::make_unique<...Command>(doc, ...).

Команда зберігає документ як std::weak_ptr<Document>, щоб не продовжувати життя документа.

CommandScheduler володіє командами через std::unique_ptr<Command> (черга власності).

runAll() витягує команду, викликає execute() → команда lock() документ і змінює текст
