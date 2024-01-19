#include <bits/stdc++.h>
#define taskname "tower_of_hanoi"
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int mod = 1000000007;
const int inf = 4444444444444444444;
const bool is_multitest = 0;

vector<pii> step;

void rec(int n, int t1, int t3, int t2) {
    if (n == 1) {
        step.push_back(mp(t1, t3));
    }
    else {
        rec(n - 1, t1, t2, t3);
        rec(1, t1, t3, t2);
        rec(n - 1, t2, t3, t1);
    }
}

void execute(int test_number)
{
    int n;  cin >> n;
    rec(n, 1, 3, 2);
    cout << step.size() << '\n';
    for (auto p : step) cout << p.X << ' ' << p.Y << '\n';
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