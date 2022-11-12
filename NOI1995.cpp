/*
在一个圆形操场的四周摆放 N 堆石子，现要将石子有次序地合并成一堆，规定每次只能选相邻的 2 堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。
试设计出一个算法,计算出将 N 堆石子合并成 1 堆的最小得分和最大得分。

输入格式
数据的第 1 行是正整数 N，表示有 N 堆石子。
第 2 行有 N 个整数，第 i 个整数 a_i表示第 i 堆石子的个数。

输出格式
输出共 2 行，第 1 行为最小得分，第 2 行为最大得分。
*/

#include<iostream>
#include<cmath>
using namespace std;
const int MAX=99999999;
int n,a[201],h[101],f1[301][301],f2[301][301],min1=MAX,max1=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[n+i]=a[i];
	}
	for(int i=1;i<=2*n;i++)
	h[i]=h[i-1]+a[i];
	for(int i=1;i<(2*n);i++)
	{f1[i][i]=0;f2[i][i]=0;}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<(2*n)-l+1 ;i++)
		{
			int j=i+l-1;
			f2[i][j]=MAX;
			for(int k=i;k<j;k++)
			{
				if(f1[i][j]<f1[i][k]+f1[k+1][j]+(h[j]-h[i-1]))
					f1[i][j]=f1[i][k]+f1[k+1][j]+h[j]-h[i-1];
				if(f2[i][j]>f2[i][k]+f2[k+1][j]+(h[j]-h[i-1]))
					f2[i][j]=f2[i][k]+f2[k+1][j]+(h[j]-h[i-1]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{	
		if(max1<f1[i][i+n-1])
			max1=f1[i][i+n-1];
		if(min1>f2[i][i+n-1])
			min1=f2[i][i+n-1];
	}
	cout<<min1<<endl;
	cout<<max1;
	return 0;
}
