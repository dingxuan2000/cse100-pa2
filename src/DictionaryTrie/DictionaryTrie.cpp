/**
 * TODO: File Header
 *
 * Author: Xuan Ding, xding@ucsd.edu
 *         Qilong Li, qil009@ucsd.edu
 * DictionaryTrie class provides the ability of storing strings and frequency
 * used in the class. This class provides the functionalities of find and
 * insert of strings and an autocomplete function when the prefix of a word is
 * provided by the user. This class is implemented using TSTNode class with
 * stores character and frequency in each node. This file provides
 * implementation of functions for DiectionaryTrie.hpp
 */
#include "DictionaryTrie.hpp"
#include <iostream>

/* TODO
 * initialized object with root = 0,
 * initialized object with char and frequency
 */
DictionaryTrie::DictionaryTrie() : root(0) {}

/* TODO
 * this function take a parameter of string and int it allows user to insert
 * string and frequency into the dictionaryTrie , if insert is successful
 * returns true returns false otherwise.
 */
bool DictionaryTrie::insert(string word, unsigned int freq) {
    // When the given string is empty, return false
    if (word.empty()) return false;
    // When see the duplicate word, return false.
    if (this->find(word) == true) return false;
    // When the root is nullptr, then directly insert the root, and insert its
    // middle children
    if (this->root == NULL) {
        // 1. When the word is one character, insert as root directly.
        if (word.length() == 1) {
            TSTNode* newNode = new TSTNode(word[0], freq, freq);
            this->root = newNode;
            return true;
        }
        // 2. insert the remaining node as root's middle child, until reach to
        // the end of the word.
        else {
            TSTNode* newNode = new TSTNode(word[0], 0, 0);
            this->root = newNode;
            TSTNode* curr = root;
            int i = 1;
            int cfreq;
            int maxfreq = freq;
            while (i < word.length()) {
                // if not reach to the end of the word, freq is 0
                if (i != word.length() - 1) cfreq = 0;
                // otherwise, freq should be assigned to the end of the word
                else
                    cfreq = freq;
                curr->middle = new TSTNode(word[i], cfreq, maxfreq);
                // For the first word, have to go to middle child
                curr = curr->middle;
                i++;
            }
            return true;
        }
    }
    // When the root is not empty, travrse the trie, and compare the node's data
    // with the word's each character's data.
    int i = 0;
    int cfreq;
    TSTNode* curr;
    curr = this->root;

    while (i < word.length()) {
        // case1: the char in word is greater than current node's data, go to
        // right
        if (curr->getLetter() < word[i]) {
            if (curr->get_Max_Freq() < freq) curr->set_Max_Freq(freq);
            if (curr->right != 0) curr = curr->right;
            // if curr node has no right child, create a new node, with data and
            // appropriate frequency
            else {
                if (i != word.length() - 1)
                    cfreq = 0;
                else
                    cfreq = freq;
                TSTNode* newNode = new TSTNode(word[i], cfreq, cfreq);
                curr->right = newNode;
                curr = curr->right;
            }

        }
        // case 2: the char in word is smaller than current node's data, go to
        // left
        else if (word[i] < curr->getLetter()) {
            if (curr->get_Max_Freq() < freq) curr->set_Max_Freq(freq);
            if (curr->left != 0)
                curr = curr->left;
            else {
                // if curr node has no left child, create a new node, with data
                // and appropriate frequency
                if (i != word.length() - 1)
                    cfreq = 0;
                else
                    cfreq = freq;
                auto* newNode = new TSTNode(word[i], cfreq, cfreq);
                curr->left = newNode;
                curr = curr->left;
                // i++;
            }

        }
        // case 3: the char in word is same as current node's data
        else {
            // when the current node has middle child
            if (curr->get_Max_Freq() < freq) curr->set_Max_Freq(freq);
            if (curr->middle != 0) {
                // if now has reached to the end of the word, set current node's
                // frequency to be a new frequency of the inserted word.
                if (i == word.length() - 1) {
                    curr->setFreq(freq);
                    return true;
                }
                // else, just go to middle child
                else {
                    curr = curr->middle;
                    i++;
                }
            }
            // when the current node has no middle child, just create a new node
            // with its data and appropriate frequency.
            else {
                i++;
                if (i > word.length() - 1) {
                    cfreq = freq;
                    return true;
                } else if (i != word.length() - 1)
                    cfreq = 0;
                else
                    cfreq = freq;

                TSTNode* newNode = new TSTNode(word[i], cfreq, cfreq);
                curr->middle = newNode;
                curr = curr->middle;
            }
        }
        //}
    }
    // When out of while loop, it means we have reached the end of the word,
    // so we have inserted the whole word sucessfully.
    return true;
}

/* TODO
 * this function take a parameter of string, allows user search a string in this
 * dictionaryTrie
 * returns true when a string is found, False otherwise.
 */
