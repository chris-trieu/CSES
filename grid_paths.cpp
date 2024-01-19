#include <bits/stdc++.h>
#define taskname "Grid_Paths"
//#define int long long
#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int mod = 1000000007;
//const int inf = 4444444444444444444;
const bool is_multitest = 0;

string s = "";
int v[7][7];
int xx[4] = {1, 0, -1, 0};
int yy[4] = {0, -1, 0, 1};
char dd[4] = {'R', 'D', 'L', 'U'};
int sx = 0, sy = 6;
int fx = 0, fy = 0;
int gate[5];
int g[7][7];
vector<string> vs;

bool check(int x, int y) {
    if (x < 0) return false;
    if (x > 6) return false;
    if (y < 0) return false;
    if (y > 6) return false;
    if (v[x][y]) return false;
    return true;
}

void generate(int count, int x, int y) {
    if (x == fx && y == fy) {
        if (count == 48) vs.push_back(s);
        return;
    } 
    if (gate[0] && count < 47) return;
    if (gate[1] > 2 || (gate[1] == 2 && g[fx][fy] != 1)) return;
    for (int d = 0; d < 4; ++d) {
        int x1 = x + xx[d], y1 = y + yy[d];
        if (check(x1, y1)) {
            s += dd[d];
            v[x1][y1] = 1;
            gate[g[x1][y1]] -= 1;
            for (int d1 = 0; d1 < 4; ++d1)
                if (check(x1 + xx[d1], y1 + yy[d1])) {
                    gate[g[x1 + xx[d1]][y1 + yy[d1]]--]--;
                    gate[g[x1 + xx[d1]][y1 + yy[d1]]]++;
                }

            generate(count + 1, x1, y1);

            s.pop_back();
            v[x1][y1] = 0;
            gate[g[x1][y1]] += 1;
            for (int d1 = 0; d1 < 4; ++d1)
                if (check(x1 + xx[d1], y1 + yy[d1])) {
                    gate[g[x1 + xx[d1]][y1 + yy[d1]]++]--;
                    gate[g[x1 + xx[d1]][y1 + yy[d1]]]++;
                }
        }
    }

}

void execute(int test_number)
{
    for (int x = 0; x < 7; ++x)
        for (int y = 0; y < 7; ++y) {
            g[x][y] = 4;
            for (int d = 0; d < 4; ++d) 
                if (!check(x + xx[d], y + yy[d])) g[x][y] -= 1;
            gate[g[x][y]] += 1;
        }

    v[sx][sy] = 1;
    gate[g[sx][sy]] -= 1;
    for (int d = 0; d < 4; ++d)
        if (check(sx + xx[d], sy + yy[d])) {
            gate[g[sx + xx[d]][sy + yy[d]]--]--;
            gate[g[sx + xx[d]][sy + yy[d]]]++;
        }
    generate(0, sx, sy);

    string ss;  cin >> ss;
    int ans = 0;
    for (int i = 0; i < vs.size(); ++i) {
        int check = 1;
        for (int c = 0; c < 48; ++c) 
            if (ss[c] != '?' && ss[c] != vs[i][c]) {
                check = 0;
                break;
            }
        ans += check;
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);
    if (ifstream("test.inp"))
    {
        freopen("test.inp", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else if (ifstream(taskname".inp"))
    {
            freopen(taskname".inp", "r", stdin);
            freopen(taskname".out", "w", stdout);
    }

    int ntest;
    if (is_multitest) cin >> ntest;
    else ntest = 1;

    for (int testno = 1; testno <= ntest; testno++)
    {
        execute(testno);
    }
}