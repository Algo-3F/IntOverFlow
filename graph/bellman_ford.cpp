#include<iostream>
#include<cstring>
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
int gph[MaxN]{};
int n, m, o;
int cnt = 0;

void addedge(int v1, int v2, int w)
{
    cnt++;
    e[cnt].v1 = v1;
    e[cnt].v2 = v2;
    e[cnt].w = w;
    e[cnt].nxt = top[v1];

    top[v1] = cnt;
}

bool bellman_ford()
{
    bool upd;

    memset(gph, INF, 4 * MaxN);

    gph[o] = 0;

    for (int t(1); t <= n; t++)
    {
        upd = 0;

        for (int i(1); i <= m; i++)
        {
            if (gph[e[i].v2] > gph[e[i].v1] + e[i].w)
            {
                gph[e[i].v2] = gph[e[i].v1] + e[i].w;

                upd = 1;
            }
        }

        if (!upd)
        {
            return 1;
        }

        if (t == n)
        {
            return 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);

    int x, y, z;
    bool ringless = 1;
    bool connective = 1;
    
    cin >> n >> m >> o;

    for (int i(1); i <= m; i++)
    {
        cin >> x >> y >> z;

        addedge(x, y, z);
        // addedge(y, x, z);
    }

    ringless = bellman_ford();

    for (int i(1); i <= n; i++)
    {
        if (gph[i] == INF)
        {
            connective = 0;
        }
    }

    if (ringless && connective)
    {
        for (int i(1); i <= n; i++)
        {
            cout << gph[i] << " ";
        }

        cout << endl;
    }
    else
    {
        cout << "I AK IOI" << endl;
    }

    return 0;
}
