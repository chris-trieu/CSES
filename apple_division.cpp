#include <bits/stdc++.h>
#define taskname "apple_division"
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int mod = 1000000007;
const int inf = 4444444444444444444;
const bool is_multitest = 0;

void execute(int test_number)
{
    int n;  cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int ret = inf;
    for (int i = 0; i < 1 << n; ++i) {
        int s1 = 0, s2 = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) s1 += a[j];
            else s2 += a[j];
        }
        ret = min(ret, abs(s1 - s2));
    }
    cout << ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);
    ifstream test_inp_file("test.inp");
    if (test_inp_file)
    {
        freopen("test.inp", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else
    {
        ifstream task_inp_file(taskname".inp");
        if (task_inp_file)
        {
            freopen(taskname".inp", "r", stdin);
            freopen(taskname".out", "w", stdout);
        }
    }

    int ntest;
    if (is_multitest) cin >> ntest;
    else ntest = 1;

    for (int testno = 1; testno <= ntest; testno++)
    {
        execute(testno);
    }
}