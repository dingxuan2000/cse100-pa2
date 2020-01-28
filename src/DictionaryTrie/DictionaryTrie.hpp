/**
 * TODO: File Header
 *
 * Author:
 */
#ifndef DICTIONARY_TRIE_HPP
#define DICTIONARY_TRIE_HPP

#include <string>
#include <utility>
#include <vector>

using namespace std;

/**
 * The class for a dictionary ADT, implemented as either
 * a mulit-way trie or a ternary search tree.
 */
class DictionaryTrie {
  private:
    // TODO: add private members and helper methods here
    TSTNode* root;

  public:
    /* TODO: add function header */
    DictionaryTrie();

    /* TODO: add function header */
    bool insert(string word, unsigned int freq);

    /* TODO: add function header */
    bool find(string word) const;

    /* TODO: add function header */
    vector<string> predictCompletions(string prefix,
                                      unsigned int numCompletions);

    /* TODO: add function header */
    vector<string> predictUnderscores(string pattern,
                                      unsigned int numCompletions);

    /* TODO: add function header */
    ~DictionaryTrie();
};
// Declare the trie node as a class type
class TSTNode {
  private:
    int frequency;
    char letter;
    // bool isEnd;

  public:
    TSTNode* left;
    TSTNode* middle;
    TSTNode* right;
    TSTNode() {
        left = middle = right = 0;
        frequency = 0;
        // isEnd = false;
    }
    TSTNode(const char& character, const int& freq) {
        letter = character;
        frequency = freq;
        left = middle = right = 0;
        // isEnd = false;
    }
    void setFreq(const int& f) { frequency = f; }
    int getFreq() { return frequency; }
    void setLetter(const char& c) { letter = c; }
    char getLetter() { return letter; }
    // void setIsEnd(bool isEnd){isEnd = }
    ~TSTNode() {
        delete left;
        delete middle;
        delete right;
    }
};

#endif  // DICTIONARY_TRIE_HPP
