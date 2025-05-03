PRACTICAL 4
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToPostfix(string prefix) {
    stack<string> st;
    
    reverse(prefix.begin(), prefix.end());
    
    for (char ch : prefix) {
        if (isalnum(ch)) {
            string op(1, ch);
            st.push(op);
        } else if (isOperator(ch)) {
            if (st.size() < 2) return "Invalid Expression";
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string postfix = op1 + op2 + ch; 
            st.push(postfix);
        }
    }
    
    return st.top();
} 

int main() {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;
    
    cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;
    return 0;
}
