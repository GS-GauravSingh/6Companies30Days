#include <bits/stdc++.h>
using namespace std;

class ThroneInheritance
{
    unordered_map<string, vector<string>> childrens;
    unordered_map<string, bool> isExpired;
    string king;

    void dfs(string curr, vector<string> &order)
    {
        if (!isExpired[curr])
        {
            order.push_back(curr);
        }

        // Childrens
        for (auto &child : childrens[curr])
        {
            dfs(child, order);
        }
    }

public:
    ThroneInheritance(string kingName)
    {
        this->king = kingName;
    }

    void birth(string parentName, string childName)
    {
        childrens[parentName].push_back(childName);
    }

    void death(string name)
    {
        isExpired[name] = true;
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> inheritanceOrder;
        dfs(king, inheritanceOrder);
        return inheritanceOrder;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */