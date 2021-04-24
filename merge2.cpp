#include <iostream>
#include <vector>
#define maxN 20

using std::vector;
using std::cout;
using std::endl;

int aux[maxN];

/*
* IN-PLACE SORT WITH NO EXTRA SENTINEL
* putting one vector after the other in reverse ensures that the max value lies at the end of each
* because the two vectors are sorted.
* That's what we do here. 
* The first part is copied as it is into aux.
* The second part is copied after it in reverse.
* The rest is more or less the same, the diff being that the first part is checked from the left.
* while the second part is checked from the right, while copying back to the original vector.
*/

void merge(vector<int>& v, int l, int m, int r)
{
	int i, j;

	// copying a as it is into aux. Doing it back to front so as to leave i pointing to l.
	for (i = m + 1; i > l; --i) aux[i - 1] = v[i - 1];

	// copying b into aux, reversing its order. j points to r on exit.
	for (j = m; j < r; ++j) aux[r + m - j] = v[j + 1];

	// Currently, i == l and j == r;
	// aux = { 2, 8, 10, 36, 80,70,60,50, 40, 38,32,21,9,1,0 } => BITONIC SEQUENCE in aux too
	// so 80 is serving as sentinel as it is the largest value


	// sorting the array in-place
	for (int k = l; k <= r; ++k)
		v[k] = aux[i] < aux[j] ? aux[i++] : aux[j--];

}

int main()
{
	// vector<int> a = { 2, 8, 10, 36 };
	// vector<int> b = { 0, 1, 9, 21, 32, 38, 40, 50, 60, 70, 80 };
	vector<int> v = { 2, 8, 10, 36, 0, 1, 9, 21, 32, 38, 40, 50, 60, 70, 80 };
	// we combine a and b end to end to get v

	// 3 = index of last element of a
	merge(v, 0, 3, v.size() - 1);

	for (auto it : v) cout << it << endl;
	
	return 0;
}