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

// insert an integer x just before the head of linked list:

Node* insertionBeforeHead(Node* head, int x){
  Node* newNode = new Node(x);
  if(head==nullptr){
    return newNode;
  }
  else{
  head->back = newNode;
  newNode->next = head;
  return newNode;
  }
}


int main(){
  vector<int> arr = {1,2,3,4,5};
  Node* head = convertArrToDLL(arr);
  print(head);
  head = insertionBeforeHead(head, 10);
  print(head);
  return 0;
}