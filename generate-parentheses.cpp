/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper("", n, n, result);
        return result;
    }
    
private:
    void generateParenthesisHelper(string current, int open, int close, vector<string>& result) {
        // Base case: if we've used all parentheses, add the current string to the result
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }
        
        // If we have remaining open parentheses, we can always add an open parenthesis
        if (open > 0) {
            generateParenthesisHelper(current + "(", open - 1, close, result);
        }
        
        // We can only add a closing parenthesis if there are more closed parentheses remaining than open
        if (close > open) {
            generateParenthesisHelper(current + ")", open, close - 1, result);
        }
    }
};