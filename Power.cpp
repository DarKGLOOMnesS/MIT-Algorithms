#include<iostream>
using namespace std;

/*函数功能:利用分治策略实现乘方问题*/

int Power(int x, int n)
{
  if (n == 0)              //如果n为零,则返回1,因为任何数的零次幂都为1
	  return 1;        
  if (n == 1)             //如果n为1,则返回这个数本身,因为任何数的1次幂都是本身           
          return x;
  int t = Power(x, n / 2);
  if (n & 0x01 == 1)       //如果n为奇数  
	  return t * t * x;
  else 
	  return t * t;    //n为偶数时
}

/*测试函数*/
int main()
{
  int result = Power(5,3);
  cout << "5的三次方是:" << result << endl;
  return 0;
}
