#include <bits/stdc++.h>
#define taskname "two_knights"
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
    for (int i = 1; i <= n; ++i) {
        if (i == 1) cout << 0 << '\n';
        else if (i == 2) cout << 6 << '\n';
        else if (i == 3) cout << 28 << '\n';
        else {
            int ret = 0;
            ret += (i - 4) * (i - 4) * (i * i - 8 - 1);
            ret += (i - 4) * 4 * (i * i - 6 - 1);
            ret += ((i - 4) * 4 + 4) * (i * i - 4 - 1);
            ret += 8 * (i * i - 3 - 1);
            ret += 4 * (i * i - 2 - 1);
            cout << ret / 2 << '\n';
        }
    }
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