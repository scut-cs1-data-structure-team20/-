#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 1e5;

struct TireNode
{
    TireNode *children[26];
    TireNode *fail;
    vector<int> output;

    TireNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        fail = nullptr;
    }
};

void insert(TireNode *root, const string &pattern, int index)
{
    TireNode *node = root;
    for (char c : pattern)
    {
        int idx = c - 'a';
        if (!node->children[idx])
        {
            node->children[idx] = new TireNode();
        }
        node = node->children[idx];
    }
    node->output.push_back(index);
}

void buildFailPointer(TireNode *root)
{
    queue<TireNode *> q;
    for (int i = 0; i < 26; ++i)
    {
        if (root->children[i])
        {
            root->children[i]->fail = root;
            q.push(root->children[i]);
        }
    }
    while (!q.empty())
    {
        TireNode *current = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i)
        {
            if (current->children[i])
            {
                TireNode *child = current->children[i];
                TireNode *failNode = current->fail;
                while (failNode && !failNode->children[i])
                {
                    failNode = failNode->fail;
                }
                child->fail = failNode ? failNode->children[i] : root;
                q.push(child);
            }
        }
    }
}

void search(TireNode *root, const string &text)
{
    TireNode *current = root;
    for (int i = 0; i < text.length(); ++i)
    {
        int idx = text[i] - 'a';
        while (current != root && !current->children[idx])
        {
            current = current->fail;
        }
        if (current->children[idx])
        {
            current = current->children[idx];
        }
        TireNode *temp = current;
        while (temp != root)
        {
            for (int index : temp->output)
            {
                cout << "Pattern found at index " << i << " for pattern index" << endl;
            }
            temp = temp->fail;
        }
    }
}

void freeTire(TireNode *node)
{
    if (!node)
        return;
    for (int i = 0; i < 26; ++i)
    {
        if (node->children[i])
        {
            freeTire(node->children[i]);
        }
    }
    delete node;
}

int main()
{
    TireNode *root = new TireNode();
    vector<string> patterns = {"he", "she", "his", "hers"};
    for (int i = 0; i < patterns.size(); ++i)
    {
        insert(root, patterns[i], i);
    }
    buildFailPointer(root);
    string text = "ushers";
    search(root, text);
    freeTire(root);
    return 0;
}