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
//     ASSERT_EQ(dict.insert("a", 2), true);
//     EXPECT_EQ(dict.insert("abc", 3), true);
//     EXPECT_EQ(dict.insert("abd", 3), true);
//     ASSERT_EQ(dict.insert("abdf", 3), true);
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
//     // vtr.push_back("abc");
//     // vtr.push_back("ab");
//     // ASSERT_EQ(dict.predictCompletions("ab", 2), vtr);
//     vtr = dict.predictCompletions("ab", 2);
//     for (string s : vtr) cout << s << "\n" << endl;
// }
// TEST(DictTrieTests, startNode){

// }

/* TODO */
