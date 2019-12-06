/*
 * binary search tree + Enumeration
 * 01/17/2017 (951028)
 * Vahid Ramazani
*/
#ifndef EBST_H_
#define EBST_H_

#include<iostream>
#include<string>
#include "node.h"
using namespace std;

template<class T>
class tree
{
	private:
		node<T> *nil;
		void print(node<T>* x) { cout<<x->k<<","; }
		struct slrx { string s; node<T> *l, *r, *x; };
	public:
		tree()
		{
			nil = new node<T>(0);
			nil->p = nil->r = nil->l = nil;
		}
		node<T> *root() { return nil->l; } ///equals to nil->l; just for convention

		slrx both_str(node<T> *x, T k) ///output: str, last l, last r
		{
			slrx outy;
			outy.x = x;
			outy.s = "";
			outy.l = outy.r = x;
			while (outy.x != nil)
			{
				if (outy.x->k == k)
				{
					outy.s.push_back('2'); ///found
					return outy;
				}
				if (k < outy.x->k )
				{
					outy.s.push_back('1');
					outy.l = outy.x;
					outy.x = outy.x->l;
				}
				else
				{
					outy.s.push_back('3');
					outy.r = outy.x;
					outy.x= outy.x->r;
				}
			}
			return outy;
		}
		slrx both_str(T k) { return  both_str(root(), k); }

		///NEW: returns count
		int enumerate(node<T>* x, T a, T b)
		{
			slrx a_slrx = both_str(a);
			slrx b_slrx = both_str(b);

			if (a_slrx.s > b_slrx.s)
			{
				cerr<<"IMPOSSIBLE!"<<endl;
				return -1;
			}
			if (a_slrx.s == b_slrx.s)
				//if (a_slrx.s.back() == '2') ///--std=c++11
				if (a_slrx.s[a_slrx.s.length()-1] == '2') ///
				{
					print(a_slrx.x);
					return 1;
				}
				else
				{
					cout<<"none."<<endl;
					return 0;
				}
			else
			{
				int c = 1;
				node<T> *beg, *end, *z;

				//if(a_slrx.s.back() == '2') ///--std=c++11
				if(a_slrx.s[a_slrx.s.length()-1] == '2')
					beg = a_slrx.x;
				else
					beg = a_slrx.l;
					
				//if(b_slrx.s.back() == '2') ///--std=c++11
				if(b_slrx.s[b_slrx.s.length()-1] == '2')
					end = b_slrx.x;
				else
					end = b_slrx.r;

				z = beg;
				while (z != end)
				{
					++c;
					print(z);
					z = tree_successor(z);
				}
				if (z!=end) cerr<<"IMPOSSIBLE! z!=end"<<endl;
				print(z);
				return c;
			}
		}
		int enumerate(T a, T b) { return enumerate(root(), a, b); }

/*
		node<T>* select_str(node<T> *x, const string s)
		{
			node<T>* y = x;
			for (int i=0;i<s.length();++i)
			{
				y = x;
				switch(s[i])
				{
					case '1':
						x = x->l;
						break;
					case '3':
						x = x->r;
						break;
					case '2':
						if(i < s.length-1)
							cerr<<"IMPOSSIBLE! sel: 2 before end of the string"<<endl;
						break;
					default:
						cerr<<"IMPOSSIBLE! sel: not 1,2 or 3"<<endl;
						break;
				}
			}
			return y;
		}
		node<T>* select_str(string s) { return select_str(root(), s); }
		
		string look_str(node<T> *x, T k)
		{
			string outy = "";
			while (x != nil)
			{
				if (x->k == k)
				{
					outy.push_back('2'); ///found
					return outy;
				}
				if (k < x->k )
				{
					outy.push_back('1');
					x = x->l;
				}
				else
				{
					outy.push_back('3');
					x= x->r;
				}
			}
			return outy;
		}
		string look_str(T k) { return look_str(root(), k); }
*/

		void tree_insert(node<T> *z)
		{
			node<T> *x, *y;
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

		void transplant(node<T> *u, node<T> *v)
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

		void tree_delete(node<T> *z)
		{
			if (z->l == nil)
				transplant(z, z->r);
			else
				if (z->r == nil)
					transplant(z, z->l);
				else
				{
					node<T> *y = tree_minimum(z->r);
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

		node<T> *tree_search(node<T> *x, T k)
		{
			if (x == nil || k == x->k )
				return x;
			if (k < x->k )
				return tree_search(x->l, k);
			else
				return tree_search(x->r, k);
		}
		node<T> *tree_search(T k) { return tree_search(root(), k); }

		node<T> *iterative_tree_search(node<T> *x, T k)
		{
			while (x != nil && k != x->k )
				if (k < x->k )
					x = x->l;
				else
					x= x->r;
			return x;
		}
		node<T> *iterative_tree_search(T k) { return iterative_tree_search(root(), k); }

		node<T> *tree_minimum(node<T> *x)
		{
			while (x->l != nil)
				x = x->l;
			return x;
		}

		node<T> *tree_maximum(node<T> *x)
		{
			while (x->r != nil)
				x = x->r;
			return x;
		}

		node<T> *tree_successor(node<T> *x)
		{
			if (x->r != nil)
				return tree_minimum(x->r);
			node<T> *y = x->p;
			while (y != nil && x == y->r )
			{
				x = y;
				y = y->p;
			}
			return y;
		}

		node<T> *tree_predecessor(node<T> *x)
		{
			if (x->l != nil)
				return tree_maximum(x->l);
			node<T> *y = x->p;
			while (y != nil && x == y->l )
			{
				x = y;
				y = y->p;
			}
			return y;
		}

		void rotate_left(node<T> *x)
		{
			node<T> *y = x->r;
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

		void rotate_right(node<T> *x)
		{
			node<T> *y = x->l;
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

		void recursive_pre_order_walk(node<T> *x)
		{
			if(x != nil)
			{
				print(x);
				recursive_pre_order_walk(x->l);
				recursive_pre_order_walk(x->r);
			}
		}
		void recursive_pre_order_walk() { recursive_pre_order_walk(root()); }

		void recursive_in_order_walk(node<T> *x)
		{
			if(x != nil)
			{
				recursive_in_order_walk(x->l);
				print(x);
				recursive_in_order_walk(x->r);
			}
		}
		void recursive_in_order_walk() { recursive_in_order_walk(root()); }

		void recursive_post_order_walk(node<T> *x)
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
		void in_order_walk(node<T> *x) ///non-recursive
		{
			bool fr = false; ///boolean[From Right]
			node<T> *y = tree_minimum(x);
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
