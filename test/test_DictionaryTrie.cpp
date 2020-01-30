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
TEST(DictTrieTests, EMPTY_TEST) {
    DictionaryTrie dict;
    ASSERT_EQ(dict.find("abrakadabra"), false);
}
TEST(DictTrieTests, INSERT) {
    DictionaryTrie dict;
    dict.insert("a", 2);
    dict.insert("bc", 3);
    dict.insert("ba", 3);
    EXPECT_EQ(dict.insert("a", 2), false);
    EXPECT_EQ(dict.insert("bc", 2), false);
    ASSERT_EQ(dict.insert("ba", 3), false);
}
TEST(DictTrieTests, FIND) {
    DictionaryTrie dict;
    dict.insert("a", 2);
    dict.insert("ab", 2);
    dict.insert("bc", 3);
    dict.insert("ba", 3);
    EXPECT_EQ(dict.find("a"), true);
    EXPECT_EQ(dict.find("ab"), true);
    EXPECT_EQ(dict.find("bc"), true);
    ASSERT_EQ(dict.find("ba"), true);
}

TEST(DictTrieTests, predictCompletion) {
    DictionaryTrie dict;
    dict.insert("ab", 2);
    dict.insert("abc", 3);
    dict.insert("def", 2);

    vector<string> vtr;
    vtr.push_back("abc");
    vtr.push_back("ab");
    ASSERT_EQ(dict.predictCompletions("ab", 2), vtr);

    // vtr = dict.predictCompletions("d", 2);
    // for (string s : vtr) cout << s << "\n" << endl;
}

/* TODO */
