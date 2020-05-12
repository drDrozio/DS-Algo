#include<iostream>

using namespace std;

int* selectionSort(int* a,int size)
{
	for(int i=0;i<size-1;i++)
	{
		int minIndex=i;
		for(int j=i+1;j<size;j++)
		{
			if(a[j]<a[minIndex])
			{
				minIndex=j;
			}
		}
		int temp=a[i];
		a[i]=a[minIndex];
		a[minIndex]=temp;
	}
	return a;
}

bool binarySearch_iter(int* a,int size,int x)
{
	int* ptr=selectionSort(a,size);
	cout<<"Sorted array: ";
	//Printing array
	cout<<"Array = [";
	for(int i=0;i<size-1;i++)
	{
		cout<<a[i]<<",";
	}
	cout<<a[size-1]<<"] "<<endl;
	
	int start=0;
	int end=size-1;
		
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(ptr[mid]==x)
			return true;
		else
		{
			if(x<ptr[mid]) //Left
				end=mid-1;
			else //Right
				start=mid+1;	
		}	
	}
	return false;
}

int* bubbleSort(int* a,int size)
{
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			else
				continue;
		}
	}
	return a;
}

int* insertionSort(int*a,int size)
{
	for(int i=1;i<size;i++)
	{
		int temp=a[i];
		int j=i-1;
		while(j>=0 && temp<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	return a;
}

int* shellSort(int*a,int n)
{
	int gap=n/2;
	while(gap>=1)
	{
		for(int i=0;i<n-gap+1;i++)
		{
			if(a[i]>a[i+gap])
			{
				int temp=a[i+gap];
				a[i+gap]=a[i];
				a[i]=temp;
			}
		}
		gap=gap/2;
	}
	return a;
}


void mergeSortFunc(int*a,int start,int end,int size)
{
	if(start>=end)
	{
		return;
	}
	
	int mid=(start+end)/2;
	mergeSortFunc(a,start,mid,size/2);
	mergeSortFunc(a,mid+1,end,size/2);
	
	int i=start;
	int j=mid+1;
	int*c=new int[end-start+1];
	int k=0;
	while(i<=mid && j<=end)
	{
		if(a[i]>=a[j])
		{
			c[k]=a[j];
			j++;
		}
		else
		{
			c[k]=a[i];
			i++;
		}
		k++;
	}
	while(i<=mid)
	{
		c[k++]=a[i++];
	}
	while(j<=end)
	{
		c[k++]=a[j++];
	}
	int l=0;
    for(int m=start;m<=end;m++,l++)
    {
        a[m]=c[l];
    }
}

int* mergeSort(int*a,int size)
{
	if(size==0 ||size==1)
		return a;
	else
	{
		int start=0;
		int end=size-1;
		mergeSortFunc(a,start,end,size);
		return a;
	}
}

int partition(int*a,int start,int end)
{
	int pivot=a[start];
	
	int t=0;
	int count=0;
	while(a[t]<=pivot)
	{
		count++;
		t++;
	}
	int temp=a[start+count];
	a[start+count]=pivot;
	a[start]=temp;
	
	int i=start;
	int j=end;
	while(i<j)
	{
		if(a[i]<=pivot)
			i++;
		else
		{
			if(a[j]>=pivot)
				j--;
			else
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				i++;
				j--;
			}	
		}	
	}
	return start+count;
}


void quickSorter(int*a,int start,int end)
{
	if(start>=end)
		return;
		
	int c=partition(a,start,end);
	
	quickSorter(a,start,c-1);
	quickSorter(a,c+1,end);
}

int* quickSort(int*a,int size)
{
	int start=0;
	int end=size-1;
	quickSorter(a,start,end);
	return a;
}


int* countSort(int*a,int size)
{
	int op[size+1];
	int max=0;
	for(int i=0;i<size;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	int count[max];
	for(int i=0;i<=max;i++)
	{
		count[i]=0;
	}
	
	for(int i=0;i<size;i++)
	{
		count[a[i]]++;
	}
	
	for(int i=1;i<=max;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	
	for(int i=0;i<size;i++)
	{
		op[count[a[i]]]=a[i];
		count[a[i]]--;
	}
	for (int i=0;i<size;i++){
		a[i]=op[i+1];
	}
	return a;
}

int main()
{
	int size;
	cout<<"Enter size of array ";
	cin>>size;
	
	int a[size];
	cout<<endl<<"Enter elements of array ("<<size<<") ";
	//Taking array input
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	//Printing array
	cout<<"Array = [";
	for(int i=0;i<size-1;i++)
	{
		cout<<a[i]<<",";
	}
	cout<<a[size-1]<<"] "<<endl;
	
	
	//Searching:-
	/*int x;
	cout<<endl<<"Enter element to be searched ";
	cin>>x;
	
	//Binary search
	bool presence=binarySearch_iter(a,size,x);
	if(presence==true)
		cout<<endl<<"Number present";
	else
		cout<<endl<<"Number not present";
	
    */
	//Sorting:-
	
	/*
	//Bubble Sort
	int *pBubble=bubbleSort(a,size);
	cout<<"Sorted array: ";
	//Printing array
	cout<<"Array = [";
	for(int i=0;i<size-1;i++)
	{
		cout<<pBubble[i]<<",";
	}
	cout<<pBubble[size-1]<<"] "<<endl;
	
	//Insertion Sort
	int *pIns=insertionSort(a,size);
	cout<<"Sorted array: ";
	//Printing array
	cout<<"Array = [";
	for(int i=0;i<size-1;i++)
	{
		cout<<pIns[i]<<",";
	}
	cout<<pIns[size-1]<<"] "<<endl;
	
	
	//Shell Sort
	int *pShell=shellSort(a,size);
	cout<<"Sorted array: ";
	//Printing array
	cout<<"Array = [";
	for(int i=0;i<size-1;i++)
	{
		cout<<pShell[i]<<",";
	}
	cout<<pShell[size-1]<<"] "<<endl;
	*/
	
	//Quick Sort
	int *pQuick=quickSort(a,size);
	cout<<"Sorted array: ";
	//Printing array
	cout<<"Array = [";
	for(int i=0;i<size-1;i++)
	{
		cout<<pQuick[i]<<",";
	}
	cout<<pQuick[size-1]<<"] "<<endl;
	
	
	//Counting Sort
	int *pCount=countSort(a,size);
	cout<<"Sorted array: ";
	//Printing array
	cout<<"Array = [";
	for(int i=0;i<size-1;i++)
	{
		cout<<pCount[i]<<",";
	}
	cout<<pCount[size-1]<<"] "<<endl;
}
