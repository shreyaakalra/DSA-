#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* back;
  
  Node(int data1, Node* next1,Node* back1) {
    data = data1;
    next = next1;
    back = back1;
  }
  
  Node(int data1){
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

// taking input or converting array into DLL

Node* convertArrToDLL(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* prev = head;
  
  for(int i=1; i<arr.size(); i++){
    Node* temp = new Node(arr[i],nullptr,prev);
    prev->next = temp;
    prev=temp;
  }
  return head;
}

// printing DLL

void print(Node* head){
  while(head!=nullptr){
    cout << head->data << " ";
    head=head->next;
  }
  cout << endl;
}

// DELETION:

// 1) Delete the head node:

Node* deleteHeadNode(Node* head){
  if(head==nullptr){ 
    return head;
  }
  else if(head->next==nullptr){
    return nullptr;
  }
  else{
  Node* temp = head->next;
  temp->back = nullptr;
  head->next = nullptr;
  delete head;
  return temp;
  }
}

// 2) Delete the last node:

void deleteLastNode(Node* head){
  if(head==nullptr or head->next==nullptr){
    return;
  }
  else{
    Node* temp = head;
    while(temp->next->next!=nullptr){
      temp = temp->next;
    }
    temp->next->back = nullptr;
    Node* last = temp->next;
    temp->next = nullptr;
    delete last;
  }
}

// 3) delete any node except first and last:

void deleteAnyNode(Node* head,int index){
  Node* temp = head;
  for(int i=1; i<index; i++){
    temp = temp->next;
  }
  temp->back->next = temp->next;
  Node* prev = temp->back;
  temp->back = nullptr;
  temp->next->back = prev;
  temp->next = nullptr;
  delete temp;
}


int main(){
  vector<int> arr = {12,5,8,7};
  Node* head = convertArrToDLL(arr);
  print(head);
  deleteAnyNode(head, 3);
  print(head);
  return 0;
}