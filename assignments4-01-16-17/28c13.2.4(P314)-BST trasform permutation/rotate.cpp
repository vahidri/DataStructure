#include<iostream>
#include<vector>
#include "bst_transform.h"
using namespace std;


int main()
{
	tree<int> a;
	a.tree_insert(new node<int>(4));
	a.tree_insert(new node<int>(3));
	a.tree_insert(new node<int>(2));
	a.tree_insert(new node<int>(5));

	tree<int> b;
	b.tree_insert(new node<int>(3));
	b.tree_insert(new node<int>(2));
	b.tree_insert(new node<int>(4));
	b.tree_insert(new node<int>(5));

	vector< node<int>* > rra, rrb; ///right rotate sequences (converting to right spine)

	cout<<"walks are pre-order\n";
	cout<<"#tree A:\n";
	a.recursive_pre_order_walk(); cout<<endl;
	rra = a.spiner_right();	///look it up in "bst_transform.h"
	cout<<"\ttree A, right spined:\n\t";
	a.recursive_pre_order_walk(); cout<<endl;

	cout<<endl;

	cout<<"#tree B\n";
	b.recursive_pre_order_walk(); cout<<endl;
	rrb = b.spiner_right();	
	cout<<"\ttree B, right spined:\n\t";
	b.recursive_pre_order_walk(); cout<<endl;

	cout<<endl;
	cout<<"doing left-rotates(from B's right-rotations) in the reverse order on A to get B!\n";

	///this assumes that keys are distinct/unique;
		///otherwise it's wrong. To obviate that case, we need to make them unique, by giving them unique labels, for example.
	for (int i=rrb.size()-1;i>=0;--i)
		a.rotate_left( a.iterative_tree_search(rrb[i]->key())->parent() );
			///notice: Page313(334), figure 13.2: right-rotate(T,y) <-> left-rotate(T,y.p)

	cout<<"#tree A, after transformation:\n";
	a.recursive_pre_order_walk(); cout<<endl;

	cout<<"\tis the same as initial B"<<endl;
	cout<<endl;

	cout<<"\n###Rotations on A, to become B###\n";
	for (node<int>* i: rra) ///g++ --std=c++11
		cout<<"r"<<i->key()<<",";
	cout<<" ";
	for (int i=rrb.size()-1;i>=0;--i)
		cout<<"l"<<rrb[i]->key()<< "("<<rrb[i]->parent()->key()<<")" <<",";
	cout<<endl;
	cout<<"\n>Legends\nr: right-rotate\nl: left-rotate\nnumber is the key value of the corresponding node"<<endl;
	return 0;
}
