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

#define left 2*at
#define right 2*at+1

int toggle[400005], on[400005], n;
char s[100005];

void marge(int at){
    on[at]= on[left]+ on[right];
}

void build(int at, int l, int r){
    if(l==r){
        toggle[at]= 0;
        on[at]= s[l]- '0';
        return;
    }

    int mid= (l+r)/2;

    build(left,l,mid);
    build(right,mid+1,r);
    marge(at);
}

void propagate(int at, int l, int r){
    int mid= (l+r)/2;
    int left_l= l, left_r= mid, right_l= mid+1, right_r= r;

    toggle[at]= 0;
    toggle[left]^= 1;
    toggle[right]^= 1;

    on[left]= left_r-left_l+1-on[left];
    on[right]= right_r-right_l+1-on[right];
}

void update(int at, int l, int r, int x, int y){
    if(x<=l && r<=y){
        toggle[at]^= 1;
        on[at]= r-l+1-on[at];
        return;
    }

    if(x>r || y<l)  return;

    if(toggle[at]) propagate(at,l,r);

    int mid= (l+r)/2;

    update(left,l,mid,x,y);
    update(right,mid+1,r,x,y);
    marge(at);
}

int query(int at, int l, int r, int x, int y){
    if(x<=l && r<=y)  return on[at];
    if(x>r || y<l)  return 0;

    if(toggle[at]) propagate(at,l,r);

    int mid= (l+r)/2;
    int a= query(left,l,mid,x,y);
    int b= query(right,mid+1,r,x,y);

    return a+b;
}

main(){
    int no;
    si(no);

    fr1(no){
        clr(toggle);
        clr(on);

        scanf("%s",s);
        n=strlen(s);

        int q, x, y;
        char opt;
        si(q);

        build(1,0,n-1);

        printf("Case %d:\n",i);

        while(q--){
            scanf("\n%c",&opt);

            if(opt=='Q'){
                si(x);
                i64 ans= query(1, 0, n-1, x-1, x-1);
                printf("%lld\n",ans);
            }
            else{
                sii(x,y);
                update(1,0,n-1,x-1,y-1);
            }
        }
    }
}
