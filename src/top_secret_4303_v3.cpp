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

long long MOD;


void mul(int n, vector<ll> &va, vector<ll> &vb, vector<ll> &res) {
    static vector<ll> vc(1024);
    for (int i = 0; i < n; ++i) {
        vc[i] = 0;
        for (int j = 0; j < n; ++j) {
            vc[i] += va[j] * vb[(i - j + n) % n];
        }
    }
    for (int i = 0; i < n; ++i) {
        res[i] = vc[i] % MOD;
    }
}

void pow(int n, vector<ll> &va, int s, vector<ll> & res) {
    static vector<ll> vc(1024);
    fill(vc.begin(), vc.end(), 0);
    
    vc[0] = 1;
    for (; s; s >>= 1 ) {
        if ((s & 1) != 0) {
            mul(n, vc, va, vc);
        }
        mul(n, va, va, va);
    }
    for (int i = 0; i < n; ++i) {
        res[i] = vc[i] % MOD;
    }
}


int main() {
    int T, n, s, l, r, x;
    long long res;
    vector<ll> prod(1000), v(1000);
    
    ll modu[10];
    modu[0] = 1;
    for (int i = 1; i < 10; ++i) {
        modu[i] = modu[i - 1] * 10;
    }
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        cin >> n >> s >> l >> r >> x;
        
        MOD = modu[x];
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            v[i] %= MOD;
        }
        
        fill(prod.begin(), prod.end(), 0);
        
        prod[0] = 1;
        prod[n - 1] += l % MOD;
        prod[1] += r % MOD;
        pow(n, prod, s, prod);
        
        for (int i = 0; i < n; ++i) {
            res = 0;
            for (int j = 0; j < n; ++j) {
                res += prod[(j - i + n) % n] * v[j];
            }
            if (i == n-1) {
                cout << res % MOD << endl;
            }
            else {
                cout << res % MOD << " " ;
            }
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
