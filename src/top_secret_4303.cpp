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
#include <cmath>
#include <cstdio>
#include <cstring>


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



typedef long long P[1024];

long long mod[12];
long long MOD;

void debug(int n, const P p) {
    for (int i = 0; i < n; ++i) {
        printf("%lld%c", p[i], i == n - 1 ? '\n' : ' ');
    }
}


void mul(int n, const P a, const P b, P ret) {
    static P c;
    for (int i = 0; i < n; ++i) {
        c[i] = 0;
        for (int j = 0; j < n; ++j) {
            c[i] += a[j] * b[(i - j + n) % n];
        }
    }
    for (int i = 0; i < n; ++i) {
        ret[i] = c[i] % MOD;
    }
}

void pow(int n, P a, int b, P ret) {
    static P c;
    for (int i = 0; i < n; ++i) {
        c[i] = 0;
    }
    c[0] = 1;
    while (b > 0) {
        if ((b & 1) != 0) {
            mul(n, c, a, c);
        }
        mul(n, a, a, a);
        b >>= 1;
    }
    for (int i = 0; i < n; ++i) {
        ret[i] = c[i] % MOD;
    }
}

int main() {
    int re;
    int n, s, l, r, m;
    long long ans;
    P p, v;
    
    mod[0] = 1;
    for (int i = 1; i < 12; ++i) {
        mod[i] = mod[i - 1] * 10;
    }
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%d%d%d", &n, &s, &l, &r, &m);
        MOD = mod[m];
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &v[i]);
            v[i] %= MOD;
        }
        for (int i = 0; i < n; ++i) {
            p[i] = 0;
        }
        p[0] = 1 % MOD;
        p[n - 1] += l % MOD;
        p[1] += r % MOD;
        pow(n, p, s, p);
        // debug(n, p);
        for (int i = 0; i < n; ++i) {
            ans = 0;
            for (int j = 0; j < n; ++j) {
                ans += p[(j - i + n) % n] * v[j];
            }
            printf("%lld%c", ans % MOD, i == n - 1 ? '\n' : ' ');
        }
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
