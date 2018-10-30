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

int lazy[4*maxn], army_at[4*maxn], a[maxn], n;

void build(int at, int l, int r){
    if(l==r){
        army_at[at]= l;
        return;
    }

        mid= (l+r)/2;

    build(lefts,l,mid);
    build(rights,mid+1,r);
}

void insert(int at, int l, int r, int pos){
    if(l==r){
        army_at[at]= pos;
        return;
    }

    int mid= (l+r)/2;

    if(pos<=mid)  insert(lefts,l,mid,pos);
    else  insert(rights,mid+1,r,pos);
}

void upd(int at, int x){
    lazy[at]+= x;

    army_at[at]+= x;
}

void propagate(int at){
    upd(lefts, lazy[at]);
    upd(rights, lazy[at]);

    lazy[at]= 0;
}

void update(int at, int l, int r, int x, int y){
    if(x<=l && r<=y){
        lazy[at]++;
        army_at[at]++;
        return;
    }

    if(x>r || y<l)  return;

    if(lazy[at]) propagate(at);
    int mid= (l+r)/2;

    update(lefts,l,mid,x,y);
    update(rights,mid+1,r,x,y);
}

int query(int at, int l, int r, int pos){
    if(l==r)  return army_at[at];

    if(lazy[at]) propagate(at);
    int mid= (l+r)/2;

    if(pos<=mid)  return query(lefts,l,mid,pos);
    else  return query(rights,mid+1,r,pos);
}

void reset(){
    clr(lazy);
}

main(){
    //fastIO();

    int t, q, x, y;
    char opt;
    si(t);

    for(int o=1;o<=t;o++){
        reset();

        cin>>n>>q;
        fr(n)
            cin>>a[i];

        build(1,0,maxn-1);

        //printf("Case %d:\n",o);
        cout<<"Case "<<o<<":"<<endl;

        while(q--){
            cin>>opt;

            if(opt=='C'){
                cin>>x;
                int ans= query(1, 0, maxn-1, x-1);
                ans= query(1, 0, maxn-1, ans);

                update(1,0,maxn-1,x-1,maxn-1);
                cout<<a[ans]<<endl;
            }
            else{
                cin>>x;
                a[n]= x;
                insert(1,0,maxn-1,n);
                n++;
            }
        }
    }
}

/*
2
5 5
6 5 3 2 1
C 2
C 1
C 1
*/
