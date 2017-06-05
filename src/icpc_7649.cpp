/* Performance review 7649 13164 uvalive - icpc */ 
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <sstream>
#include <memory>
#include <algorithm>
#include <memory>
#include <iomanip>
#include <cmath>
#include <string.h>


/* My Templates for convenience */
#define INF 0x3f3f3f3f
#define rep(i, j, k) for(int i = (int)j; i < (int)k; ++i)
#define sz(x) ( (int) x.size())
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define zero(x) memset((x), 0, sizeof((x)))
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int ,int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using seii = set<ii>;
using stii = stack<ii>;
using StrSet = set<string>;
using vs = vector<string>;


ll n;
ll par[1000010];
ll discovTime[1000010];
ll finishTime[1000010];
ll edgeNum=0;
ll dfsNum=0;
ll mgmtLevel[1000010];
map<ll,ll>visited;

struct Node
{
    ll par;
    ll to;
}N[4*1000010];

struct Emp
{
    ll time;
    ll techLevel;
    ll id;
}E[1000010],EE[1000010];

ll segTree[1000010];

bool cmp(const Emp& a, const Emp& b)
{
    if (a.techLevel < b.techLevel) {
        return true;
    }
    else {
        if (a.techLevel == b.techLevel) {
            return mgmtLevel[discovTime[a.id]] <= mgmtLevel[discovTime[b.id]];
        }
    }
    return false;
}

void add(ll from,ll to)
{
    ++edgeNum;
    N[edgeNum].to=to;
    N[edgeNum].par=par[from];
    par[from]=edgeNum;
}

void dfs(ll node,ll depth)
{
    discovTime[node]=++dfsNum;
    EE[dfsNum]=E[node];
    mgmtLevel[dfsNum]=depth;
    visited[node]=1;
    
    for (ll i=par[node]; i; i=N[i].par) {
        if (visited[N[i].to]) {
            continue;
        }
        dfs(N[i].to,depth+1);
    }
    finishTime[node]=dfsNum;
}

/* standards API of segement tree  - Add and Query*/

void add2SegTree(ll p, ll time) {
    for ( segTree[p += n] = time; p > 1; p >>= 1) {
        segTree[p>>1] = segTree[p] + segTree[p^1];
    }
}

ll query(ll l, ll r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += segTree[l++];
        if (r&1) res += segTree[--r];
    }
    return res;
}

int main()
{
    cin >> n;
    /* init */
    memset(segTree,0,sizeof(segTree));
    memset(par,0,sizeof(par));
    edgeNum = 0;
    ll director = 0;
    
    for (ll i=1;i<=n;i++) {
        ll m,tec,time;
        cin >> m >> tec >> time;
        E[i].time = time;
        E[i].techLevel = tec;
        E[i].id = i;
        if (m ==-1) {
            director = i;
            continue;
        }
        add(m, i);
        add(i, m);
    }
    
    dfs(director,1);
    ll res[1000010];
    sort(EE+1,EE+1+n,cmp);
    
    for (ll i=1; i<=n; ++i) {
        ll l,r;
        l = discovTime[EE[i].id];
        r = finishTime[EE[i].id];
        
        res[EE[i].id] = query(l, r+1);
        add2SegTree(l,EE[i].time);
    }
    
    for (ll i=1; i <= n; ++i) {
        cout << res[i] << endl;
    }
    
    return 0;
}
