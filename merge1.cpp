#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::vector;

/* IMPROVEMENT OVER THE BASIC MERGE ALGORITHM */


/*
* The two if conditions which check if the vector has reached its end
* are usually false. 
* To counter this we put the max. possible values(INT_MAX) at the ends of a and b as SENTINELS.
* Now when we reach the end of a (or b), values are taken from b (or a) till its end is reached.
* When we reach the end of both the vectors, that is when a[i] and b[j] are INT_MAX,
* INT_MAX from b is taken and pushed onto c.
* Now when j is incremented, the conditiion k < a.size() + b.size() - 1 becomes false and we break the loop,
* thus ensuring that the vector indices remain in range.
* 
* Finally we remove the INT_MAXs from a and b; and the one INT_MAX which was added from b onto c.
*/


void merge(vector<int>& a, vector<int>& b, vector<int>& c)
{
	// adding the sentinel keys to the end of the vectors
	a.push_back(INT_MAX); // a = {3, 19, 25, 87, 96, INT_MAX}
	b.push_back(INT_MAX); // b = {2, 25, 27, 31, 43, 59, 66, 72, 80, 98, 103, INT_MAX}
	
	for (int k = 0, i = 0, j = 0; k < a.size() + b.size() - 1; ++k)
	{
		// commenting out these extraneous if conditions
		// if(i==a.size()) {c.push_back(b[j++]);continue;}
		// if(j==b.size()) {c.push_back(a[i++]);continue;}
		a[i] < b[j] ? c.push_back(a[i++]) : c.push_back(b[j++]);
	}

	// removing the sentinels from the ends of a and b
	a.pop_back();
	b.pop_back();

	// removing the INT_MAX which has been added to the end of c
	c.pop_back();
}

int main()
{	
	vector<int> a = {3, 19, 25, 87, 96};
	vector<int> b = {2, 25, 27, 31, 43, 59, 66, 72, 80, 98, 103};

	vector<int> c;

	merge(a, b, c);
	for(int i = 0; i<c.size(); ++i) cout<<c[i]<<endl;

	return 0;
}