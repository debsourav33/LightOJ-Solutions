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


i64 ceilsqrt(i64 n){
    i64 sq= sqrt(n);

    if(sq*sq==n) return sq;
    return sq+1;
}

main(){
    i64 opt, o=1, n;
    cin>>opt;

    while(o<=opt){
        sl(n);
        i64 id= ceilsqrt(n), row, col;
        i64 mid= ((id-1)*(id-1)+id*id+1)/2;

        if(id&1){
            if(n>=mid){
                row= id;
                col= id- (n-mid);
            }
            else{
                col= id;
                row= id- (mid-n);
            }
        }
        else{
            if(n<=mid){
                row= id;
                col= id- (mid-n);
            }
            else{
                col= id;
                row= id- (n-mid);
            }

        }

        printf("Case %lld: %lld %lld\n",o++,col,row);

    }
}
