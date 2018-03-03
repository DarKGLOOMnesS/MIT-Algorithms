#include<iostream>
using namespace std;

/*函数功能：在已经排好序的数组中查找期望值x,递归二分查找*/
/*参数：数组a,数组起点，数组终点，待查找的期望值*/
int BinarySearch(int a[],int low,int high,int expected)
{
   if(low > high)
	   return -1;
   int mid = (low + high)/2;
   if(a[mid] == expected)
	   return mid;    //数组中间的数字正好是要查找的数
   if(a[mid] < expected)
	   return BinarySearch(a, mid + 1, high, expected);//中间位置的数小于要查找的数，那么在中间数的右区间找
   else
   {
           return BinarySearch(a,low,mid - 1,expected);  //中间位置的数大于要查找的数，那么在中间数的左区间找
   }

}

/*测试函数*/
int main()
{
  int a[7] = {1,3,5,7,9,11,13};
  int ret1 = BinarySearch(a,0,6,9);
  int ret2 = BinarySearch(a,0,6,7);
  int ret3 = BinarySearch(a,0,6,11);
  cout << "数字9在数组a的第" << ret1 << "位" << endl;
  cout << "数字7在数组a的第" << ret2 << "位" << endl;
  cout << "数字11在数组a的第" << ret3 << "位" << endl;
  return 0;
}
