// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> g1;
	int n;
	cin >> n;
	cout << n << endl;
	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	cout << "Output of begin and end: "; // Returns an iterator pointing to the first element in the vector.
	for (auto i = g1.begin(); i != g1.end(); ++i)
		cout << *i << " ";

	cout << "\nOutput of cbegin and cend: "; // Returns a constant iterator pointing to the first element in the vector.
	for (auto i = g1.cbegin(); i != g1.cend(); ++i)
		cout << *i << " ";

	cout << "\nOutput of rbegin and rend: "; // Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector.
	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
		cout << *ir << " ";

	cout << "\nOutput of crbegin and crend : "; // Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
	for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
		cout << *ir << " ";

	return 0;
}
