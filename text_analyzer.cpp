#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string getFileContent() {
    string filePath, content, line;
    
    cout << "Enter file path: ";
    getline(cin, filePath);
    fstream file(filePath, fstream::in);
    
    if (!file.is_open()) {
        cerr << "Error: File not found!" << endl;
        return getFileContent();
    }
    while (getline(file, line)) {
        content += line + '\n';
    }
    file.close();
    return content;
}

int main() {
    string content = getFileContent();
    stringstream ss(content);
    string str;
    int lines = 0, words = 0, chars = 0;
    
    /* 
    The following algorithm excludes carriage return (\r) since it's used
    with line feed (\n) on Windows to represent a single newline (CRLF)
    
    Linux and modern Mac use only linefeed (LF), represented as '\n'
    
    may cause an issue where lines will never be
    incremented on older Mac systems, prior to OS X (introduced in 2001),
    where a newline is represented only by a carriage return (CR),
    represented as '\r'
    */
    for (int i = 0; i < content.size(); i++) {
        if (content[i] == '\n') lines++;
        else if (content[i] != '\r') chars++;
    }
    while (ss >> str) words++;
    
    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters: " << chars << endl;
    return 0;
}
