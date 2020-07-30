#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

static int p=0;
int count=0,m;

class student
     {
     	char l_name[20],classs[4],section[2],age[3],gender[7];
     	
     	public:
     		char f_name[20];
     		void add();
     		void list();
     		void modify();
     		void deleter();
     		
	 }*record;
	 
void vline(char ch)
    {
    	for(int i=80;i>0;i--)
    	   cout<<ch;
	}
	
void student::add()
    {
    	
		cout<<"Enter first name of the student :\t";
    	cin>>*record[p].f_name;
    	cout<<"Enter last name of the student :\t";
    	cin>>*record[p].l_name;
    	
    	cout<<"Enter gender of the student :\t";
    	cin>>*record[p].gender;
    	
    	cout<<"Enter class of the student :\t";
    	cin>>*record[p].classs;
    	
    	cout<<"Enter section of the student :\t";
    	cin>>*record[p].section;
    	
    	count++;
    	
	}
	
void student::list()
    {
    	
    	for(int i=0;i<count;i++)
    	   {
    	   	vline('*');
    	   	
    	   	cout<<"\nName :\t"<<record[i].f_name<<" "<<record[i].l_name<<"\t\tGender :\t"
    	   	<<record[i].gender<<"\nClass :\t"<<record[i].classs<<"\t\tSection :\t"<<record[i].section<<"\n\n";
    	   	
		   }
		vline('*');
		
	}
	
void student::modify()
    {
    	
    	cout<<"Enter first name of the student :\t";
    	cin>>record[m].f_name;
    	
    	cout<<"Enter last name of the student :\t";
    	cin>>record[m].l_name;
    	
    	cout<<"Enter gender of the student :\t";
    	cin>>record[m].gender;
    	
    	cout<<"Enter class of the student :\t";
    	cin>>record[m].classs;
    	
    	cout<<"Enter section of the student :\t";
    	cin>>record[m].section;
    	
	}
	
void student::deleter()
    {
    	int i;
    	
    	for(i=m;i<count;i++)
    	   {
    	   	
			   strcpy(record[i].f_name,record[i+1].f_name);
    	   	
    	   	   strcpy(record[i].l_name,record[i+1].l_name);
    	   	
    	   	   strcpy(record[i].gender,record[i+1].gender);
    	   	
    	   	   strcpy(record[i].classs,record[i+1].classs);
    	   	
    	   	   strcpy(record[i].section,record[i+1].section);
    	   	   
		   }
		   
		count--;
	}
	
int main()
   {
   	
   	char name[20],choice;
   	int flag,ch,i;
   	
   	while(1)
   	    {
   	    	
   	     	cout<<"*****STUDENT DATABASE MANAGEMENT SYSTEM*****\n";
   	     	cout<<"\t\t1. Add Record\n";
   	     	cout<<"\t\t2. List Record\n";
   	     	cout<<"\t\t3. Modify Record\n";
   	     	cout<<"\t\t4. Delete Record\n";
   	     	cout<<"\t\t5. Exit\n\n";
   	     	
   	     	cout<<"Enter your choice : ";
   	     	cin>>ch;
   	     	
   	     	switch(ch)
   	     	    {
   	     	    	case 1:
   	     	    		label:
   	     	    			cout<<"Fill student's details\n";
   	     	    			record[p].add();
   	     	    			p++;
   	     	    			cout<<"To add details of more students press Y if not then press N : ";
   	     	    			cin>>choice;
   	     	    			if(choice=='Y'||choice=='y')
   	     	    			    goto label;
   	     	    			
   	     	    		break;
							
					case 2:
					    record[0].list();
						break;
						
					case 3:
					    mod:
						   cout<<"Enter first name of the student whose data you want to change : \t";
						   cin>>name;
						   
						   for(i=0;i<=count;i++)
						      {
						      	if(strcmp(record[i].f_name,name)==0)
						      	  {
								    m=i;
									record[m].modify();
						      	  	break;
								  }
								else
								  flag=1;
								      
				              }
				            if(flag==1)
				              cout<<"Record does not exist\n";
				              
				            cout<<"To modify more students database press Y if not then press N :\t";
				            cin>>choice;
				            
				            if(choice=='Y'||choice=='y')
				              goto mod;
				              
				        break;
				        
				    case 4:
				    	del:
						   cout<<"Enter first name of the student whose data you want to delete : \t";
						   cin>>name;
						   
						   for(i=0;i<=count;i++)
						      {
						      	if(strcmp(record[i].f_name,name)==0)
						      	  {
						      	  	m=i;
									record[m].deleter();
						      	  	break;
								  }
								else
								  flag=1;
								     
				              }
				            if(flag==1)
				              cout<<"Record does not exist\n";
				              
				            cout<<"To delete more students database press Y if not then press N :\t";
				            cin>>choice;
				            
				            if(choice=='Y'||choice=='y')
				              goto del;
				              
				        break;
				    
				    case 5:
				    	exit(0);
			}
		}
		return 0;
   }
