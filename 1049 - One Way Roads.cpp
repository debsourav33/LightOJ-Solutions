#include <bits/stdc++.h>
using namespace std;

// Reads two integers and prints their sum
int n;
vector<vector<vector<int>>> v, t;
vector<int> vis;

void basicIO() {
    scanf("%d\n",&n);
    
    v = vector(n+1,vector<vector<int>>());
    t = vector(n+1,vector<vector<int>>());
    
    int x, y, w;
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&x,&y,&w);
        v[x].push_back({y,w});
        t[y].push_back({x,w});
    }  
}


/*
If from one node there's no outdegree edge,
use the indegree edge and add the cost (which implies reverting the indegree edge)
*/
int dfs(int u, int p){
    if(vis[u])  return 0;
    vis[u] = 1;
    
    //try to traverse using outdegree edge
    for(auto adj: v[u]){
        int node = adj[0], cost = adj[1];
        if(node==p)  continue;
        
        return dfs(node,u);
    }
    
    //if unable, try to traverse using indegree edge and add reversal cost
    for(auto adj: t[u]){
        int node = adj[0], cost = adj[1];
        if(node==p)  continue;
        
        return cost + dfs(node,u);
    }
    
    return 1e9;
}

int solve(){
    int two_out = -1;
    for(int i=1;i<=n;i++){
        auto &adj =  v[i];
        if(adj.size()==2)  two_out = i;
    }
    
    if(two_out==-1)  return 0;
    
    vis = vector(n+1,0);
    int cost1 = dfs(two_out,-1);
    
  
    //swap the out edges of the source node
    swap(v[two_out][0],v[two_out][1]);
    
    vis = vector(n+1,0);
    int cost2 = dfs(two_out,-1);
    
    return min(cost1,cost2);

}



int main() {
    int cas = 0, q;
    scanf("%d",&q);
    while(cas++<q){
        basicIO();
        printf("Case %d: %d\n",cas,solve());
    }
    // Your cpp code here
    return 0;
}
