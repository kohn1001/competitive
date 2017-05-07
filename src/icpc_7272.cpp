//
//
//  Created by Nathaniel Kohn on 11 M 2017.
//  Copyright © 2017 Nathaniel Kohn. All rights reserved.
//

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


void addEdge(vector<vi> &adjl, int from, int to)
{
    adjl[from].eb(to);
}

static int dfs(int s, vector<vi> &adj)
{
    stack<int> q;
    q.push(s);
    vi visited(adj.size(), 0);
    visited[s] = 1;
    while (!q.empty()) {
        auto curr = q.top(); q.pop();
        for (auto &n : adj[curr]) {
            if(!visited[n]) {
            //cout << "neig is: " << n << endl;
                visited[n] = 1;
                q.push(n);
            }
        }
    }
    int res = 0;
    for (auto &i: visited) {
        if(i) {
            ++res;
        }
    }
    return res;
}

int main()

{
    int A, B, P, E;
    while(scanf("%d%d%d%d",&A,&B,&E,&P)!=EOF) {
        vi mustPromot(E, 0);
        vi notPromot(E, 0);
        vector<vi> adjList(E);
        vector<vi> backAdjList(E);
        //adjList.resize(P);
        //backAdjList.resize(P);
        int from, to;
        for (auto i=0; i < P; ++i) {
            cin >> from >> to;
            addEdge(adjList, from, to);
            addEdge(backAdjList, to, from);
    	}
        for (auto i=0; i<E; ++i) {
            mustPromot[i] = E - dfs(i, adjList) + 1;
            notPromot[i] = dfs(i, backAdjList) -1;
        }
        int mustBpromotedA = 0, mustBpromotedB =0, notPromotedNum=0;
        for (int i=0; i < E; ++i) {
            if (mustPromot[i] <= A) {
                ++mustBpromotedA;
            }
            if (mustPromot[i] <= B) {
                ++mustBpromotedB;
            }
            if (notPromot[i] >= B) {
                ++notPromotedNum;
            }
        }
        cout << mustBpromotedA <<  endl;
        cout << mustBpromotedB <<  endl;
        cout << notPromotedNum <<  endl;
    }
    return 0;
}







#ifdef DEGBUG
    /*
    int N; int T;
    cin >> T;
    rep(i, 0, T) {
        vii v;
        cin >> N;
       int M;
        cin >> M; set<string> fs;
        for (int i = 0; i < N; ++i) {
            string name;
//            while(getline(cin, name) && name.empty());
           //        reverseStr(s) ;
        }
//        printFs(fs);
        
        rep(i, 0, M) {
            string dir;
            while(getline(cin, dir) && dir.empty());
//            ll num = getCommNum(fs, dir);
//            cout << "Case #" << i+1 << ": " << num << endl;
        }
    }
    
    //    cout << "the sum: " << sum << endl;
    // cout << "the sum: " << sum << endl;
   */

#endif
