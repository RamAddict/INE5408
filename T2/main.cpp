#include <iostream>
#include <fstream>
#include <list>
#include <bits/stdc++.h>

const int ALPHABET_SIZE = 26; 
//! TrieNode struct
/*!
    \brief Main data structure for implementing the digital tree
*/
struct TrieNode {
    char letter;
    TrieNode* children[ALPHABET_SIZE];
    int inicio;
    int comprimento;  //se maior que zero, indica último caracter de uma palavra
    bool isEndOfWord;
};

//! Creates digital tree
/*!
    \brief Populates the tree received with the dictionary specified by path 
    \return void
*/
void create_trie(TrieNode*& tree, std::string path);

//! Creates a new node
/*!
    \brief The created node's letter is defined by the char l 
    \returns The node created
*/
TrieNode* newNode(char l);

//! Inserts a node
/*!
    \brief Creates a node with the specified data and inserts from root
    \returns The last node created
*/
TrieNode* insert(TrieNode* root, std::string data);

//! Finds the word in the dictionary
/*!
    \brief Performs the search for data with O(N) complexity from the root 
    \returns A string containing the data's position and it's definition's lenght or if data is a prefix or not
*/
std::string search(TrieNode* root, std::string data);

int main() {
    
    std::string filename;
    
    // entrada
    std::cin >> filename;

    auto tree = newNode('.');
    // inicializa a arvore
    create_trie(tree, filename);

    std::list<std::string> words;
    {
        std::string word;
        while (1) {  // leitura das palavras ate' encontrar "0"
            std::cin >> word;
            if (word.compare("0") == 0) {
                break;
            }
            words.push_back(word);
        }
    }
    for (auto word: words)
    {
        std::cout << search(tree, word) << std::endl;
    }
    

    return 0;
}

void create_trie(TrieNode*& tree, std::string path)
{
    std::fstream file(path);
    std::string line;
    auto position = 0;
    auto size = 0;
    TrieNode* last;
    auto again = false;
    while (std::getline(file, line))
    {
        auto contains_word = true;
        std::string word = "";
        size = line.size();
        
        if (line.rfind('[') == std::string::npos) // se ele nao encontrar [ ]
        {
            contains_word = false;
        }
        if (contains_word == true) {
            for (int i = 1; i != line.size(); i++)
            {
                if (line.at(i) == ']')
                    break;
                word = word + line.at(i);
            }

            last = insert(tree, word);
            last->comprimento = size;
            last->inicio = position;
            
            // std::cout << word;
            // std::cout << " position: " << last->inicio;
            // std::cout << " size: " << last->comprimento << std::endl;
            
            position = position + size + 1; //< inicio da proxima linha
        } else {
            last->comprimento = position+size;
            position = position + size+1;
        }
    }
}
//! Returns new trie node
TrieNode* newNode(char l)
{
    auto* pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false;
    pNode->letter = l;
    pNode->inicio = 0;
    pNode->comprimento = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
}
TrieNode* insert(TrieNode* root, std::string data)
{
    auto* temp = root;

    for (auto i = 0; i != data.length(); i++)
    {
        auto index = data[i] - 'a';
        if (temp->children[index] == NULL)
            temp->children[index] = newNode(data[i]);

        // iterate over the recently added node//std::list<char> children[ALPHABET_SIZE];   //pode ser uma 'LinkedList' de ponteiros
        temp = temp->children[index];
    }
    temp->isEndOfWord = true;
    return temp;
}
std::string search(TrieNode* root, std::string data)
{ 
    auto* temp = root;

    for (auto i = 0; i != data.length(); i++)
    {
        auto index = data[i] - 'a';
        if (temp->children[index] == NULL) // palavra nao existe
            return "is not prefix";

        // iterate over the recently added node
        temp = temp->children[index];
    }
    std::string result = std::to_string(temp->inicio) + " " + std::to_string(temp->comprimento);
    return (temp->isEndOfWord)? result : "is prefix"; 
}