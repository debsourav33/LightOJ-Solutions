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

i64 n, cost[22][3], dp[4][22];

i64 call(int prev, int pos){
    if(pos==n)  return 0;
    if(dp[prev][pos]!=-1)  return dp[prev][pos];

    i64 mini= 10e15;
    fr(3){
        if(i==prev)  continue;

        i64 tmp= cost[pos][i]+ call(i, pos+1);
        mini= min(tmp, mini);
    }

    return dp[prev][pos]= mini;
}

main(){
    int opt;
    si(opt);

    for(int o=1;o<=opt;o++){
        sets(dp);
        sl(n);

        fr(n){
            for(int j=0;j<3;j++)
                sl(cost[i][j]);
        }

        printf("Case %d: %lld\n",o,call(3,0));
    }
}

/*
2
4
13 23 12
77 36 64
44 89 76
31 78 45
3
26 40 83
49 60 57
13 89 99
*/
