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

const int maxn= 2e5+5;

int lazy[4*maxn], sum[4*maxn], n, l[maxn], r[maxn], q[maxn], ml[maxn], mr[maxn], mq[maxn];
vector<int> v;

void marge(int at){
    sum[at]= sum[lefts]+ sum[rights];
}

void build(int at, int l, int r){
    if(l==r){
        sum[at]= 0;
        return;
    }

    int mid= (l+r)/2;

    build(lefts,l,mid);
    build(rights,mid+1,r);
    marge(at);
}

void upd(int at, int x){
    lazy[at]+= x;
    sum[at]+= x;
}

void propagate(int at){
    upd(lefts, lazy[at]);
    upd(rights, lazy[at]);

    lazy[at]= 0;
}

void update(int at, int l, int r, int x, int y){
    if(x<=l && r<=y){
        lazy[at]++;
        sum[at]++;
        return;
    }

    if(x>r || y<l)  return;

    if(lazy[at]) propagate(at);

    int mid= (l+r)/2;

    update(lefts,l,mid,x,y);
    update(rights,mid+1,r,x,y);
    marge(at);
}

int query(int at, int l, int r, int pos){
    if(l==r)  return sum[at];

    if(lazy[at]) propagate(at);

    int mid= (l+r)/2;

    if(pos<=mid)  return query(lefts,l,mid,pos);
    else  return query(rights,mid+1,r,pos);
}

void reset(){
    clr(lazy);
    clr(sum);
    clr(mr);
    clr(ml);
    clr(mq);
    v.clear();
}

main(){
    int t, qr, x, y, opt;
    si(t);

    for(int o=1;o<=t;o++){
        reset();

        sii(n,qr);
        build(1,0,maxn-1);

        printf("Case %d:\n",o);

        fr(n){
            sii(l[i],r[i]);
            v.pb(l[i]); v.pb(r[i]);
        }

        fr(qr){
            si(q[i]);
            v.pb(q[i]);
        }

        sort(all(v));

        fr(n){
            ml[i]= lower_bound(all(v),l[i])- v.begin();
            mr[i]= lower_bound(all(v),r[i])- v.begin();

            update(1,0,maxn-1,ml[i],mr[i]);
        }

        fr(qr){
            mq[i]= lower_bound(all(v),q[i])- v.begin();
            int ans= query(1, 0, maxn-1, mq[i]);

            printf("%d\n",ans);
        }

    }
}

/*
1
5 4
6 12
8 8
10 12
8 11
0 12
11
12
2
20
*/
