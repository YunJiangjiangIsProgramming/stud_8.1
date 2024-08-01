#define _CRT_SECURE_NO_WARNINGS 1

#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include <algorithm>

using namespace std;

class Solution0 {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        // 对输入的cards向量进行排序
        sort(cards.begin(), cards.end());

        // 初始化结果变量
        int ans = 0;
        int tmp = 0;
        int odd, even = -1;

        // 计算cards中需要被忽略的元素数量
        int end = cards.size() - cnt;

        // 选择cards中最大的cnt个元素，并累加它们的和
        for (int i = cards.size() - 1; i >= end; i--) {
            tmp += cards[i];
            // 记录最大的奇数和偶数值
            if (cards[i] & 1) {
                odd = cards[i];
            }
            else {
                even = cards[i];
            }
        }

        // 如果累加和是偶数，直接返回
        if (!(tmp & 1)) {
            return tmp;
        }

        // 尝试替换一个奇数或偶数，以使和变为偶数
        for (int i = cards.size() - cnt - 1; i >= 0; i--) {
            if (cards[i] & 1) {
                // 如果替换的是奇数，并且存在一个偶数可以被替换，更新结果
                if (even != -1) {
                    ans = max(ans, tmp - even + cards[i]);
                }
            }
            else {
                // 如果替换的是偶数，并且存在一个奇数可以被替换，更新结果
                if (odd != -1) {
                    ans = max(ans, tmp - odd + cards[i]);
                }
            }
        }
        // 返回最大的偶数和
        return ans;
    }
};



void test_set1()
{
    set<int> s1; // 创建一个空的set容器
    s1.insert(3);
    s1.insert(1);
    s1.insert(4);
    s1.insert(2);
    s1.insert(1);
    s1.insert(2); // 插入多个元素，重复元素将被自动忽略

    set<int>::iterator it1 = s1.begin(); // 获取set的迭代器
    while (it1 != s1.end())
    {
        
        cout << *it1 << " "; // 输出元素
        ++it1; // 移动迭代器
    }
    cout << endl;

    // 使用范围for循环遍历set
    for (auto e : s1)
    {
        cout << e << " ";
    }
    cout << endl;
}

// test_set2: 使用set查找元素
void test_set2()
{
    set<int> s1;  // 创建一个空的set容器
    // 插入元素
    s1.insert(3);
    s1.insert(1);
    s1.insert(4);
    s1.insert(2);
    s1.insert(1);
    s1.insert(2);

    //int x;
    //// 读取输入并查找元素
    //while (cin >> x)
    //{
    //    if (s1.count(x)) // 使用count方法，如果元素存在返回1，否则返回0
    //    {
    //        cout << "在" << endl;
    //    }
    //    else
    //    {
    //        cout << "不在" << endl;
    //    }
    //}
}

// test_set3: 使用multiset容器
void test_set3()
{
    multiset<int> s1; // 创建一个空的multiset容器
    // 插入元素
    s1.insert(3);
    s1.insert(1);
    s1.insert(4);
    s1.insert(2);
    s1.insert(1);
    s1.insert(1);
    s1.insert(1);
    s1.insert(2);

    multiset<int>::iterator it1 = s1.begin(); // 获取multiset的迭代器
    while (it1 != s1.end())
    {
     
        cout << *it1 << " "; // 输出元素
        ++it1; // 移动迭代器
    }
    cout << endl;

    // 查找值为1的元素
    auto ret = s1.find(1);
    while (ret != s1.end() && *ret == 1)
    {
        cout << *ret << " "; // 输出找到的元素
        ++ret; // 移动迭代器
    }
    cout << endl;

    // 使用count方法统计元素数量
    cout << s1.count(1) << endl;
    cout << s1.count(2) << endl;
}

