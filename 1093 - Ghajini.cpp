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
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

#define lefts 2*at
#define rights 2*at+1

#define INF 1e9

const int maxn= 2e5+5;

i64 maxi[4*maxn], mini[4*maxn];
i64 num[maxn];

struct node{
    i64 mx, mn;

    node(i64 _mx, i64 _mn){
        mx= _mx;
        mn= _mn;
    }
};

void marge(int at){
    maxi[at]= max(maxi[lefts],maxi[rights]);
    mini[at]= min(mini[lefts],mini[rights]);
}

void build(int at, int l, int r){
    if(l==r){
        maxi[at]= num[l];
        mini[at]= num[l];
        return;
    }

    int mid= (l+r)/2;

    build(lefts,l,mid);
    build(rights,mid+1,r);
    marge(at);
}


node query(int x, int y, int at, int l, int r){
    if(l>=x && r<=y)  return node(maxi[at], mini[at]);
    if(l>y || r<x)  return node(-INF, INF);

    int mid= (l+r)/2;

    node a= query(x,y,lefts,l,mid);
    node b= query(x,y,rights,mid+1,r);

    return node(max(a.mx,b.mx),min(a.mn,b.mn));
}

main(){
    int opt;
    si(opt);

    for(int o=1;o<=opt;o++){
        int n, d;
        sii(n,d);

        fr(n)
            sl(num[i]);

        build(1,0,n-1);

        i64 diff= -1;

        for(int i=0; i+d-1<n; i++){
            node a= query(i,i+d-1,1,0,n-1);
            diff= max(diff,a.mx-a.mn);
        }

        printf("Case %d: %lld\n",o,diff);

    }
}
