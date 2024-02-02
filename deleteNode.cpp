#include <iostream>
using namespace std;

class Node
{
public:
 int data;
 Node *next; // pointer to the next node in the list.

 Node(int data)
 {
  this->data = data;
  this->next = NULL;
 }
 ~Node(){
 }
};

void insertAtHead(Node *&head, int d)
{
 Node *temp = new Node(d);
 temp->next = head;
 head = temp;
}

void insertAtTail(Node *&tail, int d)
{
 Node *temp = new Node(d);
 tail->next = temp;
 tail = temp;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
 // Handling the case for position of 1
 if (position == 1)
 {
  insertAtHead(head, d);
  return;
 }

 Node *temp = head;
 int cnt = 1;
 while (cnt < position - 1)
 {
  temp = temp->next;
  cnt++;
 }
 // Now Handling the case for the tail node
 if (temp->next == NULL)
 {
  insertAtTail(tail, d);
  return;
 }

 Node *nodeToInsert = new Node(d);
 nodeToInsert->next = temp->next;
 temp->next = nodeToInsert;
}

void deleteNode(int position,Node* &head,Node* &tail){
 if(position==1){
  Node* temp = head;
  head = head->next;
  temp->next = NULL;
  delete temp;
 }
 else{
  Node* prev = NULL;
  Node* curr = head;
  int cnt = 1;
  while(cnt<position){
   prev = curr;
   curr = curr->next;
   cnt++;
  // For handling the tail position 
   if(curr->next==NULL){
    tail = prev;
   }
  }
  prev->next = curr->next;
  curr->next = NULL;
  delete curr;
 }
}

void print(Node *head)
{
 Node *temp = head;
 while (temp != NULL)
 {
  cout << temp->data << " ";
  temp = temp->next;
 }
 cout << endl;
}

int main()
{
 Node *node1 = new Node(10);
 // cout << node1->data << endl;
 // cout << node1->next << endl;

 Node *head = node1;
 Node *tail = node1;
 print(head);

 insertAtTail(tail, 12);
 print(head);

 insertAtTail(tail, 15);
 print(head);

 insertAtPosition(tail, head, 4, 22);
 print(head);
 cout << "head " << head->data << endl;
 cout << "tail " << tail->data << endl;

 deleteNode(4,head,tail);
 print(head);
 cout << "head " << head->data << endl;
 cout << "tail " << tail->data << endl;
 return 0;
}