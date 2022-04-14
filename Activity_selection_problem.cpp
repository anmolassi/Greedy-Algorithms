#include<iostream>
using namespace std;
void swap(int *arr,int m,int n)
{
	int temp=arr[m];
	arr[m]=arr[n];
	arr[n]=temp;
}
int main()
{
	/*pair<int,int> p;
	p.first;
	p.second;*/
	int n;
	cout<<"Enter the number of activities :";
	cin>>n;
	int start[n],end[n],act[n];
	for(int i=0;i<n;i++)
	{
		act[i]=i+1;
		cin>>start[i];
		cin>>end[i];
	}
	// sort with respect to end-time in ascending order
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(end[i]<end[j])
			{
				swap(start,i,j);
				swap(act,i,j);
				swap(end,i,j);
			}
		}
	}
	int time=end[0];
	int count=1;
	cout<<act[0];
	for(int i=1;i<n;i++)
	{
		if(time<=start[i])
		{
			cout<<"->";
			time=end[i];
			count++;
			cout<<act[i];
		}
	}
	cout<<endl;
}
