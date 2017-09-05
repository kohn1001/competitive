//
//
//
// check all possible breaks of a number (permutations) for primes



/*
ICPC problem - very very interesting :) 

Here is the problem statement :
Direct Link to it:
https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2610


Industrial spying is very common for modern research labs. I am such an industrial spy - dont tell
anybody! My recent job was to steal the latest inventions from a famous math research lab. It was
hard to obtain some of their results but I got their waste out of a document shredder.
I have already reconstructed that their research topic is fast factorization. But the remaining paper
snippets only have single digits on it and I cannot imagine what they are for. Could it be that those
digits form prime numbers? Please help me to find out how many prime numbers can be formed using
the given digits.
Input
The first line of the input holds the number of test cases c (1 ≤ c ≤ 200). Each test case consists of a
single line. This line contains the digits (at least one, at most seven) that are on the paper snippets.
Output

=====>>>>>
For each test case, print one line containing the number of different primes that can be reconstructed
by shuffling the digits. You may ignore digits while reconstructing the primes (e.g., if you get the digits
7 and 1, you can reconstruct three primes 7, 17, and 71). Reconstructed numbers that (regarded as
strings) differ just by leading zeros, are considered identical (see the fourth case of the sample input).
Sample Input
4
17
1276543
9999999
011
Sample Output
3
1336
0
2



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




