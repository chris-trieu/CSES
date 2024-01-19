#include <bits/stdc++.h>
#define taskname "palindrome_reorder"
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int mod = 1000000007;
const int inf = 4444444444444444444;
const bool is_multitest = 0;

int c[27];

void execute(int test_number)
{
    string s;   cin >> s;
    for (auto ch : s) c[ch - 'A']++;
    char ch;
    int nodd = 0;
    for (int i = 0; i < 27; ++i) 
        if (c[i] & 1) {
            c[i]--;
            ++nodd;
            ch = i + 'A'; 
        }
    if (nodd > 1) cout << "NO SOLUTION";
    else {
        for (int i = 0; i < 27; ++i) {
            for (int j = 1; j <= c[i] / 2; ++j) cout << char(i + 'A');
        }
        if (nodd) cout << ch;
        for (int i = 26; i >= 0; --i) {
            for (int j = 1; j <= c[i] / 2; ++j) cout << char(i + 'A');
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