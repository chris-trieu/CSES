#include <bits/stdc++.h>
#define taskname "grey_code"
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
    vector<string> v;
    string s = "";
    for (int i = 0; i < n; ++i) s.push_back('0');
    v.push_back(s);
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = v.size() - 1; j >= 0; --j) 
        {
            s = v[j];
            s[i] = '1';
            v.push_back(s);
        }
    }
    for (auto p : v) cout << p << '\n';
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