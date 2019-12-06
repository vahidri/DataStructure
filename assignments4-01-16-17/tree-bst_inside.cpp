#include<iostream>
using namespace std;

template<class T>
class node
{
	private:
		T k;
		node<T> *l, *r, *p;
		template<class> friend class tree; ///NOTEWORTHY
	public:
		node(T key) : k(key) { p = l = r = NULL; }
		T key() { return k; }

		///to enable writing x.right() [beside x->right] and so on
		node<T>* left() { return l; }
		node<T>* right() { return r; }
		node<T>* parent() { return p; }
};

template<class T>
class tree
{
	private:
		node<T> *nil;
	public:
		tree()
		{
			nil = new node<T>(0);
			///convention
			nil->p = nil;
			nil->l = nil;
			nil->r = nil;
		}
		node<T> *root() { return nil->l; } ///equals to nil->l; just for convention
		//node<T> *nil() { return nil; }

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
					x= x.rigth();
			return x;
		}

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
				cout<<x->k<<",";
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
				cout<<x->k<<",";
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
		void in_order_walk(node<T> *x) //non-recursive
		{
			bool fr = false; ///boolean[From Right]
			node<T> *y = tree_minimum(x);
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
	
	cout<<"\nnon-recursive in_order_walk\n";
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
	return 0;
}
