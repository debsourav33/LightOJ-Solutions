#include<bits/stdc++.h>
using namespace std;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

#define cel(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define INF 10000007
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

i64 n, cost[20][20], dp[131080][20];

i64 setbit(int mask, int i){
    return mask | (1<<i);
}

bool checkbit(int mask, int i){
    return mask & (1<<i);
}

i64 call(int mask, int pos){
    if(pos==n)  return 0;
    if(dp[mask][pos]!=-1)  return dp[mask][pos];

    i64 maxi= -10e15;
    fr(n){
        if(checkbit(mask,i))  continue;

        i64 tmp= cost[pos][i]+ call(setbit(mask,i), pos+1);
        maxi= max(tmp, maxi);
    }

    return dp[mask][pos]= maxi;
}

main(){
    int opt;
    si(opt);

    for(int o=1;o<=opt;o++){
        sets(dp);
        sl(n);

        fr(n){
            for(int j=0;j<n;j++)
                sl(cost[i][j]);
        }

        printf("Case %d: %lld\n",o,call(0,0));
    }
}
