
#include<conio.h>
#include<iostream>
#include <stdlib.h> 
#include <time.h> 
using namespace std; 


void swap (int arr[],int i,int j) 
{
    int temp= arr[i];
    arr[i]= arr[j];
    arr[j]=temp;
}


void printArray (int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 


void randomize (int arr[], int n) 
{ 
	// i just got to know about this seed means itll take random clock input whenver program is run so that u dont  get same random sequence everytime
	srand (time(NULL)); 

	for (int i = n - 1; i > 0; i--) 
	{ 
	
		int j = rand() % (i + 1); 
 
		swap(arr,i,j); 
	} 
} 

int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
     cout<<n<<endl;
     
	randomize (arr, n); 
	printArray(arr, n); 

	return 0; 
} 
 
