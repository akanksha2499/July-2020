#include<iostream>
#include<new>

using namespace std;

int prime(int num)//function to check passed element to e filled is prime or not
   {
   	int i,flag=0;
   	for(i=2;i<num/2;i++)
   	   {
   	   	if(num%i==0)
   	   	    {
   	   	  	    flag++;
   	   	  	    return flag;
		    }
	   }
	return flag;
   }

void* read(int *ptr,int n)//function to read elements of array of prime numbers less than the number entered by the user
    {
    	int i=0,temp=n;
    	while(temp<=n)
    	     {
    	     	if(!prime(temp))
    	     	  {
    	     	  	ptr[i]=temp;
    	     	  	i++;
				  }
				temp--;
			 }
	}

void del(int *ptr,int num)//function to delete used prime number from array
    {
    	int i,flag=0;
    	for(i=0;ptr[i+1]!=2;i++)
    	   {
    	   	ptr[i]=ptr[i+1];
    	   	flag++;
		   }
		ptr[flag]=ptr[i+1];
		ptr[flag+1]=num;
	}	

void check(int *ptr,int n)//function to check and display the two prime numbers whose sum equals 
//to the number entered by user
    {
    	int temp,i;
    	do
    	     {
    	     	temp=ptr[0],i=0;
    	     	while(temp>=ptr[i])
    	     	     {
    	     	     	if(temp+ptr[i]==n)
    	     	     	  {
    	     	     	  	cout<<n<<"="<<temp<<"+"<<ptr[i]<<endl;
						  }
						i++;
					  }
				del(ptr,2);
			 }while(ptr[0]!=2);
	}
	
int main()
   {
   	int *ptr,n;
   	cout<<"Enter an integer to express it as sum of two prime numbers"<<endl;
   	cin>>n;
   	if(n==1 || n==2 || n==3)
   	    cout<<"Number can't be expressed as sum of two prime numbers";
   	else
   	  {
   	  	ptr=new int[n];
   	  	read(ptr,n);
   	  	check(ptr,n);
	  }
	return 0;
   }
