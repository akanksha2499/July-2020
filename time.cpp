#include<iostream>

using namespace std;

class time
     {
     	int h,m,s,ts;
     	public:
     		void read()
     		    {
     		    	cout<<"Enter time :"<<endl;
     		    	cout<<"Hours ? ";
     		    	cin>>h;
     		    	cout<<"Minutes ? ";
     		    	cin>>m;
     		    	cout<<"Seconds ? ";
     		    	cin>>s;
				}
			void check()
			    {
			    	if(s>=60)
			    	  {
			    	  	s-=60;
			    	  	m+=1;
					  }
					if(m>=60)
					  {
					  	m-=60;
					  	h+=1;
					  }
				}
			void display()
			    {
			    	check();
			    	cout<<"The time is = ";
			    	if(h<=9)
			    	  cout<<0<<h<<":";
			    	else
			    	  cout<<h<<":";
			    	if(m<=9)
			    	  cout<<0<<m<<":";
			    	else
			    	  cout<<m<<":";
			    	if(s<=9)
			    	  cout<<0<<s<<":";
			    	else
			    	  cout<<s<<endl;
				}
			void calculation()
			    {
			    	ts=h*60*60+m*60+s;
				}
			void displayts()
			    {
			    	calculation();
			    	cout<<"Time in total seconds : "<<ts<<endl;
				}
	 };
int main()
   {
   	time t;
   	t.read();
   	t.display();
   	t.displayts();
   	return 0;
   }
