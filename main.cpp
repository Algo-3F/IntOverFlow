#include<iostream>
#include<queue>
using namespace std;

const int INF(0x3F3F3F3F);

const int MaxN(1e3 + 1);
const int MaxM(5e3 + 1);

struct edge
{
    int v1 = 0, v2 = 0;
    int w = 0;
    int nxt = 0;
};

edge e[MaxM]{};
int top[MaxN]{};
int abs_o[MaxN]{};
int abs_i[MaxN]{};
int cnt = 1;
int n, m;
queue <int> a;

void addedge(int v1, int v2, int w)
{
    cnt++;
    e[cnt].v1 = v1;
    e[cnt].v2 = v2;
    e[cnt].w = w;
    e[cnt].nxt = top[v1];

    top[v1] = cnt;
}

queue <int> topo()
{
    queue <int> q;
    int x;

    for (int i(1); i <= n; i++)
    {
        if (!abs_i[i])
        {
            a.push(i);
        }
    }

    for ( ; a.size() ; )
    {
        x = a.front();
        a.pop();

        q.push(x);

        for (int i(top[x]); i; i = e[i].nxt)
        {
            abs_o[e[i].v1]--;
            abs_i[e[i].v2]--;

            if (!abs_i[e[i].v2])
            {
                a.push(e[i].v2);
            }
        }
    }

    return q;
}

int main()
{
    ios::sync_with_stdio(0);

    queue <int> q;
    int x;

    cin >> n;

    for (int i(1); i <= n; i++)
    {
        for (cin >> x; x; cin >> x)
        {
            addedge(i, x, 1);

            abs_o[i]++;
            abs_i[x]++;

            m++;
        }
    }

    q = topo();

    for ( ; q.size() ; )
    {
        x = q.front();
        q.pop();

        cout << x << " ";
    }

    return 0;
}
