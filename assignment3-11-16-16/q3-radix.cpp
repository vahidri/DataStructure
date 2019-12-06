///remember to enter lower-case letters; otherwise, use the lower_case function

#include<iostream>
using namespace std;

int inter(string s, int dig) { if(s.length()<dig+1) return 0; return s[dig]-96; }

void radix_sort(string* ps, int size);
void dig_sort(string* ps, int size, int dig);

void outy(string* s, int size);
void outy(int* c, int size)
{
	for(int i=0;i<size;++i)
		cout<<c[i]<<" ";
	cout<<endl;
}
char lower_case(char c);

int main()
{	
	string* ss= new string[5];
	ss[3] = "a";
	ss[4] = "ab";
	ss[2] = "b";
	ss[1] = "c";
	ss[0] = "cd";
	cout<<"initial:\n";
	outy(ss,5);
	radix_sort(ss, 5);
	cout<<endl<<"sorted:\n";
	outy(ss, 5);
	cout<<"\ndone";
	return 0;
}

void radix_sort(string* ps, int size) ///size is string count
{
	int max_len=0;
	///get max length
	for(int i=0;i<size;++i)
		if(ps[i].length() > max_len)
			max_len = ps[i].length();
	
	for(int i=max_len-1;i>=0;--i)
	{
		dig_sort(ps, size, i);
		//cout<<"dig: "<<i<<"\n";
	}
		
}

void dig_sort(string* ps, int size, int dig) ///using counting sort algorithm
{
	string* ptmp = new string[size];
	int* c = new int[27];
	
	int i;
	for(i=0;i<size;++i)
		++c[inter(ps[i], dig)];
	
	for(i=1;i<27;++i)
		c[i] += c[i-1];
	
	//outy(c, 27);
	for(i=size-1;i>=0;--i)
		//ptmp[ c[ inter(ps[i], dig) ]-- -1 ] = ps[i]; ///art :D
		ptmp[ --c[ inter(ps[i], dig) ] ] = ps[i]; ///even better!
	
	for(int i=0;i<size;++i)
		ps[i] = ptmp[i];
	delete [] ptmp;
	delete [] c;
}

char lower_case(char c)
{
	///'A' 65
	///'a' 97
	///97-65=32
	
	///assuming it's in range ( [a-z] or [A-Z] )
	if (c>=65)
		return c-32;
	return c;
}

void outy(string* s, int size)
{
	for(int i=0;i<size;++i)
		cout<<s[i]<<endl;
	cout<<endl;
}