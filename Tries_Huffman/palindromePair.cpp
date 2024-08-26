#include <iostream>
#include <vector>
#include <climits>
#include<set>
#include<map>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;

class Node{
    public:
    char data;
    int id = -1;
    vector<int> isPalindrome;
    Node* child[26];

    Node(char data){
        this->data = data;
        for(int i = 0; i < 26; i++){
            this->child[i] = NULL;
        }
    }
};

bool checkPalindrome(string word, int si, int ei){
    int i = si;
    int j = ei;
    while(i < j){
        if(word[i] != word[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void insert(Node* root, string word, int word_index){
    Node *p = root;
    for(int i = word.size() - 1; i >= 0; i--){
        //step 1, check palindrome(0, i)
        if(checkPalindrome(word, 0, i)){
            p->isPalindrome.push_back(word_index);
        }

        //step 2. standard tries stuff
        int index = word[i] - 'a';
        if(p->child[index] == NULL){
            Node *newNode = new Node(word[i]);
            p->child[index] = newNode;
        }
        p = p -> child[index];
    }

    p->id = word_index;
    p->isPalindrome.push_back(word_index);
}

void find(Node *root, string word, int word_index, vector<vector<int>> &palindromicPair){
    Node* p = root;

    vector<int> pair;
    for(int i = 0; i < word.size(); i++){
        if(p->id >= 0 && checkPalindrome(word, i, word.size() - 1)){
            palindromicPair.push_back({word_index, p->id});
        }   

        int index = word[i] - 'a';
        p = p->child[index];

        if( p == NULL){
            break;
        }
    }

    if( p == NULL) return;

    for(int idx : p->isPalindrome){
        if(word_index != idx){
            palindromicPair.push_back({word_index, p->id});
        }
    }
}
vector<vector<int>> countPalindromicPairs(vector<string> &words)
{
    // Write your code here.
    vector<vector<int>> result;
    Node* root = new Node('$');

    for(int i = 0; i < words.size(); i++){
        string word = words[i];
        insert(root, word, i);
    }

    for(int i = 0; i < words.size(); i++){
        string word = words[i];
        find(root, word, i, result);
    }
    return result;
}

class Runner
{
    int t;
    vector<int> tn;
    vector<vector<string>> twords;  


public:
    void takeInput()
    {
        cin >> t;       
        for (int c = 0; c < t; c++)
        {
           int n;
           cin>>n;
            vector<string> tmp(n);
            for(int i=0;i<n;i++){
                cin>>tmp[i];
            }        

            
            tn.push_back(n);
            twords.push_back(tmp);
            
        }
    }

    void execute()
    {
        

        for (int i = 0; i < t; i++)
        {   
            vector<vector<string>> copytwords = twords;
            vector<vector<int>> ans = countPalindromicPairs(copytwords[i]);           

        }

        
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {   
            vector<vector<int>> ans = countPalindromicPairs(twords[i] );           
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}