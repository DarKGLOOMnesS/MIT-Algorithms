#include<stdio.h>

//暴力解法
//利用C语言结构体,定义矩阵
const int MAXN = 1000;
struct matrix
{
  int n,m;
  double data[MAXN][MAXN];
};
/*利用矩阵乘法定义求解矩阵相乘问题*/
int  MatrixMultiply(matrix& c, const matrix& a, const matrix& b)
{
   if(a.m != b.n)
	   return 0;
   c.n = a.n;
   c.m = b.m;
   for(int i = 0; i < c.n; i++)
	   for(int j = 0; j < c.m; j++)
	   {
	     c.data[i][j] = 0;
	     for(int k = 0; k < a.m; k++)
		     c.data[i][j] += a.data[i][j] += a.data[i][k] * b.data[k][j];
	   }
   return 1;
}

/*测试函数不会写*/
