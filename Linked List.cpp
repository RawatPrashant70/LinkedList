// Linkedlist

#include<bits/stdc++.h>
using namespace std;

struct node{
  int data ;
  node *next;
};


class LinkedList
{
    private:
            node *head, *tail ;

    public:
            LinkedList()
            {
                head = NULL ;
                tail = NULL ;
            }

            void createlist(int value);
            void display();
            void insert_starting(int value);
            void position(int value, int pos);
            void delete_value(char a);
            void delete_value_position(int pos);
};

void LinkedList:: createlist(int value)
{
    node *temp = new node ;
    temp->data = value ;
    temp->next = NULL ;

    if(head==NULL)
    {
        head=temp ;
        tail=temp ;
        temp=NULL ;
    }
    else
    {
        tail->next = temp;
        tail =  temp ;
    }
}


void LinkedList::display()
{
    node *temp;
    temp=head;

    while(temp != NULL)
    {
        std::cout << temp->data<<" ";
        temp =  temp->next ;
    }
}


void LinkedList::insert_starting(int value)
{
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;

    if(head == NULL)
    {
        std::cout << "CREATE A LINKED LIST" <<std::endl;
    }
    else
    {
        temp->next = head ;
        head = temp ;
    }
}

void LinkedList::position(int value, int pos)
{
    node *p, *c ;
    c = head ;

    node *temp = new node ;
    temp->data = value ;
    temp->next = NULL ;

    if(pos==1)
    {
        insert_starting(value);
        return;
    }

    for(int i=1; i<pos; i++ )
    {
        p=c ;
        c=c->next ;
    }
    temp->next = c ;
    p->next = temp ;
}

void LinkedList::delete_value(char a)
{
    node *temp, *p, *c ;

    if(a == 'f' || a == 'F')
    {
        temp = head ;
        head = head->next ;
        delete temp ;
    }
    if(a == 'l' || a == 'L')
    {
        c=head ;
        while(c->next!=NULL)
        {
            p=c ;
            c = c->next ;
        }
        tail = p ;
        p->next = NULL ;
        delete c ;
    }

}


void LinkedList::delete_value_position(int pos)
{
    node *p, *c ;
    c=head ;
    for(int i=1; i<pos; i++)
    {
        p=c;
        c=c->next ;
    }
    p->next = c->next ;
}


int main()
{   char a ;

    LinkedList ll;

    // ll.insert_starting(0);

    ll.createlist(5);
    ll.createlist(10);
    ll.createlist(15);
    ll.createlist(20);
    ll.createlist(25);

    //-------------------------------

    ll.insert_starting(0);

    ll.display();

    //-------------------------------

    ll.position(30,2); // location 2nd

    ll.position(07,1);// location 1st or use insert_starting method

    std::cout<<endl << "-------------------------------" << std::endl;
    ll.display();

    //std::cout<<endl << "ENTER 'F( for first element deletion)' 'L( for last elemnt deletion)'" << std::endl;
    //cin>>a;

    ll.delete_value('F');
    ll.delete_value('L');

    std::cout<<endl << "-------------------------------" << std::endl;
    ll.display();


    // Delete value from a location

    ll.delete_value_position(3);

    std::cout<<endl << "-------------------------------" << std::endl;
    ll.display();

    return 0;

}














