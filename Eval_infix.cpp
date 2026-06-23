#include <iostream>
#include <stack>
#include <string>
#include <cctype> // For isdigit()

using namespace std;

// Helper function to establish operator precedence
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Helper function to perform the arithmetic
int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

int evaluateInfix(string tokens)
{
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < tokens.length(); i++)
    {
        // 1. Skip spaces
        if (tokens[i] == ' ')
            continue;

        // 2. Push opening parenthesis
        if (tokens[i] == '(')
        {
            ops.push(tokens[i]);
        }
        // 3. Parse numbers and push to values stack
        else if (isdigit(tokens[i]))
        {
            int val = 0;
            // Handle multi-digit numbers (e.g., "42" instead of just "4")
            while (i < tokens.length() && isdigit(tokens[i]))
            {
                val = (val * 10) + (tokens[i] - '0'); // Converting char to int!
                i++;
            }
            values.push(val);
            i--; // The outer loop will increment i again, so we step back one
        }
        // 4. Closing parenthesis: solve everything inside the brackets
        else if (tokens[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty())
                ops.pop(); // Pop the opening '('
        }
        // 5. Current character is an operator
        else
        {
            // While top of 'ops' has same or greater precedence, apply it first
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i]))
            {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            // Push the current operator
            ops.push(tokens[i]);
        }
    }

    // 6. Apply any remaining operators
    while (!ops.empty())
    {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    // The top of 'values' contains the final answer
    return values.top();
}

// --- Example Usage ---
int main()
{
    string exp1 = "10 + 2 * 6";
    string exp2 = "100 * ( 2 + 12 )";
    string exp3 = "100 * ( 2 + 12 ) / 14";

    cout << exp1 << " = " << evaluateInfix(exp1) << "\n"; // Expected: 22
    cout << exp2 << " = " << evaluateInfix(exp2) << "\n"; // Expected: 1400
    cout << exp3 << " = " << evaluateInfix(exp3) << "\n"; // Expected: 100

    return 0;
}