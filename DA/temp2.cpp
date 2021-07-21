#include <map>
#include <vector>
#include <string>

using namespace std;

class trie {
    public:
        map<char, trie*> child;
        trie* failureLinks;
        trie* dictionaryLinks;
        int endOfWord;
    public:
        trie* newNode() { 
        trie* temp = new trie; 
        temp ->failureLinks = nullptr;
        temp ->dictionaryLinks = nullptr;
        temp ->endOfWord = -1;

        return temp;
    }

    void trieCreation(trie* root, vector<string> &listOfWords) {

    for(int i = 0; i < listOfWords.size() ;i++){ 
        trie* current = root;
        string word = listOfWords[i];
        for(int j = 0; j < word.length(); j++) { 

            char letter = word[j];
            if(current ->child.count(letter)) 
                current = current ->child[letter];
            else{
                trie* addAlpha = newNode(); 
                current ->child.insert({letter, addAlpha});
                current = addAlpha;
            }
        }
        current ->endOfWord = i; 
    }
}
};

