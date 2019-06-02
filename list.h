#include <iostream>
#ifndef __LIST_H
#define __LIST_H

typedef int Data;

struct Node{

	Node* next;
	Data key;

};

class List{
	
	std::string name;
  	Node *first;
  	int count;
  		

private: 
		Node* getNode(int index);
		void init();
public:
 		
 	List();	

	List(const char *lname);

 	int Insert(int data, int index);

	void ShowList();

	int InsertAppend(int data);

	int InsertInit(int data);


	int isEmpty();

	int deleteElem(int index);

	void deleteList();	

	inline
	int getCount(){
		return count;	
	}
	~List();

	int InsertOrd(int data);

	Data *ToArray();

	Data ToArray(int *v);

	int ArrayToList(int *v,int num_pos);

	void ListSort(bool asc);

	inline
	int getIndex(int index){
		return getNode(index)->key;
	}

	inline
	List &operator=(const List &list){
		deleteList();
		concat(list);
		return *this;		
	}

	inline
	std::string getName(){
		return name;
	}

	inline
	std::string setName(const char* lname){
		name = lname;
		return name;
	}

	void concat(const List &list);	

	inline
	Data operator[](Data index){
		return getNode(index)->key;
	}

	inline 
	void operator+=(const List &list){
		concat(list);			
	} 

	inline
	List operator<<(Data x){
		return rotation(x);
	}
	
	List rotation(Data x);
};
	


#endif
