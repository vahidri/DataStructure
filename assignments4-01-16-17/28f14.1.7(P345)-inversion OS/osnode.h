#ifndef OSNODE_H_
#define OSNODE_H_

template<class T>
class node
{
	private:
		T k;
		int size;
		node<T> *l, *r, *p;
		template<class> friend class tree; ///NOTEWORTHY
	public:
		node(T key) : k(key) { p = l = r = NULL; size = 0; }
		node(T key,int inpSize) : k(key) { p = l = r = NULL; size = inpSize; }
		T key() { return k; }

		node<T>* left() { return l; }
		node<T>* right() { return r; }
		node<T>* parent() { return p; }
		int s() { return size; }
};

#endif
