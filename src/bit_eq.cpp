//
//  Created b Nathaniel Kohn ID: 036048817.
//  Created b Dror Shwimmer ID: .
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
#include <unordered_map>
#include <unordered_set>

/* My Templates for convenience */
#define INF 0x3f3f3f3f
#define rep(i, j, k) for(i = (int)j; i < (int)k; ++i)
#define nrep(i, j, k) for(int i = (int)j; i < (int)k; ++i)
#define sz(x) ( (int) x.size())
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define zero(x) memset((x), 0, sizeof((x)))
#define um unordered_map
#define us unordered_set
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

int main()
{
	map<int, int> m;
    int  C;
	string str;
    cin >> C;
    nrep(c, 0, C) {
        string S, T;
		cin >> S >> T; 
        int onesDiff = 0;
        int queMarkCnt=0;
      
        int opCnt = 0, chZeroToOneCnt = 0, chOneToZeroCnt =0;
        
        for (int s = 0;  s < S.size(); ++s) {
           if(S[s] == '?') {
                ++queMarkCnt;
            }
            if(S[s] == '?' && T[s] == '1') {
                ++onesDiff;
            }
            else if(S[s] == '1' && T[s] == '0') {
                ++chOneToZeroCnt;
                --onesDiff;
            }
            else if (S[s] == '0' && T[s] == '1') {
                ++chZeroToOneCnt;
                ++onesDiff;
            }
        }
        if (onesDiff < 0) {
            cout << "Case " << c+1 << ": " << -1 << endl;
        }
        else {
            opCnt = queMarkCnt + max(chZeroToOneCnt, chOneToZeroCnt);
            cout << "Case " << c+1 << ": " << opCnt  << endl;
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
