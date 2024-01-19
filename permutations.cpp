#include <bits/stdc++.h>
#define taskname "permutations"
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
    if (n <= 3) {
        if (n == 1) cout << 1;
        else if (n == 2 || n == 3) cout << "NO SOLUTION";
    }
    else {
        for (int i = 2; i <= n; i += 2) cout << i << ' ';
        for (int i = 1; i <= n; i += 2) cout << i << ' ';
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