#include<iostream>
#include<time.h>
#include<stdlib.h>
#include "treap.h"

#define max_pr 100
using namespace std;

int gen_pr() { return rand() % max_pr; }

int main()
{
	treap<int,int> tp;
	tp.treap_insert(new node<int,int>(5, -1) );
	cout<<"pre: "; tp.recursive_pre_order_walk(); cout<<endl;
	tp.treap_insert(new node<int,int>(7, -4 ) );
	cout<<"pre: "; tp.recursive_pre_order_walk(); cout<<endl;
	tp.treap_insert(new node<int,int>(10, -3) );
	cout<<"pre: "; tp.recursive_pre_order_walk(); cout<<endl;
	tp.treap_insert(new node<int,int>(6, -7) );
	cout<<"pre: "; tp.recursive_pre_order_walk(); cout<<endl;
	tp.treap_insert(new node<int,int>(8, -9) );
	cout<<"pre: "; tp.recursive_pre_order_walk(); cout<<endl;
	tp.treap_insert(new node<int,int>(4, -8) );
	cout<<"pre: "; tp.recursive_pre_order_walk(); cout<<endl;
	
	cout<<endl<<"in: ";
	tp.in_order_walk();
/*
	srand(time(NULL)); 

	treap<int,int> trp;
	trp.treap_insert(new node<int,int>(5, gen_pr() ) );
	trp.recursive_pre_order_walk(); cout<<endl;
	trp.treap_insert(new node<int,int>(7, 24 ) );
	trp.recursive_pre_order_walk(); cout<<endl;
	trp.treap_insert(new node<int,int>(10, gen_pr() ) );
	trp.recursive_pre_order_walk(); cout<<endl;
	trp.treap_insert(new node<int,int>(6, gen_pr() ) );
	trp.recursive_pre_order_walk(); cout<<endl;
	trp.treap_insert(new node<int,int>(8, gen_pr() ) );
	trp.recursive_pre_order_walk(); cout<<endl;
	trp.treap_insert(new node<int,int>(4, gen_pr() ) );
	trp.recursive_pre_order_walk(); cout<<endl;
	trp.treap_insert(new node<int,int>(9, gen_pr() ) );
	trp.recursive_pre_order_walk(); cout<<endl;
	
	cout<<endl;
	trp.in_order_walk();
*/

	return 0;
}
