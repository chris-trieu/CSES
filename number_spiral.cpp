#include <bits/stdc++.h>
#define taskname "number_spiral"
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int mod = 1000000007;
const int inf = 4444444444444444444;
const bool is_multitest = 1;

void execute(int test_number)
{
    int x, y;   cin >> x >> y;
    int mid = max(x, y);
    mid = mid * mid - mid + 1;
    if (x == y) cout << mid;
    else if (x > y) {
        if (x & 1) cout << mid - (x - y);
        else cout << mid + (x - y);
    }
    else {
        if (y & 1) cout << mid + (y - x);
        else cout << mid - (y - x);
    }
    cout << '\n';

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