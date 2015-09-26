#include<iostream>
void swap(int x,y)
{
	int k,temp;
	for (k = 0; k <= n; ++k)
			{
				temp:=a[x][k];
				a[x][k]=a[y][k];
				a[y][k]=temp;
			}
}

void del(x,l)
{

}

int main()
{
	int a[100][101],temp,i,i2,j,k,n;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			cin>>a[i][j];
		}
	}	//init
	for (i = 0; i < n; ++i)
	{
		if (a[i][i]=0)
		{
			for (i2 = i+1; i2 < n; ++i2)
			{
				if(a[i2][i]!=0)
				{
					swap(i,i2);
					i2=n+1;
				}
			}
		}else
		for (i2 = i+1; i2 < n; ++i2)
		{
			del(a[i][i],i2);
		}
	}
	return 0;
}