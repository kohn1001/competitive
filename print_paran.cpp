//
//
//  Created b Nathaniel Kohn on 11 M 2017.
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
#define rep(i, j, k) for(int i = (int)j; i < (int)k; ++i)
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

void print_paran(string str, int l, int r, int n) 
{
	if(l < r) { return ; }
	if(str.size() == n) {
		cout << str << endl;
	}
	if(l < 3) {
		print_paran(str+'(', l+1, r, n);
	}
	if(r < 3) {
		print_paran(str+')', l, r+1, n);
	}

}

int main()

{
	map<int, int> m;
	int N, T, K;
	int nx, ny;
	string str;
	print_paran(str, 0, 0, 6);



#ifdef DEBUG
	while (cin >> nx) {
		cin >> ny >> w;
		if( nx == 0 && ny == 0 && w == 0.0) {
			break;
		}
		vector<float> vecfx(nx);
		vector<float> vecfy(ny);
//		um<float> seq;
		float gmaxx = 75, gmaxy = 100;

		rep(j, 0, nx) {
			cin >> vecfx[j];
		//	xs.emplace(cin.get());
			//cout << "This is x: " << x << " " << endl;
		}
		rep(j, 0, ny) {
			cin >> vecfy[j];
			//cout << "This is y: " << y << " " << endl;
		}
		sort(vecfx.begin(), vecfx.end());
		sort(vecfy.begin(), vecfy.end());
		/*for (auto &i : vecfx) {
			cout << "ix: " << i << " " << endl;
		}
		for (auto &i : vecfy) {
			cout << "iy: " << i << " " << endl;
		}
		*/
		if (vecfx[0] > (w/2) || vecfy[0] > (w/2)) {
			cout <<"NO" << endl;
			continue;
		}
		if (vecfy[ny-1] + w/2 < gmaxy || vecfx[nx-1] + w/2 < gmaxx) {
			cout << "NO" << endl;
			continue;
		}
		int i;	
		for ( i = 1; i < vecfx.size(); ++i) {
			if(vecfx[i] - vecfx[i-1] > w) {
				cout << "NO" << endl;
				break;
			}
		}
		if (i !=  vecfx.size()) {
			continue;
		}
		for (i = 1; i < vecfy.size(); ++i) {
			if(vecfy[i] - vecfy[i-1] > w) {
				cout << "NO" << endl;	
				break;
			}
		}
		if (i != vecfy.size()) {
			continue;
		}
		cout << "YES" << endl;
	}
#endif
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
