#include<iostream>
#include<cstring>
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

struct vertex
{
    int v = 0;
    int w = 0;

    bool operator>(vertex x)
    const
    {
        return w > x.w;
    }
};

priority_queue < vertex, vector <vertex>, greater <vertex> > q;
edge e[MaxM]{};
int top[MaxN]{};
int gph[MaxN]{};
int vis[MaxN]{};
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

void dijkstra()
{
    int v1, v2;
    vertex x;

    memset(gph, INF, 4 * MaxN);

    gph[o] = 0;
    q.push(vertex{o, 0});

    for ( ; q.size() ; )
    {
        x = q.top();
        q.pop();
        v1 = x.v;

        if (vis[v1])
        {
            continue;
        }

        vis[v1] = 1;

        for (int i(top[v1]); i; i = e[i].nxt)
        {
            v2 = e[i].v2;

            if (gph[v2] > gph[v1] + e[i].w)
            {
            	gph[v2] = gph[v1] + e[i].w;

            	q.push(vertex{v2, gph[v2]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);

    int x, y, z;
    bool connective = 1;

    cin >> n >> m >> o;

    for (int i(1); i <= m; i++)
    {
        cin >> x >> y >> z;

        addedge(x, y, z);
        // addedge(y, x, z);
    }

    dijkstra();

    for (int i(1); i <= n; i++)
    {
        if (gph[i] == INF)
        {
            connective = 0;

            break;
        }
    }

    if (connective)
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
