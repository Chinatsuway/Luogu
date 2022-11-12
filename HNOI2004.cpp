#include<bits/stdc++.h>
using namespace std;
int mp[114][114],num[514][514],f[191][981][60];
int main()
{
	int n,m,ans,broke;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			cin>>mp[i][j];
	memset(f,-1,sizeof(f));
    f[n][1][1]=mp[1][n];
    f[n][0][0]=0;
    for (int j=1;j<=n;j++)
        for (int i=1;i<=n-j+1;i++)
            num[j][i]=num[j][i-1]+mp[i][j];
    for(int i=n-1;i>=1;i--)
    {
    	for(int j=0;j<=m && j<=(n-i+1) * (n-i+2)/2;j++)
    	{
    		for (int k=0;k<=j && k<=n-i+1;k++)
            {
            	broke=0;
            	if(broke<k-1)	broke=k-1;
                for (int p=broke;p<=n-i;p++)
                    if (j>=k && p<=j-k && f[i+1][j-k][p]>=0)
                    	if(f[i][j][k]<f[i+1][j-k][p])
                    		f[i][j][k]=f[i+1][j-k][p];
                if (f[i][j][k]>=0)
                    f[i][j][k]+=num[i][k];
                if(ans<f[i][j][k])
                	ans=f[i][j][k];
            }
		}
	}
	cout<<ans;
	return 0;
}
