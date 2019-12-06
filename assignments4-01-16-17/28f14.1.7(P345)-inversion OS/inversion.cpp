/*
 * 14.1.7
 * array inversion count using OS
 * Vahid Ramazani
 * 01/17/2017 (951028)
*/
#include<iostream>
#include "osbst.h"
using namespace std;

void print(int *a,int n);
int inversions(int *a, int n)
{
	int outy = 0, tmp=0;
	tree<int> t;
	cout<<"inversions: ";
	for(int i=0;i<n;++i)
	{
		tmp = i+1 - t.tree_insert(new node<int>(a[i]) );
		cout<<tmp<<";";
		outy += tmp;
	}
	cout<<endl;
	return outy;
}

int main()
{
	int a[] = {40, 20, 30, 10};
	cout<<"array: ";
	print(a,4);

	cout<<"Total inversion count is: "<<inversions(a,4)<<endl;
	return 0;
}

void print(int *a, int n)
{
	for(int i=0;i<n;++i)
		cout<<a[i]<<",";
	cout<<endl;
}
