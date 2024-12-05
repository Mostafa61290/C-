// application file 


#include <iostream>
#include <String>
#include "list.h"
#include "stdio.h"  // to using NULL 
using namespace std ;

// function to check the count of zero in the list 
int countZero (list &l1){
	l1.toFirst() ;  // make the cursor in the first node 
	int k1 ;   // variable int to store in it the value of key in nodes 
	// note that the function we will calling use pass by reference not by value 
	int count = 0 ; // to use it for check and count (sum +1 each loop )
	if(!l1.listIsEmpty()){ // to only enter to the list when it is contain data
		while (!l1.cursorEmpty()){ // to loop while cursor on nodes not in the NULL
		l1.displaykey11(k1) ; // we here pass the variable k1 address , and this function make the k1 
		 // equal the value of key (passing variable )
	  	if(k1 == 0){
	  	count++; 	
		  }
	  	l1.advance() ;
	   }
		}
	  
		
	return count ;
	
}
// function to sum the key of all nodes in list 
int SumKeyList(list &l2){
	int k2 ;
	int sum = 0 ;  
	l2.toFirst() ; // make the cursor at the first node 
	if (!l2.listIsEmpty()){
		while (!l2.cursorEmpty()) {
		   l2.displaykey11(k2) ;
			sum += k2  ;
			l2.advance() ;	
		}
	}
	
	return sum ;
}
void splitList (list &l1 , list &l2 , list &l3){
	int k ;
	char d ;
	l1.toFirst() ;
	l2.makelistEmpty() ;
	l3.makelistEmpty() ;
	while(!l1.cursorEmpty()){
		l1.displaydata(k , d );
		if(k > 0) {
			l2.insertEND(k , d);
		} else {
			l3.insertTolist(k , d) ;
		}
		l1.advance() ;
	}
	l1.makelistEmpty() ;
}

int main(){
	list l ; // make object from class list  (static)
	list lpos , lneg ; 
	//list *p = new list() ; // make object from class list (dynamic)
	l.insertFisrt(1 ,'a') ;
	l.insertEND(2 ,'b');
	l.insertEND(-5 ,'c');
	l.insertEND(4 ,'d');
	l.insertEND(-6 ,'e');
	l.insertEND(6 ,'f');
	l.insertEND(-8,'f');
	l.insertTolist(3,'e') ;	
	l.travers();
	// test method countZero
  int count = countZero(l);
	cout<< " count "<< count << endl;
	// test method sum of all key 
	int sum = SumKeyList(l);
	cout << " Sum of all key in the list : "<< sum <<endl ;	
	// test split list method
	splitList(l ,lpos , lneg) ;
	cout << " posative nomber list  : \n" ; 
	 lpos.travers();
    cout << " negative nomber list  : \n" ;
     lneg.travers();
}
