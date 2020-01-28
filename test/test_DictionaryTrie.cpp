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
    ASSERT_EQ(dict.insert("a", 2), true);
    EXPECT_EQ(dict.insert("abc", 3), true);
    EXPECT_EQ(dict.insert("abd", 3), true);
    ASSERT_EQ(dict.insert("abdf", 3), true);
}
TEST(DictTrieTests, FIND) {
    DictionaryTrie dict;
    dict.insert("a", 2);
    dict.insert("ab", 2);
    EXPECT_EQ(dict.find("a"), true);
    ASSERT_EQ(dict.find("ab"), true);
}

/* TODO */
