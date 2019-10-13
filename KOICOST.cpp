#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define F            first
#define S            second
#define pb(x)        push_back(x)
#define mp(a,b)      make_pair(a,b)
#define mt(a,b,c)    make_tuple(a,b,c)
#define sz           size()
#define all(A)       A.begin(), A.end()
#define mem(a, b)    memset(a, b, sizeof(a))   // all elements of A are b=0 or b=-1 else don't work
#define f0(i,b)      for(ll i=0;i<(b);i++)
#define f1(i,b)      for(ll i=1;i<=(b);i++)
#define f2(i,a,b)    for(ll i=(a);i<=(b);i++)
#define f3(i,b,a)    for(ll i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(ll i=(a);i!=(b);i+=(c))

#define mod          1000000000
#define PI           acos(-1.0)
#define MAX3(a,b,c)  max(a,max(b,c))

#define whilee(i,t)  while(i!=t)
#define  sl(a)       scanf("%lld",&a)
#define  pl(a)       printf("%lld\n",a)

//x = 1e18 means 10^18
//for(auto it =A.begin(); it!=A.end(); it++)
//sort(A.begin(),A.end()); //sort(A, +n, greater<int>());
//binary_search(A.begin(),A.end(),x);
//reverse(A.begin(), A.end());
//cout << *max_element(A.begin(), A.end());
//cout << *min_element(A.begin(), A.end());
//count(A.begin(), A.end(), X); //counts the occurrences of X
//distance(A.begin(),A.end());  //distance between first to last element
//accumulate(A.begin(), A.end(), 0); //add
//next_permutation(A.begin(), A.end());
//prev_permutation(A.begin(), A.end());
//swap(S[0], T[0]);

//scanf("%lld",&x);
//printf("%lld\n",x);
//printf("%I64d\n", a);
//while (scanf("%lld %lld", &a, &b) == 2)
//printf("Case %lld: %lld\n", t++, a);

//vector <ll> A;
//deque <ll> A;
//queue <ll> A;
//stack <ll> A;
//list <int> A;
//set <ll> A;
//map <ll,ll> A;
//unordered_map <ll, ll> A;
//pair <ll,ll> A ;
//tuple <ll, ll, ll> A;
vector <pair <ll,ll>> A[200005];
//bitset<32> bset1;
//bool ok = true;
//char ch;
//string S, T, U;

ll parent[200005], Size[200005];

void makeSet(ll x)
{
    parent[x] = x;
    Size[x] = 1;
}

ll Find(ll x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(ll a, ll b)
{
    ll x = Find(a);
    ll y = Find(b);

    if(Size[x] > Size[y])
    {
        parent[y] = x;
        Size[x] += Size[y];
    }
    else
    {
        parent[x] = y;
        Size[y] += Size[x];
    }
}

ll i=0, j=0, k=0, a, b, c, d, e, f, g, h, l, m, n, o, p, q, r, s, t=0, u, v, w, x, y, z, maxx=INT_MIN, minn=INT_MAX, ans=0, sum=0, cnt=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);//NULL
    cout.tie(nullptr);//NULL

    for (int i=1; i <=200000; i++)
    {
        makeSet(i);
    }
    cin>>n>>m;

    f0(i,m)
    {
        cin>>x>>y>>w;
        A[w].pb(mp(x,y));
        A[w].pb(mp(y,x));
        maxx = max(maxx, w);
    }

    f3(i,maxx,1)
    {
        cnt = A[i].sz;
        if(cnt>0)
        {
            u = A[i][0].F;
            v = A[i][0].S;

            p = Find(u);
            q = Find(v);
            if(p!=q)
            {
                ans = (ans%mod + (((Size[p]*Size[q])+ t)*i)%mod)%mod;
                t = ((Size[p]*Size[q])%mod + t%mod)%mod;
                Union(u,v);
            }
            else
            {
                ans += (t*i)%mod;
                ans%=mod;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
