#include <stdlib.h>
#include <iostream>
#include "list.h"

void List::init(){

	first=NULL;
	count=0;
	

}

List::List(){
	
	init();
	
}

List::List(const char *lname){
	
	name = lname;	
	init();

}

List::~List(){
	
	deleteList();

}

Node *List::getNode(int index){

	Node* node = first;
	
	
	if(index <0 || index>=count)
		return NULL;
	
	for (int i=0; i<index; i++)
		node=node->next;
	return node;
	
	
}

int List::Insert(Data data,int index){

	Node *value = new Node;
	Node *prev;
	
  if(index<0 || index>count)
  	return -1;  
	
	
	if(value == NULL)
		return -1;

	value->key = data;

	if(first==NULL){
	 	//value->next = first;
	  	first       = value;
  } else if (index > 0){
		
		prev = getNode(index - 1);
		value->next=prev->next;
		prev->next = value;
	}
	else{
		value->next = first;
		first = value;

  }
  	
	count++;
	return index;
}

void List::ShowList(){

	Node *aux = first;
	std::cout<<name<<" = ";
	std::cout<<"[ ";
	while(aux!=NULL){

		std::cout<<aux->key<<",";
		aux=aux->next;
	}

	std::cout<<"\b ]\n";
	

}

int List::InsertAppend(int data){

	return Insert(data,count);
	


}

int List::InsertInit(int data){

	return Insert(data,0);

}

int List::isEmpty(){

	return count==0;
}

int List::deleteElem(int index){

	Node *prev;
	Node *aux;

	if(index<0 || index > count)
		return -81581057;

	if(index == 0){

		first = first->next;
		
	}

	if(index>0){

		prev=getNode(index-1);

		if(prev->next->next==NULL){
			
			prev->next = NULL;		
			
		}

		else{
			
			aux = prev->next->next;
			prev->next=aux;			
	
		}
	
	}
	
	return 1;


}

void List::deleteList(){

	
	Node *curr=first;
	Node *aux;
		
	while(curr!=NULL){
 		
		aux=curr->next;
		delete curr;
		curr = aux;
		
		
	}
	
	
	first=NULL;
	count=0;
	
}

int List::InsertOrd(int data){


	Node *value = (Node*) malloc(sizeof(Node));
	Node *aux;
	Node *curr=first;
	
	
	
	value->key = data;	

	if(first==NULL){
		value->next=first;
		first= value;
	}
	
	else if(first->key > data){

		value->next = first;
		first = value;

	}
 
	else{
		while(curr!=NULL){
			
			if(curr->next == NULL){
					
				curr->next	= value;
				value->next = NULL;
				break;		
				
			}
			
			else if(curr->next->key > data){
				
				aux = curr->next;
				curr->next = value;
				value->next = aux;
				break;

			}			
			
			curr=curr->next;

		}
	}

	count++;
	return count; 

} 

Data List::ToArray(int *v){

	Node *aux=first;
	int i=0;


	while(aux!=NULL){
	
		v[i++]=aux->key;
		aux=aux->next;


	}

	return 1;
}

Data *List::ToArray(){

	int *v = new int[count];
	
	ToArray(v);

	return v;

}

int List::ArrayToList(int *v,int num_pos){

	
	int i;
	Node *aux=first;	
	
	for(i=0;i<num_pos;i++){
		aux->key = v[i];
		aux=aux->next;
	}

	return 1;

}



int cmp(const void *e1, const void *e2){
	
	int d1,d2;

	d1 = *((int*)e1);
	d2 = *((int*)e2);
	


	return d1 > d2 ? 1  : d2>d1 ? -1 : 0;


} 

void List::ListSort(bool asc){
	
	if(isEmpty())
		return;
	
	int *v = new int[count];
	ToArray(v);
	qsort(v,count,sizeof(*v),cmp);
	ArrayToList(v,count);

	delete[] v;


}


void List::concat(const List &list){

	Node* aux=list.first;

	for(int i=0;i<list.count;i++){
		InsertAppend(aux->key);;
		aux=aux->next;		
	}
	delete aux;


}

List List::rotation(Data x){

	List r;
	
	Node *elem;

	elem = getNode(x%count);
	x = count;

	while(x>0){
		r.InsertAppend(elem->key)	;
		if(elem->next!=NULL)
			elem=elem->next;
		else
			elem=first;
		x--;		
	}	
		
	return r;

}




	
