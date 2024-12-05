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

