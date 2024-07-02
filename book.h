#include<iostream>
#include<string.h>
using namespace std;
#pragma once

class Book{
	int bid;
	char title[40];
	char author[40];
	double price;
	int ratings;
	char category[40];
	
	public:
		Book();
		Book(char*,int,char*,int,double,char*);
		void setTitle(char*);
		void setId(int);
		void setAuthor(char*);
		void setratings(int);
		void setPrice(double);
		void setCategory(char*);
		
		char* getTitle();
		int getId();
		char* getAuthor();
		int getRatings();
		double getPrice();
		char* getCatogory();
		
		void displayBook();
};
