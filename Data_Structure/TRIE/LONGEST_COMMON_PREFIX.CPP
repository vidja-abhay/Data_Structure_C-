#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public :

    char data;
    TrieNode* children[26];
    bool isterminal;
    int childcout;

    TrieNode(char ch)
    {
        data = ch;

        for(int i=0;i<26;i++)
        {
            children[i] = NULL;
        }

        isterminal = false;

        childcout = 0;
    }
};

class trie
{
    public :
    TrieNode* root;

    trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void InsertUtil(TrieNode* root,string word)
    {
        // base case
        if(word.length() == 0)
        {
            root->isterminal = true;
            return;
        }

        // assumption will be in caps;
        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }

        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->childcout++;
            root->children[index] = child;
        }

        //recursion

        InsertUtil(child,word.substr(1));
    }

    void InsertWord(string word)
    {
        InsertUtil(root,word);
    }

    void lcp(string str,string &ans)
    {
        for(int i=0;i<str.length();i++)
        {
            char ch = str[i];

            if(root->childcout == 1)
            {
                ans.push_back(ch);

                // age badho

                int index = ch - 'A';

                root = root->children[index];
            }

            else
            {
                break;
            }

            if(root->isterminal)
            {
                break;
            }
        }
    }
};

string longestcommonprefix(vector<string> &str,int n)
{
    trie* t = new trie('\0');

    // insert all string
    for(int i=0;i<n;i++)
    {
        t->InsertWord(str[i]);
    }

    string first = str[0];
    string ans = "";

    t->lcp(first,ans);
    return ans;
}

int main()
{
    vector<string> s;

    int n; cin>>n;

    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;

        s.push_back(str);
    }

    string ans = longestcommonprefix(s,n);

    cout<<ans;
}