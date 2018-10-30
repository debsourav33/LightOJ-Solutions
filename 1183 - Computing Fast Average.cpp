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

#define lefts 2*at
#define rights 2*at+1

const int maxn= 1e5+5;

int a[maxn], lazy[4*maxn], sum[4*maxn], n;

struct node{
    int s, n;

    node(int ss, int nn){
        s= ss;
        n= nn;
    }
    node(){}
};

void marge(int at){
    sum[at]= sum[lefts]+ sum[rights];
}

void build(int at, int l, int r){
    if(l==r){
        sum[at]= 0;
        //avg[at]= a[r];
        return;
    }

    int mid= (l+r)/2;

    build(lefts,l,mid);
    build(rights,mid+1,r);
    marge(at);
}

void upd(int at, int x, int l, int r){
    lazy[at]= x;
    sum[at]= x* (r-l+1);
    //avg[at]= x;
}

void propagate(int at, int l, int r){
    int mid= (l+r)/2;
    int left_l= l, left_r= mid, right_l= mid+1, right_r= r;

    upd(lefts, lazy[at], left_l, left_r);
    upd(rights, lazy[at], right_l, right_r);

    lazy[at]= -1;
}

void update(int at, int l, int r, int x, int y, int val){
    if(x<=l && r<=y){
        lazy[at]= val;
        sum[at]= val* (r-l+1);
        //avg[at]= val;
        return;
    }

    if(x>r || y<l)  return;

    if(lazy[at]!=-1) propagate(at,l,r);

    int mid= (l+r)/2;

    update(lefts,l,mid,x,y,val);
    update(rights,mid+1,r,x,y,val);
    marge(at);
}

node query(int at, int l, int r, int x, int y){
    if(x<=l && r<=y)  return node(sum[at],r-l+1);
    if(x>r || y<l)  return node(0,0);

    if(lazy[at]!=-1) propagate(at,l,r);

    int mid= (l+r)/2;
    node a= query(lefts,l,mid,x,y);
    node b= query(rights,mid+1,r,x,y);

    return node(a.s+b.s, a.n+b.n);
}

void reset(){
    clr(a);
    sets(lazy);
    clr(sum);
}

main(){
    int t, q, x, y, opt;
    si(t);

    for(int o=1;o<=t;o++){
        reset();

        sii(n,q);
        build(1,0,n-1);

        printf("Case %d:\n",o);

        while(q--){
            si(opt);

            if(opt==2){
                sii(x,y);
                node ans= query(1, 0, n-1, x, y);

                if(ans.s%ans.n==0)
                    printf("%d\n",ans.s/ans.n);
                else{
                    int gc= __gcd(ans.s,ans.n);
                    printf("%d/%d\n",ans.s/gc,ans.n/gc);
                }


            }
            else{
                int z;
                siii(x,y,z);
                update(1,0,n-1,x,y,z);
            }
        }
    }
}

/*
3
5 55
1 0 4 1
2 0 4
2 0 0
1 0 4 0
2 0 4
2 0 0

10 5
1 0 4 2
1 5 9 3
2 0 4
2 5 9
2 0 9

10 6
1 0 6 6
2 0 1
1 1 1 2
2 0 5
1 0 3 7
2 0 1
*/
