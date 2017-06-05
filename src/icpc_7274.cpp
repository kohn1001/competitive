//
// 7274 - Canvas Painting - icpc uvalive 

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

int main()

{
	//while(scanf("%d%d%d%d",&A,&B,&E,&P)!=EOF) {
    int N, T;
    while(cin >> T) {
        for(int i=0; i < T; ++i) {
            priority_queue<ll , vector<ll>, greater<ll>> q;
            cin >> N;
    		for(int i=0; i < N; ++i) {
                ll v;
                cin >> v;
                q.push(v);
    		}
            ll sum = 0;
            while (q.size() >= 2) {
                auto first = q.top(); q.pop();
                auto second = q.top(); q.pop();
                sum += first + second;
                q.push(first+second);
            }
            cout << sum << endl;
    	}
    }
	//}
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
