#ifndef PNODE_H_
#define PNODE_H_

template<class T, class U>
class node
{
	private:
		T k;
		U pr; ///heap
		node<T, U> *l, *r, *p;
		template<class, class> friend class tree;
		template<class, class> friend class treap;
	public:
		node(T key, U pri) : k(key), pr(pri) { p = l = r = NULL; }
		T key() { return k; }
		U priority() { return pr; }

		///to enable writing x.right() [beside x->right] and so on
		node<T, U>* left() { return l; }
		node<T, U>* right() { return r; }
		node<T, U>* parent() { return p; }
};

#endif
