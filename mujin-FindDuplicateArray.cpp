//Given n+1 integers, with range 1 to n, find one that is duplicate
//Use O(1) extra memory to store the incoming array
//Reference: http://keithschwarz.com/interesting/code/?dir=find-

//Algorithm example
//Consider arr[arr[i]] made up a chain, then there must exist a rho loop
//|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
//                      |_______|
//Where c=12 is the open chain, and l=5 is the closed chain
//We can find a location inside the closed chain and denote it as l'
//Solve l'=k*l>12 where k=3 so l'=15
//Now we can easily see that f(l')=f(2l')
//So we can draw two conclusions:
//Starting from the beginning of the chain, given two pointers pt1 and pt2
//If pt1 goes l' step and pt2 goes 2l' step, they colide and same position, then we find the the first flag
//Now pt3 start from the beginning and goes to c while pt1 goes to another c which is l'+c in total, pt1 and pt3 collide at the entrance
//of the loop, the value they are pointing is the value that duplicates
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
