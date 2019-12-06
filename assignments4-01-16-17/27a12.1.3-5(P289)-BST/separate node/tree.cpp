// 12.1.3, 12.1.4, 12.1.5
#include<iostream>
#include "bst.h"
using namespace std;

int main()
{
	tree<int> t;

	t.tree_insert(new node<int>(6));
	t.tree_insert(new node<int>(2));
	t.tree_insert(new node<int>(4));
	t.tree_insert(new node<int>(9));
	t.tree_insert(new node<int>(7));
	t.tree_insert(new node<int>(8));
	
	cout<<"root: "<<t.root()->key()<<endl;

	cout<<"\nrecursive_in_order_walk\n";
	t.recursive_in_order_walk();
	cout<<endl;
	
	///12.1.3
	cout<<"\nnon-recursive in_order_walk (12.1.3)\n";
	t.in_order_walk();
	cout<<endl;
	
	t.tree_insert(new node<int>(3));
	t.tree_insert(new node<int>(5));
	
	cout<<"sub-tree, root: 4 \npre,in,post Walks:\n";
	t.recursive_pre_order_walk(t.tree_search(4));
	cout<<endl;
	t.in_order_walk(t.tree_search(4));
	t.recursive_post_order_walk(t.tree_search(4));
	cout<<endl;

	cout<<"\n12.1.5\nEnter n: ";
	int n, inp=0;
	cin>>n;

	tree<int> t5;
	for(int i=0;i<n;++i)
	{
		cin>>inp;
		t5.tree_insert(new node<int>(inp));
	}
	t5.in_order_walk();

	return 0;
}
