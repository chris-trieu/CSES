#include <bits/stdc++.h>
#define taskname "digit_queries"
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
    vector<int> p(18);
    p[0] = 1;
    for (int i = 1; i < 18; ++i) p[i] = p[i - 1] * 10;

    int n;  cin >> n;
    int d = 1;
    while (1) {
        if (n > 9 * p[d - 1] * d) {
            n -= 9 * p[d - 1] * d;
            ++d;
        }
        else break;
    }
    int num = p[d - 1] + (n + d - 1) / d - 1;
    int digit = (n % d)? n % d: d;
    num /= p[d - digit];
    cout << num % 10 << '\n';
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