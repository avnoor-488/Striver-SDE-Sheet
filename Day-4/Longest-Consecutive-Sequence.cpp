#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define forT(t) for(int i=0;i<t;i++)
#define forN(n) for(int j=0;j<n;j++)
#define MOD 1000000007


typedef pair<int, int> pii;
typedef vector<string> vs;
typedef set<int> seti;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vv;


void fastscan( ll &number)
{
    bool negative = false;
    register int c;

    number = 0;

    c = getchar();
    if (c == '-')
    {
        negative = true;

        c = getchar();
    }

    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;


    if (negative)
        number *= -1;
}

ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

ll dp[100010][110][2];
ll arr[100010];

int solve(vi vec)
{
    unordered_set<int>s(begin(vec), end(vec));
    int count = 0;

    for (auto it : s)
    {
        if (s.count(it - 1))continue;

        int num = 1;
        while (s.count(it + num))num++;
        count = max(num, count);
    }
    return count;
}




int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)

    {
        int n; cin >> n;

        vi vec(n);

        forT(n)
        {
            cin >> vec[i];
        }


        cout << solve(vec) << endl;
    }
    return 0;
}

// coded with the ❤️ Avnoor

