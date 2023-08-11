#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;

struct Node{
	string name;
	long long int phone_number;
	Node *next;
	Node *prev;
};

class ContactBook{
	string x;
	long long int y;
	Node *head;
	public:
		ContactBook(){
			head=NULL;
			x="";
			y=0;
		}
		
		void CreateNode()							//This function is used to add the contact in the contact book.....
		{
			if(head==NULL)							//This is the condition when the contact book is empty.....
			{
				Node *newer=new Node;
				cout<<"Enter the Name: ";
				cin>>x;
				newer->name=x;
				cout<<"Enter the Phone Number: ";
				cin>>y;
				newer->phone_number=y;
				newer->next=NULL;
				newer->prev=NULL;
				head=newer;
				cout<<"Contact Added Successfully:\n";
			}
			else{									//This is the condition when the contact book is not empty....
				Node *newer= new Node;
				cout<<"Enter the Name: ";
				cin>>x;
				newer->name=x;
				cout<<"Enter the Phone Number: ";
				cin>>y;
				newer->phone_number=y;
				newer->next=NULL;
				Node *temp=head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=newer;
				newer->prev=temp;
				cout<<"Contact Added Successfully:\n\n";
			}
		}
		
		void Display()								//This is the function to show the contacts present in the Contact Book..
		{
			BubbleSort();							//This function is used to sort the Contacts alphabetically....
			Node *temp=head;
			int count=0;
			if(temp==NULL)
			{
				cout<<"Sorry! Contact Book is Empty...\n";
				cout<<"Please Add Some Contacts:\nThank You..\n";
			}
			else{
				cout<<"\n------------------------------------------\n";
				cout<<"Name:"<<"			"<<"		"<<"Number: \n";
				while(temp!=NULL)
				{	cout<<endl;
					cout<<temp->name<<"					";
					cout<<temp->phone_number<<"\n";
					count++;
					temp=temp->next;
				}
				cout<<"\n\nTotal Contacts: "<<count<<endl;
				cout<<"\n------------------------------------------\n";
			}
		}
		
		void search()							//This is the function used for searching a particular Contact in the Contact Book....
		{
			Node *temp=head;
			if(temp==NULL)
			cout<<"\nContact Book is Empty!\n";
			else{
			
			bool check=false;
			cout<<"Press 1 if you want to search the contact by the name:\n";
			cout<<"Press 2 if you want to search the contact by the phone number:\n";
			int command;
			cout<<"Enter the Command: ";
			cin>>command;
			cout<<"\n";
			if(command==1 && temp!=NULL)
			{	cout<<"Enter the Name to Be Search:\n";
				cin>>x;	//
				
				while(temp!=NULL)
				{
					if(temp->name==x){
						cout<<"\n*********\n";
						cout<<"Name: "<<temp->name;
						cout<<"\nNumber: "<<temp->phone_number;
						cout<<"\n*********\n";
						check=true;
						break;
					}
					temp=temp->next;
				}
				if(check==false)
				cout<<"\nContact is Not Found:\n";
			}
			
			else if(command==2){
				cout<<"Enter the Phone Number to Be Search:\n";
				cin>>y;
				
				while(temp!=NULL)
				{	
					if(temp->phone_number==y){
					cout<<"\n*********\n";
					cout<<"Name: "<<temp->name;
					cout<<"\nNumber: "<<temp->phone_number;
					cout<<"\n*********\n";
					check=true;
					break;
				}
				temp=temp->next;
			}
			if(check==false)
			cout<<"\nContact is Not Found:\n";
			}
		}
	}
		
