#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;
const char *OP = "+-*/";
const int N = (1 << 6) + 10;
struct Node {
    LL sum ,v1, v2;
    int s1, s2, op;
    Node() {}
    Node(LL _sum, int _s1, int _s2, LL _v1, LL _v2, int _op) {
        sum = _sum;
        s1 = _s1;
        s2 = _s2;
        v1 = _v1;
        v2 = _v2;
        op = _op;
    }
} ;
vector<Node> res[N];

void PRE() {
    LL x;
    for (int i = 0; i < N; i++) res[i].clear();
    Node tmp;
    for (int i = 0; i < 6; i++) {
        cin >> x;
        tmp = Node(x, 0, 0, 0ll, 0ll, -1);
        res[1 << i].push_back(tmp);
    }
}

void work() {
    int end = 1 << 6;
//    int sum = 0;
    Node tmp;
    set<int> has;
    for (int i = 0; i < end; i++) {
        has.clear();
        for (int t = i & (i - 1); t > 0; t = i & (t - 1)) {
            int op = i ^ t, szt = res[t].size(), szop = res[op].size();
            for (int ii = 0; ii < szt; ii++) {
                for (int jj = 0; jj < szop; jj++) {
                    tmp = Node(res[t][ii].sum + res[op][jj].sum, t, op, res[t][ii].sum, res[op][jj].sum, 0);
                    if (tmp.sum > 0 && has.find(tmp.sum) == has.end()) res[i].push_back(tmp), has.insert(tmp.sum);
                    tmp = Node(res[t][ii].sum - res[op][jj].sum, t, op, res[t][ii].sum, res[op][jj].sum, 1);
                    if (tmp.sum > 0 && has.find(tmp.sum) == has.end()) res[i].push_back(tmp), has.insert(tmp.sum);
                    tmp = Node(res[t][ii].sum * res[op][jj].sum, t, op, res[t][ii].sum, res[op][jj].sum, 2);
                    if (tmp.sum > 0 && has.find(tmp.sum) == has.end()) res[i].push_back(tmp), has.insert(tmp.sum);
                    if ((res[op][jj].sum != 0) && (res[t][ii].sum % res[op][jj].sum == 0)) {
                        tmp = Node(res[t][ii].sum / res[op][jj].sum, t, op, res[t][ii].sum, res[op][jj].sum, 3);
                        if (tmp.sum > 0 && has.find(tmp.sum) == has.end()) res[i].push_back(tmp), has.insert(tmp.sum);
                    }
                }
            }
        }
//        sum += res[i].size();
    }
//    cout << sum << endl;
}

void dfs(int id, LL val) {
    int szid = res[id].size();
    for (int i = 0; i < szid; i++) {
        if (res[id][i].sum == val) {
            if (res[id][i].op == -1) return ;
            dfs(res[id][i].s1, res[id][i].v1);
            dfs(res[id][i].s2, res[id][i].v2);
            cout << res[id][i].v1 << ' ' << OP[res[id][i].op] << ' ' << res[id][i].v2 << " = " << val << endl;
            return ;
        }
    }
}

void print(int tar) {
    cout << "Target: " << tar << endl;
    LL mn = 0x7777777777777777ll;
    int end = 1 << 6, mk;
    for (int i = 0; i < end; i++) {
        int szi = res[i].size();
        for (int j = 0; j < szi; j++) {
            if (abs(mn - tar) > abs(res[i][j].sum - tar)) {
                mn = res[i][j].sum;
                mk = i;
            }
//            if (i == end - 1) {
//                cout << res[i][j].sum << endl;
//            }
//            if (res[i][j].sum == 400) {
//                for (int j = 0; j < 6; j++) {
//                    putchar((i & (1 << j)) != 0 ? '1' : '0');
//                }
//                cout << "Ahhhhhh~" << endl;
//                dfs(i, res[i][j].sum);
//            }
        }
    }
//    for (int i = 5; i >= 0; i--) {
//        putchar(mk & (1 << i) ? '1' : '0');
//    }
//    cout << endl;
    dfs(mk, mn);
    cout << "Best approx: " << mn << endl << endl;
}

int main() {
//    freopen("in", "r", stdin);
    int T, tar;
    cin >> T;
    while (T--) {
        PRE();
        cin >> tar;
        work();
        print(tar);
    }
    return 0;
}
