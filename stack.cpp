//stack using template
#include<iostream>
//#include "stack.h"
using namespace std;

template<class T>
class stack
{
private:
	int top;
	T data[100];
public:
	stack();
	void push(T i);
	T pop();
	int size();
};

int main()
{
	stack<int> s_int;
	s_int.push(5);
	s_int.push(12);
	s_int.push(-2);

	while(s_int.size() > 0)
		cout<<s_int.pop()<<' ';
	cout<<endl;
	return 0;
}

template<class T>
stack<T>::stack()
{
	top = -1;
}

template<class T>
void stack<T>::push(T inp)
{
	data[++top] = inp;
}

template<class T>
T stack<T>::pop()
{
	if (top < 0)
		cerr<<"ERR: popping empty stack"<<endl;
	else
		return data[top--];
}

template<class T>
int stack<T>::size()
{
	return top+1;
}
