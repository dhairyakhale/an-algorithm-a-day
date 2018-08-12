#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int f, int l)
{
	int pivot = f;
	f++;

	while(f<=l)
	{
		while(arr[f]<=arr[pivot])
			f++;
		while(arr[l]>arr[pivot])
			l--;
		if(f<l)
		{
			swap(&arr[f],&arr[l]);
		}
	}
	swap(&arr[pivot], &arr[l]);
	return l;
}

void quicksort(int arr[],int f, int l)
{
	if(f<l)
	{
		int pi = partition(arr, f, l);

		quicksort(arr, f, pi-1);
		quicksort(arr, pi+1, l);
	}
}


int main()
{
	int arr[] = {1, 5, 2, 4, 10, 8, 7, 9, 3, 6};
	int n = sizeof(arr)/sizeof(arr[0]);

	quicksort(arr, 0, n-1);

	cout<<"Sorted array: "<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	
	cout<<endl;

	return 0;
}