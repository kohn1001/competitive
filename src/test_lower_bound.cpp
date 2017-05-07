#include <iostream> 


#include <set>
#include <vector>

using namespace std;

void lowSet()
{
	

}

int main()
{
	vector<int> v = {0, 5, 7, 11, 13};
	set<int> s;
	//auto it = v.lower_bound(5);
	
	int cnt=0;
	for (auto &i : v) {
		cout << "Object #" << cnt << ": " << i << " " << endl;
		s.emplace(i);
		++cnt;
	}
	auto it = s.lower_bound(5);
	s.insert(it, 6);
	cout << "test lower bound: " << *it << " " << endl;
	for (auto &i : s) { 
		cout << i << endl;
	}
	cout << 1e5 << endl;
	return 0;
}
