/*
* Q3, optimized phase sort
	* adapted the quicksort to perform the task. (plus reusing the code I'd written earlier)
	* notice, this algorithm has 3 partitions => it's theta(n)
		* explanation:
			* left: smaller ranges
			* I: intersecting ranges
			* right: bigger ranges

			* ###the Intersecting partition, doesn't get recursion; this causes the Optimization
*/

#include<iostream>
using namespace std;

struct range {
	int l,r;
};

void ranger(range& R, int l, int r) { R.l = l; R.r = r;}
bool before(range a, range b) { return a.r < b.l; }
//bool intersects(range a, range b) { return a.l <= b.r && b.l <= a.r; } //not necessary!
bool after(range a, range b) { return  b.r < a.l; }
void quicksort(int n, range* a);
void quicksort(int n, range* a, int pivot_index);
void outy(int n, range* a);

void swap(range& a, range& b) { range x; x.l = a.l; x.r = a.r; a.l = b.l; a.r = b.r; b.l = x.l; b.r = x.r;}

int main()
{
	range r[8];
	ranger(r[0], 1,3);
	ranger(r[1], 3,4);
	ranger(r[2], 4,7);
	ranger(r[3], 5,6);
	ranger(r[4], 11,12);
	ranger(r[5], 8,10);
	ranger(r[6], 13,15);
	ranger(r[7], 7,11);
	quicksort(8, r);
	outy(8, r);
	return 0;
}

void quicksort(int n, range* a, int pivot_index)
{
	if ( n-1 != pivot_index)
		swap(a[n-1], a[pivot_index]);
	quicksort(n, a);
}

void outy(int n, range* a)
{
	for (int i=0;i<n;i++)
		cout<<"["<<a[i].l<<","<<a[i].r<<"] ";
	cout<<endl;
}

void quicksort(int n, range* a)
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
	    rs = 0, //right_size
		is = 0; //intersecting_size
	if (1==n)
		return;

	const range pivot = a[n-1];
	for(int i=0;i<n-1-rs;i++)
		//loop invariant: right here, i == ls+is
		if( before(a[i], pivot) )
		{
			if (is > 0)
				swap(a[ls], a[i]); //a[ls] is the first(far left) member of I partition
			++ls;
		}
		else if ( after(a[i], pivot) )
		{
			swap( a[i], a[n-2-rs]);
			++rs;
			--i; //deprecated, but necessary :)
		}
		else
			++is;
	//by this time, ls+is+rs == n-1 (size of array-1)
	if ( n-1 != ls + is + rs)
		cout<<"ERROR: n-1("<<n-1<<") != ls("<<ls<<") + is("<<is<<") + "<<rs<<"("<<rs<<")"<<endl;
	swap(a[ls+is], a[n-1]); //ls+is = first(far left) member of right partition; note! array starts from 0

	if (ls>0)
		quicksort(ls, a);
	if (rs>0)
		quicksort(rs, &a[ls+is+1]); //[0,ls) is left partition, a[ls] , now, is the pivot
}
