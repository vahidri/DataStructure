/*
 * radix bit Tree
 * 01/16/2017 (951027)
 * Vahid Ramazani
*/
#ifndef RBBST_H_
#define RBBST_H_

#include<iostream>
#include<string>
using namespace std;

///bool operator < (const string a,const string b) { return a.compare(b)<0; }

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
		node *head;
		void print(node *x) { if(x->k != "-") cout<<x->k<<","; }
		
	public:
		tree()
		{
			nil = new node("nil");
			head = new node("-");
			nil->l = nil->r = head;
			head->p = head->l = head->r = nil->p = nil;
		}
		node *root() { return head; }

		void insert(string z)
		{
			//cerr<<"string: "<<z<<endl;
			node *y = nil;
			node *x = head; ///root
			for(int i=0;i<z.length();++i)
			{
				//cerr<<"dbg: "<<x->k<<endl;
				y = x;
				//if (x->k == "-") x->k = '+';
				if('0'==z[i])
				{
					x = x->l;
					if (x == nil)
					{
						x = new node("-");
						x->p = y;
						x->l = x->r = nil;

						y->l = x;
					}
				}
				else ///'1'
				{
					x = x->r;
					if (x == nil)
					{
						x = new node("-");
						x->p = y;
						x->l = x->r = nil;

						y->r = x;
					}
				}
			}

			x->k = z;
			//cerr<<"dbg: "<<x->k<<endl;
			//cerr<<endl;

		}

		node *search(string k)
		{
			node *x = head; ///root
			for(int i=0;i<k.length();++i)
			{
				if('0'==k[i])
					x = x->l;
				else ///'1'
					x = x->r;

				if (x == nil || k == x->k )
					return x;
			}
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
				print(x);
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
				print(x);
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
		void in_order_walk(node *x) ///non-recursive
		{
			bool fr = false; ///boolean[From Right]
			node *y = tree_minimum(x);
			print(x);
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
					print(x);
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
