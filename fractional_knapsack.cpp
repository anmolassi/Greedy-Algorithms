#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the no. of objects :";
	cin>>n;
	int objects[n];
	int value[n];
	int weight[n];
	int ratio[n];
	double profit=0;
	cout<<"Enter the capacity of knapsnack:";
	int capacity;
	cin>>capacity;
	int backup=capacity;
	for(int i=0;i<n;i++)
	{
		objects[i]=i+1;
		cout<<"Enter the weight of object"<<i+1<<":";
		cin>>weight[i];
		cout<<"Enter the value of object"<<i+1<<":";
		cin>>value[i];
		ratio[i]=value[i]/weight[i];
	}
	cout<<endl<<endl<<endl;
	cout<<"Weight perference profit :";
	for(int i=0; i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(weight[i]<weight[j])
			{
				int temp;
				temp=weight[i];
				weight[i]=weight[j];
				weight[j]=temp;
				temp=objects[i];
				objects[i]=objects[j];
				objects[j]=temp;
				temp=value[i];
				value[i]=value[j];
				value[j]=temp;
				temp=ratio[i];
				ratio[i]=ratio[j];
				ratio[j]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(weight[i]<=capacity)
		{
			profit+=value[i];
			capacity-=weight[i];
		}
		else
		{
			profit+=(value[i]/weight[i])*(capacity);
			capacity=backup;
			break;
		}
	}
	cout<<profit<<endl;
	profit=0;
	cout<<"value perference : ";
	for(int i=0; i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(value[i]>value[j])
			{
				int temp;
				temp=weight[i];
				weight[i]=weight[j];
				weight[j]=temp;
				temp=objects[i];
				objects[i]=objects[j];
				objects[j]=temp;
				temp=value[i];
				value[i]=value[j];
				value[j]=temp;
				temp=ratio[i];
				ratio[i]=ratio[j];
				ratio[j]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(weight[i]<=capacity)
		{
			profit+=value[i];
			capacity-=weight[i];
		}
		else
		{
			profit+=(1.0*value[i]/weight[i])*(capacity);
			capacity=backup;
			break;
		}
	}
	cout<<profit<<endl;
	profit=0;
	cout<<"ratio preference : ";
	for(int i=0; i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ratio[i]>ratio[j])
			{
				int temp;
				temp=weight[i];
				weight[i]=weight[j];
				weight[j]=temp;
				temp=objects[i];
				objects[i]=objects[j];
				objects[j]=temp;
				temp=value[i];
				value[i]=value[j];
				value[j]=temp;
				temp=ratio[i];
				ratio[i]=ratio[j];
				ratio[j]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(weight[i]<=capacity)
		{
			profit+=value[i];
			capacity-=weight[i];
		}
		else
		{
			profit+=(value[i]/weight[i])*(capacity);
			capacity=backup;
			break;
		}
	}
	cout<<profit<<endl;
}
