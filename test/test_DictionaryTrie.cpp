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
//     // findLeaf()
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

TEST(DictTrieTests, startNode) {
    DictionaryTrie dict;
    dict.insert("ab", 2);
    dict.insert("abc", 3);
    dict.insert("def", 2);
    // cout << dict.root->getLetter() << endl;
    // cout << dict.root->right->getLetter() << endl;

    cerr << "Testing Insert" << endl;
    cerr << dict.root->getLetter() << endl;
    cerr << dict.root->right->getLetter() << endl;
    cerr << dict.root->right->middle->getLetter() << endl;
    cerr << dict.root->right->middle->middle->getLetter() << endl;

    cerr << "Testing Find" << endl;
    cerr << "Testing startNode" << endl;
    // TSTNode* start = dict.startNode("def");
    // cout << start->getLetter() << endl;
}

/* TODO */
