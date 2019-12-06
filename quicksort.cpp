//950809 Sun
//quicksort, CLRS
//Vahid Ramazani, 94222035
#include<iostream>
using namespace std;

void quicksort(int n, int* a);
void quicksort(int n, int* a, int pivot);
void outy(int n, int* a);

int main()
{
	int a[10] = {14, 17, 13, 15, 19, 10, 3, 16, 9, 12};
	quicksort(10, a);
	return 0;
}

void quicksort(int n, int* a, int pivot_index)
{
	if ( n-1 != pivot_index)
		swap(a[n-1], a[pivot_index]);
	quicksort(n, a);
}

void outy(int n, int* a)
{
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void quicksort(int n, int* a)
{
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

	if (ls>0)
		quicksort(ls, a);
	if (rs>0)
		quicksort(rs, &a[ls+1]); //[0,ls) is left partition, a[ls] , now, is the pivot
}
