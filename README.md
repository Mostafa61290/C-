# C++
C++ 
class list {
    // we must create struct or class to create the Node 
////////////////////////////////////start of data memebers 
    // class node here are the data members of class list 
private : // if we did not write private , it will be private by default 
    class Node {
    public : // as we will need to access on node(next) so that we need to make it public
        int key ;
        char data ;
        Node* next ;
    };
    
    
 
    // cursore , previose , head are data memebrs (nodes) 
    Node *head , *cursor , *prev ; 
////////////////////////////////////end of data memebers .
// functuions memebers 
public :   
    list() ; // constructor  

    bool listIsEmpty();// function check is list are empty or note 
    // check is there are node or not ? if the head point to null meaning that the list is empty . 
    bool cursorEmpty(); //check cursor is empty 
    void toFirst(); // make cursor point to head (first node ) 
    void advance(); // make advance to the next node ;
    bool atFirst(); // check the current node at first of list 
    void toEnd() ; // move the cursor to the end of linked list 
    bool atEnd() ; // check the cursor at the end or not 
    int listSize(); // return no. of nodes in list 
    void insertFisrt(int key , char data) ; // to insert in First 
    void insertAfter(int key , char dat ); 
    void insertBefore (int key , char dat ); 
    void insertEND (int key , char dat );
    void UpdateData (char dat) ; // update data of node .
    int DisplayDataKey1();// first 1.1 way to display key only .
    char DisplayDatadata1();// first 1.2 way to display data only .
    void displaydata(int &k , char &dat) const ; // second way to retrieve the data in one method using call by ref
    void displaykey11(int &k ) const ; // display key only using call by ref
    void deleteNode()  ; // delete node if it at first or not .
    void deleteFirst(); // to delete the first node 
    void deleteEnd() ; // to delete the End node 
    void makelistEmpty() ; // to delete all list in memory , we use it in the destructor 
    bool listSearch(const int &k ); // to search about key is found or not 
    void insertTolist(const int &k , const char &dat) ; // to insert node in the list Put it in its proper place in ascending order
    void travers () ; // to print all items in list 
    ~list();  // destructor 
};


#include<iostream>
#include<String>
#include "stdio.h"  // to using NULL 
#include"list.h" 
using namespace std ;

list::list(){ // constructor 
    head = cursor = prev =  NULL ;   // initial value of pointer of nodes are NULL    
}

bool list::listIsEmpty() {
    if (head == NULL)
        return true ;
    else
        return false ;
    // another way 
    //  return(head==NULL);  
}

bool list::cursorEmpty() {
    if(cursor==NULL) 
        return true ;
    else 
        return false ;
}

void list::toFirst(){
    cursor = head ; 
    prev = NULL ; // as previous point must be before cursor , so that we must make it here equal NULL    
}

void list::advance() {
    prev = cursor ;
    cursor = cursor->next ;
}

bool list::atFirst(){
    if(cursor == head)
        return true ;
    else 
        return false ;
}

void list::toEnd() {
    // move through list till the next will equal Null
    // 1. call function toFirst to make the cursor at the first 
    toFirst() ;
    // make condition if the list not empty start advance from first to end 
    // if list is already empty there was no need to make loop 
    if (!listIsEmpty()) {
        while(cursor->next != NULL) {
            advance() ; 
        }
    }    
}

bool list::atEnd() {
    // check first if list empty
    if (listIsEmpty()){
        return true ;
    }
    // when list not empty but cursor are equal NULL mean that cursor not at end so return false
    else if(cursor == NULL){
        return false ;
    } else { // cursor not NULL (contain data ) , check the next of cursor if equal NULL return true
    // else return false
        if (cursor->next == NULL) 
            return true ;
        else 
            return false ; 
    
    // one line for last if 
    //  return (cursor->next == NULL ) 
    }
}

int list::listSize() {
    int count = 0 ;
    // best practice create node to count and don't use cursor 
    toFirst() ; 
    Node *p ;
    p=head ; 
    while (p != NULL) { // we didn't write p->next != NULL as if this we will not count the last node
        count++ ;
        p = p->next ;
    }
    return count ;    
}

void list::insertFisrt(int k , char d) {
    Node *p = new Node();  // 1. create node 
    p->key = k ; p->data = d ;  // 2. fill data 
    p->next = head ;   // 3. point the next of new to the head 
    head = p ; // 4. make head point to p 
    // added steps 
    cursor = p ;  // to make the cursor in our position 
    prev = NULL ;  // to make previous always before p 
}

void list::insertAfter(int k, char d ) {
    Node *p = new Node();  // 1. create node 
    p->key = k ; p->data = d ;  // 2. fill data 
    p->next = cursor->next ;  // 3.
    cursor->next = p ;  // 4.
    
    prev = cursor ;
    cursor = p ; 
}

void list::insertBefore (int k , char d ){
    Node *p = new Node();  // 1. create node 
    p->key = k ; p->data = d ;  // 2. fill data 
    p->next = cursor ;
    prev->next = p ;
    cursor = p ; 
}

void list::insertEND (int k , char d ){
    if (listIsEmpty()) insertFisrt(k , d) ;
    else {
        toEnd(); // to make cursor at the end then make insert after 
        insertAfter(k , d) ;
    }
}

void list::UpdateData (char dat) { // we send the data to the method 
    cursor->data = dat ;  // cursor at the node we need to update 
}

int list::DisplayDataKey1(){
    // first 1.1 way to display key only .
    return cursor->key ; 
}

char list::DisplayDatadata1(){
    // first 1.2 way to display data only .
    return cursor->data ; 
}

void list::displaydata(int &k , char &dat) const { // const mean the function can not change data in class 
    // second way to retrieve the data in one method using call by ref
    k = cursor->key ;
    dat = cursor->data ;
   // cout << k << endl << dat << endl ;
} // when we call this function we send the variable of k and dat (ex. li.displaydata(d1 , k1 ))

void list::displaykey11(int &k ) const {
    k = cursor->key ;
}

void list::deleteNode()  {
    // first check is the linked list empty or not 
    // then check if the cursor at first or not 
    if(!listIsEmpty()) {
        Node *p = new Node();
        if(atFirst()) {        
            p = cursor ;
            head = head->next ;
            cursor = head ;
            delete p ;
        } else {
            p = cursor ;
            cursor = cursor->next ;
            prev->next = cursor ;
            delete p ;
        }
    }
}

void list::deleteFirst() {
    // check is list empty or not 
    if(!listIsEmpty()){
        toFirst() ;
        deleteNode() ;
    }
}

void list::deleteEnd() {
    // check is list empty or not 
    if(!listIsEmpty()){
        toEnd() ;
        deleteNode() ;
    }
}

void list::makelistEmpty(){
    toFirst() ;
    while(!listIsEmpty()){
        deleteNode() ;
    }
}

bool list::listSearch(const int &k ) {
    bool found = false ;
    toFirst() ;
    while (cursor != NULL &&  !found) {// two conditions to stop search 
        if(cursor->key == k )
            found = true ;
        else 
            advance() ;
    } 
    return found ;
}

void list::insertTolist(const int &k , const char &dat) {
    toFirst() ;
    while(cursor != NULL && k > cursor->key){// move and check 
        advance() ;    // move while condition true     
    }
    if (prev == NULL) // insert at first 
        insertFisrt(k , dat) ;
    else
        insertAfter(k , dat) ;
}

void list::travers () {
    // move through and display all data till NULL 
    toFirst() ;
    while (cursor != NULL) {
        cout << cursor->key << " " << cursor->data << endl ; 
        advance() ;
    }
}

list::~list() {
    makelistEmpty() ;
}


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
