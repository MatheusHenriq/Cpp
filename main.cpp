#include <iostream>
#include "list.h"

using namespace std;
int main(){

	List a("a"),b("b"),c("c");
	

	a.Insert(1,0);
	a.Insert(2,1);
	a.Insert(3,2);
	a.Insert(4,3);
	a.Insert(5,4);

	
	a.ShowList();
	b=a<<3;

	b.ShowList();
	
	
	return 0;

}
