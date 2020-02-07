#include <bits/stdc++.h>
using namespace std;

#define left(x) (x<<1)
#define right(x) ((x<<1)+1)
#define mid(x,y) ((x+y)>>1)
#define NEUTRAL 0
#define ll long long
#define vi vector<ll>
#define add emplace_pack

vi tree, lazy, a;

void build(int node, int i, int j){
    if(i==j){
        tree[node] = a[i];
    }else{
        build(left(node), i, mid(i,j));
        build(left(node), mid(i,j)+1, j);
        tree[node] = tree[left(node)] + tree[right(node)];
    }
}

void push(int node, int i, int j){
    tree[node] += lazy[node]*(j-i+1);
    if(i!=j){
        lazy[left(node)] += lazy[node];
        lazy[right(node)] += lazy[node];
    }
    lazy[node] = NEUTRAL;
}

void update(int node, int i, int j, int l, int r, ll val){
    push(node, i, j);
    if(i>r||j<l) return;
    if(i>=l && j<=r) {
        lazy[node] += val;
        push(node, i, j);
    }else{
        update(left(node), i, mid(i,j), l, r, val);
        update(right(node), mid(i,j)+1, j, l, r, val);
        tree[node] = tree[left(node)]+tree[right(node)];
    }
}

ll query(int node, int i, int j, int l, int r){
    push(node, i, j);
    if(i>r||j<l) return NEUTRAL;
    if(i>=l && j<=r){
        return tree[node];
    }
    ll lans = query(left(node), i, mid(i,j), l, r);
    ll rans = query(right(node), mid(i,j)+1, j, l, r);
    return lans+rans;
}

int main(){
    int t, n, p, q, c, cmd;
    ll val;
    
    cin >> t;
    while(t--){
        cin >> n >> c;
        tree = vi(4*n+n, 0), lazy = vi(4*n+n, 0);
        //for(int i=1; i<=n; ++i) cin >> a[i];
        //build(1,1,n);
        
        while(c--){
            cin >> cmd >> p >> q;
            if(p>q) swap(p,q);
            
            if(cmd==0){
                cin >> val;
                update(1,1,n,p,q,val);
            }else{
                cout << query(1,1,n,p,q) << endl;
            }
        }
    }

    return 0;
}
