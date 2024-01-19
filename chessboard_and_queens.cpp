#include <bits/stdc++.h>
#define taskname "chessboard_and_queens"
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int mod = 1000000007;
const int inf = 4444444444444444444;
const bool is_multitest = 0;

int v[8][8];
int row[8], col[8];
int d1[15], d2[15];
int num = 0;

void gen(int k, int p) {
    if (k == 8) {
        num++;
        return;
    }
    for (int temp = p; temp < 64; ++temp) {
        int i = temp / 8, j = temp % 8;
        if (row[i] || col[j] || v[i][j] || d1[i + j] || d2[i - j + 7]) continue;
        row[i] = 1;
        col[j] = 1;
        v[i][j] = 1;
        d1[i + j] = 1;
        d2[i - j + 7] = 1;
        gen(k + 1, temp + 1);
        row[i] = 0;
        col[j] = 0;
        v[i][j] = 0;
        d1[i + j] = 0;
        d2[i - j + 7] = 0;
    }
}

void execute(int test_number)
{
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j) {
            char c;     
            cin >> c;
            if (c == '*') v[i][j] = 1;
        }
    gen(0, 0);
    cout << num;
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