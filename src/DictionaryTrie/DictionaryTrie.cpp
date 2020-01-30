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
    //如果当前node不是end of word, 那么copy of freq就是0, 否则,
    // cfreq是freq的值
    if (this->root == NULL) {
        // insert directly

        if (word.length() == 1) {
            TSTNode* newNode = new TSTNode(word[0], freq);
            this->root = newNode;
            return true;
        } else {
            TSTNode* newNode = new TSTNode(word[0], 0);

            this->root = newNode;
            TSTNode* curr = root;
            int i = 1;
            int cfreq;
            while (i < word.length()) {
                if (i != word.length() - 1)
                    cfreq = 0;
                else
                    cfreq = freq;
                curr->middle = new TSTNode(word[i], cfreq);
                curr = curr->middle;
                i++;
            }
            return true;
        }
    }

    int i = 0;
    int cfreq;
    TSTNode* curr;
    curr = this->root;

    while (i < word.length()) {
        // case1: empty trie, insert the whole string as the only one word
        // in the trie, 如果current node是空的话，就create a new node.
        if (curr->getLetter() < word[i]) {
            if (curr->right != 0)
                curr = curr->right;
            else {
                if (i != word.length() - 1)
                    cfreq = 0;
                else
                    cfreq = freq;
                TSTNode* newNode = new TSTNode(word[i], cfreq);
                curr->right = newNode;
                curr = curr->right;
                // i++;
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
                // i++;
            }

        } else {
            if (curr->middle != 0) {
                curr = curr->middle;
                i++;
            } else {
                i++;
                if (i > word.length() - 1)
                    return true;
                else if (i != word.length() - 1)
                    cfreq = 0;
                else
                    cfreq = freq;

                TSTNode* newNode = new TSTNode(word[i], cfreq);
                curr->middle = newNode;
                curr = curr->middle;
            }
        }
        //}
    }
    return true;
    //当出了while循环，说明已经遍历了整个word，把word的每个char都insert进去了
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
    // 写一个helper function, returns the node, which is the end of the
    // prefix,当做start node, 去找 这个start node下面的所有valid word.
    // 一旦找到一个node, which frequency>0, 那么用一个helper function
    // 从下到上的去将每个char组成一个string.
    vector<string> vtr;
    pq queue;
    // Segmentation fault
    if (startNode(prefix) == 0) {
        return vtr;
    } else if (startNode(prefix)->middle == 0) {
        if (startNode(prefix)->getFreq() == 0)
            return vtr;
        else {
            vtr.push_back(prefix);
            return vtr;
        }
    }
    // When the middle
    else {
        // when the end of prefix's node has middle child, then still need to
        // check if the startNode has frequencies, if the prefix is also a word,
        // make as a pair, and push into the queue.
        if (startNode(prefix)->getFreq() != 0) {
            // pair<string, int>* ptr =
            //     new pair<string, int>(prefix, startNode(prefix)->getFreq());
            queue.push(make_pair(prefix, startNode(prefix)->getFreq()));
        }

        // When the middle subtree is not null
        TSTNode* start = startNode(prefix)->middle;
        findLeaf(prefix, start, queue);
        for (int i = 0; i < numCompletions; i++) {
            pair<string, int> currPair;
            if (!queue.empty()) {
                currPair = queue.top();
                queue.pop();
            } else {
                break;
            }

            vtr.push_back(currPair.first);
        }
        return vtr;
    }
}
void DictionaryTrie::findLeaf(string prefix, TSTNode* curr, pq& queue) {
    if (curr == 0) return;  // maybe the problem
    if (curr->getFreq() > 0) {
        // pair<string, int>* ptr =
        //     new pair<string, int>(prefix + curr->getLetter(),
        //     curr->getFreq());
        queue.push(make_pair(prefix + curr->getLetter(), curr->getFreq()));
    }

    findLeaf(prefix, curr->left, queue);
    findLeaf(prefix, curr->right, queue);
    if (curr->middle != 0) {
        findLeaf(prefix + curr->getLetter(), curr->middle, queue);
    }
}
/* TODO */
std::vector<string> DictionaryTrie::predictUnderscores(
    string pattern, unsigned int numCompletions) {
    return {};
}
void DictionaryTrie::deleteAll(TSTNode* n) {
    if (n == 0) return;
    deleteAll(n->left);
    deleteAll(n->middle);
    deleteAll(n->right);
    delete n;
}

/* TODO */
DictionaryTrie::~DictionaryTrie() { deleteAll(this->root); }
TSTNode* DictionaryTrie::startNode(string prefix) {
    TSTNode* ptr;
    ptr = this->root;
    if (ptr == NULL) return nullptr;
    // int index = 0;
    int i = 0;
    while ((ptr != NULL) && (i < prefix.length())) {
        if (ptr->getLetter() < prefix[i]) {
            ptr = ptr->right;

        } else if (prefix[i] < ptr->getLetter()) {
            ptr = ptr->left;

        } else {
            // When found the char in word, then go to the middle child, and
            // go to the next char of the word
            if ((i == prefix.length() - 1))
                return ptr;
            else {
                ptr = ptr->middle;
                i++;
            }
        }
    }

    return nullptr;
}
