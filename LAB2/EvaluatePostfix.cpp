#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evaluatePostfix(string expression) {
    stack<int> st;
    
    for (char ch : expression) {
        if (isdigit(ch)) {
            st.push(ch - '0'); // Convert char to int
        } else {
            if (st.size() < 2) return -1; // Invalid expression
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            
            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': 
                    if (val2 == 0) return -1; // Handle division by zero
                    st.push(val1 / val2); 
                    break;
                default: return -1; // Invalid operator
            }
        }
    }
    
    return st.top();
}

int main() {
    string expression;
    cout << "Enter a postfix expression: ";
    cin >> expression;
    
    int result = evaluatePostfix(expression);
    if (result == -1) {
        cout << "Invalid Expression" << endl;
    } else {
        cout << "Result: " << result << endl;
    }
    
    return 0;
}
