/* 
Welcome to JDoodle!

You can execute code here in 88 languages. Right now you’re in the C++ IDE.

  1. Click the orange Execute button ▶ to execute the sample code below and see how it works.

  2. Want help writing or debugging code? Type a query into JDroid on the right hand side ---------------->

  3. Try the menu buttons on the left. Save your file, share code with friends and open saved projects.

Want to change languages? Try the search bar up the top. 
*/

#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **child;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        childCount = 0;
        child = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        isTerminal = false;
    }
};

 void insert(TrieNode* root, string &word)
    {
    TrieNode* cur = root;

    for(int idx = 0; idx < word.size(); ++idx)
    {   
        int diff = word[idx] - 'a';
        
        // If the child[diff] of cur is an empty node
        if (cur->child[diff] == NULL)
        {
            cur->child[diff] = new TrieNode(word[idx]);
            cur->childCount += 1;
        }

        cur = cur->child[diff];
    }

    // Marking the endOfWord of last character as true.
    cur->isTerminal = true;    
    }

string longestCommonPrefix(vector<string> &arr, int n)
    {
        // Write your code here
        
        if(n == 0) return "-1";
        
        TrieNode *root = new TrieNode('$');
        for(int i = 0; i < arr.size(); i++){
            string word = arr[i];
            insert(root, word);
        }

        string result = "";
        TrieNode *cur = root;

        while(cur != NULL && cur->childCount == 1){
            bool foundChild = false;

            for(int i = 0; i < 26; i++){
                if(cur->child[i] != NULL){
                    result += cur->child[i]->data;
                    cout<<"81 : "<<result<<endl;
                    cur = cur->child[i];
                    foundChild = true;
                    break;
                }
            }
            if(!foundChild){
                return "-1";
            }
        }

        return result;
}
int main() {
    int n;
    cin>>n;

    // string words[n];
    vector<string> words(n);
    int i = 0;
    while(n--){
        TrieNode *root = new TrieNode('$');
        cin>>words[i];
        insert(root, words[i]);
        i++;
    }
    
    string result = longestCommonPrefix(words, n);
    cout<<result<<endl;
    
}