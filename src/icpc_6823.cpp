#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

int main() 
{ 
	string S;
	while(cin >> S) {
		S += "$";
		ll total_substhreengs = 0;
		vector<ll> hist(3,0);
		hist[0] = 1;
		int digit_sum = 0;

		for(unsigned int i=0; i<S.size(); ++i) {
			int num = char(S[i]-'0');
					if ((num >= 0) && (num <= 9)) {
						digit_sum += num;
						digit_sum %= 3;
						hist[digit_sum]++;
					}
					else {
						for(int k=0;  k < 3; ++k) {
							total_substhreengs += hist[k]*(hist[k]-1)/2;
						}
						hist = vector<ll>(3,0);
						hist[0] = 1;
						digit_sum = 0;
					}
		}
		cout << total_substhreengs << endl;
	}
	return 0;
}
