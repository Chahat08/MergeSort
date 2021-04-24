#include <iostream>
#include <cstdlib>
#include <vector>

using std::cout; using std::endl;
using std::vector;

void merge(vector<int>& a, vector<int>& b, vector<int>& c)
{
	for(int k=0, i=0, j=0; k<a.size()+b.size(); ++k)
	{
		if(i==a.size()) {c.push_back(b[j++]);continue;}
		if(j==b.size()) {c.push_back(a[i++]);continue;}
		a[i] < b[j] ? c.push_back(a[i++]) : c.push_back(b[j++]);
	}
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