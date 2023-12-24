#include<iostream>
#include<algorithm>
using namespace std;

const int INF(0x3F3F3F3F);

const int MaxN(1e3 + 1);
const int MaxM(5e3 + 1);

struct edge
{
	int v1 = 0;
    int v2 = 0;
    int w = 0;

    bool operator<(edge x)
    const
    {
        return w < x.w;
    }
};

edge e[MaxM]{};
int root[MaxN]{};
int n, m;
int _cnt = 0;
int cnt, ans;
int v1, v2;

void addedge(int x, int y, int z)
{
    _cnt++;
    e[_cnt].v1 = x;
    e[_cnt].v2 = y;
    e[_cnt].w = z;
}

int src(int x)
{
    for ( ; root[x] ; )
    {
        x = root[x];
    }

    return x;
}

void kruskal()
{
    sort(e + 1, e + m + 1);

    for (int i(1); i <= m; i++)
    {
        v1 = src(e[i].v1);
        v2 = src(e[i].v2);

        if(v1 == v2)
        {
            continue;
        }

        root[v2] = v1;
        ans += e[i].w;
        cnt++;

        if(cnt == n - 1)
        {
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);

    int x, y, z;

    cin >> n >> m;

    for (int i(1); i <= m; i++)
    {
        cin >> x >> y >> z;

        addedge(x, y, z);
    }

    kruskal();

    if (cnt == n - 1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "I AK IOI" << endl;
    }

    return 0;
}
