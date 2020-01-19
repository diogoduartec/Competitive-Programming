//TSP - COMBATE A DENGE

#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f3f3f3fLL

int n;
double dist[17][17];
double memo[17][1<<17];

double d(int xi, int yi, int xii, int yii){
    return hypot(xi - xii, yi-yii);
}

double f(int idx, int bitmask){
    
    if(bitmask == (1<<n)-1) return dist[idx][0];
    if(memo[idx][bitmask] != -1){return memo[idx][bitmask];}
    
    double ans = INF;
    
    for(int i=0; i<n; i++){
        if(!(bitmask & (1<<i))){
            ans = min(ans, f(i, (bitmask | (1<<i))) + dist[idx][i]);
        }
    }
    
    return memo[idx][bitmask] = ans;
    
}

int main(){
    
    
    
    while(scanf("%d", &n), n){
        n++;
        int x[n], y[n];
        
        for(int i=0; i<n; i++)
            scanf("%d %d", x+i, y+i);
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
               dist[i][j] = dist[j][i] = d(x[i], y[i], x[j], y[j]);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j < (1<<n); j++) memo[i][j] = -1;
        }
        printf("%.2lf\n", f(0,1));
        
    }
    
    return 0;
}
