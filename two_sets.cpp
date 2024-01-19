#include <bits/stdc++.h>
#define taskname "two_sets"
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
    if ((n * (n + 1) / 2) & 1) cout << "NO\n";
    else {
        int sum = n * (n + 1) / 4;
        vector<int> g1, g2;
        for (int i = n; i; --i) {
            if (i <= sum) {
                sum -= i;
                g1.emplace_back(i);
            }
            else g2.emplace_back(i);
        }
        cout << "YES\n";
        cout << g1.size() << '\n';
        for (int i : g1) cout << i << ' ';
        cout << '\n';
        cout << g2.size() << '\n';
        for (int i : g2) cout << i << ' ';
        cout << '\n';
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