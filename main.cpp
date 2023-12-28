#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector <int> ans;
vector <int> nxt;

void nxttab(string p)
{
    int i = 0, j = -1;

    nxt.resize(p.length() + 1);
    nxt[0] = -1;

    for ( ; i < p.length() ; )
    {
        if ((j < 0) || (p[i] == p[j]))
        {
            i++;
            j++;

            nxt[i] = j;
        }
        else
        {
            j = nxt[j];
        }
    }
}

void kmp(string s, string p)
{
    int lens = s.length();
    int lenp = p.length();
    int i = 0, j = 0;

    nxttab(p);

    while ((i < lens) && (j < lenp))
    {
        if ((j < 0) || (s[i] == p[j]))
        {
            i++;
            j++;

            if (j == lenp)
            {
                ans.push_back(i - j + 1);
                j = nxt[j];
            }
        }
        else
        {
            j = nxt[j];
        }
    }
}

int main()
{
    string s, p;

    cin >> s >> p;

    kmp(s, p);

    for (int i = 0; i < ans.size(); i++)    // 输出匹配位置
    {
        cout << ans[i] << endl;
    }

    for (int i = 1; i < nxt.size(); i++)   // 输出 border 数组
    {
        cout << nxt[i] << " ";
    }

    cout << endl;

    return 0;
}
