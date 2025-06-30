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

// reversing DLL:

// 1) using a stack (complexity:O(2N)):

void reverseDLLUsingStack(Node* head){
  if(head==nullptr or head->next==nullptr) return head;
  
  stack<int> num;
  Node* temp = head;
  while(temp!=nullptr){
    num.push(temp->data);
    temp = temp->next;
  }
  temp = head;
  while(num.size()!=0){
    temp->data = num.top();
    num.pop();
    temp = temp->next;
  }
}

// 2) most optimal soln(complexity:O(N)):

Node* reverseDLL(Node*head){
  if(head==nullptr or head->next==nullptr) return head;
  
  Node* temp = head;
  Node* front = nullptr;
  Node* prev = nullptr;
  
  while(temp!=nullptr){
    front = temp->next;
    prev = temp->back;
    temp->next = prev;
    temp->back = front;
    
    head = temp;
    temp = temp->back;
  }
  
  return head;
}


int main(){
  vector<int> arr = {1,2,3,4,5,6,7,8,9};
  Node* head = convertArrToDLL(arr);
  print(head);
  reverseDLLUsingStack(head);
  print(head);
  return 0;
}