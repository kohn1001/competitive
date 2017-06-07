//
//
//  Created by Nathaniel Kohn on 11 M 2017.
//  4944 - Fair Division uvalive icpc
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
#include <list>

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

struct  Member{
    int money;
    int index;
    int amount_paid;
    Member(int money, int index) : money(money), index(index), amount_paid(0) {}
} ;
const int N = 101;
Member* members[N];
list<Member*> current;
bool cmp (const Member *a, const Member *b) {
    if (a->money == b->money) {
        return b->index < a->index;
    }
    return a->money < b->money;
}
void clean()
{
}

int main()

{
    int T;
    //while(cin >> T) {
    cin >> T;
    for (int t = 0; t < T; ++t) {
        current.clear();
		clean();
        int n, P;
        cin >> P >> n;
        int sum = 0;
		for(int i=0; i < n; ++i) {
            int val;
            cin >> val;
            sum += val;
            members[i] = new Member(val, i);
            current.push_back(members[i]);
		}
        current.sort(cmp);
        if (sum < P) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        while (true) {
            int mid = P/current.size();
            if (mid > current.front()->money) {
                P -= current.front()->money;
                current.front()->amount_paid = current.front()->money;
                current.pop_front();
                continue;
            }
            for (list<Member*>::iterator i = current.begin(); i != current.end(); ++i) {
                (*i)->amount_paid += mid;
                P -= mid;
            }
            for (auto &i : current) {
//                cout << "paoid: " << i->amount_paid << endl;
                auto pa = i->amount_paid;
                auto mo = i->money;
//                cout << "money: " << i->money << endl;
            }
            for (list<Member*>::reverse_iterator end = current.rbegin(); P != 0 && end != current.rend(); ++end) {
                (*end)->amount_paid++;
                --P;
            }
            break;
        }
        
        for (auto i = 0; i < n; ++i) {
            if(i) {
                cout << " ";
            }
            cout << members[i]->amount_paid;
        }
        cout << endl;
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
