#include <bits/stdc++.h>
#define taskname "creating_strings"
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int mod = 1000000007;
const int inf = 4444444444444444444;
const bool is_multitest = 0;

string s, gens;
int a[8];
vector<string> v;

void gen(int k) {
    if (k == s.size()) {
        v.push_back(gens);
        return;
    }
    for (int i = 0; i < s.size(); ++i)
        if (!a[i]) {
            a[i] = 1;
            gens.push_back(s[i]);
            gen(k + 1);
            a[i] = 0;
            gens.pop_back(); 
        }
}

void execute(int test_number)
{
    cin >> s;
    gen(0);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << '\n';
    for (string sp : v) cout << sp << '\n';
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