#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluate(string S) {
    stack<int> values;  // To store integer values
    stack<char> ops;    // To store operators

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == ' ') continue;  // Skip spaces (although input doesn't have spaces)
        
        // If current character is a number, parse the full number
        if (isdigit(S[i])) {
            int val = 0;
            while (i < S.length() && isdigit(S[i])) {
                val = (val * 10) + (S[i] - '0');
                i++;
            }
            values.push(val);
            i--;  // Step back to avoid skipping a character
        }
        // If current character is an operator
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(S[i])) {
                int val2 = values.top();
                values.pop();
                
                int val1 = values.top();
                values.pop();
                
                char op = ops.top();
                ops.pop();
                
                values.push(applyOp(val1, val2, op));
            }
            // Push the current operator to ops stack
            ops.push(S[i]);
        }
    }

    // Apply remaining operations
    while (!ops.empty()) {
        int val2 = values.top();
        values.pop();
        
        int val1 = values.top();
        values.pop();
        
        char op = ops.top();
        ops.pop();
        
        values.push(applyOp(val1, val2, op));
    }

    // The final result is stored at the top of the values stack
    return values.top();
}

int main() {
    string s; cin >> s;
    cout << evaluate(s) << endl;
    return 0;
}
