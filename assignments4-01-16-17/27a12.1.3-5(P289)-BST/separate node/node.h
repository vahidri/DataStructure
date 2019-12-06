#ifndef NODE_H_
#define NODE_H_

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

#endif
