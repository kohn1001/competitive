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
const int ones_lim = 1 << 16;
const int MapSize = 256;

vi ones_cnt_map (MapSize, 0);


int count(ll in) {
	int res = 0;
	for (; in; in >>= 1) {
		if (in & 1) {
			++res;
		}
	}
	return res;
}

void buildOnesMat()
{
	for (int i=0; i <  MapSize; ++i) {
		ones_cnt_map[i] = count(i);
	}
}

ull getOnesInNum(ull num, int numOfBytes)
{
	//int res = count(num);
	static bool needToInitMap = true;
	//cout << "size of bytes: " << numOfBytes << " " << endl;
	if(needToInitMap) { 
		buildOnesMat();
		needToInitMap = false;
	}
	//cout << "res is: " << res << endl;
	ull sum = 0;
	unsigned char *tbuff = (unsigned char *)&num;
	for (int k = 0 ; k < numOfBytes; ++k) {
		cout << "tbuff[" << k << "]" << " " << (ull)tbuff[k] << " " << endl;
        int n = tbuff[k];
//		sum += ones_cnt_map[(ull)tbuff[k]];
        int ones = ones_cnt_map[n];
//		sum += ones_cnt_map[n];
		sum += ones;
	}
	//cout << "sum is: " << sum << " " << endl;
	return sum;
}

ull calcInRange(ll a, ll b)
{
//    for (ll k=0; k <= a; ++k) {
//	}
	ull res2=0;
	for (ll k=a; k <= b; ++k) {
		res2 += getOnesInNum(k, sizeof(ll));
	}

    return res2;
}

int main()
{

	
	cout << endl;
	ull a, b;
	//cin >> a >> b;
	//ll res = count_ones_in_range(a,b);
	//
	//count_ones_in_range(2,12);
	cin >> a >> b;
    cout << "a is: " << a << " b is: " << b << endl;
	cout << "in range: " << calcInRange(a,b) << endl;
//	testMap(a, sizeof(ll));
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
