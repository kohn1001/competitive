#define lld long long int
#define llf long double
#include <iostream>
using namespace std;
const int MAXN = 100002;
#include <string> 
int c;
lld res[3];
 
int main()
{
//    optimizar;
    string S;
    while(cin >> S) {
        c = res[1] = res[2] = 0;
        res[0] = 1;
        lld r = 0;
        for(int i = 0; i < S.size(); i++) {
            if(S[i] < '0' || S[i] > '9') {
                c = res[1] = res[2] = 0;
                res[0] = 1;
                continue;
            }
			//cout << "s[i]: " << S[i] << " " << endl;
            c += S[i] - '0';
            c %= 3;
			//cout << "c is: " << c << " " << endl;
            r += res[c];
			//cout << " res[c]: " << res[c] << " " << endl;
			//cout << " r is: " << r << " " << endl;
            res[c]++;
			//cout << " res[c]++: " << res[c] << " " << endl;
        }
        cout << r << "\n";
    }
    return 0;
}
