/**
 * TODO: File HEADER
 *
 * Author: Xuan Ding, xding@ucsd.edu
 *          Qilong Li, qil009@ucsd.edu
 * Use googleTest to test find, insert, predictCompletion functions.
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
TEST(DictTrieTests, EMPTY_TEST) {
    DictionaryTrie dict;
    ASSERT_EQ(dict.find("abrakadabra"), false);
}
TEST(DictTrieTests, INSERT) {
    DictionaryTrie dict;
    dict.insert("a", 2);
    dict.insert("bc", 3);
    dict.insert("ba", 3);
    // EXPECT_EQ(dict.insert("a", 2), false);
    // EXPECT_EQ(dict.insert("bc", 2), false);
    // EXPECT_EQ(dict.insert("ba", 3), false);
    // EXPECT_EQ(dict.insert("def", 5), true);
    vector<string> vtr;
    // vtr.push_back("sea");
    // ASSERT_EQ(dict.predictCompletions("a", 0), vtr);
    ASSERT_EQ(dict.predictCompletions("s", 1), vtr);
}
// TEST(DictTrieTests, FIND) {
//     DictionaryTrie dict;
//     dict.insert("shell", 2);
//     dict.insert("she", 3);
//     dict.insert("ab", 2);
//     dict.insert("bc", 3);
//     dict.insert("ba", 3);
//     EXPECT_EQ(dict.find("ba"), true);
//     EXPECT_EQ(dict.find("ab"), true);
//     EXPECT_EQ(dict.find("bc"), true);
//     EXPECT_EQ(dict.find("she"), true);
//     EXPECT_EQ(dict.find("shell"), true);
// }

// TEST(DictTrieTests, predictCompletion) {
//     DictionaryTrie dict;
//     dict.insert("ab", 2);
//     dict.insert("abc", 3);
//     dict.insert("def", 2);

//     vector<string> vtr;
//     vtr.push_back("abc");
//     vtr.push_back("ab");
//     ASSERT_EQ(dict.predictCompletions("ab", 2), vtr);

//     // vtr = dict.predictCompletions("d", 2);
//     // for (string s : vtr) cout << s << "\n" << endl;
// }
// TEST(DictTrieTests, PredictCompletion_TEST) {
//     DictionaryTrie dict;
//     dict.insert("shells", 50);
//     dict.insert("by", 3);
//     dict.insert("the", 2);
//     dict.insert("sells", 2);
//     dict.insert("sea", 100);
//     dict.insert("she", 6);
//     dict.insert("shore", 2);

//     vector<string> start_with_s;
//     start_with_s.push_back("sea");
//     ASSERT_EQ(dict.predictCompletions("s", 1), start_with_s);
//     start_with_s.push_back("shells");
//     ASSERT_EQ(dict.predictCompletions("s", 2), start_with_s);
//     vector<string> start_with_by;
//     start_with_by.push_back("by");
//     ASSERT_EQ(dict.predictCompletions("by", 1), start_with_by);
//     ASSERT_EQ(dict.predictCompletions("by", 2), start_with_by);

//     EXPECT_TRUE(dict.find("shells"));
//     EXPECT_TRUE(dict.find("by"));
//     EXPECT_TRUE(dict.find("the"));
//     EXPECT_TRUE(dict.find("sells"));
//     EXPECT_TRUE(dict.find("sea"));
//     EXPECT_TRUE(dict.find("she"));
//     EXPECT_TRUE(dict.find("shore"));

//     EXPECT_FALSE(dict.insert("shells", 40));
// }

/* TODO */
