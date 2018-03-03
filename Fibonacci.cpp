#include<iostream>
using namespace std;

struct Matrix
{
   int data[2][2];
};

/*函数功能:实现矩阵相乘,利用两个矩阵相乘的定义编写代码*/
Matrix Mutiply(const Matrix& a, const Matrix& b)
{
   Matrix c;
   for(int i = 0; i < 2; i++)
   {
      for(int j = 0; j < 2; j++)
      {
         c.data[i][j] = 0;
	 for(int k = 0; k < 2; k++)
		 c.data[i][j] += a.data[i][k] * b.data[k][j];
      }
   }
   return c;
}

/*函数功能:类似与乘方问题,根据分之策略利用平方递归的方法进行划分*/
Matrix MatrixOperate(int n)
{
  Matrix m;
  int data[2][2] = {{1,1},{1,0}};
  for(int i = 0; i < 2; i++)
	  for(int j = 0; j < 2; j++)
		  m.data[i][j] = data[i][j];
  if(n == 1)
	  return m;
  Matrix t = MatrixOperate( n / 2);//继续向下划分
  if(n & 0x01 == 1)                //当n是奇数时,把（n & 0x01) == 0换成（n % 2) == 0等价 ， 唯一区别在于（n & 0x01) == 0计算效率高
	  return Mutiply(Mutiply(t,t),m);
  else                             //当n是偶数时
	  return Mutiply(t,t);
}

/*函数功能:求第n位斐波那契数列的值*/
int Fibonacci(int n)
{
   if(n <= 0)
	   return 0;
   if(n == 1)
	   return 1;
   Matrix m = MatrixOperate(n-1);
   return m.data[0][0];
}

/*测试函数*/
int main()                      //溢出问题还没有解决:(
{
  int  x = Fibonacci(5);
  int  y = Fibonacci(6);
  int  z = Fibonacci(9);
  int  e = Fibonacci(47);
  cout << "第5位斐波那契数列的值是:" << x << endl;
  cout << "第6位斐波那契数列的值是:" << y << endl;
  cout << "第9位斐波那契数列的值是:" << z << endl;
  cout << "第47位斐波那契数列的值是:" << e << endl;
  return 0;
}
