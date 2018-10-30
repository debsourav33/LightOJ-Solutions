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

const int maxn= 32;

string s1, s2;
string dp[maxn][maxn];
i64 dp2[maxn][maxn][2*maxn];
int n;

string call(int p1, int p2){
    if(p2==s2.length())  return s1.substr(p1,s1.length()-p1);
    if(p1==s1.length())  return s2.substr(p2,s2.length()-p2);

    string &ret= dp[p1][p2];
    if(ret!="")  return ret;

    if(s1[p1]==s2[p2])
        return s1[p1]+ call(p1+1,p2+1);

    string opt1, opt2;

    opt1= s1[p1]+ call(p1+1,p2);
    opt2= s2[p2]+ call(p1,p2+1);

    if(opt1.length()<opt2.length())  return ret= opt1;
    else  return ret= opt2;
}

i64 call2(int p1, int p2, int n){
    if(p1==s1.length() && p2==s2.length())  return n==0? 1 : 0;
    if(n<=0)  return 0;

    i64 &ret= dp2[p1][p2][n];
    if(ret!=-1)  return ret;

    i64 opt1= 0, opt2= 0;

    if(p1<s1.length() && p2<s2.length() && s1[p1]==s2[p2])  return ret= call2(p1+1, p2+1, n-1);

    if(p1<s1.length())  opt1= call2(p1+1,p2,n-1);
    if(p2<s2.length()) opt2= call2(p1,p2+1,n-1);

    return ret= opt1+opt2;
}


void initdp(){
    fr(maxn)
        for(int j=0;j<maxn;j++)
            dp[i][j]="";
}

main(){
    int opt, o=1;
    cin>>opt;
    while(o<=opt){
        initdp();
        sets(dp2);

        cin>>s1>>s2;

        i64 ans= call(0,0).length();
        cout<<"Case "<<o++<<": "<<ans<<" "<<call2(0,0,ans)<<endl;
    }
}
