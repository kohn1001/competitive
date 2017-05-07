/*130a303



==========
general idea:
	1
	13
	130
	0
	00
	000
	0000
*/
#include <iostream>
#include <string>
using namespace std;
/*
 *
 *
 *   130a303
 *   1
*	 13
 */
using ll = long long int;
ll findSubStr(const string & str)
{
	ll subStNum = 0, tail;
	string substring;
	int digitSum = 0;
	for(int i = 0; i < str.size(); ++i) {
		if (isalpha(str[i])) {
			continue;
		}
		int head, tail;
		for (head = i, tail = i; head < str.size(); ++head) {
			int num = char(str[i])-'0';
			if ((num < 0) || (num > 9)) { break;}
			/* cout << "isalpha: " << isalpha(str[head]) << " " << str[head] << endl;
			cout << "tail is: " << tail << " " << "head is: " << head << " " << endl; */
			//string tmpStr = str.substr(tail, head-tail+1);
			
			//cout << tmpStr << endl;
			//long long num += stoll(tmpStr);
			//long long num += str[head] - '0';
			//cout << "num is: " << num << " " << endl;
			digitSum += num;
			if (digitSum%3 == 0) {
				++subStNum;
				//cout << "SubStrNum: " << subStNum << " " << endl;
			}
		}
	}
		/*
		while (++tail <= head) {
			string tmpStr = str.substr(tail, head-tail+1);
			cout << "SubStr: " << tmpStr << " " << endl;
			int num = stoi(tmpStr);	

			if (num%3 == 0) {
				cout << "SubStrNum: " << subStNum << " " << endl;
				++subStNum;
			}
		}
		*/
	return subStNum;
}

#ifdef deb
int main()
{
	int T;
	string str;
	while(cin >> str) {
	//cin >> T;

	//cout << "string is: " << str << " " << endl;
		cout << findSubStr(str) << endl;
	}
	return 0;
}
#endif
