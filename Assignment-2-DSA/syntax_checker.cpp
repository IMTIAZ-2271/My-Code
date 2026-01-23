#include <stack>
#include <string>
using namespace std;

/**
 * Helper function to check if an opening bracket matches a closing bracket
 * @param opening: The opening bracket character
 * @param closing: The closing bracket character
 * @return true if they form a matching pair, false otherwise
 */
bool isMatchingPair(char opening, char closing)
{
    // TODO: Implement this helper function
    // Check if opening and closing brackets match
    // Valid pairs: (), [], {}
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

/**
 * Checks if brackets in an arithmetic expression are properly matched
 * @param expression: A string containing an arithmetic expression
 * @return true if all brackets are properly matched and balanced, false otherwise
 */
bool isValidExpression(const string &expression)
{
    // TODO: Implement the syntax checker using std::stack

    stack<char> brackets;
    int n = expression.length();
    for (int i = 0; i < n; ++i)
    {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            brackets.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (brackets.empty())
            {
                return false;
            }
            char top = brackets.top();
            brackets.pop();
            if (!isMatchingPair(top, ch))
            {
                return false; 
            }
        }
    }
    return brackets.empty();
}
