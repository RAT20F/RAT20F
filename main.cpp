#include "lexical.h"
#include "lexical.cpp"

void getFile(std::ifstream& file, int& i);
//void scanFile(std::ifstream& file);
void scanFiles(std::ifstream& file, int& i);

int main(int argc, const char** argv) {
    
    for(int i = 1; i <= 3; ++i){
        std::ifstream testFile;
        getFile(testFile, i);
        scanFiles(testFile, i);
    }

    return 0;
}

/* Checking whether file exists in local directory */
void getFile(std::ifstream& file, int& i) {

    std::string filename;
    std::cout << "Enter filename-"<< i << " for lexical analysis: ";
    while (true) {
        std::cin >> filename;
        file.open(filename);
        if (!file) { std::cout << "File cannot be found. n ter valid filename: "; }
        else { break; }
    } 
    
  
}

/* getTestFiles scans each test_file and displays a*/
void getTestfiles(std::ifstream& file, int& i){

    std::string new_test_case = "";
    std::string base("-test-output.txt");

    std::string output_file_name = std::to_string(i) + base;
    std::ofstream test_file;
    test_file.open(output_file_name);
    int x = 0;
    std::string temp;
    std::vector<std::string> recordList;
    std::string lexerOutput = "";
    std::cout << "\nScanning file with words and index numbers...\n";
    test_file << "Token '\t' Lexeme\n";
    while (file >> temp) {
        x++;
        recordList = lexer(temp);
        for (int x = 0; x < recordList.size(); x++) {
            std::cout << recordList[x] << "\n";
            test_file << recordList[x] << "\n";
        }
    }
    test_file.close();
    file.close();

}
