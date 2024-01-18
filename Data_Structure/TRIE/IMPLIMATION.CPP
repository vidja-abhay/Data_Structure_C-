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

    bool SearchUtil(TrieNode* root,string word)
    {
        // base case

        if(word.length() == 0)
        {
            return root->isterminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }

        else
        {
            return false;
        }

        return SearchUtil(child,word.substr(1));
    }

    bool Search(string word)
    {
        return SearchUtil(root,word);
    }

    void DeleteUtil(TrieNode* root,string word)
    {
        // base case

        if(word.length() == 0)
        {
            root->isterminal = false;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }

        // // absent   creation to he j nai
        // else
        // {
        //     child = new TrieNode(word[0]);
        //     root->children[index] = child;
        // }

        // recursion

        DeleteUtil(child,word.substr(1));
    }

    void DLT(string word)
    {
        DeleteUtil(root,word);
    }
};

int main()
{
    Trie *t = new Trie();

    t->InsertWord("ABHAY");
    t->InsertWord("YASH");
    t->InsertWord("DHRUV");
    t->InsertWord("JEET");

    cout<<t->Search("RAJ")<<endl;
    cout<<t->Search("YASH")<<endl;

    t->DLT("YASH");
    cout<<t->Search("YASH")<<endl;
}