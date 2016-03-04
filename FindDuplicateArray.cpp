//Given n+1 integers, with range 1 to n, find one that is duplicate
//Use O(1) extra memory to store the incoming array
//Reference: http://keithschwarz.com/interesting/code/?dir=find-duplicate
#include <iostream>
int findDuplicate(int* a,int length)
{
	int slow=length-1;
	int fast = length - 1;
	
	while(1)
	{
		slow=a[slow];
		fast=a[a[fast]];
		
		if(slow==fast)
		{
			break;
		}
	}
	
	int finder = length - 1;
	
	while(1)
	{
		slow=a[slow];
		finder=a[finder];
		
		if(slow==finder)
		{
			return slow;
		}
	}
	
}

int main()
{
	//n variables ranging from 0~n-1
	//e.g. f(arr[4])=f(3)=arr[3]=1
	//Once the first iteration ends, it never goes back to arr[4] since there is no 4 in this array
	int arr[5]={1,2,1,2,3};
	int value=findDuplicate(arr,sizeof(arr)/sizeof(arr[0]));

	std::cout << value << std::endl;

	std::cin.get();
	return 0;
}
