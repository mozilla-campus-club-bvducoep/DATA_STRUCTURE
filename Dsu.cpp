#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// class to represent a disjoint set
class DisjointSet
{
	unordered_map<int, int> parent;

public:

	// perform MakeSet operation
	void makeSet(vector<int> const &universe)
	{
		// create n disjoint sets (one for each item)
		for (int i : universe)
			parent[i] = i;
	}

	// Find the root of the set in which element k belongs
	int Find(int k)
	{
		// if k is root
		if (parent[k] == k)
			return k;

		// recur for parent until we find root
		return Find(parent[k]);
	}

	// Perform Union of two subsets
	void Union(int a, int b)
	{
		// find root of the sets in which elements
		// x and y belongs
		int x = Find(a);
		int y = Find(b);

		parent[x] = y;
	}
}

void printSets(vector<int> const &universe, DisjointSet &ds)
{
	for (int i : universe)
		cout << ds.Find(i) << " ";

	cout << '\n';
}

// Disjoint-Set Data Structure (Union Find Algorithm)
int main()
{
	// universe of items
	vector<int> universe = { 1, 2, 3, 4, 5 };

	// initialize DisjointSet class
	DisjointSet ds;

	// create singleton set for each element of universe
	ds.makeSet(universe);
	printSets(universe, ds);

	ds.Union(4, 3); // 4 and 3 are in same set
	printSets(universe, ds);

	ds.Union(2, 1); // 1 and 2 are in same set
	printSets(universe, ds);

	ds.Union(1, 3); // 1, 2, 3, 4 are in same set
	printSets(universe, ds);

	return 0;
}