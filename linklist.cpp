#include "linklist.h"
#include <fstream>
#include <string.h>

template<class T>
Linklist<T>::Linklist()
{
	start=nullptr;
	int i=1;
	ifstream out("manju.bin",ios_base::binary);
	if(out)
	{
	while(!out.eof())
	{
		
		T obj; //Obj of book
		out.read((char*)&obj,sizeof(obj));
		if(out.eof())
		{
			break;
		}	
		insertBookPos(obj,i);
		i++;
	}
	out.close();
	}
}
	
template<class T>
void Linklist<T>::insertBookPos(T &data, int pos)
	{
		Node<T>* temp= new Node<T>(data); 
		if(start == nullptr)   ///when nullptr
		{
			start=temp;
			return;
		} 
		if(pos==1)     //insert at beggining
		{
			temp->setNext(start);
			start=temp;
			return;
		}
		int i=1;   //insert at any position  
		Node<T>* p=start;
		while(i<pos-1 && p->getNext()!=nullptr)
		{
			p=p->getNext();
			i++;
		}
		temp->setNext(p->getNext());
		p->setNext(temp);
	}

template<class T>	
void Linklist<T>::display()
	{
		if(start == nullptr)
		{
			cout<<"\nNo nodes to display.";
		}
		else
		{
			Node<T>* p=start;
			while(p!=nullptr)
			{
				p->getdata().displayBook();
				p = p->getNext();
			}
		}
	}
	
template<class T>	
Node<T>* Linklist<T>::searchById(int id)
	{
		if(start==NULL)
		{
			return NULL;
		}
		else
		{
			Node<T>* p=start;
			while(p!=NULL)
			{
				if(p->getdata().getId()==id)
				{
				    return p;
			    }
				p=p->getNext();
			}
		}
		return NULL;
	}

template<class T>		
void Linklist<T>::display2(Node<T>* i)
{
	i->getdata().displayBook();
}
	
template<class T>	
bool Linklist<T>::deletebyId(int id)
	{
		if(start==NULL)
		{
			return false;
		}
	    Node<T>* p=start;
		if(p->getdata().getId()==id)
		{
			start=p->getNext();
			delete p;
			return true;
		} 
		while(p->getNext()!=NULL)
		{
			Node<T>* q=p->getNext();
			if(q->getdata().getId()==id)
			{
				p->setNext(q->getNext());
				delete q;
				return true;
			}
	        p=p->getNext();
		} 
		return false;
	}

	
template<class T>	
bool Linklist<T>::updateBook(int id)
{
	Node<T>* i=searchById(id);
	if(i==NULL)
	{
		return false;
	}
	else
	{
		int op;
		double price,ratings;
		i->getdata().displayBook();
		cout<<"\nEnter what you want to update:\n1. Price \n2. Ratings\n";
	    cin>>op;
	    if(op==1)
	    {
		    cout<<"\nEnter updated price of book :";
		    cin>>price;
		    Book b=i->getdata();
		    b.setPrice(price);
		    i->setdata(b);
		    return true;
	    }
	    else if(op==2)
	    {
	    	cout<<"\nEnter updated rating of book :";
		    cin>>ratings;
		    Book b=i->getdata();
		    b.setratings(ratings);
		    i->setdata(b);
		    return true;
		}
	    else
	    {
	        cout<<"\nInvalid choice...";
	    }
	}
}
	
template<class T>	
void Linklist<T>::top3PriceBooks()
{
	int i,count=0;
	Book temp;
	if(start==NULL)
	{
		cout<<"\nLinkedlist is empty";
		return;
	}
	else
	{
		Linklist ll2;
		Node<T>* p=start;
		for(int i=1;p!=NULL;i++)
		{
			ll2.insertBookPos(p->getdata(),i);
			p=p->getNext();
			count++;
		}
		cout<<"no of nodes="<<count;
		for(Node<T>* p=ll2.start;p->getNext()!=NULL;p=p->getNext())
		{
			for(Node<T>* q=p->getNext();q!=NULL;q=q->getNext())
			{
				if(p->getdata().getPrice()<q->getdata().getPrice())
				{
					temp=p->getdata();
					p->setdata(q->getdata());
					q->setdata(temp);	
				}
			}
		}
		int i=0;
		p=ll2.start;
		while(i<3 && i<count)
		{
			p->getdata().displayBook();
			p=p->getNext();
			i++;
		}
    }
}
	
//template<class T>
//Linklist<T>::~Linklist()
//	{
//		while(start!=nullptr)
//		{
//			Node<T>* p= start;
//			start=p->getNext();
//			delete p;
//		}	
//	}

//template<class T>
//Linklist<T>::~Linklist()
//{
//	Node<T>*p;
//	ofstream out("manju.bin",ios_base::binary);
//	while(start != NULL){
//		p=start;
//		out.write((char*)&(start->getdata()),sizeof(start->getdata()));
//		start=start->getNext();
//		delete p;
//	}
//	out.close();
//}

template<class T>
Linklist<T>::~Linklist()
{
	Node<T>*p=start;
	ofstream out("manju.bin",ios_base::binary);
	while(p != NULL){
		T obj=p->getdata();
		out.write((char*)&obj,sizeof(obj));
		p=p->getNext();
		cout<<endl;
	}
	out.close();
	p=start;
	while(start != NULL)
	{
		start = start->getNext();
		delete p;
		p=start;
		cout<<"\nDestructor is called!!!!!!!!!!!!";
	}
}




















































