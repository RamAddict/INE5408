#ifndef TRIE_H
#define TRIE_H

#include <string>

namespace trie
{
    const int ALPHABET_SIZE = 26; 

    struct TrieNode {
        char letter;
        TrieNode* children[ALPHABET_SIZE]; 
        unsigned long posicao;
        unsigned long comprimento;  //se maior que zero, indica último caracter de uma palavra
        bool isEndOfWord;
    };
    //! Returns new trie node (initialized to NULLs) 
    TrieNode* insert(TrieNode* root, std::string data);
    
    std::string search(TrieNode* root, std::string data);

    TrieNode* newNode(char l);
}


#endif