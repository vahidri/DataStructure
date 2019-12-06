//Q4, CLRS assignments(3rd)
#include<iostream>
using namespace std;

int N, *A;
int c=0;

void quicksort(int n, int* a, bool);
void quicksort(int n, int* a, int pivot);
void outy(int n, int* a);

int main()
{
	int a[10] = {14, 17, 13, 15, 19, 10, 3, 16, 9, 12};
	N=10;
	A=a;
	outy(N, A);
	int ind=N-1;
	cout<<"pivot(0-9)? ";
	cin>>ind;
	quicksort(10, a, ind);
	outy(N, A);
	return 0;
}

void quicksort(int n, int* a, int pivot_index)
{
	if ( n-1 != pivot_index)
		swap(a[n-1], a[pivot_index]);
	quicksort(n, a, true);
}

void outy(int n, int* a)
{
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void quicksort(int n, int* a, bool cont)
{
	//cout<<"c: "<<c<<endl;
	/*
	* left partition
	* 	[0,ls-1] or [0,ls)
	* 	elements are smaller than or equal to the pivot
	* right partition
	* 	[ls,ls+rs-1] or [ls,ls+rs)
	* 	elements are bigger than the pivot
	*/
	int ls = 0, //left_size
	    rs = 0; //right_size

	//if (3==c || 4==c) outy(N,A);

	cout<<endl<<c++<<". "<<n<<" ["<<a-A<<","<<a-A+n-1<<"]"<<endl;
	outy(N,A);
	outy(n,a);

	if (1==n)
		return;

	const int pivot = a[n-1];
	for(int i=0;i<n-1;i++)
		if(a[i] <= pivot)
		{
			if (rs > 0)
				swap(a[ls], a[i]);
			++ls;
		}
		else //a[i] > pivot
			++rs;
	//by this time, ls+rs == n-1 (size of array-1)
	if ( n-1 != ls + rs)
		cout<<"ERROR: n-1("<<n-1<<") != ls("<<ls<<") + rs("<<rs<<")"<<endl;
	swap(a[ls], a[n-1]);

	//cout<<"n("<<n<<"), ls("<<ls<<") , rs("<<rs<<")"<<endl;
	//cout<<n<<": ";
	//outy(n, a);
	//cout<<N<<": ";
	//outy(N, A);

	//cout<<"c; "<<c<<endl;
	if (cont)
	{
		if (ls>0)
			quicksort(ls, a, false);
		if (rs>0)
			quicksort(rs, &a[ls+1], false); //[0,ls) is left partition, a[ls] , now, is the pivot
	}
}
