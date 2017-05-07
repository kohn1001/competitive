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
using seii = set<ii>;
using stii = stack<ii>;
using StrSet = set<string>;
using vs = vector<string>;
#ifdef DBG
int main()
{
    priority_queue<int> q;
    int Z, N, M;//, K;
    cin >> Z;
    for(int i=0; i < Z; ++i) {
        cin >> N >> M;
    	vector<int> v;
        for(int j = 0; j < M; ++j) {
            int t;
            cin >> t;
            v.eb(t);
        }
        set<ii>  zeroInd;
		int zeros = 0;
		bool noSol = false;
		vector<int> ans(M);
		vector<int> last(N+10, -1);
        for (int i=0; i < M; ++i) {
            if(v[i] == 0 ) {
				ans[zeros] = 0;
                zeroInd.emplace(mp(i, zeros));
				++zeros;
            }
			else {
				auto toDrink = zeroInd.lower_bound(mp(last[v[i]], 0));
				if (toDrink == zeroInd.end()) {
					noSol = true;
					break;
				}
				else {
					ans[toDrink->second] = v[i];	
					last[v[i]] = i;
                    zeroInd.erase(toDrink);
				}
			}
        }
		if (noSol) {
			cout << "NO" << endl;
			continue;
		}

		  cout << "YES" << endl;
		  for (int i = 0; i < zeros; ++i) {
			if (i) cout << " ";
			cout << ans[i];
		  }
		  cout << endl;
	}
    return 0;
}

#endif

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
