#include "book.h"
Book::Book()
	{
		strcpy(title,"Not Given");
		bid=0;
		strcpy(author,"Not Given");
		ratings=0;
		price=0;
		strcpy(category,"Not Define");
	}

Book::Book(char* t,int id,char* a,int r,double p,char* c)
	{
		strcpy(title,t);
		bid=id;
		strcpy(author,a);
		ratings=r;
		price=p;
		strcpy(category,c);
	}
	
void Book::setTitle(char* t)
	{
		strcpy(title,t);
	}
	
void Book::setId(int id)
	{
		bid=id;
	}
	
void Book::setAuthor(char* a)
	{
		strcpy(author,a);
	}
	
void Book::setratings(int r)
	{
		ratings=r;
	}

void Book::setPrice(double p)
	{
		price=p;
	}
	
void Book::setCategory(char* c)
	{
		strcpy(category,c);
	}	
char* Book::getTitle()
	{
		return title;
	}
	
int Book::getId()
	{
		return bid;
	}

char* Book::getAuthor()
	{
		return author;
	}	

int Book::getRatings()
	{
		return ratings;
	}

double Book::getPrice()
	{
		return price;
	}
	
char* Book::getCatogory()
	{
		return category;
	}
	
void Book::displayBook()
	{
			cout<<"\nTitle :"<<this->title;
			cout<<"\nBook Id :"<<this->bid;
			cout<<"\nAuthor :"<<this->author;
			cout<<"\nPrice :"<<this->price;
			cout<<"\nRatings : "<<this->ratings;
			cout<<"\nCategory :"<<this->category;
			cout<<"\n--------------------------";
	}
	