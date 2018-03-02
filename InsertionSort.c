#include<stdio.h>

void InsertionSort(int a[],int length)
{
   for (int i = 1 ; i < length; i++)
   {
      int key = a[i];     //从待插入的数组中取出第一个元素
      int j = i-1;       //i-1为有序组最后一个元素的下标，与待插入元素相邻
      while(j>=0 && a[j]>key)//j>=0是边界限制，a[j]>key插入条件判断
      {
        a[j+1] = a[j];//若不是合适位置，则有序组元素向后移动
	j--;
      }
      a[j+1] = key;  //找到合适位置，将元素插入
   }
}

int main()
{
  int i = 0;
  int a[] = {8,2,4,9,3,6};
  InsertionSort(a,6);
  for(i=0;i<6;i++)
  {
    printf("%d",a[i]);
  }
  return 0;
}
