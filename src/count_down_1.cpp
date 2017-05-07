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
const long long MAX_LL = numeric_limits<long long>::max();

using ll = long long;
using ull = unsigned long long;
using ii = pair<int ,int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using seii = set<ii>;
using stii = stack<ii>;

const string Operation = "+-*/";
const int N = (1 << 6) + 10;

struct Node {
    ll _sum ,_v1, _v2;
    int _s1, _s2, _op;
    Node() {}
    Node(ll sum, int s1, int s2, ll v1, ll v2, int op) {
        _sum = sum;
        _s1 = s1;
        _s2 = s2;
        _v1 = v1;
        _v2 = v2;
        _op = op;
    }
} ;
vector<Node> res[N];

void init() {
    ll val;
    for (int i = 0; i < N; i++) res[i].clear();
    Node t_node;
    for (int i = 0; i < 6; i++) {
        cin >> val;
        t_node = Node(val, 0, 0, 0, 0, -1);
        res[1 << i].push_back(t_node);
    }
}

void calc() {
    int end = 1 << 6;
//    int sum = 0;
    Node t_node;
    set<int> exist;
    for (int i = 0; i < end; i++) {
        exist.clear();
        for (int t = i & (i - 1); t > 0; t = i & (t - 1)) {
            int op = i ^ t, szt = res[t].size(), szop = res[op].size();
            for (int ii = 0; ii < szt; ii++) {
                for (int jj = 0; jj < szop; jj++) {
                    t_node = Node(res[t][ii]._sum + res[op][jj]._sum, t, op, res[t][ii]._sum, res[op][jj]._sum, 0);
                    if (t_node._sum > 0 && exist.find(t_node._sum) == exist.end()) res[i].push_back(t_node), exist.insert(t_node._sum);
                    t_node = Node(res[t][ii]._sum - res[op][jj]._sum, t, op, res[t][ii]._sum, res[op][jj]._sum, 1);
                    if (t_node._sum > 0 && exist.find(t_node._sum) == exist.end()) res[i].push_back(t_node), exist.insert(t_node._sum);
                    t_node = Node(res[t][ii]._sum * res[op][jj]._sum, t, op, res[t][ii]._sum, res[op][jj]._sum, 2);
                    if (t_node._sum > 0 && exist.find(t_node._sum) == exist.end()) res[i].push_back(t_node), exist.insert(t_node._sum);
                    if ((res[op][jj]._sum != 0) && (res[t][ii]._sum % res[op][jj]._sum == 0)) {
                        t_node = Node(res[t][ii]._sum / res[op][jj]._sum, t, op, res[t][ii]._sum, res[op][jj]._sum, 3);
                        if (t_node._sum > 0 && exist.find(t_node._sum) == exist.end()) res[i].push_back(t_node), exist.insert(t_node._sum);
                    }
                }
            }
        }
    }
}

void dfs(int id, ll val) {
    int szid = res[id].size();
    for (int i = 0; i < szid; i++) {
        if (res[id][i]._sum == val) {
            if (res[id][i]._op == -1) return ;
            dfs(res[id][i]._s1, res[id][i]._v1);
            dfs(res[id][i]._s2, res[id][i]._v2);
            cout << res[id][i]._v1 << ' ' << Operation[res[id][i]._op] << ' ' << res[id][i]._v2 << " = " << val << endl;
            return ;
        }
    }
}

void print_res(int target) {
    cout << "Target: " << target << endl;
    ll mn = MAX_LL;
    int end = 1 << 6, mk;
    for (int i = 0; i < end; i++) {
        int szi = res[i].size();
        for (int j = 0; j < szi; j++) {
            if (abs(mn - target) > abs(res[i][j]._sum - target)) {
                mn = res[i][j]._sum;
                mk = i;
            }
       }
    }
    dfs(mk, mn);
    cout << "Best approx: " << mn << endl << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    int T, target;
    cin >> T;
    while (T--) {
        init();
        cin >> target;
        calc();
        print_res(target);
    }
    return 0;
}
