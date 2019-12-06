//cyclic doubly linked list

#ifndef LIST_H_
#define LIST_H_

#include<iostream>
using namespace std;
 
template<class T>
class node
{
private:
	T _data;
	node<T> *next, *prev;
template<class> friend class list; ///NOTEWORTHY
public:
	node(T data) : _data(data) { next = prev = NULL; }
	T get_data() { return _data; }
};

template<class T>
class list
{
private:
	node<T> *nil;
	unsigned int _size;
public:
	list()
	{
		nil = new node<T>(0);
		nil->next = nil->prev = nil;
		_size = 0;
	}
	unsigned int size() { return _size; }
	node<T> *head() { return nil->next; }
	node<T> *tail() { return nil->prev; }

	void remove(node<T> *x)
	{
		if(nil == x)
		{
			cerr<<"tryed to remove \"nil\"\n";
			return;
		}
		if(0==_size)
		{
			cerr<<"tryed to remove from an empty list\n";
			return;
		}
		x->next->prev = x->prev;
		x->prev->next = x->next;
		--_size;
	}

	void print()
	{
		for (node<T> *p = nil->next; p != nil; p = p->next)
			cout<<p->get_data()<<' ';
		cout<<endl;
	}

	void print_reverse()
	{
		for (node<T> *p = nil->prev; p != nil; p = p->prev)
			cout<<p->get_data()<<' ';
		cout<<endl;
	}

	node<T> *search(T key)
	{
		node<T> *p = nil->next; //this.head
		while (p != nil && key != p->get_data())
			p = p->next;
		return p;
	}

	node<T> *search_reverse(T key)
	{
		node<T> *p = nil->prev; //this.tail
		while (p != nil && key != p->get_data())
			p = p->prev;
		return p;
	}

	void push_head(node<T> *x)
	{
		if (nil->prev == nil) //empty list
			nil->prev = x;
		else
			nil->next->prev = x;
		x->next = nil->next; //applies also to empty list
		x->prev = nil;
		nil->next = x;
		++_size;
	}
	
	void push_tail(node<T> *x)
	{
		if(nil == nil->prev) //empty list
			nil->next = x;
		else
			nil->prev->next = x;
		x->prev = nil->prev; //applies also to empty list
		x->next = nil;
		nil->prev = x;
		++_size;
	}

	void push_after(node<T> *x, node<T> *before_x)
	{
		x->next = before_x->next;
		x->prev = before_x;
		before_x->next->prev = x;
		before_x->next = x;
		++_size;
	}

	void push_before(node<T> *x, node<T> *after_x)
	{
		x->next = after_x;
		x->prev = after_x->prev;
		after_x->prev->next = x;
		after_x->prev = x;
		++_size;
	}

	void move_after(node<T> *x, node<T> *before_x) { remove(x); push_after(x, before_x); }
	void move_before(node<T> *x, node<T> *after_x) { remove(x); push_before(x, after_x); }
	void move_to_head(node<T> *x) { remove(x); push_head(x); }
	void move_to_tail(node<T> *x) { remove(x); push_tail(x); }

	int swap(node<T> *a, node<T> *b)
	{
		if (a == nil || b == nil) return -1; //problem
		if(a==b) return 0;
		if(b == a->next)
		{
			a->next = b->next;
			b->next->prev = a;
			b->prev = a->prev;
			a->prev->next = b;
			a->prev = b;
			b->next = a;
			return 1;
		}
		if(a == b->next)
		{
			this->swap(b,a);
			return 11;
		}
		node<T> tmp = *a;
		a->next = b->next;
		a->prev = b->prev;
		b->next = tmp.next;
		b->prev = tmp.prev;
		a->next->prev = a;
		a->prev->next = a;
		tmp.next->prev = b;
		tmp.prev->next = b;
		return 2;
	}
};

#endif
