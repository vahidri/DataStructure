/*
 * radix bit BST
 * 01/16/2017 (951027)
 * Vahid Ramazani
*/
#ifndef RBBST_H_
#define RBBST_H_

#include<iostream>
#include<string>
using namespace std;

bool operator < (const string a,const string b) { return a.compare(b)<0; }

class node
{
	private:
		string k;
		node *l, *r, *p;
		friend class tree; ///NOTEWORTHY
	public:
		node(string key) : k(key) { p = l = r = NULL; }
		string key() { return k; }

		///to enable writing x.right() [beside x->right] and so on
		node* left() { return l; }
		node* right() { return r; }
		node* parent() { return p; }
};

class tree
{
	private:
		node *nil;
	public:
		tree()
		{
			nil = new node("");
			///convention
			nil->p = nil;
			nil->l = nil;
			nil->r = nil;
		}
		node *root() { return nil->l; } ///equals to nil->l; just for convention
		//node *nil() { return nil; }

		void tree_insert(node *z)
		{
			node *x, *y;
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

		void transplant(node *u, node *v)
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

		void tree_delete(node *z)
		{
			if (z->l == nil)
				transplant(z, z->r);
			else
				if (z->r == nil)
					transplant(z, z->l);
				else
				{
					node *y = tree_minimum(z->r);
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

		node *tree_search(node *x, string k)
		{
			if (x == nil || k == x->k )
				return x;
			if (k < x->k )
				return tree_search(x->l, k);
			else
				return tree_search(x->r, k);
		}
		node *tree_search(string k) { return tree_search(root(), k); }

		node *iterative_tree_search(node *x, string k)
		{
			while (x != nil && k != x->k )
				if (k < x->k )
					x = x->l;
				else
					x= x->right();
			return x;
		}

		node *tree_minimum(node *x)
		{
			while (x->l != nil)
				x = x->l;
			return x;
		}

		node *tree_maximum(node *x)
		{
			while (x->r != nil)
				x = x->r;
			return x;
		}

		node *tree_successor(node *x)
		{
			if (x->r != nil)
				return tree_minimum(x->r);
			node *y = x->p;
			while (y != nil && x == y->r )
			{
				x = y;
				y = y->p;
			}
			return y;
		}

		node *tree_predecessor(node *x)
		{
			if (x->l != nil)
				return tree_maximum(x->l);
			node *y = x->p;
			while (y != nil && x == y->l )
			{
				x = y;
				y = y->p;
			}
			return y;
		}

		void rotate_left(node *x)
		{
			node *y = x->r;
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

		void rotate_right(node *x)
		{
			node *y = x->l;
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

		void recursive_pre_order_walk(node *x)
		{
			if(x != nil)
			{
				cout<<x->k<<",";
				recursive_pre_order_walk(x->l);
				recursive_pre_order_walk(x->r);
			}
		}
		void recursive_pre_order_walk() { recursive_pre_order_walk(root()); }

		void recursive_in_order_walk(node *x)
		{
			if(x != nil)
			{
				recursive_in_order_walk(x->l);
				cout<<x->k<<",";
				recursive_in_order_walk(x->r);
			}
		}
		void recursive_in_order_walk() { recursive_in_order_walk(root()); }

		void recursive_post_order_walk(node *x)
		{
			if(x != nil)
			{
				recursive_post_order_walk(x->l);
				recursive_post_order_walk(x->r);
				cout<<x->k<<",";
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
		void in_order_walk(node *x) ///non-recursive
		{
			bool fr = false; ///boolean[From Right]
			node *y = tree_minimum(x);
			cout<<y->k<<",";
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
					cout<<y->k<<",";
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
