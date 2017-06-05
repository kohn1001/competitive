#include <cstdio>
#include <cstring>

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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

struct Trie
{
	int leaf, c[26];
} trie[1000010];

int n, sz;
ll res;

void insert(string str = string())
{
	int v = 0;
    if(str.empty()) {
        cin >> str;
    }
    for (auto &i : str) {
        int c = i - 'a';
		if(!trie[v].c[c]) {
			trie[v].c[c] = ++sz;
		}
		v = trie[v].c[c];
	}
	++trie[v].leaf;
}

bool search(string &str) {
    int v = 0;
    for (auto &i : str) {
        int c = i - 'a';
        if(!trie[v].c[c]) return false;
        v = trie[v].c[c];
    }
    return trie[v].leaf > 0;
}
void dfs(int v, int dep)
{
	res += (ll)dep * trie[v].leaf;
	int cnt = trie[v].leaf > 0;
    for(int i = 0; i < 26; ++i) {
        if(trie[v].c[i]) {
			++cnt;
        }
    }
    
    for(int i = 0; i < 26; ++i) {
        if(trie[v].c[i]) {
			dfs(trie[v].c[i], dep + (cnt > 1));
        }
    }
}

int main()
{
	while(cin >> n) {
        if(n == 0) return 0;
		memset(trie, 0, sizeof trie);
		sz = 0;
        res = 0;
        for(int i = 0; i < n; ++i) {
			insert();
        }
        for(int i = 0; i < 26; ++i) {
            if(trie[0].c[i]) {
				dfs(trie[0].c[i], 1);
            }
        }
		printf("%.2f\n", (double)res / n);
	}
    /*
    vector<string> keys = {"hello", "hell" , "eager"};
    string output[] = {"NO", "YES"};
    for(int i=0; i < keys.size(); ++i) {
        insert(keys[i]);
    }
    cout << "Is " << keys[1] << " " <<"inside: " << output[search(keys[1])] << endl;
     */
	return 0;
}
