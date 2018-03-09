#include <stdio.h>
#include <limits.h>
void MergeSort(int arr[],int p,int r);
void Merge(int arr[],int p,int q,int r);
int main(int argc, char const *argv[])
{
	/* code */
	int arr[10]={1,5,2,4,8,6,9,8,6,10};
	MergeSort(arr,0,9);
	for(int i=0;i<10;i++)
		printf("%d ",arr[i] );
	getchar();
	return 0;
}
void MergeSort(int arr[],int p,int r)
{
	if (p<r)
	{
		
		int q=(p+r)/2;
		MergeSort(arr,p,q);
		MergeSort(arr,q+1,r);
		Merge(arr,p,q,r);
	}
}
void Merge(int arr[],int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1],R[n2+1];
	for(int i=0;i<n1;i++)
		L[i]=arr[p+i];
	for(int i=0;i<n2;i++)
		R[i]=arr[q+1+i];
	L[n1]=INT_MAX;
	R[n2]=INT_MAX;
	int i=0,j=0;
	for(int k=p;k<r+1;k++)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}		
	}
}

