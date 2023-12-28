#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int MaxN(1e6 + 1);
const int MaxM(2e1 + 6);

struct actrie
{
    struct at_base
    {
        int vis[MaxM]{};
        int fail = 0;
        int end = 0;
    };

    at_base ac[MaxN]{};
    int cnt = 0;

    void ist(string s)
    {
        int l = s.length();
        int now = 0;

        for (int i(0); i < l; i++)
        {
            if (ac[now].vis[s[i] - 'a'] == 0)
            {
                cnt++;
                ac[now].vis[s[i] - 'a'] = cnt;
            }

            now = ac[now].vis[s[i] - 'a'];
        }

        ac[now].end++;
    }

    void crtfail()
    {
        queue <int> q;
        int u;

        ac[0].fail = 0;

        for (int i(0); i < MaxM; i++)
        {
            if (ac[0].vis[i])
            {
                ac[ac[0].vis[i]].fail = 0;
                q.push(ac[0].vis[i]);
            }
        }

        for ( ; q.size() ; )
        {
            u = q.front();

            q.pop();

            for (int i(0); i < MaxM; i++)
            {
                if(ac[u].vis[i])
                {
                    ac[ac[u].vis[i]].fail = ac[ac[u].fail].vis[i];
                    q.push(ac[u].vis[i]);
                }
                else
                {
                    ac[u].vis[i] = ac[ac[u].fail].vis[i];
                }
            }
        }
    }

    int src(string s)
    {
        int l = s.length();
        int now = 0;
        int ans = 0;

        for(int i(0); i < l; i++)
        {
            now = ac[now].vis[s[i] - 'a'];

            for(int t = now; (t) && (ac[t].end != -1); t = ac[t].fail)
            {
                ans += ac[t].end;
                ac[t].end = -1;
            }
        }

        return ans;
    }
};

actrie a;

int main()
{
    int n;
    string s;

    cin >> n;

    for(int i(1); i <= n; i++)
    {
        cin >> s;

        a.ist(s);
    }

    a.crtfail();

    cin >> s;
    cout << a.src(s)<<endl;

    return 0;
}
