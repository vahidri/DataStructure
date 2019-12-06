//cyclic doubly linked list, using sentinel element
//date: Sun, 06 Nov 2016 22:34:36 +0330
//DONE951027 moved list and node classes to a header file
#include<iostream>
#include "linked_list_cyclic_doubly_sentinel.h"
using namespace std;

int main()
{
	list<int> l;
	l.print();
	l.push_tail(new node<int>(40));
	l.print();
	l.push_head(new node<int>(30));
	l.print();
	l.push_head(new node<int>(20));
	l.print();
	l.push_tail(new node<int>(50));
	l.print();
	l.push_head(new node<int>(10));
	l.print();
	l.push_after(new node<int>(22),l.search(20));
	l.print();
	l.push_before(new node<int>(35), l.search(40));
	l.print();
	cout<<l.swap(l.search(10), l.search(50))<<endl;
	l.print();
	l.move_after(l.search_reverse(40), l.search(20));
	l.print();
	l.move_to_head(l.search_reverse(35));
	l.print();
	l.move_to_tail(l.search_reverse(22));
	l.print();
	return 0;
}
