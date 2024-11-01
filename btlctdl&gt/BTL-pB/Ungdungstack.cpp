//Tm
#include<bits/stdc++.h>
using namespace std;
#include "D:\Codeing\btlctdl&gt\BTL-pB\StackArray\stack.cpp"

int main() {
    string s;
    cin >> s; 
    Stack<int> stack;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stack.push(i + 1);
        } else if (s[i] == ')') {
            if (!stack.empty()) {
                int openIndex = stack.top();
                stack.pop();
                cout << openIndex << " " << i + 1 << endl;
            }
        }
    }

    return 0;
}