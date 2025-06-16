#include<bits/stdc++.h>
using namespace std;

// struct represents one node in a binary tree
struct Node{
  int data; // stores value in the node
  struct Node *left; // pointer to the left child
  struct Node *right; // pointer to the right child
  
  // this is a constructor
  Node(int value){
    data = value;
    left=right=NULL;
  }
};

int main(){
  struct Node *root = new Node(1);
  root -> left = new Node(2);
  root -> right = new Node(3);
  root -> left -> right = new Node(5);
}