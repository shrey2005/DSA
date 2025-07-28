#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main() {
    string s = "/home/user/Documents/../Pictures";
    stringstream ss(s);
    string token;
    stack<string> pathStack;

    // Use getline with '/' delimiter in a while loop
    while (getline(ss, token, '/')) {
        if (token == "" || token == ".") {
            continue; // skip empty or current dir
        } else if (token == "..") {
            if (!pathStack.empty()) {
                pathStack.pop(); // go back
            }
        } else {
            pathStack.push(token); // add dir to path
        }
    }

    // Build the resolved path
    string result = "/";
    stack<string> reverseStack;
    while (!pathStack.empty()) {
        reverseStack.push(pathStack.top());
        pathStack.pop();
    }

    while (!reverseStack.empty()) {
        result += reverseStack.top();
        reverseStack.pop();
        if (!reverseStack.empty()) result += "/";
    }

    cout << "Resolved Path: " << result << endl;
    return 0;
}
