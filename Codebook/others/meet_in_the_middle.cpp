#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define M 1123456
#define N 50

ll a[M], b[M], vec[N];

// calculate all possible sums
void calc_subarray(ll *subarray, int sz, int start){
    for(int i=0; i<(1<<sz); ++i){
        ll s = 0;
        for(int j=0; j<sz; ++j){
            // if bit j is on
            if(i & (1<<j))
                s += vec[start+j];
        }
        subarray[i] = s;
    }
}

ll solve(int sz, ll x){
    // compute subset sums on subarrays
    calc_subarray(a, sz/2, 0);
    calc_subarray(b, sz-sz/2, sz/2);

    int sz_a = 1<<(sz/2);
    int sz_b = 1<<(sz-sz/2);
    
    sort(b, b+sz_b);
    
    ll mx = 0;

    for(int i=0; i<sz_a; ++i){
        if(a[i] <= x){
            int pos = lower_bound(b, b+sz_b, x-a[i]) - b;
            // if not found
            if(pos == sz_b || b[pos] != (x-a[i]))
                --pos;
            // pos < 0 if first element in b is greater than x-a[i]
            if(pos>=0){
                // set max possible sum <= x
                mx = max(a[i] + b[pos], mx);
            }
        }
    }
    
    return mx;
}

int main(){
    int n;
    ll m;

    while(cin >> n >> m){
        for(int i=0; i<n; ++i) cin >> vec[i];
        // get value <= m
        ll ans = solve(n, m);
        cout << (ans==m?"sim":"nao") << endl;
    }

    return 0;
}
