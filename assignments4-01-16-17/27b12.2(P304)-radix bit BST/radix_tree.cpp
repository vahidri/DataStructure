#include<string>
#include<iostream>
#include "rbbst.h"
using namespace std;

int main()
{
	tree t;
	//t.insert("10");
	//t.insert("1");
	//t.insert("0");
	//t.insert("00");

	t.insert("0");
	t.insert("011");
	t.insert("10");
	t.insert("100");
	t.insert("1011");

	//cout<<t.search("010")->key()<<endl;
	//cout<<t.search("10")->key()<<endl;

	t.recursive_pre_order_walk();
	cout<<endl;

	return 0;
}
