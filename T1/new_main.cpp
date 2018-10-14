#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <list>
#include <map>
#include <queue>
//#include <typeinfo>

  //! gets filename from input stream

std::string get_file_name() {
    std::string xmlfilename;
    std::cin >> xmlfilename;  // entrada
    return xmlfilename;
};
  //! check if the file is open and stores each char of the file 
std::list<char> create_char_array_of_file(std::fstream& tfile);
  //! gets the name from every image and pushes it onto the list, closes the file
int get_atribute_name(std::fstream& file, std::list<std::string>& name_list_);
  //! gets the height from every image and pushes it onto the list, closes the file
int get_atribute_height(std::fstream& file, std::list<std::string>& height_list_);
  //! gets the width from every image and pushes it onto the list, closes the file
int get_atribute_width(std::fstream& file, std::list<std::string>& width_list_);
  //! gets the data from every image and pushes it onto the list, closes the file
int get_atribute_data(std::fstream& file, std::list<std::string>& data_list_, std::list<std::string> height_list_);
  //! labelling algorithm, returns the ammount of single elements in the data
int labelling(std::string name, std::string height, std::string width, std::string data);
  //! verifica se o xml tem erros
bool verify_xml(std::fstream& file);
int main() {
    auto file_name = get_file_name();
    
    std::fstream file(file_name);

    if (verify_xml(file) == true) {
        std::cout << "error";
        return 0;
    }
    
    std::list<std::string> name_list;
    std::list<std::string> height_list;
    std::list<std::string> width_list;
    std::list<std::string> data_list;
    
    file.open(file_name);

    // std::cout << "name size: ";
    get_atribute_name(file, name_list);
    // //<< " ";
    // for (auto it: name_list) {
    //     std::cout << it << " ";
    // }
    file.open(file_name);
    //std::cout << "height size: " <<
    get_atribute_height(file, height_list);
    //<< " ";
    // for (auto it: height_list) {
    //     std::cout << it << "!   !";
    // }   
    file.open(file_name);
    // std::cout << "width size: ";
    get_atribute_width(file, width_list);
    // for (auto it: width_list) {
    //     std::cout << it << " ";
    // }
    file.open(file_name);
    // std::cout << "data size: ";
    get_atribute_data(file, data_list, height_list);
    // for (auto it: data_list) {
    //     std::cout << it << " ";
    // }
///////////////////////////////////////////////////////////////////////// segunda parte
    auto size = name_list.size();
    for (int i = 0; i != size; i++) {
        std::cout << name_list.front() << " " << labelling(name_list.front(),
        height_list.front(), width_list.front(), data_list.front()) << std::endl;
        name_list.pop_front();height_list.pop_front();width_list.pop_front();data_list.pop_front();
    }

    return 0;
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
int labelling(std::string name, std::string height, std::string width, std::string data) {
    auto _height = stoi(height);
    auto _width = stoi(width);
    //std::cout << name << " rola " << _height << " penis " << _width << "caralho" << data;
    char copy[_height][_width];
    char reference[_height][_width];
    //std::cout << _height << " height" << std::endl;
    //std::cout << _width <<" width" << std::endl;
    //std::pair(int, int) copy;
    //std::pair(int, int) original;
    
     for (int i = 0; i != _height; i++)
         for (int j = 0; j != _width; j++) {
            copy[i][j] = '0'; // de baixo pra cima 
         }  
    // for (int i = 0; i != _width; i++) {
    //      for (int j = 0; j != _height; j++) {
    //         std::cout << copy[j][i] <<" "; // de baixo pra cima 
    //      }
    //         std::cout << "\n";
    // }

    int j = 0;
    for (int i = 0; i != data.size(); i++) {
        
        if (i%_width == 0 && i != 0) {
            j++;
        }
        /////////////////////////////////////////////ESQUERDA PRA DIREITA
        reference[j][i%_width] = data.at(i); 
        //std::cout<< "is: " << reference[j][i%_width] << " expected: " << data.at(i) <<std::endl;
    }
    //std::cout << "\n";
    int num = 0;
    char label = '1';
    std::queue<std::pair<int, int>> kiwi;
    for (int i = 0; i != _height; i++) {
        for (int k = 0; k != _width; k++) {
            //std::cout << reference[i][k]; // <<" i: " << i << " j: " << j << std::endl; de baixo pra cima 
            if (reference[i][k] == '1' && copy[i][k] == '0') {
                kiwi.push(std::make_pair(i, k));
                while(!kiwi.empty()){
                    //std::cout << "penis!";
                    auto temp = kiwi.front();
                    kiwi.pop();
                    //std::cout << "tipo " << typeid(label).name() << " label: " << label << " ";
                    if (temp.first-1 >= 0)
                        if(reference[temp.first-1][temp.second] == '1' && copy[temp.first-1][temp.second] == '0') {
                            kiwi.push(std::make_pair(temp.first-1, temp.second));
                            copy[temp.first-1][temp.second] = label;
                        }
                    if (temp.first+1 < _height)
                        if(reference[temp.first+1][temp.second] == '1' && copy[temp.first+1][temp.second] == '0') {
                            kiwi.push(std::make_pair(temp.first+1, temp.second));
                            copy[temp.first+1][temp.second] = label;
                        }
                    if (temp.second-1 >= 0)
                        if (reference[temp.first][temp.second-1] == '1' && copy[temp.first][temp.second-1] == '0') {
                            kiwi.push(std::make_pair(temp.first, temp.second-1));
                            copy[temp.first][temp.second-1] = label;
                        }
                    if (temp.second+1 < _width)
                        if (reference[temp.first][temp.second+1] == '1' && copy[temp.first][temp.second+1] == '0') {
                            kiwi.push(std::make_pair(temp.first, temp.second+1));
                            copy[temp.first][temp.second+1] = label;
                        }
                        copy[temp.first][temp.second] = label;
                     // pondo label na copia de zeros
                }
                //std::cout << "num:" << num << std::endl;
                num++;
            }
        }
            //std::cout << "\n";
    }

    
    return num;
}
bool verify_xml(std::fstream& file) {
    std::stack<std::string> stack;
        
    bool read = false;
    bool error = false;
    int m = 0;
    std::string temp_data = "";
    if (file.is_open()) {
        std::string line = "";
        while(std::getline(file, line)) {
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
                                    // std::cout << "desempilhando: " << info << std::endl;
                                    stack.pop();  ///< se for o topo desempilha
                                    break;
                                } else {  ///< se não, lança erro
                                    error = true;
                                    break;
                                }
                            } else {
                                break;
                                error = true;
                            }
                        } else if (line[j] == '>' && !desempilha) {  ///< se encontrou fechamento e desempilhar for falso
                                // std::cout << "empilhando: " << info << std::endl;
                                stack.push(info);  ///< empilha o tag
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
        error = true;
    }
    file.close();
    return error;
}

