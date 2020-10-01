#include "lexical.h"

int main(int argc, const char** argv) {
    ifstream testFile;
    getFile(testFile);
    scanFile(testFile);

    return 0;
}

void getFile(ifstream &file) {  //Check if a file exists
    string filename;
    cout << "Enter filename for lexical analysis: ";
    while(true) {
        cin >> filename;
        file.open(filename);
        if (!file) {
            cout << "File does not exist. Enter a valid filename: ";
        } else {
            break;
        }
    }
}

void scanFile(ifstream &file) {
    ofstream userOutput;
    userOutput.open("output.txt");
    int i = 0;
    string temp;
    vector<string> recordList;
    string lexerOutput = "";
    cout << "\nScanning file with words and index numbers\n";
    userOutput << "Token \t Lexeme\n";
    while (file >> temp) {
        i++;
        recordList = lexical(temp);
        for (int i = 0; i < recordList.size(); i++) {
            cout << recordList[i] << "\n";
            userOutput << recordList[i] << "\n";
        }
    }
    userOutput.close();
}