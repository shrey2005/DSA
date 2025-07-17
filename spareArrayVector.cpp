#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    vector<int> matchingCount;
    for(int i = 0; i < queries.size();i++){
        int count = 0;
        string currentQueries = queries[i];
        for(int j = 0; j < stringList.size(); j++){
            string currentString = stringList[j];
            if(currentQueries == currentString){
                count++;
            }
        }
        matchingCount.push_back(count);
    }
    return matchingCount;
}
int main() {
    int n, q;

    cout << "Enter number of strings in stringList: ";
    cin >> n;
    vector<string> stringList(n);
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; ++i) {
        getline(cin, stringList[i]);
    }

    cout << "Enter number of queries: ";
    cin >> q;
    cin.ignore();
    vector<string> queries(q);
    cout << "Enter " << q << " query strings:\n";
    for (int i = 0; i < q; ++i) {
        getline(cin, queries[i]);
    }

    vector<int> result = matchingStrings(stringList, queries);

    cout << "Query results:\n";
    for (int count : result) {
        cout << count << endl;
    }

    return 0;
}