// l1.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include <string>
#include<vector>

#include<unordered_map>
#include<set>
#include<unordered_set>//o(1) but no upper/lower bound
#include<map>//o(log(n)) the keys orderd.
#include<queue>
#include <algorithm>

using namespace std;


struct comparator {
	bool operator()(int i, int j) {
		return i > j;
	}
};
/*
int main()
{
	//טיפוסים
	cout << "int= "<<sizeof(int)<<endl<< "long= " << sizeof(long) 
		<< endl<< "long long= " << sizeof(long long) << endl<< "double= " << sizeof(double)<<endl 
		<< "long double= " << sizeof( long double) << endl;

	//pair
	pair<int, string> a = { 2,"what" };
	cout << a.first << " , " << a.second<<endl;
	pair<int, pair<int, int>> tuple;

	

	//string
	string s = "hello";
	s.pop_back();
	cout << s << endl;
	s.push_back('l');
	cout << s << endl;
	s += " world";
	cout << s << endl;

	
	//vector in O(1)
	vector<int> arr1(1e5, 0);//init o(n)
	arr1[0] = 1;
	vector<int> arr2 = arr1;//copy o(n)
	arr2[0] = 2;//arr1[0]=1
	arr1.push_back(3);
	cout << "arr1[1e5]="<<arr1[arr1.size() - 1]<<endl;
	arr1.pop_back();

	//unordered_map-hash table in O(1)-keys must have hash function so int ,string, long long and so on
	//is ok but!! pair ot struct arent ok because they dont have hash function so..you can implement or use map.
	unordered_map<string, int> ht;
	ht["key"] = 5;
	cout << "ht[""key""]=" << ht["key"] << endl;
	if (ht.find("key") != ht.end())
		cout << "key found"<<endl;
	else
		cout << "key not found" << endl;
	cout << "second=" << ht["second"]<<endl;
	ht["second"]++;//if the key already exist in the hash table add 1 to the val else insert the key and put 1 in val.
	for (auto& p : ht)//to over all pairs O(n)
		cout << "key=" <<p.first << " " << "val=" << p.second << endl;

	//priority_queue-min/max heap
	vector<int> arr = { 5,3,6,3,2,1,1 };
	priority_queue<int> max_heap(arr.begin(),arr.end());//O(n)
	cout << "my max_heap" << endl;
	while (!max_heap.empty())
	{
		cout << max_heap.top()<<endl;
		max_heap.pop();
	}

	
	priority_queue<int, vector<int>, comparator> min_heap;
	min_heap.push(6);min_heap.push(8);min_heap.push(1);min_heap.push(2);//log(n)

	
	cout << "my min_heap" << endl;
	while (!min_heap.empty())
	{
		cout << min_heap.top() << endl;
		min_heap.pop();
	}

	//set-sorted arr with binary search implemention ,every val exist only ones in log(N)
	set<int> g;
	g.insert(5);//log(n)
	g.insert(2);
	g.insert(8);
	g.insert(2);
	g.erase(2);//log(n);
	g.insert(1);
	g.insert(9);
	cout << "my set" << endl;
	for (auto& x : g)
		cout << x << " ";
	cout << endl;
	if (g.find(1) != g.end())//log(n)
		cout << "1 has been found";
	cout << endl;
	auto itr = g.lower_bound(1);//find the first which does not compare less than val
	cout << *itr<<endl;
	itr++;
	cout << *itr << endl<< endl;
	itr = g.lower_bound(2);
	cout << *itr << endl;
	itr++;
	cout << *itr << endl << endl;

	 itr = g.upper_bound(1);//find the first which compares greater than val
	cout << *itr << endl;
	itr++;
	cout << *itr << endl << endl;
	itr = g.lower_bound(2);
	cout << *itr << endl;
	itr++;
	cout << *itr << endl << endl;

	//algo

	//sort
	arr.clear();
	arr.push_back(3);arr.push_back(1);arr.push_back(1);arr.push_back(7);
	sort(arr.begin(), arr.end());//nlog(n)
	for (auto& x : arr)
		cout << x << " ";
	cout << endl;
	vector<pair<int, int>> vp;
	sort(vp.begin(), vp.end());//by the first element and if eqval then by the second.

	//max element
	cout << "the max element is " << *max_element(arr.begin(), arr.end())<<endl;//o(n) return iterator(pointer)
	
	//All permutation
	int myints[] = { 1,2,3 };
	sort(myints, myints + 3);//must!!! before next_permutation
cout << "The 3! possible permutations with 3 elements:\n"; do { cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n'; } while (next_permutation(myints, myints + 3)); cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n'; return 0;
}
*/
