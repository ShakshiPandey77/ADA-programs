/*
Program 8b : Given k sorted lists of integers of size n each, find the smallest range that contains 
at least one element from each of the k lists. If more than one smallest ranges are found, print 
any of them
*/

#include <iostream>
#include <climits> 
using namespace std; 

// A min heap node
struct MinHeapNode 
{ 
	int element; // The element to be stored 
	int i; // index of the list from which the element is taken 
	int j; // index of the next element to be picked from list 
}; 

// function to swap two min heap nodes 
void swap(MinHeapNode *x, MinHeapNode *y); 

// A class for Min Heap 
class MinHeap 
{ 
	MinHeapNode *harr; // pointer to array of elements in heap 
	int heap_size; // size of min heap 
public: 
	// Constructor creates a min heap of given size 
	MinHeap(MinHeapNode a[], int size); 

	// to heapify a subtree with root at given index 
	void MinHeapify(int rootIndex); 

	// to get index of left child of node at index i 
	int left(int i) { return (2*i + 1); } 

	// to get index of right child of node at index i 
	int right(int i) { return (2*i + 2); } 

	// to get the root 
	MinHeapNode getMin() { return harr[0]; } 

	// to replace root with new node x and heapify() new root 
	void replaceMin(MinHeapNode x) { harr[0] = x; MinHeapify(0); } 
}; 

// Constructor  builds a heap from a given array a[] of given size 
MinHeap::MinHeap(MinHeapNode a[], int size) 
{ 
	heap_size = size; 
	harr = a; // store address of array 
	int i = (heap_size - 1)/2; 
	while (i >= 0) 
	{ 
		MinHeapify(i); 
		i--; 
	} 
} 

// A recursive method to heapify a subtree with root at 
// given index. This method assumes that the subtrees 
// are already heapified 
void MinHeap::MinHeapify(int rootIndex) 
{ 
	int l = left(rootIndex); 
	int r = right(rootIndex); 
	int smallest = rootIndex; 
	if (l < heap_size && harr[l].element < harr[rootIndex].element) 
		smallest = l; 
	if (r < heap_size && harr[r].element < harr[smallest].element) 
		smallest = r; 
	if (smallest != rootIndex) 
	{ 
		swap(harr[rootIndex], harr[smallest]); 
		MinHeapify(smallest); 
	} 
} 

// This function takes an k sorted lists in the form of 
// 2D array as an argument. It finds out smallest range 
// that includes elements from each of the k lists. 
void findSmallestRange(int **arr, int n,int k) 
{ 
	// Create a min heap with k heap nodes. Every heap node 
	// has first element of an list 
	int range = INT_MAX; 
	int min = INT_MAX, max = INT_MIN; 
	int start, end; 

	MinHeapNode *harr = new MinHeapNode[k]; 
	for (int i = 0; i < k; i++) 
	{ 
		harr[i].element = arr[i][0]; // Store the first element 
		harr[i].i = i; // index of list 
		harr[i].j = 1; // Index of next element to be stored 
					// from list 

		// store max element in the min heap
		if (harr[i].element > max) 
			max = harr[i].element; 
	} 

	MinHeap hp(harr, k); // Create the heap 

	// Now one by one get the minimum element from min 
	// heap and replace it with next element of its list 
	while (1) 
	{ 
		// Get the minimum element and store it in output 
		MinHeapNode root = hp.getMin(); 

		// update min 
		min = hp.getMin().element; 

		// update range 
		if (range > max - min + 1) 
		{ 
			range = max - min + 1; 
			start = min; 
			end = max; 
		} 

		// Find the next element that will replace current 
		// root of heap. The next element belongs to same 
		// list as the current root. 
		if (root.j < n) 
		{ 
			root.element = arr[root.i][root.j]; 
			root.j += 1; 

			// update max element 
			if (root.element > max) 
				max = root.element; 
		} 

		// break if we have reached end of any list 
		else break; 

		// Replace root with next element of list 
		hp.replaceMin(root); 
	} 

	cout << "The smallest range is " << "["
		<< start << " " << end << "]" << endl;; 
} 

int main(){ 
	int **arr, n, k;
	cout<<"Enter number of lists :";
	cin>>k;
	cout<<"Enter the number of elements in each list :";
	cin>>n;
	
	arr = new int*[k];
	for(int i =0; i<k; i++)
		arr[i] = new int[n];
	cout<<"Enter the lists :\n";
	for(int i =0; i<k;i++){
		cout<<"List "<<i+1<<" : ";
		for(int j =0; j<n; j++)
			cin>>arr[i][j];
	}//end of for
	findSmallestRange(arr,n,k);
	return 0; 
} // end of main

/*
OUPUT :
Enter number of lists :3
Enter the number of elements in each list :5
Enter the lists :
List 1 : 4 7 9 12 15
List 2 : 0 8 10 14 20
List 3 : 6 12 16 30 50
The smallest range is [6 8]
*/
