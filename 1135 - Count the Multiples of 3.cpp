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

int lazy[400005], ones[400005], twos[400005], zeros[400005], n;

struct node{
    int z, o, t;

    node(int ze, int on, int tw){
        z= ze;
        o= on;
        t= tw;
    }
    node(){}
};

void marge(int at){
    zeros[at]= zeros[lefts]+ zeros[rights];
    ones[at]= ones[lefts]+ ones[rights];
    twos[at]= twos[lefts]+ twos[rights];
}

void build(int at, int l, int r){
    if(l==r){
        zeros[at]= 1;
        return;
    }

    int mid= (l+r)/2;

    build(lefts,l,mid);
    build(rights,mid+1,r);
    marge(at);
}

void upd(int at, int x){
    lazy[at]+= x;

    if(x%3==1){
        int tmp= zeros[at];
        zeros[at]= twos[at];
        twos[at]= ones[at];
        ones[at]= tmp;
    }

    if(x%3==2){
        int tmp= zeros[at];
        zeros[at]= ones[at];
        ones[at]= twos[at];
        twos[at]= tmp;
    }
}

void propagate(int at){
    upd(lefts, lazy[at]);
    upd(rights, lazy[at]);

    lazy[at]= 0;
}

void update(int at, int l, int r, int x, int y){
    if(x<=l && r<=y){
        lazy[at]++;
        int tmp= zeros[at];
        zeros[at]= twos[at];
        twos[at]= ones[at];
        ones[at]= tmp;

        return;
    }

    if(x>r || y<l)  return;

    if(lazy[at]) propagate(at);

    int mid= (l+r)/2;

    update(lefts,l,mid,x,y);
    update(rights,mid+1,r,x,y);
    marge(at);
}

node query(int at, int l, int r, int x, int y){
    if(x<=l && r<=y)  return node(zeros[at],ones[at],twos[at]);
    if(x>r || y<l)  return node(0,0,0);


    if(lazy[at]) propagate(at);

    int mid= (l+r)/2;
    node a= query(lefts,l,mid,x,y);
    node b= query(rights,mid+1,r,x,y);

    return node(a.z+b.z, a.o+b.o, a.t+b.t);
}

void reset(){
    clr(lazy);
    clr(ones);
    clr(twos);
    clr(zeros);
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

            if(opt){
                sii(x,y);
                node ans= query(1, 0, n-1, x, y);
                printf("%d\n",ans.z);
            }
            else{
                sii(x,y);
                update(1,0,n-1,x,y);
            }
        }
    }
}
