#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <stack>
#include <sstream>
#include <list>

  //! gets filename from input stream
std::string get_file_name();
  //! check if the file is open and stores each char of the file 
std::list<char> create_char_array_of_file(std::fstream& tfile);

int main() {
    std::fstream file;
    
    auto file_name = get_file_name();

    file.open(file_name);

    auto char_array = create_char_array_of_file(file);
    
    std::cout << char_array.size() << "\n";
    
    file.close();

    return 0;
}

std::string get_file_name() {
    std::string xmlfilename;
    std::cin >> xmlfilename;  // entrada
    return xmlfilename;
}

std::list<char> create_char_array_of_file(std::fstream& tfile) {
    std::list<char> file_chars;
    if (tfile.is_open()) {

        std::string line = "";
        while(std::getline(tfile, line, '\n')) {
            for (auto a : line) {
                file_chars.push_back(a);
            }
            //std::cout << line;
        }

    } else {
            printf("didnt open!\n");
        }
    return file_chars;
}