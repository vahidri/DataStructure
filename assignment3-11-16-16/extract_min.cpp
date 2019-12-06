/*
* Q1, young table
* extract minimum from the Matrix(m x n), maintaining its order
	* in Theta(m+n)
*/

#include<iostream>
using namespace std;

#define Def_extracted -1
#define Def_data_type int

int m, n;
Def_data_type ** matrix;
    
void outy();
Def_data_type extract();
void swap_elements(Def_data_type i, Def_data_type j, Def_data_type k, Def_data_type l);

int main()
{
	m = 3;
	n = 4;
	matrix = new Def_data_type*[m];
	for(int i=0;i<n;++i)
		matrix[i] = new Def_data_type[n];

	matrix[0][0] = 2;
	matrix[0][1] = 3;
	matrix[0][2] = 3;
	matrix[0][3] = 4;

	matrix[1][0] = 3;
	matrix[1][1] = 4;
	matrix[1][2] = 6;
	matrix[1][3] = 7;

	matrix[2][0] = 4;
	matrix[2][1] = 4;
	matrix[2][2] = 8;
	matrix[2][3] = 9;

	cout<<"initial matrix"<<endl;
	outy();
	cout<<endl;

	int times = 3;
	for(int i=0;i<times;++i)
	{
		cout<<"extracted: "<<extract();
		cout<<endl<<endl;
		outy();
		cout<<endl<<endl;
	}
	return 0;
}

void outy()
{
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

Def_data_type extract()
{
	int i=0, j=0;
	Def_data_type out=Def_extracted;
	if (Def_extracted == matrix[0][0]) //matrix is empty/full of infinity :D
		return Def_extracted;
	out = matrix[0][0];
	matrix[0][0] = Def_extracted;
	int bound_row = m-1;
	int bound_col = n-1;
	while(i<bound_row || j<bound_col)
	{
		if(i<bound_row && j<bound_col)
			if(matrix[i+1][j] <= matrix[i][j+1])
			{
				swap_elements(i, j, i+1, j);
				++i;
			}
			else
			{
				swap_elements(i, j, i, j+1);
				++j;
			}
		else if(j<bound_col)
		{
			for(;j<bound_col;++j)
				if(matrix[i][j+1]!=Def_extracted)
					swap_elements(i,j,i,j+1);
				else //adjacent to another infinity
					break;
			j=bound_col; //done doing columns
		}
		else if(i<bound_row)
		{
			for(;i<bound_row;++i)
					if(matrix[i+1][j]!=Def_extracted)
						swap_elements(i,j,i+1,j);
					else //adjacent to another infinity
						break;
			i=bound_row; //done doing rows
		}
		else
			cerr<<"something is wrong!"<<endl; //ilogical state!
	}
	return out;
}

void swap_elements(Def_data_type i, Def_data_type j, Def_data_type k, Def_data_type l)
{
	Def_data_type tmp = matrix[i][j];
	matrix[i][j] = matrix[k][l];
	matrix[k][l] = tmp;
}

