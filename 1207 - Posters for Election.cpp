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

const int maxn= 200005;
const int madmax= 1e7+4;

#define lefts 2*at
#define rights 2*at+1

int lazy[4*maxn], mark[4*maxn], n, l[maxn], r[maxn], ml[maxn], mr[maxn], ranks[madmax];
vector<int> v;

void build(int at, int l, int r){
    if(l==r){
        lazy[at]= 0;
        return;
    }

    int mid= (l+r)/2;

    build(lefts,l,mid);
    build(rights,mid+1,r);
}

void upd(int at, int x){
    lazy[at]= x;
}

void propagate(int at){
    upd(lefts, lazy[at]);
    upd(rights, lazy[at]);

    lazy[at]= 0;
}

void update(int at, int l, int r, int x, int y, int val){
    if(x<=l && r<=y){
        lazy[at]= val;
        return;
    }

    if(x>r || y<l)  return;

    if(lazy[at]) propagate(at);

    int mid= (l+r)/2;

    update(lefts,l,mid,x,y,val);
    update(rights,mid+1,r,x,y,val);
}

int query(int at, int l, int r, int x){
    if(l==r)  return lazy[at];

    if(lazy[at]) propagate(at);

    int mid= (l+r)/2;

    if(x<=mid)  return query(lefts,l,mid,x);
    else  return query(rights,mid+1,r,x);
}

void reset(){
    clr(lazy);
    clr(mark);
    clr(ml);
    clr(mr);
    clr(l);
    clr(r);
    clr(ranks);
    v.clear();
}

main(){
    int opt;
    si(opt);

    for(int o=1;o<=opt;o++){
        reset();

        int x, y;
        si(n);

        build(1,0,maxn-1);

        fr(n){
            sii(l[i],r[i]);
            v.pb(l[i]); v.pb(r[i]);
        }

        sort(all(v));

        int prev= 0;
        ranks[v[0]]= 0;
        fr1(v.size()-1){
            if(v[i]==v[i-1])
                continue;
            if(v[i]==v[i-1]+1)
                ranks[v[i]]= ++prev;
            else{
                prev+=2;
                ranks[v[i]]= prev;
            }
        }

        fr(n){
            ml[i]= ranks[l[i]];
            mr[i]= ranks[r[i]];
        }

        fr(n){
            //cout<<ml[i]<<" "<<mr[i]<<endl;
            update(1,0,maxn-1,ml[i],mr[i],i+1);
        }

        mark[0]= 1;

        int cnt= 0;

        fr(maxn){
            int q= query(1,0,maxn-1,i);
            //cout<<i<<": "<<q<<endl;
            if(!mark[q]){
                mark[q]= 1;
                cnt++;
            }
        }

        printf("Case %d: %d\n",o,cnt);
    }
}

/*
5
4
1 8 1 4 8 12 8 13
8
3 8
4 6
2 5
9 10
8 11
10 12
13 14
11 13
*/
