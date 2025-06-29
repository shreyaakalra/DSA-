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

Node* InsertAtBeginning(Node *head){
  int data;
  cin >> data;
  Node *newNode = new Node(data);
  Node *temp = head;
  head = newNode;
  newNode->next = temp;
  
  return head;
}

int main(){
  
  Node *head = nullptr;
  Node *head2 = nullptr;
  head = takeInput();
  head2 = InsertAtBeginning(head);
  print(head2);

}