#include <iostream>
#include <cstdlib>

using std::cout; using std::endl;

void merge(int* a, int* b, int* c, int m, int n)
{
	for(int k=0, i=0, j=0; k<m+n; ++k)
	{
		if(i==m) {c[k]=(b[j++]);continue;}
		if(j==n) {c[k]=(a[i++]);continue;}
		c[k] =  a[i] < b[j] ? (a[i++]) : (b[j++]);
	}
}

int main()
{	
	int a[] = {3, 19, 25, 87, 96};
	int b[] = {2, 25, 27, 31, 43, 59, 66, 72, 80, 98, 103};

	int m = sizeof(a)/sizeof(a[0]), n = sizeof(b)/sizeof(b[0]);
	int* c = new int[m+n];

	merge(a, b, c, m, n);
	for(int i = 0; i<m+n; ++i) cout<<c[i]<<endl;

	return 0;
}