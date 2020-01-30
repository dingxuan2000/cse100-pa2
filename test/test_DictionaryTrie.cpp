/**
 * TODO: File HEADER
 *
 * Author:
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "DictionaryTrie.hpp"
#include "util.hpp"

using namespace std;
using namespace testing;

/* Empty test */
// TEST(DictTrieTests, EMPTY_TEST) {
//     DictionaryTrie dict;
//     ASSERT_EQ(dict.find("abrakadabra"), false);
// }
// TEST(DictTrieTests, INSERT) {
//     DictionaryTrie dict;
//     dict.insert("a", 2);
//     dict.insert("bc", 3);
//     dict.insert("ba", 3);
//     // dict.insert("abdf", 3);

//     cout << (dict.root)->getLetter() << endl;
//     cout << (dict.root)->right->getLetter() << endl;
//     cout << (dict.root)->right->middle->getLetter() << endl;
//     cout << (dict.root)->right->right->getLetter() << endl;
// }
// TEST(DictTrieTests, FIND) {
//     DictionaryTrie dict;
//     dict.insert("a", 2);
//     dict.insert("ab", 2);
//     EXPECT_EQ(dict.find("a"), true);
//     ASSERT_EQ(dict.find("ab"), true);
// }
// TEST(DictTrieTests, findLeaf) {
//     DictionaryTrie dict;
//     dict.insert("a", 2);
//     dict.insert("ab", 2);
//     priority_queue<pair<string, int>, vector<pair<string, int>>, cmpFreq> pq;

//     dict.findLeaf("a", dict.root, pq);
//     cout << pq.size() << endl;
//     while (!pq.empty()) {
//         cout << pq.top().first << endl;
//         pq.pop();
//     }
// }
// TEST(DictTrieTests, predictCompletion) {
//     DictionaryTrie dict;
//     dict.insert("ab", 2);
//     dict.insert("abc", 3);
//     dict.insert("def", 2);

//     vector<string> vtr;
//     // //     // vtr.push_back("abc");
//     // //     // vtr.push_back("ab");
//     // //     // ASSERT_EQ(dict.predictCompletions("ab", 2), vtr);
//     vtr = dict.predictCompletions("d", 2);
//     for (string s : vtr) cout << s << "\n" << endl;
//     //}
//     // TEST(DictTrieTests, startNode){
// }

// TEST(DictTrieTests, startNode) {
//     DictionaryTrie dict;
//     dict.insert("ab", 2);
//     dict.insert("abc", 3);
//     dict.insert("def", 2);
//     cout << dict.root->getLetter() << endl;
//     cout << dict.root->right->getLetter() << endl;
//     cerr << "Testing startNode" << endl;
//     cerr << dict.startNode("a")->getLetter() << endl;
//     cerr << dict.startNode("de")->getLetter() << endl;
//     cerr << dict.startNode("ab")->getLetter() << endl;
//     cerr << dict.startNode("aa")->getLetter() << endl;

// ASSERT_EQ(dict.startNode("aa"), nullptr);
// cerr << "Testing Insert" << endl;
// cerr << dict.root->getLetter() << endl;
// cerr << dict.root->right->getLetter() << endl;
// cerr << dict.root->right->middle->getLetter() << endl;
// cerr << dict.root->right->middle->middle->getLetter() << endl;

// cerr << "Testing Find" << endl;
// cerr << dict.find("ab") << endl;
// cerr << dict.find("abc") << endl;
// cerr << dict.find("def") << endl;
// ASSERT_TRUE(dict.find("ab"));
// ASSERT_TRUE(dict.find("abc"));
// ASSERT_TRUE(dict.find("def"));
// TSTNode* start = dict.startNode("def");
// cout << start->getLetter() << endl;
//}
TEST(DictTrieTests, PQ) {
    DictionaryTrie dict;
    dict.insert("ab", 2);
    dict.insert("abc", 3);
    dict.insert("def", 2);
    vector<string> vtr;
    vtr = dict.predictCompletions("a", 2);
    cout << vtr.size() << endl;
    for (int i = 0; i < vtr.size(); i++) {
        cout << "----88888-" << endl;
        cout << vtr.at(i) << endl;
    }
}

/* TODO */
