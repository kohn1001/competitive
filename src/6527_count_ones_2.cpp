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

ull getOnesInNum(ll num, int numOfBytes)
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
	//	cout << "tbuff[" << k << "]" << " " << (ull)tbuff[k] << " " << endl;
		sum += ones_cnt_map[(ull)tbuff[k]];
	}
	//cout << "sum is: " << sum << " " << endl;
	return sum;
}
/*
ll count_ones_in_range(ll a, ll b)
{
	ll sum = 0;
	cout << "a is: " << a << " " << "b is: " << b << endl;
	for (ll i = a; i <=b ; ++i) {
		sum += count(i);;
		cout << " sum is: " << sum << " " << endl;
	}
	return sum;
}
*/

/*
ll countOnes(ll a, ll b)
{
	ll res = 0;
	static bool firstTime = true;

	if (firstTime) {
		firstTime = false;
		buildOnesMat();	
		return count_ones_in_range(a,b);
	}
	return 0;
}
*/
ll calcInRange(ll a, ll b)
{
	a--;
	ll sum1=0,sum2=0;
	ll n=a;
	ll i=0;
	while(n)
	{
		i++;
		ll po=(ll)pow(2,i);
		ll po2=(ll)pow(2,i-1);
		ll moo=a%po;
		if(moo>=po/2) {
			int r = po*po2;
			int ar = a/r;
			int arr = a/po*po2;
			sum1+=a/po*po2+moo-(po2-1);
		}
		else { 
			sum1+=a/po*po2;
		}
		n/=2;
	}
	n=b;
	i=0;
	while(n)
	{
		i++;
		ll po=(ll)pow(2,i);
		ll po2=(ll)pow(2,i-1);
		ll moo=b%po;
		if(moo>=po/2)
			sum2+=b/po*po2+moo-(po2-1);
		else sum2+=b/po*po2;
		n/=2;
	}
	cout<<sum2-sum1<<endl;  
	return sum2-sum1;
}
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
ll calc(ll x) {
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
