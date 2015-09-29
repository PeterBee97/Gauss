#include<iostream>
using namespace std;
int a[100][101],temp,i,i2,j,k,n;

void printa()
{
	for (int i = 0; i <n; ++i)
	{
		for(int j=0;j<=n;j++)cout<<a[i][j]<<" ";
			cout<<endl;
	}
}

void swapxy(int x,int y)
{
	int k,temp;
	for (k = 0; k <= n; ++k)
			{
				temp=a[x][k];
				a[x][k]=a[y][k];
				a[y][k]=temp;
			}
}

int gcd(int m,int n)
{
	return m%n?gcd(n,m%n):n;
}

void del(int l1,int l2,int code)
{
	if(!a[l2][l1]) return;
	int g=gcd(a[l1][l1],a[l2][l1]);
    int p1=a[l2][l1]/g;
    int p2=a[l1][l1]/g;
	if (code==0)
        for (int i = l1; i < n; ++i)
        {  	a[l1][i]*=p1;
            a[l2][i]*=p2;//get lcm
            a[l2][i]-=a[l1][i];//delete
        }
	else
        for (int i = l1; i >= 0; --i)
        {
            a[l1][i]*=p1;
            a[l2][i]*=p2;//get lcm
            a[l2][i]-=a[l1][i];//delete
        }
    a[l1][n]*=p1;
    a[l2][n]*=p2;
    a[l2][n]-=a[l1][n];//process the last element
}

int main()
{
    cout<<"input n,then input the matrix:";
    cin>>n;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			cin>>a[i][j];
		}
	}	//init
	cout<<"Reading complete,calculating...\n";
	for (i = 0; i < n; ++i)
	{
		if (a[i][i]==0)
		{
			for (i2 = i+1; i2 < n; ++i2)
			{
				if(a[i2][i]!=0)
				{
					swapxy(i,i2);
					i2=n+1;
				}
			}
		};
		for (i2 = i+1; i2 < n; ++i2)
		{
			del(i,i2,0);//将第i2行化为0,消成上三角
		}
	}
	for(i=n-1;i>=0;--i)
    {
        if(a[i][i]==0)
        {
            if (a[i][n]!=0) {cout<<"No solution";return 0;} else {cout<<"Infinite solutions";return 0;}
        }else
            for (i2 = i-1; i2 >= 0; --i2)
		{
			del(i,i2,1);//将第i2行化为0,消成对角线
		}
    }
	//printa();
	for(i=0;i<n;i++)//print solution
    {
        cout<<"a"<<i+1<<"="<<1.0*a[i][n]/a[i][i]<<endl;
    }
	return 0;
}
