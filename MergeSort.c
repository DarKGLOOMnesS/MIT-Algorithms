#include<stdio.h>

/*合并两个已经排好的数组，其中p为第一个数组的起点，q为第一个数组的终点*/
/*r为第二个数组的终点.有序数组为a[p,...q]和a[q+1,...,r]*/
void merge(int a[],int p, int q,int r)
{
   int length1 = q-p+1;    //length1是第一个有序数组的长度
   int length2 = r-q;      //length2是第二个有序数组的长度

   //将合并的数组存入到临时数组L,R中
   int L[length1],R[length2];
   for(int i = 0; i < length1; i++)
	   L[i] = a[p+i];
   for(int j = 0; j < length2; j++)
	   R[j] = a[q+j+1];
   int i = 0,j = 0,k = 0;
   /*比较两个临时数组元素，将较小的值存入原数组，直到L或R数组访问完最后一个元素*/
   while(i < length1 && j < length2)
   {
      if(L[i] < R[j])
      {
         a[p+k] = L[i];
	 i++;
      }
      else
      {
        a[p+k] = R[j];
	j++;
      }
      k++;
   }

   /*如果R数组到达尾部时，L数组没有到达尾部*/
   while(i < length1)
   {
     a[p+k] = L[i];
     i++;
     k++;
   }
   /*如果R数组没有达到尾部，L数组达到尾部时*/
   while(j < length2 )
   {
     a[p+k] = R[j];
     j++;
     k++;
   }
}

/*函数实现功能:归并排序（递归算法）*/
//传入参数：int a[]数组，p为起点，r为终点
void MergeSort(int a[], int p ,int r)
{
  //假如待合并的数组长度为1，则返回
  int length = r-p+1;
  if(length == 1)
	  return;
  int q = (p+r) / 2;
  MergeSort(a,p,q);
  MergeSort(a,q+1,r);
  merge(a,p,q,r);
}

/*测试函数*/
int main()
{
  int i = 0;
  int a[] = {8,2,4,9,3,6};
  MergeSort(a,0,5);
  for(i=0;i<6;i++)
  {
    printf("%d",a[i]);
  }
  return 0;
}
