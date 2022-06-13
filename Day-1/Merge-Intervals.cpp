#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define forT(t) for(int i=0;i<t;i++)
#define forN(n) for(int j=0;j<n;j++)
#define MOD 1000000007
#define num 4e6 + 5



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

void solve(vv vec)
{
    vv output;
    sort(vec.begin(), vec.end());


    vector<int>temp(2) ;
    temp = vec[0];

    if (vec.size() == 0)return ;
    // for (auto it : temp)cout << it << " ";
    for (int i = 1 ; i < vec.size(); i++)
    {
        if (vec[i][0] <= temp[1])
        {
            temp[1] = max(vec[i][1], temp[1]);
        }
        else
        {
            output.push_back(temp);
            temp = vec[i];
        }

        // cout << temp[0] << " " << temp[1]<<" ";
    }

    output.push_back(temp);

    // return output;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << output[i][j] << " ";
        }

        cout << endl;
    }

}

int main() {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vv vec(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << vec[i][j] << " ";
    //     }

    //     cout << endl;
    // }


    // vv output = solve(vec);
    solve(vec);


    return 0;
}

// coded with the ❤️ Avnoor