		void edit()
		{	Node *temp=head;
			if(temp==NULL)
			{
				cout<<"Contact Book is Empty!"<<endl;
			}
			
			
			else{
			cout<<"\nPress 1 if you want to search the contact by Name:\n";
			cout<<"Press 2 if you want to search the contact by Phone Number:\n";
			int Ecommand;
			cout<<"Enter the Command: ";
			cin>>Ecommand;
			cout<<"\n";
				if(Ecommand==1)
				{
					bool Echeck=false;
					cout<<"Enter the Name: ";
					cin>>x;
					while(temp!=NULL)
					{
						if(temp->name==x)
						{
						cout<<"*********\n";
						cout<<"Name: "<<temp->name;
						cout<<"\nNumber: "<<temp->phone_number;
						cout<<"\n*********\n";
						Echeck=true;
						break;
						}
						temp=temp->next;
					}
					if(Echeck==true)
					{
						int com;
						cout<<"\nPress 1 to Edit the Contact: ";
						cin>>com;
						if(com==1)
						{
							cout<<"\nEnter the New Name: ";
							cin>>x;
							cout<<"\nEnter the New Number: ";
							cin>>y;
							temp->name=x;
							temp->phone_number=y;
							cout<<"\nContact Edit Successfully:\n";
						}
						else
						cout<<"\nYou Enter the Wrong Command.....Please Try Again!\n";
					}
					else if(Echeck==false)
					cout<<"\nContact Not Found!\n";
				}
				else if(Ecommand==2)
				{
					bool Echeck=false;
	    		cout<<"Enter the Number: ";
	    		cin>>y;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->phone_number==y)
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"Name: "<<temp->name<<endl;
		        		cout<<"Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		Echeck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Echeck==true)
	        	{
	            	int command;
	        	    cout<<"  Press 1 to Edit the Contact: ";
	            	cin>>command;
	        	    if(command==1)
	        	    {
	        		    cout<<"  Enter New Name: ";
    	        		cin>>x;
	            		cout<<"  Enter New Number: ";
	            		cin>>y;
	        		
	            		temp->name=x;
	        	    	temp->phone_number=y;
	        		
	        		    cout<<"\nContact Edited Successfully"<<endl;
			    	}
			    	else
			    	{
					    cout<<"\nYou Entered the Wrong Command....Please Try Again...\n"<<endl;
	    	        }
	        	}
	        	else if(Echeck==false)
	        	{
	        	    cout<<"\nContact Not Found\n"<<endl;
	            }
	        }
				}
			}
			
			
		
		void DeleteAllContacts()				//This is the function used for the deletion of all the contacts present in the contact books.....
		{
			Node *temp=head;
			Node *temp2;
			if(temp==NULL)
			{
				cout<<"Already Contact Book is Empty!\n";
			}
			else{
				while(temp!=NULL)
				{
					temp2=temp;
					delete temp2;
					temp=temp->next;
				}
				head=NULL;
				cout<<"Successfully Deleted All Contacts:\n";
			}
		}
		
		void DeleteContact()					//This is the function used for the deletion of a particular contact from the Contact Book....
		{	Node *temp=head;
			if(temp==NULL)
			cout<<"\nContact Book is Empty!\n";
			
		   	else if(temp!=NULL)
			{	
				
				cout<<"Press 1, If you want to delete the Contact by Name:\n";
				cout<<"Press 2, If you want to delete the Contact by Phone Number:\n";
				int Dcommand;
				cout<<"Enter the Command: ";
				cin>>Dcommand;
				
				if(Dcommand==1){
				bool Dcheck=false;
				cout<<"Enter the Name to Delete: ";
				cin>>x;
				while(temp!=NULL)
				{
					if(temp->name==x)
					{
						cout<<"\n***********"<<endl;
		        		cout<<"\nName: "<<temp->name;
		        		cout<<"\nPhone Number: "<<temp->phone_number;
		        		cout<<"\n\n***********\n"<<endl;
		        		Dcheck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Dcheck==true)
	        	{
	        		int comp;
	        		cout<<"\nPress 1 for Deletion: ";
	        		cin>>comp;
					if(comp==1 && temp==head)
					{
						Node *temp1;
						temp1=temp;
						temp=temp->next;
						delete temp1;
						
						temp->prev=NULL;
						head=temp;
						cout<<"\nContact Deleted Successfully!\n";
					}
					else if(comp==1 && temp->next==NULL)
					{
						temp->prev->next=NULL;
						delete temp;
						cout<<"\nContact Deleted Successfully!\n";
					}
					else if(comp==1)
					{
						Node *temp2;
						temp2=temp;
						temp->prev->next=temp2->next;
						temp->next->prev=temp2->prev;
						delete temp2;
						cout<<"\nContact Deleted Successfully!\n";
					}
					else{
						cout<<"\nYou Entered the Wrong Command....Please Try Again!\n";
					}
				}
				else if(Dcheck==false){
					cout<<"\nContact Not Found....\n";
				}
				
				}
			else if(Dcommand==2)
			{
				bool Dcheck=false;
	    		cout<<"\nEnter the Number to Delete: ";
	    		cin>>y;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->phone_number==y)
		        	{
		        		cout<<"\n***********"<<endl;
		        		cout<<"Name: "<<temp->name<<endl;
		        		cout<<"Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		Dcheck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Dcheck==true)
	        	{
	            	int comm;
	            	cout<<"\nPress 1 for Deletion: ";
	        	    cin>>comm;
    	        	if(comm==1 && temp==head)
	            	{
	            		Node *temp1;
	            		temp1=temp;
	        	    	temp=temp->next;
	        		    delete temp1;
	        		
    	        		temp->prev=NULL;
	            		head=temp;
	            		cout<<"\nContact Deleted Successfully"<<endl;
			    	}
				    else if(comm==1 && temp->next==NULL)
    				{
	    				temp->prev->next=NULL;
		    			delete temp;
			    		cout<<"\nContact Deleted Successfully"<<endl;
				    }
				    else if(comm==1)
    				{
	    				Node *temp1;
		    			temp1=temp;
			    		temp->prev->next=temp1->next;
				    	temp->next->prev=temp1->prev;
					    delete temp1;
		    			cout<<"\nContact Deleted Success Fully"<<endl;	
			    	}
				    else
				    {
				    	cout<<"\nYou Enter Wrong Command ... Try Again"<<endl;
				    }
	            }
	            else if(Dcheck==false)
				{
					cout<<"\nContact of This Number Not Found."<<endl;
				}
	    	}
	    	else{
	    		cout<<"\nYou Enter Wrong Command!\n";
			}
			}
		}
		
		void save(){
		Node *temp=head;
		ofstream file("contactbook.txt");
		if(file.is_open()){
			while(temp!=NULL)
			{
				file<<temp->name<<endl;
				file<<temp->phone_number<<endl;
				temp=temp->next;
			}
			file.close();
			Structure();
		}
		else{
			cout<<"It is Already Empty!\n";
		}
		}
		
		void open()
		{
			ifstream file("contactbook.txt");
			if(file.is_open() && file.peek()!=EOF){
				cout<<"\nContact Book is Opened!\n";
				int i=0;
                while(getline(file,x))
                {	
                    if(i % 2 == 0)
					{
						if(head==NULL)
	                    {
    	                  Node *newer= new Node;
                          newer->name=x;
		         
	                      newer->next=NULL;
	                      newer->prev=NULL;
	                      head=newer;
		                }
						else
						{
							Node *newer= new Node;
							
							newer->name=x;
							newer->next=NULL;
							
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	temp->next=newer;
		                	newer->prev=temp;		
						} 
                    }
                   else
                    {
                    	Node *temp=head;
                    	if(temp->phone_number==0)
                    	{
                    		
                    		 stringstream convert(x);
			       	         convert>>y;
                             temp->phone_number=y;
						}
						else
						{
							Node *temp1=head;
		                	while(temp1->next!=NULL)
		                	{
		                		temp1=temp1->next;
		                	}
		                	
		                	stringstream convert(x);
			       	        convert>>y;
		                	temp1->phone_number=y;
							
						}
                       
				    }
                    i++;
                }
            	file.close();
            }
            else
            {
            	cout<<"\nContact Book is Empty!\n"<<endl;
			}
		}
		
		void BubbleSort()						//This is used to sort the Contacts Alphabetically...
		{
			Node *temp=head;
            Node *i,*j;
            string n;
            long long int n2;
            if(temp==NULL)
            {
            	cout<<"\nContact Book is Empty!"<<endl;
			}
			else
			{
                for(i=head;i->next!=NULL;i=i->next)
                {
                    for(j=i->next;j!=NULL;j=j->next)
                    {
                        if(i->name>j->name)
		                {
                            n=i->name;
                            i->name=j->name;
                            j->name=n;
             
                            n2=i->phone_number;
                            i->phone_number=j->phone_number;
                            j->phone_number=n2;
                        }
                    }
                }
            }
		}
		
		void Structure()
		{	cout<<"\nSelect One of the Following Choices: "<<endl;
			cout<<"\n***********"<<endl;
	    	cout<<"  1. Add Contact"<<endl;
	    	cout<<"  2. Edit the Contact"<<endl;
	    	cout<<"  3. Delete Contact"<<endl;
	    	cout<<"  4. Search Contact"<<endl;
	    	cout<<"  5. Display All Contacts"<<endl;
	    	cout<<"  6. Delete All Contacts"<<endl;
	    	cout<<"  7. Exit"<<endl;
	    	cout<<"\n***********"<<endl;
		
	    	int Scommand;
	    	cout<<"\nEnter the Command: ";
	    	cin>>Scommand;
	    	cout<<"\n";
	    	try{
	    		if(Scommand>=1 && Scommand<=7)
	    		{
	    			if(Scommand==1)
	    			{
	    				CreateNode();
	    				save();
	    				Structure();
					}
				else if(Scommand==2)
					{	edit();
						save();
						Structure();
					}
					else if(Scommand==3)
					{	
						DeleteContact();
						Structure();
					}
				else if(Scommand==4)
					{
						search();
						Structure();
					}
				else if(Scommand==5)
					{
						Display();
						save();
						Structure();
					}
				else if(Scommand==6)
				{
					DeleteAllContacts();
					save();
					Structure();
				}
				else if(Scommand==7)
				{
					exit(1);
				}
			}
				else{
					throw(Scommand);
				}
				}
				catch(int Scom)
				{
					cout<<"You Entered the Wrong Command......Please Enter the Command Carefully!\n";
					Structure();
				}
			}		
};



int main()
{	
	system("color 0A"); 
	cout<<"************************************* CONTACT BOOK **********************************\n";
	cout<<"\t\t\t\t\t\t\t\t    -Created By Ayush"<<endl;
	
	ContactBook cb;
    cb.open();
	string n;
	cout<<"\nWhat is your Name: ";
	cin>>n;
	
    cout<<"\n***********"<<endl;
	cout<<n<<", Welcome To Contact Book "<<endl;
	cout<<"\n***********"<<endl;
	cb.Structure();
	
	return 0;
}

