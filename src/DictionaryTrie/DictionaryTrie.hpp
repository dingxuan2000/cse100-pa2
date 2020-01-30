/**
 * TODO: File Header
 *
 * Author:
 */
#ifndef DICTIONARY_TRIE_HPP
#define DICTIONARY_TRIE_HPP

#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
class TSTNode {
  private:
    int frequency;
    char letter;
    // bool isEnd;

  public:
    TSTNode* left;
    TSTNode* middle;
    TSTNode* right;
    TSTNode() : frequency(0) {
        left = middle = right = 0;
        // frequency = 0;
        // isEnd = false;
    }
    TSTNode(const char& character, const int& freq)
        : letter(character), frequency(freq) {
        // letter = character;
        // frequency = freq;
        left = middle = right = 0;
        // isEnd = false;
    }
    void setFreq(const int& f) { frequency = f; }
    int getFreq() { return frequency; }
    void setLetter(const char& c) { letter = c; }
    char getLetter() { return letter; }
    // void setIsEnd(bool isEnd){isEnd = }
    // ~TSTNode() {
    //     delete left;
    //     delete middle;
    //     delete right;
    // }
};

struct cmpFreq {
    bool operator()(pair<string, int>& w1, pair<string, int>& w2) const {
        // when two words' frequencies are different
        if (w1.second != w2.second) {
            return w1.second < w2.second;
        }
        // When the frequencies are same, compare the words
        else {
            return w1.first > w2.first;
        }
    }
};
/**
 * The class for a dictionary ADT, implemented as either
 * a mulit-way trie or a ternary search tree.
 */
class DictionaryTrie {
  private:
    // TODO: add private members and helper methods here
    // TSTNode* root;
    // static void deleteAll(TSTNode* n);
    // TSTNode* startNode(string prefix);
    typedef priority_queue<pair<string, int>, vector<pair<string, int>>,
                           cmpFreq>
        pq;
    // void findLeaf(string prefix, TSTNode* curr, pq);

  public:
    TSTNode* root;
    TSTNode* startNode(string prefix);
    void findLeaf(string prefix, TSTNode* curr, pq& queue);
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

#endif  // DICTIONARY_TRIE_HPP
