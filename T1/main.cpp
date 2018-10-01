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
  //! gets one of the attributes from every image and pushes it onto the list
void get_atribute(std::string line, std::string info, std::list<std::string>& atribute, std::string::size_type j);

int main() {
    auto file_name = get_file_name();
    
    std::fstream file(file_name);
    
    std::stack<std::string> stack;
    std::list<std::string> name;
    std::list<std::string> height;
    std::list<std::string> width;
    std::list<std::string> data;
    
    bool read = false;
    bool data_read = false;
    int m = 0;
    std::string temp_data = "";
    if (file.is_open()) {
        std::string line = "";
        while(std::getline(file, line)) {
            if (line.find("data") == line.npos) {
                temp_data = temp_data + line;
            } 
            // for para percorrer a string da linha obtida com getline
            for (std::string::size_type i = 0; i < line.size(); ++i) {
                if (line[i] == '<') {
                    auto desempilha = false;
                    if(line[i+1] == '/') {
                        i++;
                        desempilha = true;
                    }
                    std::string info ="";
                    for(std::string::size_type j = i+1; j < line.size(); ++j) {
                        if (line[j] == '>' && desempilha) {  ///< se encontrou o fechamento e desempilhar for vdd
                            if (!stack.empty()) {
                                if (stack.top().compare(info) == 0) {  ///< checa se o alvo a desempilhar é o topo
                                    //std::cout << "desempilhando: " << info << std::endl;
                                    stack.pop();  ///< se for o topo desempilha
                                    data_read = false;
                                    break;
                                } else {  ///< se não, lança erro
                                    //throw std::out_of_range("tentou desempilhar não o topo");
                                    std::cout << "error"<< std::endl;
                                }
                            } else {
                                std::cout << "error"<< std::endl;
                            }
                        } else if (line[j] == '>' && !desempilha) {  ///< se encontrou fechamento e desempilhar for falso
                                //std::cout << "empilhando: " << info << std::endl;
                                stack.push(info);  ///< empilha o tag
                                if(info.compare("name") == 0)
                                    get_atribute(line, info, name, j);
                                if(info.compare("height") == 0)
                                    get_atribute(line, info, height, j);
                                if(info.compare("width") == 0)
                                    get_atribute(line, info, width, j);
                                if(line.find("/data") != line.npos) {
                                    data.push_back(temp_data);
                                    temp_data = "";
                                }
                                break;
                            }
                        info = info + (line[j]);
                    }
                }
            }
        }
    } else {
            printf("didnt open!\n");
        }

    if (!stack.empty()) {
        // throw std::out_of_range("pilha nao vazia");
        std::cout << "error"<< std::endl;
    }
    for (auto it: name) {
        std::cout << it;
    }
        for (auto it: height) {
        std::cout << it;
    }
            for (auto it: width) {
        std::cout << it;
    }
            for (auto it: data) {
        std::cout << it << std::endl;
    }
        
        
    return 0;
}

std::string get_file_name() {
    std::string xmlfilename;
    std::cin >> xmlfilename;  // entrada
    return xmlfilename;
}

void get_atribute(std::string line, std::string info, std::list<std::string>& atribute, std::string::size_type j) {

        std::string name_ = "";
        for(std::string::size_type k = j+1; k != -1; ++k)
        {
            if (line[k] == '<') {
                break;
            }
            name_ = name_ +""+ (line[k]);
        }
        atribute.push_back(name_);
}