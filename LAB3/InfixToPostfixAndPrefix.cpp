#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix;
    
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else if (isOperator(ch)) {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    
    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    
    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    
    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    
    return prefix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
    cout << "Prefix Expression: " << infixToPrefix(infix) << endl;
    
    return 0;
}
