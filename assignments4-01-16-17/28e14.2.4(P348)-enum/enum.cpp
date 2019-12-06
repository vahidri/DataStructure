#include<iostream>
#include "ebst.h"
using namespace std;

int main()
{
	int c,ch,inp,inp2;
	c = ch = inp = inp2 =0;
	tree<int> tr;
	node<int> *x , *nil = tr.root();
	x=nil;
	do
	{
		cout<<"14.2.4: Enumerate\n1. insert\n2. delete\n3. pre-order walk\n4. in-order walk\n5. post-order walk\n6. enumerate\n9. exit\n? ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter key ";
				cin>>inp;
				tr.tree_insert(new node<int>(inp));
				break;
			case 2:
				cout<<"enter key ";
				cin>>inp;
				x = tr.tree_search(inp);
				if (x != nil) tr.tree_delete(x);
				break;
			case 3:
				tr.recursive_pre_order_walk();
				break;
			case 4:
				tr.in_order_walk();
				break;
			case 5:
				tr.recursive_post_order_walk();
				break;
			case 6:
				cout<<"enter bounds: a then b\n";
				cin>>inp>>inp2;
				c = tr.enumerate(inp, inp2); cout<<endl;
				cout<<"count: "<<c<<endl<<endl;
				break;
		}
	}
	while(ch != 9);
/*
	tree<int> t;
	int c=0;
	t.tree_insert(new node<int>(6));
	t.tree_insert(new node<int>(2));
	t.tree_insert(new node<int>(4));
	t.tree_insert(new node<int>(9));
	//t.tree_insert(new node<int>(7));
	t.tree_insert(new node<int>(8));
	t.tree_insert(new node<int>(3));
	//t.tree_insert(new node<int>(5));
	t.in_order_walk();
	cout<<endl;
	
	
	c = t.enumerate(4,8); cout<<endl;
	cout<<"count: "<<c<<endl<<endl;

	c = t.enumerate(5,7); cout<<endl;
	cout<<"count: "<<c<<endl<<endl;

	c = t.enumerate(6,6); cout<<endl;
	cout<<"count: "<<c<<endl<<endl;

	c = t.enumerate(7,6); cout<<endl;
	cout<<"count: "<<c<<endl<<endl;
*/
	return 0;
}
