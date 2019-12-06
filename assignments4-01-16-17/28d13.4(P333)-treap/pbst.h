/*
 * binary search tree
 * 01/16/2017 (951027)
 * Vahid Ramazani
*/
#ifndef PBST_H_
#define PBST_H_

#include<iostream>
#include "pnode.h"
using namespace std;

template<class T, class U>
class tree
{
	private:
		node<T,U> *nil;
		template<class, class> friend class treap;
		void print(node<T,U>* x) { cout<<x->k<< "["<<x->pr<<"]" <<","; }
	public:
		tree()
		{
			nil = new node<T,U>(0,0);
			nil->p = nil->l = nil->r = nil;
		}
		node<T,U> *root() { return nil->l; } ///equals to nil->l; just for convention

		void tree_insert(node<T,U> *z)
		{
			node<T,U> *x, *y;
			y= x = nil->l;
			while ( x != nil)
			{
				y = x;
				if (z->k < x->k )
					x = x->l;
				else
					x = x->r;
			}
			z->p = y;
			z->l = z->r = nil;
			if ( y == nil)
				nil->l = z; ///empty tree
			else
				if ( z->k < y->k )
					y->l = z;
				else
					y->r = z;
		}

		void transplant(node<T,U> *u, node<T,U> *v)
		{
			if (u->p == nil)
				nil->l = v;
			else
				if ( u == u->p->l )
					u->p->l = v;
				else
					u->p->r = v;
			if (v != nil)
				v->p = u->p;
		}

		void tree_delete(node<T,U> *z)
		{
			if (z->l == nil)
				transplant(z, z->r);
			else
				if (z->r == nil)
					transplant(z, z->l);
				else
				{
					node<T,U> *y = tree_minimum(z->r);
					if (y->p != z)
					{
						transplant(y, y->r);
						y->r = z->r;
						y->r->p = y;
					}
					transplant(z, y);
					y->l = z->l;
					y->l->p = y;
				}
		}

		node<T,U> *tree_search(node<T,U> *x, T k)
		{
			if (x == nil || k == x->k )
				return x;
			if (k < x->k )
				return tree_search(x->l, k);
			else
				return tree_search(x->r, k);
		}
		node<T,U> *tree_search(T k) { return tree_search(root(), k); }

		node<T,U> *iterative_tree_search(node<T,U> *x, T k)
		{
			while (x != nil && k != x->k )
				if (k < x->k )
					x = x->l;
				else
					x= x->r;
			return x;
		}
		node<T,U> *iterative_tree_search(T k) { return iterative_tree_search(root(), k); }

		node<T,U> *tree_minimum(node<T,U> *x)
		{
			while (x->l != nil)
				x = x->l;
			return x;
		}

		node<T,U> *tree_maximum(node<T,U> *x)
		{
			while (x->r != nil)
				x = x->r;
			return x;
		}

		node<T,U> *tree_successor(node<T,U> *x)
		{
			if (x->r != nil)
				return tree_minimum(x->r);
			node<T,U> *y = x->p;
			while (y != nil && x == y->r )
			{
				x = y;
				y = y->p;
			}
			return y;
		}

		node<T,U> *tree_predecessor(node<T,U> *x)
		{
			if (x->l != nil)
				return tree_maximum(x->l);
			node<T,U> *y = x->p;
			while (y != nil && x == y->l )
			{
				x = y;
				y = y->p;
			}
			return y;
		}

		void rotate_left(node<T,U> *x)
		{
			cerr<<"rt-left: "<<x->k<< "["<<x->pr<<"]" <<endl;
			node<T,U> *y = x->r;
			x->r = y->l;
			if (y->l != nil)
				y->l->p = x;
			y->p = x->p;
			if (x->p == nil)
				nil->l = y;
			else
				if (x == x->p->l )
					x->p->l = y;
				else
					x->p->r = y;
			y->l = x;
			x->p = y;
		}

		void rotate_right(node<T,U> *x)
		{
			cerr<<"rt-right: "<<x->k<< "["<<x->pr<<"]" <<endl;
			node<T,U> *y = x->l;
			x->l = y->r;
			if (y->r != nil)
				y->r->p = x;
			y->p = x->p;
			if (x->p == nil)
				nil->l = y;
			else
				if (x == x->p->r )
					x->p->r = y;
				else
					x->p->l = y;
			y->r = x;
			x->p = y;
		}

		void recursive_pre_order_walk(node<T,U> *x)
		{
			if(x != nil)
			{
				print(x);
				recursive_pre_order_walk(x->l);
				recursive_pre_order_walk(x->r);
			}
		}
		void recursive_pre_order_walk() { recursive_pre_order_walk(root()); }

		void recursive_in_order_walk(node<T,U> *x)
		{
			if(x != nil)
			{
				recursive_in_order_walk(x->l);
				print(x);
				recursive_in_order_walk(x->r);
			}
		}
		void recursive_in_order_walk() { recursive_in_order_walk(root()); }

		void recursive_post_order_walk(node<T,U> *x)
		{
			if(x != nil)
			{
				recursive_post_order_walk(x->l);
				recursive_post_order_walk(x->r);
				print(x);
			}
		}
		void recursive_post_order_walk() { recursive_post_order_walk(root()); }
/*
		void pre_order_walk()
		{
		///maybe TODO
		}
*/
		///12.1.3
		void in_order_walk(node<T,U> *x) ///non-recursive
		{
			bool fr = false; ///boolean[From Right]
			node<T,U> *y = tree_minimum(x);
			print(y);
			while(y != x || !fr)
			{
				if (fr || nil == y->r )
				{
					fr = false;
					if (y == y->p->r)
						fr = true;
					y = y->p;
				}
				else
				{
					y = y->r;
					y = tree_minimum(y);
				}
				if (!fr)
					print(y);
			}
			cout<<endl;
		}
		void in_order_walk() { in_order_walk(root()); }
/*
		void post_order_walk()
		{
		///maybe TODO
		}
*/
};

#endif
