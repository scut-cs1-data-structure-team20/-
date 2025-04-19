#include <iostream>
#include <vector>
using namespace std;

struct TireNode
{
    vector<TireNode *> children;
    bool isEnd;
    TireNode() : children(26, nullptr), isEnd(false) {};
};

void insert(TireNode *root, const string &word)
{
    TireNode *node = root;
    for (char ch : word)
    {
        int index = ch - 'a';
        if (!node->children[index])
        {
            node->children[index] = new TireNode();
        }
        node = node->children[index];
    }
    node->isEnd = true;
}

bool search(TireNode *root, const string &word)
{
    TireNode *node = root;
    for (char ch : word)
    {
        int index = ch - 'a';
        if (!node->children[index])
        {
            return false;
        }
        node = node->children[index];
    }
    return node->isEnd;
}

bool startsWith(TireNode *root, const string &prefix)
{
    TireNode *node = root;
    for (char ch : prefix)
    {
        int index = ch - 'a';
        if (!node->children[index])
        {
            return false;
        }
        node = node->children[index];
    }
    return true;
}

void freeTire(TireNode *root)
{
    if (!root)
        return;
    for (TireNode *child : root->children)
    {
        if (child)
            freeTire(child);
    }
    delete root;
}

int main()
{
    TireNode *root = new TireNode();
    insert(root, "apple");
    insert(root, "banana");
    insert(root, "cherry");

    cout << search(root, "apple") << endl;
    cout << search(root, "banana") << endl;
    cout << search(root, "cherry") << endl;
    cout << search(root, "grape") << endl;

    cout << startsWith(root, "app") << endl;
    cout << startsWith(root, "ban") << endl;
    cout << startsWith(root, "che") << endl;
    cout << startsWith(root, "gr") << endl;

    freeTire(root);
    return 0;
}