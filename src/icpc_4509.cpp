//
//
//  Created by Nathaniel Kohn on 11 M 2017.
//



/*
 *
 *    Hunted Grave yard - icpc 4509
 *
 *
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
#include <cstdio>
#include <cstring>


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
using pairSD = pair<pair<int, int>, pair<int, int>>;
using edgWe = pair<pairSD, int>;

int visited[30][30];
int bellman(
    vector<edgWe> &adjList,
    int numOfVertexes,
    ii &&source,
    ii &&dst,
    vector<vi> &gy)
{
    bool isVisit = false;
    for(int i=0; i<= dst.first; ++i) {
        for (int j=0; j <= dst.second; ++j) {
            visited[i][j] = 0;
        }
    }
    gy[0][0] = 0;
    visited[source.first][source.second] = 1;
    /*hold the path with shourtest path - in case there is one */
    
    for (int i=0; i<numOfVertexes; ++i) {
        isVisit = false;
        for (auto &w : adjList) {
            int ui = w.first.second.first, uj = w.first.second.second;
            int vi = w.first.first.first, vj = w.first.first.second;
            if(gy[ui][uj] > gy[vi][vj] + w.second) {
//                isVisit = true;
                if(visited[vi][vj]) {
                    visited[ui][uj] = 1;
                }
                gy[ui][uj] = gy[vi][vj] + w.second;
            }
        }
    }
    for (auto &w : adjList) {
        int ui = w.first.second.first, uj = w.first.second.second;
        int vi = w.first.first.first, vj = w.first.first.second;
        if(visited[vi][vj] && gy[vi][vj] +w.second < gy[ui][uj]) {
            cout << "Never" << endl;
            return 0;
        }
    }
//    if (isVisit == false) {
//        if (gy[dst.first][dst.second] == INF) {
    if (!visited[dst.first][dst.second]) {
        cout << "Impossible" << endl;
    }
    else {
            cout <<  gy[dst.first][dst.second] << endl;
    }
 
//    else {
//        cout << "Never" << endl;
//    }
    
    return 0;
}

bool isValid(int i, int j, int W, int H, bool grave[][30], bool huntedHol[][30])
//bool isValid(int i, int j, int W, int H, vector<vector<bool>> &grave, vector<vector<bool>> &huntedHol)
{
    if(i >= 0 && i < W && j >= 0 && j < H && !grave[i][j]) {// || gy[i][j] == -1) {
        return true;
    }
    return false;
}

void printAdjList(vector<edgWe> &adjList)
{
    for (auto &i : adjList) {
        cout << "coordinates: ui[" << i.first.first.first << "] " << "uj[" << i.first.first.second << "] ";
        cout << " vi[" << i.first.second.first << "] " << "vj[" << i.first.second.second << "]";
        cout << " Weight: " << i.second << endl;
    }
}
bool graveStone[30][30];
bool huntedHol[30][30];

int main()
{
    int W, H;
	while(true) {
        scanf("%d%d",&W,&H);
        if( W == 0) break;
    //while (cin >> W) {
//        cin >> H;
        vector<vector<int>> graveYard(W, vector<int>(H, INF));
//        vector<vector<bool>> graveStone(W, vector<bool>(H, false));
//        vector<vector<bool>> huntedHol(W, vector<bool>(H, false));
        memset(graveStone, false, sizeof(graveStone));
        memset(huntedHol, false, sizeof(huntedHol));
        vector<edgWe> adjList;
		int G, E;
        cin >> G;
        for (int i=0; i<G; ++i) {
            int ii, jj;
            cin >> ii >> jj;
//            graveYard[ii][jj] = 0;
            graveStone[ii][jj] = true;
        }
        cin >> E;
        for (int i=0; i<E; ++i) {
            int si, sj, di, dj, ww;
            cin >> si >> sj >> di >> dj >> ww;
//            graveYard[si][sj] = -1;
            huntedHol[si][sj] = true;
            
            pairSD sdPair = mp(mp(si, sj), mp(di, dj));
            adjList.eb(mp(sdPair, ww));
            /*we mark HH as - 1 */
        }
        for(int i = 0; i < W ; ++i) {
            for(int j = 0; j < H; ++j) {
//                if(graveYard[i][j] == -1 || graveYard[i][j] == 0 || (i == W-1 && j == H-1)) {
                for (int k=0; k<4; ++k) {
                   
                }
                if(graveStone[i][j] || huntedHol[i][j] || (i == W-1 && j == H-1)) {
                    continue;
                }
                if(isValid(i+1, j, W, H, graveStone, huntedHol)) {
                    pairSD psd = mp(mp(i, j), mp(i+1, j));
                    adjList.eb(mp(psd, 1));
                }
                if(isValid(i, j+1, W, H, graveStone, huntedHol)) {
                    pairSD psd = mp(mp(i, j), mp(i, j+1));
                    adjList.eb(mp(psd, 1));
                }
                if(isValid(i-1, j, W, H, graveStone, huntedHol)) {
                    pairSD psd = mp(mp(i, j), mp(i-1, j));
                    adjList.eb(mp(psd, 1));
                }
                if(isValid(i, j-1, W, H, graveStone, huntedHol)) {
                    pairSD psd = mp(mp(i, j), mp(i, j-1));
                    adjList.eb(mp(psd, 1));
                }
            }
        }
//        for (int i=0; i < W; ++i) {
//            for (int j=0; j < H; ++j) {
//                graveYard[i][j] = INF;
//            }
//        }
//        printAdjList(adjList);
        bellman(adjList, W*H, mp(0,0), mp(W-1, H-1), graveYard);
        
    }
    return 0;
}


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

