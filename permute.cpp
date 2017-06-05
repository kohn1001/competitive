#include <string>
#include <iostream>

#include <algorithm>
using namespace std;

int main()
{
	string str = {"abcd"};
	do {
		cout << "str: " << str << endl;
	}while (next_permutation(str.begin(), str.end()));
	
	return 0;
}
