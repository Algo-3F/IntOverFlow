#include<iostream>
using namespace std;

const int MaxN(1e4 + 1);

struct dsu
{
    int r[MaxN]{};

    int src(int a)
    {
        int x = a;

        for ( ; r[x] ; )
        {
            x = r[x];
        }

        for ( ; r[a] ; )
        {
            r[a] = x;
            a = r[a];
        }

        return x;
    }

    bool src(int a, int b)
    {
        if (a == b)
        {
            return 1;
        }
        else
        {
            return src(a) == src(b);
        }
    }

    bool root(int rt, int lf)
    {
        int _rt = src(rt);
        int _lf = src(lf);

        if (_rt != _lf)
        {
            r[_rt] = _lf;

            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    dsu a;
    int n, m;
    int op, x, y;

    cin >> n >> m;

    for (int i(1); i <= m; i++)
    {
        cin >> op >> x >> y;

        if (op == 1)
        {
            a.root(x, y);
        }
        else if (op == 2)
        {
            if (a.src(x, y))
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "N" << endl;
            }
        }
    }

    return 0;
}
