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
#include <deque>
#include <set>
#include <sstream>
#include <memory>
#include <algorithm>
#include <memory>
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <limits>

using namespace std;

/* My Templates for convenience */
#define rep(i, j, k) for(int i = (int)j; i < (int)k; ++i)
#define sz(x) ( (int) x.size())
#define mp std::make_pair
#define eb emplace_back
#define fi first
#define se second
#define zero(x) memset((x), 0, sizeof((x)))
const int MAX_INT = numeric_limits<int>::max();

using ll = long long;
using ull = unsigned long long;
using ii = pair<int ,int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using seii = set<ii>;
using stii = stack<ii>;

/* Global Variables */
int n, m, res;
/* ============= */


void bfs (int src, vector<vi> &adjList) {
    vi ring_dist(adjList.size(), -1);
    queue<ii> q;
    q.push(mp(src, -1));
    ring_dist[src] = 0;
    
    while (!q.empty()) {
        auto u = q.front().first;
        auto p = q.front().second;
        q.pop();
        for (int i=0; i < adjList[u].size(); ++i) {
            int v = adjList[u][i];
            if (v != p ) {
                if (ring_dist[v] == -1) {
                    ring_dist[v] = ring_dist[u] + 1;
                    q.push(mp(v, u));
                } else {
                    res = min(res, ring_dist[u] + ring_dist[v] + 1);
                }
            }
        }
    }
    
}


int main () {
    /* Optimized I/O  saves roughly ~200ms on submission */
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t=1; t <= T; ++t) {
        cin >> n >> m;
        vector<vi> adjList(n);
        
        for (int i=0; i < m; ++i) {
            int from, to;
            cin >> from >> to;
            adjList[from].eb(to);
            adjList[to].eb(from);
        }
        
        res = MAX_INT;
        for (int i=0; i < n; ++i) {
            bfs (i, adjList);
        }
        cout << "Case " << t << ": ";
        if (res == MAX_INT) {
            cout << "impossible" << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}