// test_map1: 使用map容器
void test_map1()
{
    map<string, string> dict; // 创建一个空的map容器
    // 插入键值对
    dict.insert(pair<string, string>("sort", "排序"));
    dict.insert(make_pair("string", "字符串"));
    dict.insert(make_pair("count", "计数"));

    // 遍历map容器
    map<string, string>::iterator dit = dict.begin();
    while (dit != dict.end())
    {
        cout << (*dit).first << ":" << (*dit).second << endl; // 输出键值对
        ++dit; // 移动迭代器
    }
    cout << endl;
}

// test_map2: 使用map容器，展示插入和修改操作
void test_map2()
{
    map<string, string> dict; // 创建一个空的map容器
    // 插入键值对
    dict.insert(pair<string, string>("sort", "排序"));
    dict.insert(make_pair("string", "字符串"));
    dict.insert(make_pair("count", "计数"));
    dict.insert(make_pair("string", "(字符串)")); // 插入失败，因为键"string"已存在

    // 使用[]操作符插入和修改元素
    dict["left"];			// 插入
    dict["right"] = "右边"; // 插入+修改
    dict["string"] = "(字符串)"; // 修改
    // 使用[]操作符查找元素
    cout << dict["string"] << endl;
    cout << dict["string"] << endl;

    // 遍历map容器
    map<string, string>::iterator dit = dict.begin();
    while (dit != dict.end())
    {
        cout << (*dit).first << ":" << (*dit).second << endl; // 输出键值对
        ++dit; // 移动迭代器
    }
    cout << endl;
}

// test_map3: 使用map容器统计数组中元素的频率
void test_map3()
{
    string arr[] = { "西瓜", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉", "梨" };
    map<string, int> countMap; // 创建一个空的map容器，用于统计
    // 遍历数组并统计元素频率
    for (auto& e : arr)
    {
        auto ret = countMap.find(e); // 查找元素
        if (ret == countMap.end()) // 元素不存在
        {
            countMap.insert(make_pair(e, 1)); // 插入元素
        }
        else
        {
            ret->second++; // 增加计数
        }
    }

    // 使用[]操作符简化上述代码
    for (auto& e : arr)
    {
        countMap[e]++; // 自动插入并计数
    }

    // 遍历map容器并输出结果
    for (auto& kv : countMap)
    {
        cout << kv.first << ":" << kv.second << endl;
    }
}

// test_map4: 使用multimap容器
void test_map4()
{
    map<string, string> dict; // 创建一个空的map容器
    // 插入键值对
    dict.insert(pair<string, string>("sort", "排序"));
    dict.insert(make_pair("sort", "排序")); // 插入失败，因为键"sort"已存在
    dict.insert(make_pair("string", "字符串"));
    dict.insert(make_pair("count", "计数"));

    // 输出map容器中的键值对
    for (auto& kv : dict)
    {
        cout << kv.first << ":" << kv.second << endl;
    }
    cout << endl;

    multimap<string, string> mdict; // 创建一个空的multimap容器
    // 插入键值对
    mdict.insert(pair<string, string>("sort", "排序"));
    mdict.insert(make_pair("sort", "排序")); // 插入成功，因为multimap允许键重复
    mdict.insert(make_pair("string", "字符串"));
    mdict.insert(make_pair("count", "计数"));
    mdict.insert(make_pair("string", "(字符串)")); // 插入成功
    mdict.insert(make_pair("string", "字符串")); // 插入成功

    // 输出multimap容器中的键值对
    for (auto& kv : mdict)
    {
        cout << kv.first << ":" << kv.second << endl;
    }
}

class Solution1 {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        map<string, int> countmap;
        for (auto e : words)
        {
            countmap[e]++;
        }
        multimap<int, string> sortmap;
        for (auto kv : countmap)
        {
            sortmap.insert(make_pair(kv.second, kv.first));
        }
        vector<string> v;
        auto it = sortmap.begin();
        while (it != sortmap.end())
        {
            if (k != 0)
            {
                v.push_back(it->second);
                ++it;
                --k;
            }

        }
        return v;
    }
};

int main()
{
    test_set1();
    test_set2();
    test_map1();
	test_set3();
	test_map2();
    test_map3();
    test_map4();
	return 0;
}