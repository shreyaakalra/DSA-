#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node *next;

  Node(int value){
    data = value;
    next = nullptr;
  }
};

void print(Node *head){
  Node *temp = head;
  
  while(temp!=nullptr){
    cout << temp->data << endl;
    temp = temp->next;
  }
}

Node* takeInput(){
  int data;
  cin >> data;
  
  Node *head = nullptr;
  Node *tail = nullptr;
  
  while(data!=-1){
    Node *newNode = new Node(data);
    if(head==nullptr){
      head = newNode;
      tail = newNode;
    }
    else{
      tail->next = newNode;
      tail = newNode;
    }
    
    cin >> data;
  }
  
  return head;
}

void InsertInTheMiddle(Node *head, int index, int data){
  
  Node *newNode = new Node(data);
  Node *temp = head;
  
  for(int i=1; i<index-1; i++){
    temp = temp->next;
  }
  
  newNode->next = temp->next;
  temp->next = newNode;
}

int main(){
  
  Node *head = nullptr;
  head = takeInput();
  print(head);
  cout << endl; 
  InsertInTheMiddle(head,3,10);
  print(head);

}