//
//
//Natty Kohn 036048817
//Dror Shwimmer 066138926 
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
#define SIZE 10000000
bool primeTab[SIZE] = {true};

int getNumsFromPerm(string perm)
{
//    cout << perm << " " << endl;
    return stoi(perm);
}

vector<bool> exist(SIZE, false);

bool checkIfPrime(ll n)
{
    if(n < 2) {return false;}
//    if(!exist[n] && primeTab[n]) {
    if (primeTab[n] && !exist[n]) {
        exist[n] = true;
        return true;
    }
    return false;
}

void markAll(ll k)
{
    for(ll i=k*k; i < SIZE; i += k)   {
        primeTab[i] = false;
    }
}
void createTab()
{
    static bool firstTime = true;
    if(!firstTime) return;
    for (int i=2; i < SIZE; ++i) {
        if(primeTab[i]) {
           // primeTab[i] = true;
            markAll(i);
        }
    }
}

ll findPrimes(string s)
{
    ll res=0, cnt=0;
    sort(s.begin(), s.end());
    do {
//        cout << s.size() << " " << endl;
        for(int i=1; i <= s.size(); ++i) {
            res = getNumsFromPerm(s.substr(0, i));
            if(checkIfPrime(res)) {
                cout << "is prime " << endl;
                ++cnt;
            }
        }
        
    }while(next_permutation(s.begin(), s.end()));
    return  cnt;
}
/*
int main()
{
	//while(scanf("%d%d%d%d",&A,&B,&E,&P)!=EOF) {
    for(int i=0; i< SIZE; ++i) {
        primeTab[i] = true;
    }
    createTab();
    ll T;
    cin >> T;
	rep(i, 0, T) {
        for (int i=0; i < SIZE; ++i) {
            exist[i] = false;
//            primeTab[i] = true;
        }
        
        string s;
        cin >> s;
        cout << findPrimes(s) << endl;
	}
	//} 
    return 0;
}
*/




