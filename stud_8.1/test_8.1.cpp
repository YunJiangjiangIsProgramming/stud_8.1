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
        // �������cards������������
        sort(cards.begin(), cards.end());

        // ��ʼ���������
        int ans = 0;
        int tmp = 0;
        int odd, even = -1;

        // ����cards����Ҫ�����Ե�Ԫ������
        int end = cards.size() - cnt;

        // ѡ��cards������cnt��Ԫ�أ����ۼ����ǵĺ�
        for (int i = cards.size() - 1; i >= end; i--) {
            tmp += cards[i];
            // ��¼����������ż��ֵ
            if (cards[i] & 1) {
                odd = cards[i];
            }
            else {
                even = cards[i];
            }
        }

        // ����ۼӺ���ż����ֱ�ӷ���
        if (!(tmp & 1)) {
            return tmp;
        }

        // �����滻һ��������ż������ʹ�ͱ�Ϊż��
        for (int i = cards.size() - cnt - 1; i >= 0; i--) {
            if (cards[i] & 1) {
                // ����滻�������������Ҵ���һ��ż�����Ա��滻�����½��
                if (even != -1) {
                    ans = max(ans, tmp - even + cards[i]);
                }
            }
            else {
                // ����滻����ż�������Ҵ���һ���������Ա��滻�����½��
                if (odd != -1) {
                    ans = max(ans, tmp - odd + cards[i]);
                }
            }
        }
        // ��������ż����
        return ans;
    }
};



void test_set1()
{
    set<int> s1; // ����һ���յ�set����
    s1.insert(3);
    s1.insert(1);
    s1.insert(4);
    s1.insert(2);
    s1.insert(1);
    s1.insert(2); // ������Ԫ�أ��ظ�Ԫ�ؽ����Զ�����

    set<int>::iterator it1 = s1.begin(); // ��ȡset�ĵ�����
    while (it1 != s1.end())
    {
        
        cout << *it1 << " "; // ���Ԫ��
        ++it1; // �ƶ�������
    }
    cout << endl;

    // ʹ�÷�Χforѭ������set
    for (auto e : s1)
    {
        cout << e << " ";
    }
    cout << endl;
}

// test_set2: ʹ��set����Ԫ��
void test_set2()
{
    set<int> s1;  // ����һ���յ�set����
    // ����Ԫ��
    s1.insert(3);
    s1.insert(1);
    s1.insert(4);
    s1.insert(2);
    s1.insert(1);
    s1.insert(2);

    //int x;
    //// ��ȡ���벢����Ԫ��
    //while (cin >> x)
    //{
    //    if (s1.count(x)) // ʹ��count���������Ԫ�ش��ڷ���1�����򷵻�0
    //    {
    //        cout << "��" << endl;
    //    }
    //    else
    //    {
    //        cout << "����" << endl;
    //    }
    //}
}

// test_set3: ʹ��multiset����
void test_set3()
{
    multiset<int> s1; // ����һ���յ�multiset����
    // ����Ԫ��
    s1.insert(3);
    s1.insert(1);
    s1.insert(4);
    s1.insert(2);
    s1.insert(1);
    s1.insert(1);
    s1.insert(1);
    s1.insert(2);

    multiset<int>::iterator it1 = s1.begin(); // ��ȡmultiset�ĵ�����
    while (it1 != s1.end())
    {
     
        cout << *it1 << " "; // ���Ԫ��
        ++it1; // �ƶ�������
    }
    cout << endl;

    // ����ֵΪ1��Ԫ��
    auto ret = s1.find(1);
    while (ret != s1.end() && *ret == 1)
    {
        cout << *ret << " "; // ����ҵ���Ԫ��
        ++ret; // �ƶ�������
    }
    cout << endl;

    // ʹ��count����ͳ��Ԫ������
    cout << s1.count(1) << endl;
    cout << s1.count(2) << endl;
}

// test_map1: ʹ��map����
void test_map1()
{
    map<string, string> dict; // ����һ���յ�map����
    // �����ֵ��
    dict.insert(pair<string, string>("sort", "����"));
    dict.insert(make_pair("string", "�ַ���"));
    dict.insert(make_pair("count", "����"));

    // ����map����
    map<string, string>::iterator dit = dict.begin();
    while (dit != dict.end())
    {
        cout << (*dit).first << ":" << (*dit).second << endl; // �����ֵ��
        ++dit; // �ƶ�������
    }
    cout << endl;
}

// test_map2: ʹ��map������չʾ������޸Ĳ���
void test_map2()
{
    map<string, string> dict; // ����һ���յ�map����
    // �����ֵ��
    dict.insert(pair<string, string>("sort", "����"));
    dict.insert(make_pair("string", "�ַ���"));
    dict.insert(make_pair("count", "����"));
    dict.insert(make_pair("string", "(�ַ���)")); // ����ʧ�ܣ���Ϊ��"string"�Ѵ���

    // ʹ��[]������������޸�Ԫ��
    dict["left"];			// ����
    dict["right"] = "�ұ�"; // ����+�޸�
    dict["string"] = "(�ַ���)"; // �޸�
    // ʹ��[]����������Ԫ��
    cout << dict["string"] << endl;
    cout << dict["string"] << endl;

    // ����map����
    map<string, string>::iterator dit = dict.begin();
    while (dit != dict.end())
    {
        cout << (*dit).first << ":" << (*dit).second << endl; // �����ֵ��
        ++dit; // �ƶ�������
    }
    cout << endl;
}

// test_map3: ʹ��map����ͳ��������Ԫ�ص�Ƶ��
void test_map3()
{
    string arr[] = { "����", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶", "��" };
    map<string, int> countMap; // ����һ���յ�map����������ͳ��
    // �������鲢ͳ��Ԫ��Ƶ��
    for (auto& e : arr)
    {
        auto ret = countMap.find(e); // ����Ԫ��
        if (ret == countMap.end()) // Ԫ�ز�����
        {
            countMap.insert(make_pair(e, 1)); // ����Ԫ��
        }
        else
        {
            ret->second++; // ���Ӽ���
        }
    }

    // ʹ��[]����������������
    for (auto& e : arr)
    {
        countMap[e]++; // �Զ����벢����
    }

    // ����map������������
    for (auto& kv : countMap)
    {
        cout << kv.first << ":" << kv.second << endl;
    }
}

// test_map4: ʹ��multimap����
void test_map4()
{
    map<string, string> dict; // ����һ���յ�map����
    // �����ֵ��
    dict.insert(pair<string, string>("sort", "����"));
    dict.insert(make_pair("sort", "����")); // ����ʧ�ܣ���Ϊ��"sort"�Ѵ���
    dict.insert(make_pair("string", "�ַ���"));
    dict.insert(make_pair("count", "����"));

    // ���map�����еļ�ֵ��
    for (auto& kv : dict)
    {
        cout << kv.first << ":" << kv.second << endl;
    }
    cout << endl;

    multimap<string, string> mdict; // ����һ���յ�multimap����
    // �����ֵ��
    mdict.insert(pair<string, string>("sort", "����"));
    mdict.insert(make_pair("sort", "����")); // ����ɹ�����Ϊmultimap������ظ�
    mdict.insert(make_pair("string", "�ַ���"));
    mdict.insert(make_pair("count", "����"));
    mdict.insert(make_pair("string", "(�ַ���)")); // ����ɹ�
    mdict.insert(make_pair("string", "�ַ���")); // ����ɹ�

    // ���multimap�����еļ�ֵ��
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