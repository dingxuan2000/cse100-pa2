/**
 * TODO: File Header
 *
 * Author:
 */
#include "DictionaryTrie.hpp"
#include <iostream>

/* TODO */
DictionaryTrie::DictionaryTrie() : root(0) {}

/* TODO */
bool DictionaryTrie::insert(string word, unsigned int freq) {
    // TSTNode* newNode = new TSTNode(word[i], freq);
    // When the given string is empty, return false
    if (word.empty()) return false;
    //当遇到duplicate word时，return false
    if (this->find(word) == true) return false;
    //如果当前node不是end of word, 那么copy of freq就是0, 否则, cfreq是freq的值
    if (this->root == NULL) {
        if (word.length() == 1) {
            auto* newNode = new TSTNode(word[0], freq);
            this->root = newNode;
            return true;
        } else {
            auto* newNode = new TSTNode(word[0], 0);
            this->root = newNode;
        }
    }
    int i = 0;
    int cfreq;
    TSTNode* curr;
    curr = this->root;

    while (i < word.length()) {
        // case1: empty trie, insert the whole string as the only one word in
        // the trie, 如果current node是空的话，就create a new node.
        // if (curr == NULL) {
        //     if (i != word.length() - 1)
        //         cfreq = 0;
        //     else
        //         cfreq = freq;
        //     curr = new TSTNode(word[i], cfreq);
        // } else {
        //当这个trie不是空的，首先比较root的char和word的第一个char:
        //如果想要insert word的第一个char比root大的话，去找root右边的孩子
        if (curr->getLetter() < word[i]) {
            if (curr->right != 0)
                curr = curr->right;
            else {
                if (i != word.length() - 1)
                    cfreq = 0;
                else
                    cfreq = freq;
                auto* newNode = new TSTNode(word[i], cfreq);
                curr->right = newNode;
                curr = curr->right;
                i++;
            }

        }

        else if (word[i] < curr->getLetter()) {
            if (curr->left != 0)
                curr = curr->left;
            else {
                if (i != word.length() - 1)
                    cfreq = 0;
                else
                    cfreq = freq;
                auto* newNode = new TSTNode(word[i], cfreq);
                curr->left = newNode;
                curr = curr->left;
                i++;
            }

        } else {
            if (curr->middle != 0) {
                curr = curr->middle;
                i++;
            } else {
                if (i != word.length() - 1)
                    cfreq = 0;
                else
                    cfreq = freq;
                auto* newNode = new TSTNode(word[i], cfreq);
                curr->middle = newNode;
                curr = curr->middle;
                i++;
            }
        }
        //}
    }
    return true;  //当出了while循环，说明已经遍历了整个word，把word的每个char都insert进去了
}

/* TODO */
bool DictionaryTrie::find(string word) const {
    TSTNode* ptr;
    ptr = this->root;
    if (ptr == NULL) return false;
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
            if ((i == word.length() - 1) && (ptr->getFreq() > 0))
                return true;
            else {
                ptr = ptr->middle;
                i++;
            }
        }
    }

    return false;
}

/* TODO */
vector<string> DictionaryTrie::predictCompletions(string prefix,
                                                  unsigned int numCompletions) {
    //写一个helper function, returns the node, which is the end of the
    // prefix,当做start node, 去找 这个start node下面的所有valid word.
    //一旦找到一个node, which frequency>0, 那么用一个helper function
    //从下到上的去将每个char组成一个string.
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
DictionaryTrie::~DictionaryTrie() {}
TSTNode* startNode(string prefix) {
    TSTNode* ptr;
    // ptr = this->root;
    if (ptr == NULL) return NULL;
    // int index = 0;
    int i = 0;
    while ((ptr != NULL) && (i < prefix.length())) {
        if (ptr->getLetter() < prefix[i]) {
            ptr = ptr->right;
            // i--;

        } else if (prefix[i] < ptr->getLetter()) {
            ptr = ptr->left;
            // i--;
        } else {
            // When found the char in word, then go to the middle child, and
            // go to the next char of the word
            if ((i == prefix.length() - 1) && (ptr->getFreq() > 0))
                return ptr;
            else {
                ptr = ptr->middle;
                i++;
            }
        }
    }

    return NULL;
}
