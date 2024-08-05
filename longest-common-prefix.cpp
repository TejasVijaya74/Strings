/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Use the first string as the initial prefix
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            // While the current string doesn't start with the prefix
            while (strs[i].find(prefix) != 0) {
                // Shorten the prefix by one character
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If prefix becomes empty, there's no common prefix
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};