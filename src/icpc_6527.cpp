//
//
//  Created by Nathaniel Kohn on 11 M 2017.
//
/*
 *
 *		6527 counting ones icpc - uvalive
 */
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
const int ones_lim = 1 << 16;
const int MapSize = 256;

vi ones_cnt_map (MapSize, 0);
/*

int count(ll in) {
	int res = 0;
	for (; in; in >>= 1) {
		if (in & 1) {
			++res;
		}
	}
	return res;
}
*/
ll res;
vi number_in_binary;
void count_ones(int pos, int onesSoFar) {
    if (pos == 0)
        return ;
    if (number_in_binary[pos-1] == 1) {
        res += (pos-1) * (1ll<< (pos-2));
        res += onesSoFar * (1ll << (pos-1));
    }
    count_ones(pos-1, onesSoFar+number_in_binary[pos-1]);
}
ll count(ll x) {
    if (x == 0)
        return 0;
    number_in_binary.clear();
    res = 0;
    while (x>0) {
        number_in_binary.eb(x%2);
        x /= 2;
    }
    for (int i = 0; i < (int)number_in_binary.size(); ++i)
        res += number_in_binary[i];
    count_ones((int)number_in_binary.size(), 0);
    return res;
}


int main()
{
	ull a, b;
	//cin >> a >> b;
	//ll res = count_ones_in_range(a,b);
	//
	//count_ones_in_range(2,12);
	while(cin >> a) {
		cin >>  b;
		if (a == 0 && b == 0) return 0;
		cout << count(b) - count(a-1) << endl;
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