int get_atribute_name(std::fstream& file, std::list<std::string>& name_list_) {
    if (file.is_open()){
        std::string line;
        //file.ignore();
        std::string arm;
        
        if (file.is_open()) {
        // print file:
        char c = file.get();
        //std::cout << c << " canceroso";
        while (file.good()) {
            c = file.get();
            //std::cout << c;
            if (c == '<') {
                c = file.get();
                if (c == 'n') {
                    c = file.get();
                    if (c == 'a') {
                        c = file.get();
                        if (c == 'm') {
                            c = file.get();
                            file.get();
                            while((c = file.get()) != '<' ) {
                            arm = arm + c;
                            }
                            //break;
                        }
                    }
                }
             
            }
        }
        }
        else {
        // show message:
        std::cout << "Error opening file";
        }
        std::cout << arm << " nome";




        while(std::getline(file, line)){
            std::string name;
            while (line.find("<name>") != line.npos) {
              //  std::cout << "printar";
                auto position = line.find("<name>");
                for (std::string::size_type i = position+6; i < line.size(); ++i) {
                    if (line[i] == '<') {
                        line[position+1] = '@';
                        break;
                    } else {
                        name = name + line[i];
                    }
                }
            }
            if (name != "") {

                name_list_.push_back(name);
            }
        }
    }
    file.close();
    return name_list_.size();
}
int get_atribute_height(std::fstream& file, std::list<std::string>& height_list_) {
    
    if (file.is_open()){
        std::string line;
        while(std::getline(file, line)){
            std::string height;
            while (line.find("<height>") != line.npos) {
                auto position = line.find("<height>");
                for (std::string::size_type i = position+8; i < line.size(); ++i) {
                    if (line[i] == '<') {
                        line[position+1] = '@';
                        break;
                    } else {
                        height = height + line[i];
                    }
                }
            }
            if (height != "") {
                height_list_.push_back(height);
            }
        }
    }
    file.close();
    return height_list_.size();
}
int get_atribute_width(std::fstream& file, std::list<std::string>& width_list_) {
    
    if (file.is_open()){
        std::string line;
        while(std::getline(file, line)){
            std::string width;
            while (line.find("<width>") != line.npos) {
                auto position = line.find("<width>");
                for (std::string::size_type i = position+7; i < line.size(); ++i) {
                    if (line[i] == '<') {
                        line[position+1] = '@';
                        break;
                    } else {
                        width = width + line[i];
                    }
                }
            }
            if (width != "") {
                width_list_.push_back(width);
            }
        }
    }
    file.close();
    return width_list_.size();
}
int get_atribute_data(std::fstream& file, std::list<std::string>& data_list_, std::list<std::string> height_list_) {
    std::list<std::string> aux;
    if (file.is_open()){
        std::string line;
        // file.
        
        while(std::getline(file, line)){
            if (line.find('<') == line.npos && line != "") {
                    aux.push_back(line);
            }
        }
    }
    //std::cout << aux.size();
    auto size = height_list_.size();
  //  std::cout <<"saize of listemp: " << listTemp.size() << std::endl;
    for (auto i = 0; i != size; i++) {
        std::string empilha;
        for (int j = 0; j != stoi(height_list_.front()); j++) {
                empilha = empilha + aux.front();

            aux.pop_front();
        }
        data_list_.push_back(empilha);
        height_list_.pop_front();
    }

    file.close();
    return data_list_.size();
}