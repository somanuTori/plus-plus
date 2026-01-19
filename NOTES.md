# треба вчиться



```bash
mkdir build
cmake -S . -B build -G Xcode
cmake --build build --config Debug
./build/Debug/hello
```

❌ Не додавати файли тільки у Xcode, без CMake:

завжди додаємо їх у CMakeLists.txt;

потім ` cmake -S . -B build -G Xcode`

Xcode-проєкт оновлюється.



Якщо зараз збірка все одно фейлиться

Після точно таких кроків:
```bash
cd /шлях/до/проєкту
rm -rf build
mkdir build
cmake -S . -B build -G Xcode
cmake --build build --config Debug
```
