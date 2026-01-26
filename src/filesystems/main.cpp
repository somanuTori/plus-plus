//
//  main.cpp
//  
#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

struct FileStats {
    std::uintmax_t count = 0;
    std::uintmax_t size  = 0;
};

std::string toLower(std::string s) {
    for (char& c : s) {
        c = static_cast<char>(std::tolower(c));
    }
    return s;
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: DirectoryAnalyzer <directory_path>\n";
        return 1;
    }

    fs::path directoryPath = argv[1];

    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        std::cerr << "Error: provided path is not a valid directory.\n";
        return 1;
    }

    FileStats textFiles;
    FileStats imageFiles;
    FileStats executableFiles;
    FileStats otherFiles;

    for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {

        if (!entry.is_regular_file())
            continue;

        std::string extension = toLower(entry.path().extension().string());
        std::uintmax_t fileSize = entry.file_size();

        if (extension == ".txt") {
            textFiles.count++;
            textFiles.size += fileSize;
        }
        else if (extension == ".jpg" || extension == ".png" || extension == ".bmp") {
            imageFiles.count++;
            imageFiles.size += fileSize;
        }
        else if (extension == ".exe") {
            executableFiles.count++;
            executableFiles.size += fileSize;
        }
        else {
            otherFiles.count++;
            otherFiles.size += fileSize;
        }
    }

    std::cout << "Directory analysis results:\n\n";

    std::cout << "Text files (.txt):\n";
    std::cout << "  Count: " << textFiles.count << "\n";
    std::cout << "  Total size: " << textFiles.size << " bytes\n\n";

    std::cout << "Image files (.jpg, .png, .bmp):\n";
    std::cout << "  Count: " << imageFiles.count << "\n";
    std::cout << "  Total size: " << imageFiles.size << " bytes\n\n";

    std::cout << "Executable files (.exe):\n";
    std::cout << "  Count: " << executableFiles.count << "\n";
    std::cout << "  Total size: " << executableFiles.size << " bytes\n\n";

    std::cout << "Other files:\n";
    std::cout << "  Count: " << otherFiles.count << "\n";
    std::cout << "  Total size: " << otherFiles.size << " bytes\n";

    return 0;
}
