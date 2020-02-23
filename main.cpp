
   #include <iostream>

using namespace std;

// This function merges the two halves of data into one sorted data.

void Merge(int *c, int start, int end, int mid)
{
	// We have start to mid and mid+1 to end already sorted.
	int i, j, k, temp[end-start+1];
	i = start;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= end)
	{
		if (c[i] < c[j])
		{
			temp[k] = c[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = c[j];
			k++;
			j++;
		}
	}

	// This inserts all the remaining values counting from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = c[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to end into temp[].
	while (j <= end)
	{
		temp[k] = c[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = start; i <= end; i++)
	{
		c[i] = temp[i-start];
	}
}

// A function to split array into two parts.
void MergeSort(int *c, int start, int end)
{
	int mid;
	if (start < end)
	{
		mid=(start+end)/2;
		// Split the data into two half.
		MergeSort(c, start, mid);
		MergeSort(c, mid+1, end);

		// Merge them to get sorted output.
		Merge(c, start, end, mid);
	}
}

int main()
{
	int n, i;
	cout<<"\nEnter the number of data elements for sorting: ";
	cin>>n;

	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}

	MergeSort(arr, 0, n-1);

	// Printing the sorted data.
	cout<<"\nSorted Data is: ";
	for (i = 0; i < n; i++)
        cout<<"->"<<arr[i];

	return 0;

}
