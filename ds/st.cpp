#include<iostream>
using namespace std;

const int MaxN(1e6 + 1);
const int MaxM(3e1 + 1);

#define pow2(x) (1 << (x))

struct st
{
    int log[MaxN]{};
    int f[MaxN][MaxM]{};

    void crt(int *a, int n)
    {
        for (int i(2); i <= n; i++)
        {
            log[i] = log[i >> 1] + 1;
        }

        for (int i(1); i <= n; i++)
        {
            f[i][0] = a[i];
        }

        for (int j(1); pow2(j) - 1 < n; j++)
        {
            for(int i(1); i + pow2(j) - 1 <= n; i++)
            {
                if (f[i][j - 1] > f[i + pow2(j - 1)][j - 1])
                {
                    f[i][j] = f[i][j - 1];
                }
                else
                {
                    f[i][j] = f[i + pow2(j - 1)][j - 1];
                }
            }
        }
    }

    int src(int l, int r)
    {
        int s = log[r - l + 1];

        if (f[l][s] > f[r - pow2(s) + 1][s])
        {
            return f[l][s];
        }
        else
        {
            return f[r - pow2(s) + 1][s];
        }
    }
};

st a;
int d[MaxN]{};

int main()
{
    ios::sync_with_stdio(0);

    int n, m;
    int x, y;

    cin >> n >> m;

    for (int i(1); i <= n; i++)
    {
        cin >> d[i];
    }

    a.crt(d, n);

    for (int i(1); i <= m; i++)
    {
        cin >> x >> y;

        cout << a.src(x, y) << endl;
    }

    return 0;
}
