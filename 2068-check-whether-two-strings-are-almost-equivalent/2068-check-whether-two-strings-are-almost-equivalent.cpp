class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int count[26] = {0};
        for (auto c : word1) {
            count[c-'a']++;
        }
        for (auto c : word2) {
            count[c-'a']--;
        }
        for (auto c : count) {
            if (abs(c) > 3) return false;
        }
        return true;
        
    }
};