#include<iostream>
using namespace std;

#define lft(x) (x * 2)
#define rgt(x) (x * 2 + 1)

typedef unsigned long long ll;

const int MaxN(1e5 + 1);

struct sgmtree
{
    struct st_base
    {
        int l, r;
        ll data;
        ll tag;
    };

    st_base t[4 * MaxN]{};
    ll a[MaxN]{};
    int n;

    void push(int x)
    {
        t[x].data = 0;
        t[x].data += t[lft(x)].data;
        t[x].data += t[rgt(x)].data;
    }

    void mush(int x)
    {
        int tag = t[x].tag;

        if (tag)
        {
            t[lft(x)].data += tag * (t[lft(x)].r - t[lft(x)].l + 1);
            t[lft(x)].tag += tag;

            t[rgt(x)].data += tag * (t[rgt(x)].r - t[rgt(x)].l + 1);
            t[rgt(x)].tag += tag;

            t[x].tag = 0;
        }
    }

    void crt(int r, int lt, int rt)
    {
        int ml = (lt + rt) / 2;
        int mr = (lt + rt) / 2 + 1;

        t[r].l = lt;
        t[r].r = rt;

        if (lt == rt)
        {
            t[r].data = a[lt];
        }
        else
        {
            crt(lft(r), lt, ml);
            crt(rgt(r), mr, rt);

            push(r);
        }
    }

    void crt(ll *_a, int _n)
    {
        n = _n;

        for (int i(1); i <= n; i++)
        {
            a[i] = _a[i];
        }

        crt(1, 1, n);
    }

    int src(int r, int lt, int rt)
    {
        int ml = (t[r].l + t[r].r) / 2;
        int mr = (t[r].l + t[r].r) / 2 + 1;
        int ans = 0;

        if ((lt <= t[r].l) && (t[r].r <= rt))
        {
            return t[r].data;
        }
        else
        {
            mush(r);

            if (lt <= ml)
            {
                ans += src(lft(r), lt, rt);
            }
            if (mr <= rt)
            {
                ans += src(rgt(r), lt, rt);
            }

            return ans;
        }
    }

    void set(int r, int lt, int rt, int x)
    {
        int ml = (t[r].l + t[r].r) / 2;
        int mr = (t[r].l + t[r].r) / 2 + 1;

        if ((lt <= t[r].l) && (t[r].r <= rt))
        {
            t[r].data += x * (t[r].r - t[r].l + 1);
            t[r].tag += x;
        }
        else
        {
            mush(r);

            if(lt <= ml)
            {
                set(lft(r), lt, rt, x);
            }
            if(mr <= rt)
            {
                set(rgt(r), lt, rt, x);
            }

            push(r);
        }
    }
};

sgmtree a;
ll d[MaxN]{};

int main()
{
    ios::sync_with_stdio(0);

    int n, m;
    int op, x, y;
    ll k;

    cin >> n >> m;

    for (int i(1); i <= n; i++)
    {
        cin >> d[i];
    }

    a.crt(d, n);

    for (int i(1); i <= m; i++)
    {
        cin >> op >> x >> y;

        if (op == 1)
        {
            cin >> k;

            a.set(1, x, y, k);
        }
        else if (op == 2)
        {
            cout << a.src(1, x, y) << endl;
        }
    }

    return 0;
}
