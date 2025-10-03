// 242. Valid Anagram
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.
 
// CODE:-

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length())
      return false;

    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (const char c : t) {
      if (count[c - 'a'] == 0)
        return false;
      --count[c - 'a'];
    }

    return true;
  }
};
