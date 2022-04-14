#include<iostream>
using namespace std;
double profit(int k, int n, int w, int * weight, int *price)
{
	if(n==0)
	{
		return 0;
	}
	if(w==0)
	{
		return 0;
	}
	if(w<weight[0])
	{
		double ans=(((w*1.0)/weight[0])*price[0]);
		return max(profit(k,n-1,w,weight+1,price+1),ans);
	}
	return max(price[0]+profit(k,n-1,w-weight[0],weight+1,price+1),profit(k,n-1,w,weight+1,price+1));
}
int main()
{
	int n;
	cout<<"Enter the number of items : ";
	cin>>n;
	cout<<"Enter the weight of each item :"<<endl;
	int weight[n];
	for(int i=0;i<n;i++)
	{
		cin>>weight[i];
	}
	cout<<"Enter the price of each item :"<<endl;
	int price[n];
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	int w;
	cout<<"Enter the weight of the sack :";
	cin>>w;
	double ans =profit(0,n,w,weight,price);
	cout<<"PROFIT :"<<ans;
}