bool DictionaryTrie::find(string word) const {
    TSTNode* ptr;
    ptr = this->root;
    // when the tree is empty
    if (ptr == NULL) return false;
    // int index = 0;
    int i = 0;
    // otherwise, traverse the trie
    while ((ptr != NULL) && (i < word.length())) {
        // 1. if the char in word is bigger, go to right
        if (ptr->getLetter() < word[i]) {
            ptr = ptr->right;

        }
        // 2. if the char in word is smaller, go to left
        else if (word[i] < ptr->getLetter()) {
            ptr = ptr->left;

        }
        // 3. if the char in word is exactly same as the current node's data
        else {
            // When reached to the end of the word, return true
            if ((i == word.length() - 1) && (ptr->getFreq() > 0)) return true;
            // Else, go to the middle child, and go to the next char of the word
            else {
                ptr = ptr->middle;
                i++;
            }
        }
    }

    return false;
}

/* TODO
 * This function takes parameter of string and int. It will return a vector
 * sized of the integer argument and contains list of strings sorted by their
 * frequency used. If two strings have the same frequency, strings will be
 * sorted alphabetically.
 */
vector<string> DictionaryTrie::predictCompletions(string prefix,
                                                  unsigned int numCompletions) {
    vector<string> vtr;
    pq queue;
    int max_freq = this->root->get_Max_Freq();
    // If the end node of prefix is null, return am empty vector
    if (startNode(prefix) == 0) {
        return vtr;
    }
    if (numCompletions == 0) return vtr;
    // If the startNode has no middle child, then check if the prefix is a valid
    // word
    else if (startNode(prefix)->middle == 0) {
        // the prefix is not a valid word, return empty vector
        if (startNode(prefix)->getFreq() == 0) return vtr;
        // else, push predix into vector, and return
        else {
            vtr.push_back(prefix);
            return vtr;
        }
    }
    // when the end of prefix's node has middle child, then still need to
    // check if the startNode has frequencies, if the prefix is also a word,
    // make as a pair, and push into the queue.
    else {
        if (startNode(prefix)->getFreq() != 0) {
            // pair<string, int>* ptr =
            //     new pair<string, int>(prefix, startNode(prefix)->getFreq());
            queue.push(make_pair(prefix, startNode(prefix)->getFreq()));
        }

        // When redirect the srartNode
        TSTNode* start = startNode(prefix)->middle;
        // call findLeaf to push every valid word into priority_queue
        findLeaf(prefix, start, queue, numCompletions);
        if (queue.size() > numCompletions) queue.pop();
        for (int i = 0; i < numCompletions; i++) {
            pair<string, int> currPair;
            // if (i == 0) queue.pop();
            // when the pq is not empty, pop each pair and push the first
            // element in pair to the vector
            if (!queue.empty()) {
                currPair = queue.top();
                queue.pop();
            }
            // Before the for loop finishes, if the pq is empty now, then break
            // the for loop.
            else {
                break;
            }

            vtr.insert(vtr.begin(), currPair.first);
        }
        return vtr;
    }
}
/**
 * Parameter: prefix, curr node, queue(must be reference, otherwise, it will be
 * empty pq after finish calling this function).
 * A helper function to make a pair for each valid word and its frequencies,
 * then push into sorted pq.
 */
void DictionaryTrie::findLeaf(string prefix, TSTNode* curr, pq& queue,
                              int numCompletions) {
    if (curr == 0) return;
    //需要将pq的size固定住，根据numCompletions进行判断
    // if (numCompletions == 0) return;

    // if the curr node's freq is greater then 0, then make a pair of its data
    // and freq , then push into queue.
    if (curr->getFreq() > 0) {
        if (queue.size() != numCompletions + 1)
            queue.push(make_pair(prefix + curr->getLetter(), curr->getFreq()));
        else {
            queue.pop();
            queue.push(make_pair(prefix + curr->getLetter(), curr->getFreq()));
        }
    }
    // traverse the whole trie
    findLeaf(prefix, curr->left, queue, numCompletions);
    findLeaf(prefix, curr->right, queue, numCompletions);
    // Once the curr's middle is not null, append the curr node's data to
    // prefix, and go to
    // it's middle child
    if (curr->middle != 0) {
        findLeaf(prefix + curr->getLetter(), curr->middle, queue,
                 numCompletions);
    }
}
/* TODO */
std::vector<string> DictionaryTrie::predictUnderscores(
    string pattern, unsigned int numCompletions) {
    vector<string> vtr1;
    // vector<string> vtr2;
    pq queue;
    TSTNode* start = nullptr;
    // don't forget the numCompletions == 0's edge case
    if (numCompletions == 0) return vtr1;
    // if the first char in pattern is wildcard, then the startNode should be
    // root and we still need to check if the pattern has next char, and if the
    // root has the next layer
    //首先判断第一个char是不是wildcard, 如果是的--> startNode从root开始，
    //如果不是的话，通过startNode()去找第一个char的位置
    if (pattern[0] == '_') {
        start = this->root;
    } else {
        // if not wildcard, then the first char as the substring, and call
        // startNode to determine where it is in trie, as the prefix(only one
        // char)! starts with starting letter of pattern
        start = startNode(pattern.substr(0, 1));
    }
    //如果这个startNode不存在，要不就是root=nullptr,
    //要不就是pattern的第一个char就不存在这个trie里面，那么直接return empty
    // vector
    // if cannot find
    if (start == nullptr)
        return vtr1;
    else {
        //如果startNode有值的话，就call predict()去将符合pattern的valid word塞进
        // pq里面
        string prediction("");  // will be passed into helper function
        predict(pattern, start, queue, prediction);

        while (!queue.empty()) {
            vtr1.insert(vtr1.begin(), queue.top().first);
            queue.pop();
        }
        // for (int i = 0; i < numCompletions; i++) {
        // pair<string, int> currPair;
        // When the pq is not empty, pop each pair and push the first
        // element in pair to the vector
        vector<string> vtr2 =
            std::vector<string>(vtr1.begin(), vtr1.begin() + numCompletions);

        // if (!queue.empty()) {
        //     currPair = queue.top();
        //     queue.pop();
        // }
        // // before the for loop finished, if the pq is empty now, then break
        // // the loop
        // else {
        //     break;
        // }
        //}
        return vtr2;
    }
}

