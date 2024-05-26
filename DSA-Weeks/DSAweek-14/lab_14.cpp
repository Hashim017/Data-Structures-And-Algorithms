#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int val)
    {
        val = val;
        next = nullptr;
    }
};
void hashTable(vector<int> &vec, int val)
{
    int index = val % 10;
    vec[index] = val;
}
void linearProbing(vector<int> &vec, int val)
{
    int index = val % 10;
    if (vec[index] != -1)
    {
        while (vec[index] != -1)
        {
            index++;
        }
    }
    vec[index] = val;
}
void quadraticProbing(vector<int> &vec, int val)
{
    int index = val % 10;
    if (vec[index] != -1)
    {
        while (vec[index] != -1)
        {
            index++;
            index = index * index;
        }
    }
    vec[index] = val;
}
class Chaining
{
private:
    int size;
    vector<list<int>> table;
public:
    Chaining()
    {
        size = 10;
        table = vector<list<int>> (size);
    }
    int getHash(int val)
    {
        return val % size;
    }
    void insertVal(int val)
    {
        int index = getHash(val);
        table[index].push_back(val);
    }
    void removeVal(int val)
    {
        int index = getHash(val);
        table[index].remove(val);
    }
};
int main()
{
    vector<int> vec(10, -1);
    // hashTable(vec, 10);
    // hashTable(vec, 29);
    // hashTable(vec, 38);
    // hashTable(vec, 17);
    // hashTable(vec, 16);
    // hashTable(vec, 11);
    // hashTable(vec, 22);
    // hashTable(vec, 23);
    // hashTable(vec, 34);
    // hashTable(vec, 15);

    // linearProbing(vec, 10);
    // linearProbing(vec, 29);
    // linearProbing(vec, 38);
    // linearProbing(vec, 17);
    // linearProbing(vec, 16);
    // linearProbing(vec, 20);
    // linearProbing(vec, 30);
    // linearProbing(vec, 23);
    // linearProbing(vec, 34);
    // linearProbing(vec, 15);

    quadraticProbing(vec, 10);
    quadraticProbing(vec, 30);
    quadraticProbing(vec, 40);

    for (int i = 0; i < 10; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}

// leet code problem 1
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> vec;
        unordered_map<string, int> mp;
        int len = s.size();
        string current = "";
        for (int i = 0; i <= len - 10; i++)
        {
           current = s.substr(i, 10);
           if (mp.find(current) == mp.end())
           {
               mp.insert({current, 0});
           }
           else if (!mp[current])
           {
               vec.push_back(current);
               mp[current]++;
           }
        }
        return vec;
    }
};

// leet code problem 2
class Solution {
public:
    bool isMatch(string first, string second)
    {
        int len = first.size();
        if (len == 0 && second.size() == 0)
        {
            return true;
        }
        if (len != second.size())
        {
            return false;
        }
        bool flag = false;
        for (int i = 0; i < len; i++)
        {
            flag = false;
            for (int j = 0; j < len; j++)
            {
                if(first[i] == second[j])
                {
                    second[j] = '*';
                    flag = true;
                    break;
                }
            }
            if (flag == false)
            {
                return false;
            }
        }
        return flag;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<string>> output;
        unordered_map<string, int> mp;
        if (len < 2)
        {
            output.push_back(strs);
            return output;
        }
        for (int i = 0; i < len; i++)
        {
            vector<string> vec;
            if (mp.find(strs[i]) == mp.end())
            {
                vec.push_back(strs[i]);
            for (int j = i + 1; j < len; j++)
            {
                int s = strs[j].size();
                if (isMatch(strs[i], strs[j]))
                {
                        vec.push_back(strs[j]);
                        mp.insert({strs[j], 0});
                }
            }
            }
            if (!vec.empty())
            {
                output.push_back(vec);
            }
        }
        return output;
    }
};