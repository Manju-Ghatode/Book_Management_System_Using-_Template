#include "linklist.cpp"
#include "book.h"
int main()
{
	Linklist<Book> ll;
	int ch=0;
	do{
	cout<<"\n1. Insert at the position ";
	cout<<"\n2. Display";
	cout<<"\n3. Enter ID to search";
	cout<<"\n4. Enter ID to delete";
	cout<<"\n5. Enter ID to update";
	cout<<"\n6. Top 3 the book";
	cout<<"\n10. Exit";
	cout<<"\nEnter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:{
				char title[40];
				char author[40];
				char category[40];
					int ratings, bid, pos;
					double price;
					cout<<"\nEnter the position:";
					cin>>pos;
					cout<<"\nEnter the ID of the book:";
					cin>>bid;
					cin.ignore();
					cout<<"\nEnter the title of the book:";
					cin.getline(title,40);	
					cin.ignore();
					cout<<"\nEnter the author of the book:";
					cin.getline(author,40);	
					cout<<"\nEnter the ratings of the book:";
					cin>>ratings;
					cout<<"\nEnter the price of the book:";
					cin>>price;
					cin.ignore();
					cout<<"\nEnter the category of the book:";
					cin.getline(category,40);
					
					Book b1(title,bid,author,ratings, price,category);
					ll.insertBookPos(b1,pos);
				break;
			}
			
		case 2:
			{
				ll.display();
				break;
			}
			
		case 3:
			{
				 int id;
				        char ele[20];
				        //Book b;
					        cout<<"\nEnter an book id want to search :";
					        cin>>id;
					        Node<Book>* i=ll.searchById(id);
					        if(i==NULL)
					        {
					        	cout<<"\nBook not found";
							}
							else
							{
								cout<<"\nBook found!!!!! ";
								ll.display2(i);
							}
				break;
			}
		
		case 4:
			{
				int bid;
				cout<<"\nEnter the ID to delete: ";
				cin>>bid;
				ll.deletebyId(bid);
				cout<<"\n......Book getting deleted successfully!!!!!";
			break;
			}
		
		case 5:
			{
				int bid;
				cout<<"\nEnter the ID of the book:";
				cin>>bid;
				if(ll.updateBook(bid))
				{
					cout<<"\nBook updated successfully";
				}
				else
				{
					cout<<"\nNo Books to update OR Book not found";
				}
				break;
			}
			
		case 6:
				{
					int option;
		            Linklist<Book> ll2; 
				    cout<<"\nSort top 3 Books based on price...please press 1 ";
			        cin>>option;
			        if(option==1)
			        {
			            ll.top3PriceBooks();
			        }
			        else if(option!=1)
					{
						cout<<"\nInvalid choice...";
					}  
				}
				break;
			
		case 7:
			
				cout<<"\nEnd of the program...Thank you...Exit";
				break;
				
		default:
				cout<<"\nInvalid Choice.";
		}
	}while(ch!=10);
}