void DictionaryTrie::predict(string pattern, TSTNode* curr, pq& queue,
                             string prediction) {
    //传进来的startNode不可能是0了，因为在大function里面判断过了
    if (curr == 0) return;
    //如果pattern只有一个char的话
    if ((pattern.length() == 1)) {
        //首先，如果这一个char是wildcard的话，那么传进来的curr就是root,
        //然后traverse the trie, 但是只能去left and right child,
        // 因为如果去middle的话，那这个word length就不会是1了
        if (pattern.substr(0, 1) == "_")  // wild card base case still need to
                                          // look at all left and right branch .
        {
            predict(pattern, curr->left, queue, prediction);
            predict(pattern, curr->right, queue, prediction);
            // push all candidates which frequency >1.
            if (curr->getFreq() > 0)
                queue.push(
                    make_pair(prediction + curr->getLetter(), curr->getFreq()));

        }
        //如果第一个char不是wildcard的话，可以通过find_next_Node去找到第一个char的位置
        else {  // case is not a wild card.
            curr = find_next_Node(
                curr, pattern.substr(0, 1));  // find that vaild node.
            //如果curr是nullptr的话，需要return,
            //否则可能会造成下一行的nullptr->getFreq(), 将会有segfault!!!
            if (curr == 0) return;  // don't forget this case!!!
            if (curr->getFreq() > 0) {
                queue.push(
                    make_pair(prediction + curr->getLetter(), curr->getFreq()));
            }
        }

    }
    //当这个pattern不止有一个char时
    else {
        //首先，还是先判断pattern的第一个char是不是wildcard, 如果是wildcard,
        //走left, right, middle. 如果走middle,
        //每次都需要将当前的letter加到prediction里， 然后pattern.length-1
        if (pattern.substr(0, 1) == "_") {
            predict(pattern, curr->left, queue, prediction);
            predict(pattern, curr->right, queue, prediction);
            predict(pattern.substr(1, pattern.length() - 1), curr->middle,
                    queue, prediction + curr->getLetter());
        }
        if (pattern.substr(0, 1) == " ") {
            predict(pattern.substr(1, pattern.length() - 1), curr->middle,
                    queue, prediction + " ");
        }
        // if the first char is not wildcard, we need to use find_next_Node
        // to find the curr's location
        else {
            curr = find_next_Node(
                curr,
                pattern.substr(0, 1));  // if current pattern is a char, find
                                        // next node that contains this char if
                                        // not found curr is equal to null.
            // if curr is nullptr, return
            if (curr == 0) return;
            // else, use predict() to traverse the middle subtree
            predict(pattern.substr(1, pattern.length() - 1), curr->middle,
                    queue,
                    prediction +
                        curr->getLetter());  // recurrsively calls the function
                                             // now the curr should be pointing
                                             // to the next char.
        }
    }
}
// this is different from startNode(), since the ptr is not always starts at
// root, we need to treat each char in pattern as a startNode
TSTNode* DictionaryTrie::find_next_Node(TSTNode* ptr, string prefix) {
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

    return nullptr;  // return ptr; because ptr now is nullptr.
}

// To delete all the memory of nodes in TST, will be called in ~DictionaryTrie()
void DictionaryTrie::deleteAll(TSTNode* n) {
    if (n == 0) return;
    deleteAll(n->left);
    deleteAll(n->middle);
    deleteAll(n->right);
    delete n;
}

/* TODO
 * Destructor, delete all the memory of the nodes in TST.
 */
DictionaryTrie::~DictionaryTrie() { deleteAll(this->root); }
/**
 * Parameter: prefix
 * Similar to find() method, to get the end node of the prefix.
 */
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

    return nullptr;  // return ptr; because ptr now is nullptr.
}
