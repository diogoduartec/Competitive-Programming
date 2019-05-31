//PD do SIBIXOR

#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int >
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vvii>
#define ll unsigned long long
#define ft digit
#define sc value
#define INF 0x3f3f3f3f
#define MAXN 2019
#define MOD 1000000007ULL
#define _ ios_base::sync_with_stdio(false);

int n;
ll a[MAXN];
ll dp[MAXN][MAXN];

int main(){_
    int x;
    while(cin >> n){
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        
        ll b=-1;
        
        for(int i=0; i<=n; i++) dp[i][0] = b;
        for(int i=1; i<=n; i++) dp[0][i] = 0ULL;
        
        for(int j=1; j<=n; j++){
            for(int i=1; i<=n; i++){
                dp[i][j] = (dp[i-1][j] ^ (dp[i-1][j-1]&a[i]));
            }
        }
        
        ll ans = 0ULL;
        for(int i=1; i<=n; i++) ans = ((ans)%MOD+(dp[n][i])%MOD)%MOD;
        cout << ans << endl;
        
    }
        
    return 0;
}
