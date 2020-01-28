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
    int i = 0;
    int cfreq;
    if (i != word.length() - 1)
        cfreq = 0;
    else
        cfreq = freq;
    //我们需要Insert整个word, 所以当超过了word的length的话，就结束insert
    while (i < word.length()) {
        // case1: empty trie, insert the whole string as the only one word in
        // the trie
        TSTNode* curr;
        curr = this->root;
        if (curr == NULL) {
            curr = new TSTNode(word[i], cfreq);
            //这里也是要如何recursivly create new node for each middle child?
            curr->middle = insertChar(word[i++], cfreq);
        } else {
            //当这个trie不是空的，首先比较root的char和word的第一个char:
            //如果想要insert word的第一个char比root大的话，去找root右边的孩子
            if (curr->getLetter() < word[i]) {
                curr = curr->right;
                /**1. if curr->right == null, create a new node, and set this
                 *new node as the curr's right child, Then for the rest of the
                 *char, recursively insert under the curr's right child.
                 *2. if curr->right != null, 那么继续traverse the tree, curr =
                 *curr->right;
                 */

            }
            // curr = insertChar(word[i], cfreq);
            else if (word[i] < curr->getLetter()) {
                /**这里的情况和上面一样，需要添加
                 */
                curr = curr->left;
            } else {
                /**需要完善
                 */
                // curr = insertChar(word[i], cfreq);
                curr = curr->middle;
                i++;
            }
        }
        //当i到了整个要insert的word的最后一个char时
        // if (i == word.length() - 1)
        //     return true;
        // else
        //     return false;
    }
    return true;  //当出了while循环，说明已经遍历了整个word，把word的每个char都insert进去了
    // TSTNode* currentptr = this->root;
    // if (currentptr == 0) {
    //     for (int i = 0; i < word.length(); i++) {
    //         currentptr = new TSTNode(word[i], freq);
    //         currentptr = currentptr->middle;
    //     }
    // }

    return false;
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
    return {};
}

/* TODO */
std::vector<string> DictionaryTrie::predictUnderscores(
    string pattern, unsigned int numCompletions) {
    return {};
}

/* TODO */
DictionaryTrie::~DictionaryTrie() {}
// TSTNode* newNode(char letter, int freq) {
//     TSTNode* newNode = new TSTNode();
//     newNode->setLetter(letter);
//     newNode->setFreq(freq);
//     newNode->left = newNode->middle = newNode->right = NULL;
//     return newNode;
// }
TSTNode* insertChar(char letter, int freq) {
    TSTNode* node = new TSTNode(letter, freq);
    return node;
}