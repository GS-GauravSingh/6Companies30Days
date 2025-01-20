#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    bool isTerminalNode;
    vector<TrieNode *> childrens;

    // Constructor
    TrieNode(char data)
    {
        this->data = data;
        isTerminalNode = false;
        childrens.resize(26, NULL);
    }
};

class Trie
{
private:
    TrieNode *root;

    // Recursive Method to search a word.
    bool isWordPresent(TrieNode *root, int idx, string word)
    {
        // Base Case
        if (idx >= word.length())
        {
            return root->isTerminalNode;
        }

        // Recursve Case
        char ch = word[idx];
        if (ch == '.')
        {
            // Dot can match with any other character.
            for (int i = 0; i < 26; i++)
            {
                if (root->childrens[i] == NULL)
                {
                    continue;
                }

                if (isWordPresent(root->childrens[i], idx + 1, word))
                    return true;
            }

            // After matching dot with all the non-null chidrens of curr node. If no function call returns true, it means word is not present.
            return false;
        }
        else
        {

            if (root->childrens[ch - 'a'] == NULL)
            {
                return false;
            }

            return isWordPresent(root->childrens[ch - 'a'], idx + 1, word);
        }
    }

public:
    // Constructor
    Trie()
    {
        root = new TrieNode('#'); // Creating Root node of the Trie.
    }

    // Method to insert a word into the Trie.
    void insert(string word)
    {
        TrieNode *curr = root;
        for (char &ch : word)
        {
            int index = ch - 'a';
            if (curr->childrens[index] == NULL)
            {
                TrieNode *newNode = new TrieNode(ch);
                curr->childrens[index] = newNode;
            }

            curr = curr->childrens[index];
        }

        curr->isTerminalNode = true;
    }

    // Method to search a given string in a Trie.
    bool search(string word)
    {
        TrieNode *curr = root;
        return isWordPresent(curr, 0, word);
    }
};

class WordDictionary
{

    Trie trie;

public:
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        trie.insert(word);
    }

    bool search(string word)
    {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */