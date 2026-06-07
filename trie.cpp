#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
public:

    char data;
    TrieNode* Children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;

        for(int i=0;i<26;i++)
        {
            Children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie
{
public:

    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    // INSERT

    void insertutil(TrieNode* root , string word)
    {
        if(word.length()==0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'A';

        TrieNode* child;

        if(root->Children[index] != NULL)
        {
            child = root->Children[index];
        }
        else
        {
            child = new TrieNode(word[0]);

            root->Children[index] = child;
        }

        insertutil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertutil(root, word);
    }

    // SEARCH

    bool search_util(TrieNode* root , string word)
    {
        if(word.length()==0)
        {
            return root->isTerminal;
        }

        int index = word[0]-'A';

        TrieNode *child;

        if(root->Children[index] != NULL)
        {
            child = root->Children[index];
        }
        else
        {
            return false;
        }

        return search_util(child, word.substr(1));
    }

    bool search(string word)
    {
        return search_util(root, word);
    }

    // CHECK CHILDREN

    bool hasChildren(TrieNode* root)
    {
        for(int i=0;i<26;i++)
        {
            if(root->Children[i] != NULL)
            {
                return true;
            }
        }

        return false;
    }

    // ADVANCED REMOVE

    bool removeutil(TrieNode* root, string word)
    {
        // Base Case

        if(word.length()==0)
        {
            root->isTerminal = false;

            return !hasChildren(root);
        }

        int index = word[0]-'A';

        TrieNode* child = root->Children[index];

        if(child == NULL)
        {
            return false;
        }

        bool shouldDeleteChild =
            removeutil(child, word.substr(1));

        // Delete child node

        if(shouldDeleteChild)
        {
            delete child;

            root->Children[index] = NULL;
        }

        // Current node delete?

        if(root->isTerminal == false &&
           !hasChildren(root))
        {
            return true;
        }

        return false;
    }

    void remove(string word)
    {
        removeutil(root, word);
    }
};

int main()
{
    Trie * t = new Trie();

    t->insert("ABCD");

    bool ans = t->search("ABCD");

    cout << "Before Remove = " << ans << endl;

    t->remove("ABCD");

    bool an = t->search("ABCD");

    cout << "After Remove = " << an << endl;

    return 0;
}