//Tm
#include<bits/stdc++.h>
using namespace std;
#include "D:\Codeing\btlctdl&gt\BTL-pB\StackArray\stack.cpp"

int main()
{
    int T;
    cin >> T;

    Stack<long long> stack;

    while (T--) {
        int query;
        cin >> query;

        if (query == 1) {
            long long n;
            cin >> n;
            stack.push(n);
        } 
        else if (query == 2) {
            stack.pop();
        } 
        else if (query == 3) {
            if (stack.empty()) {
                cout << "Empty!" << endl;
            } else {
                cout << stack.top() << endl;
            }
        }
    }

    return 0;
}