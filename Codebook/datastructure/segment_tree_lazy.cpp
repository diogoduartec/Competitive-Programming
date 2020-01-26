#include <bits/stdc++.h>
using namespace std;

#define left(x) (x<<1)
#define right(x) ((x<<1)+1)
#define mid(x,y) ((x+y)>>1)
#define NEUTRAL 0
#define ll long long
#define vi vector<ll>

vi tree, a, lazy;

ll comp(ll x, ll y){
    return x + y;
}

ll build(int node, int i, int j){
    if(i==j) return tree[node] = a[i];
    build(left(node), i, mid(i,j));
    build(right(node), mid(i,j)+1, j);
    return tree[node] = comp(tree[left(node)], tree[right(node)]);
}

void push(int node, int i, int j){
    tree[node] += lazy[node]*(j-i+1);
    if(i!=j){
        lazy[left(node)] = lazy[node];
        lazy[right(node)] = lazy[node];
        lazy[node] = NEUTRAL;
    }
}

ll query(int node, int i, int j, int l, int r){
    push(node, i, j);
    if(i>r || j<l) return NEUTRAL;
    if(i>=l && j<=r) return tree[node];
    ll lans = query(left(node), i, mid(i,j), l, r);
    ll rans = query(right(node), mid(i,j)+1, j, l, r);

    return comp(tree[left(node)], tree[right(node)]);
}

void update(int node, int i, int j, int l, int r, ll val){
    push(node, i, j);
    if(i>r || j<l) return;
    if(i>=l && j<=r){
        lazy[node] = val;
        push(node, i, j);
        return;
    }
    update(left(node), i, mid(i,j), l, r, val);
    update(right(node), mid(i,j)+1, j, l, r, val);
    
    tree[node] = comp(tree[left(node)], tree[right(node)]);
}


int main(){
    a = {1, 1, 2, 3, 5};
    int n = 5;
    tree = vi(4*n);
    lazy = vi(4*n);
    build(1,0,n-1);
    
    cout << query(1, 0, n-1, 0, n-1) << endl;
    update(1, 0, n-1, 0, n-1, 1);
    cout << query(1, 0, n-1, 0, n-1) << endl;
    
    return 0;

}























