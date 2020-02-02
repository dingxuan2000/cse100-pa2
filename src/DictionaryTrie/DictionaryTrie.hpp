/**
 * TODO: File Header
 *
 * Author:  Xuan Ding, xding@ucsd.edu
 *          Qilong Li, qil009@ucsd.edu
 * This file provides DictionaryTrie function delcarations as well as the
 * TSTNode class to the DictionaryTrie.cpp file. And a comparator struct to help
 * sorting the priority_queue.
 */
#ifndef DICTIONARY_TRIE_HPP
#define DICTIONARY_TRIE_HPP

#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
// The TSTNode class, for creating new TSTnode in Trie.
class TSTNode {
  private:
    int frequency;
    char letter;

  public:
    TSTNode* left;
    TSTNode* middle;
    TSTNode* right;
    TSTNode() : frequency(0) { left = middle = right = 0; }
    TSTNode(const char& character, const int& freq)
        : letter(character), frequency(freq) {
        left = middle = right = 0;
    }
    void setFreq(const int& f) { frequency = f; }
    int getFreq() { return frequency; }
    void setLetter(const char& c) { letter = c; }
    char getLetter() { return letter; }
};
// The cmpFreq struct, to help compare the elements in pair, and can sorting
// pairs in priority_queue.
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
    TSTNode* root;
    void deleteAll(TSTNode* n);
    TSTNode* startNode(string prefix);
    typedef priority_queue<pair<string, int>, vector<pair<string, int>>,
                           cmpFreq>
        pq;
    void findLeaf(string prefix, TSTNode* curr, pq& queue);
    void predict(string pattern, TSTNode* curr, pq& queue, string predict);
    TSTNode* find_next_Node(TSTNode* ptr ,string prefix);

  public:
    /* TODO: add function header
     * initialized object with root = 0,
     * initialized object with char and frequency
     */
    DictionaryTrie();

    /* TODO: add function header
     * this function take a parameter of string and int it allows user to insert
     * string and frequency into the dictionaryTrie , if insert is successful
     * returns true returns false otherwise.
     */
    bool insert(string word, unsigned int freq);

    /* TODO: add function header
     * this function take a parameter of string, allows user search a string in
     * this dictionaryTrie returns true when a string is found, False otherwise.
     */
    bool find(string word) const;

    /* TODO: add function header
     * This function takes parameter of string and int. It will return a vector
     * sized of the integer argument and contains list of strings sorted by
     * their frequency used. If two strings have the same frequency, strings
     * will be sorted alphabetically.
     */
    vector<string> predictCompletions(string prefix,
                                      unsigned int numCompletions);

    /* TODO: add function header */
    vector<string> predictUnderscores(string pattern,
                                      unsigned int numCompletions);

    /* TODO: add function header
     * Destructor, delete all the memory of the nodes in TST.
     */
    ~DictionaryTrie();
};
// Declare the trie node as a class type

#endif  // DICTIONARY_TRIE_HPP
