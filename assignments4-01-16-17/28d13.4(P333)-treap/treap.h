/*
 * treap: Augmenting BST with min-heap
 * 01/17/2017 (951028), 03:50 AM
 * Vahid Ramazani
*/
#ifndef TREAP_H_
#define TREAP_H_

#include "pnode.h"
#include "pbst.h"

using namespace std;

template<class T,class U>
class treap: public tree<T,U>
{
	private:
		void mheapify(node<T, U>* x)
		{
			while(x != this->root() && x->priority() < x->parent()->priority())
				if(x == x->parent()->l)
					this->rotate_right(x->parent());
				else
					this->rotate_left(x->parent());
		}
	public:
		treap() : tree<T, U>() { }
		void treap_insert(node<T, U>* x)
		{
			this->tree_insert(x);
			mheapify(x);
		}
};

#endif
