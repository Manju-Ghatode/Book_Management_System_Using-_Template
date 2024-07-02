#include "node.cpp"
#include "book.h"


template<class T>
class Linklist{
	Node<T>* start;
	public:
		Linklist();
		void insertBookPos(T&,int);
		Node<T>* searchById(int);
		bool deletebyId(int);
		bool updateBook(int);
		void top3PriceBooks();
		void display2(Node<T>*);
		void display();	
		~Linklist();
};

