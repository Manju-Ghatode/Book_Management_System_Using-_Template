#include<iostream>
#pragma once
using namespace std;
template<class T>
class Node{
	T data;
	Node<T>* next;
	public:
		Node(T&);
		void setdata(T &);
		void setNext(Node*);
		T& getdata();
		Node<T>* getNext();		
};
