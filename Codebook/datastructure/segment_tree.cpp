#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define left(x) (x<<1)
#define right(x) ((x<<1)+1)
#define mid(a,b) ((a+b)>>1)
#define NEUTRAL 0LL

vector<ll> tree, a;

ll comp(ll a, ll b){
    return a+b;
}

void build(int node, int i, int j){
    if(i==j){
        tree[node] = a[i];
        return;
    }
    build(left(node), i, mid(i,j));
    build(right(node), mid(i,j)+1, j);
    
    tree[node] = comp(tree[left(node)], tree[right(node)]);

}

ll query(int node, int i, int j, int l, int r){
    if(j<l || i>r) return NEUTRAL;
    if(i>=l && j<=r) return tree[node];

    int lans = query(left(node), i, mid(i,j), l, r);
    int rans = query(right(node), mid(i,j)+1, j, l, r);

    return comp(lans, rans);
}

void update(int node, int i, int j, int idx, ll val){
    if(idx<i || idx>j) return;
    if(i==j){
        tree[node] = val;
        return;
    }

    update(left(node), i, mid(i,j), idx, val);
    update(right(node), mid(i,j)+1, j, idx, val);
    
    tree[node] = comp(tree[left(node)], tree[right(node)]);
}

int main(){

    int n;
    cin >> n;
    a = vector<ll>(n+1);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    tree = vector<ll>(4*n);
    build(1, 0, n-1);
    
    int op, idx, l, r;
    ll val;
    while(cin>>op){
        if(op==1){
            cin >> l >> r;
            cout << query(1, 0, n-1, l, r) << endl;
        }else{
            cin >> idx >> val;
            update(1, 0, n-1, idx, val);
        }
    }
    
    return 0;
}


