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



#include <cstdio>
#include <algorithm>
#include <cstdio>

#include <iostream>

using namespace std;

#define MAX_SIZE 1000


struct Number{
    long long X[MAX_SIZE];
    
    Number(){
    }
};

int N,DIV;
void mult(Number &m, Number &m1, Number &m2){
    memset(m.X,0,sizeof(m.X));
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            m.X[i]=(m.X[i]+m1.X[j]*m2.X[(i+N-j)%N])%DIV;
}

Number Num,aux1,aux2 ;

Number exp(int n){
    if(n==1) return Num;
    if(n==0){
        fill(aux1.X,aux1.X+N,0);
        aux1.X[0]=1;
        return aux1;
    }
    
    aux1=exp(n/2);
    
    fill(aux2.X,aux2.X+N,0);
    aux2.X[0]=1;
    
    mult(aux2,aux1,aux1);
    
    if(n%2==1){
        mult(aux1,aux2,Num);
        return aux1;
    }
    
    return aux2;
}
/*
int main(){
    int T,S,L,R,X,a[1000];
    Number aux;
    long long res;
    
    cin >> T;
    
    for(int t=1; t<=T; ++t) {
        cin >> N >> S >> L >> R >> X;
        
        for(int i=0; i<N; ++i) {
            cin >> a[i];
        }
        fill(Num.X,Num.X+N,0);
        Num.X[0]=1;
        Num.X[N-1]=L;
        Num.X[1]=R;
        
        DIV=1;
        for(int i=0;i<X;i++) {
            DIV *= 10;
        }
        Number aux=exp(S);
        
        for(int i=0; i<N; ++i){
            res=0;
            for(int j=0; j<N; ++j) {
                res=(res+aux.X[(j+N-i)%N] * a[j]) % DIV;
            }
            
            cout << (int)res;
            if(i==N-1) {
                cout << endl;
            }
            else {
                cout << " " ;
            }
        }
    }
    
    return 0;
}
*/
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
