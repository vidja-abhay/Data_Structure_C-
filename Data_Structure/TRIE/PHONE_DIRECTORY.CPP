#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public :

    char data;
    TrieNode* children[26];
    bool isterminal;

    TrieNode(char ch)
    {
        data = ch;

        for(int i=0;i<26;i++)
        {
            children[i] = NULL;
        }

        isterminal = false;
    }
};

class Trie
{
     public :

    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
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
            root->children[index] = child;
        }

        //recursion

        InsertUtil(child,word.substr(1));
    }

    void InsertWord(string word)
    {
        InsertUtil(root,word);
    }

    void PrintSuggestion(TrieNode* curr,vector<string> &temp,string prefix)
    {
        if(curr->isterminal)
        {
            temp.push_back(prefix);
        }

        for(char ch = 'A'; ch <= 'Z'; ch++)
        {
            TrieNode* next = curr->children[ch - 'A'];

            if(next != NULL)
            {
                prefix.push_back(ch);
                PrintSuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> GetSuggestion(string str)
    {
        TrieNode* pre = root;
        vector<vector<string>> out;
        string prefix = "";

        for(int i=0;i<str.length();i++)
        {
            char lastch = str[i];

            prefix.push_back(lastch);

            // check for lastch

            TrieNode* curr = pre->children[lastch - 'A'];

            // if not found
            if(curr == NULL)
            {
                break;
            }

            // if found

            vector<string> temp;

            PrintSuggestion(curr,temp,prefix);

            out.push_back(temp);
            temp.clear();
            pre = curr;
        }

        return out;
    }
};

vector<vector<string>> phonedirectory(vector<string> &contactlist,string &querystr)
{
    Trie *t = new Trie();

    for(int i=0;i<contactlist.size();i++)
    {
        string str = contactlist[i];

        t->InsertWord(str);
    }

    // return ans

    return t->GetSuggestion(querystr);
}

int main()
{
    vector<string> contact;
    int n; cin>>n;

    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;

        contact.push_back(str);
    }

    string query;
    cin>>query;

    vector<vector<string>> out = phonedirectory(contact,query);

    for(int i=0;i<out.size();i++)
    {
        for(int j=0;j<out[i].size();j++)
        {
            cout<<out[i][j]<<" ";
        }
        
    }
}