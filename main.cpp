//
//  main.cpp
//  algorithms
//
//  Created by Gulchiroy on 22/09/2019.
//  Copyright © 2019 Gulchiroy. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>


using namespace std;

class node
{
private:
    int data;
    node *next;
    
public:
    node();
    node(int num, node* link );
    int getdata()const;
    void setdata(int num);
    node* getlink()const;
    void setlink(node *link);
    
    
    
};

typedef node* nodeptr;


void Create(nodeptr& head, int num)//Creating a new Node
{
    nodeptr temp=new node(num,head);
    head=temp;
}


void insert_begin(nodeptr& head,int num)
{
    nodeptr temp = new node(num, head);
    head=temp;
}



void insert(nodeptr& head, int num) //it sorts before inserting
{
    nodeptr temp;
    temp=new node(num, NULL);
      
    if(head==NULL)
    {
        Create(head,num);//inserting for the Empty Node
        cout<<"inserted to the Empty list"<<endl;
        return;
    }
      
    
    if(num<head->getdata())//inserting at the begining
    {
            insert_begin(head,num);
        return;
    }
    nodeptr prev=head;
    nodeptr curr=head;
    
    while(curr->getlink()!=NULL && num>curr->getdata())//iterator
    {
        prev=curr;
        curr=curr->getlink();
    }
    
    if(num<curr->getdata() && curr!=NULL)//inserting in the middle
    {
        prev->setlink(temp);
        temp->setlink(curr);
        cout<<"Inserted at the middle"<<endl;
        return;
        }
    if(num>curr->getdata()  && curr->getlink()==NULL)
    {//inserting at the end
            curr->setlink(temp);
            curr=temp;
        cout<<"Insetred at the end"<<endl;
        return;
    }
   
    
    
    }



void display(nodeptr head) //printing the elements in the list
{
    nodeptr curr;
    curr=head;
    while(curr!=NULL)
    {
        cout<<curr->getdata()<<endl;
        curr=curr->getlink();
    }
}

   void deletenode(nodeptr& head, int num) //deleting the node from all side
{
    if(head==NULL){//check if the list is Empty
        cout<<"List is Empty"<<endl;
        return;
    }
    if(head->getdata()==num&&head->getlink()!=NULL)//deleting the head;
    {
        nodeptr temp = head;
        head=head->getlink();
          cout<<"head  element "<<temp->getdata()<<" is deleted"<<endl;
        delete temp;
        return;
    }
    nodeptr  curr = head;
    nodeptr prev= head;
    while(curr!=NULL && curr->getdata()!=num)//iterator
    {
        prev=curr;
        curr=curr->getlink();
    }
    if(curr->getdata()==num&&curr->getlink()!=NULL)//deleting from the middle
    {
        prev->setlink(curr->getlink());
        cout<<"middle element "<<curr->getdata()<<" is deleted"<<endl;
        delete curr;
        return;
    }
    if(curr->getdata()==num&&curr->getlink()==NULL)//last element
    {
        prev->setlink(NULL);
        cout<<"last element "<<curr->getdata()<<" is deleted"<<endl;
         delete curr;
        return;
    }
    
    
    
}
    int main(int argc, const char * argv[])
{
    
    nodeptr head;
    head = NULL;
    
    insert(head, 8);
    insert(head, 89);
    insert(head, 86);
    insert(head, 3);
    insert(head, 12);
    
    display(head);
    deletenode(head, 12);
    deletenode(head, 89);
    deletenode(head, 3);
    display(head);

    
   /* while(temp!=NULL ) {
        nodeptr discard=temp;
        temp=temp->getlink();
        cout<<discard->getdata()<<"is being deleted"<<endl;
        delete discard;}*/
        
        
        
    
    return 0;
}

node::node():data(0),next(NULL)//constructor
{}

node::node(int num, node* link):data(num),next(link)//constructor for 2 parameter
{}

int node::getdata()const //returns the value of node
{
    return data;
    
}
void node::setdata(int num)//setting value to the node
{
    data=num;
}
node* node::getlink()const//returns the pointer to the next node
{
    return next;
}
void node::setlink(node *link)//sets the link to the next node
{
    next=link;
}
