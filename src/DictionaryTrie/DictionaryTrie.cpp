/**
 * TODO: File Header
 *
 * Author:
 */
#include "DictionaryTrie.hpp"
#include <iostream>

/* TODO */
DictionaryTrie::DictionaryTrie() { TSTNode* root = 0; }

/* TODO */
bool DictionaryTrie::insert(string word, unsigned int freq) {
    // TSTNode* newNode = new TSTNode(word[i], freq);
    // When the given string is empty, return false
    if (word.empty()) return false;
    //当遇到duplicate word时，return false
    if (this->find(word) == true) return false;
    //如果当前node不是end of word, 那么copy of freq就是0, 否则, cfreq是freq的值
    if (this->root == NULL) {
        if (word.length() == 1)
            this->root = new TSTNode(word[0], freq);
        else {
            this->root = new TSTNode(word[0], 0);
        }
    }
    int i = 0;
    int cfreq;
    TSTNode* curr;
    curr = this->root;

    while (i < word.length()) {
        // case1: empty trie, insert the whole string as the only one word in
        // the trie, 如果current node是空的话，就create a new node.
        if (curr == NULL) {
            if (i != word.length() - 1)
                cfreq = 0;
            else
                cfreq = freq;
            curr = new TSTNode(word[i], cfreq);
        } else {
            //当这个trie不是空的，首先比较root的char和word的第一个char:
            //如果想要insert word的第一个char比root大的话，去找root右边的孩子
            if (curr->getLetter() < word[i])
                curr = curr->right;

            else if (word[i] < curr->getLetter())
                curr = curr->left;
            else {
                // curr = insertChar(word[i], cfreq);
                curr = curr->middle;
                i++;
            }
        }
    }
    return true;  //当出了while循环，说明已经遍历了整个word，把word的每个char都insert进去了
}

/* TODO */
bool DictionaryTrie::find(string word) const {
    TSTNode* ptr;
    ptr = this->root;
    if (ptr == NULL) return false;

    // for (int i = 0; i < word.length(); i++) {
    // int index = 0;
    int i = 0;
    while ((ptr != NULL) && (i < word.length())) {
        if (ptr->getLetter() < word[i]) {
            ptr = ptr->right;
            // i--;

        } else if (word[i] < ptr->getLetter()) {
            ptr = ptr->left;
            // i--;
        } else {
            // When found the char in word, then go to the middle child, and
            // go to the next char of the word
            ptr = ptr->middle;
            i++;
        }
        if ((i == word.length() - 1) && (ptr->getFreq() > 0)) {
            return true;
        } else
            return false;
    }

    return false;
}

/* TODO */
vector<string> DictionaryTrie::predictCompletions(string prefix,
                                                  unsigned int numCompletions) {
    //
    return {};
}

/* TODO */
std::vector<string> DictionaryTrie::predictUnderscores(
    string pattern, unsigned int numCompletions) {
    return {};
}
// static void deleteAll(TSTNode* n) {
//     if (n == 0) return;
//     deleteAll(n->left);
//     deleteAll(n->middle);
//     deleteAll(n->right);
//     delete n;
// }

/* TODO */
DictionaryTrie::~DictionaryTrie() {
    // deleteAll(this->root);
}
// TSTNode* newNode(char letter, int freq) {
//     TSTNode* newNode = new TSTNode();
//     newNode->setLetter(letter);
//     newNode->setFreq(freq);
//     newNode->left = newNode->middle = newNode->right = NULL;
//     return newNode;
// }
// TSTNode* insertChar(char letter, int freq) {
//     TSTNode* node = new TSTNode(letter, freq);
//     return node;
// }
