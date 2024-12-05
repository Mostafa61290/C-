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

