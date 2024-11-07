#include<bits/stdc++.h>
using namespace std;

class node {
  public :
  int data;
  node* next;
  
  node(int data){
      this->data = data;
      next = NULL;
  }
};

void insertAtHead(node* &head, node* &tail, int value){
    node* temp = new node(value);
    
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    
    else{
        temp->next = head;
        head = temp;
    }
}

void inserAtTail(node* &head,node* &tail,int data){
    if(tail == NULL){
        node* temp = new node(data);
        head = temp;
        tail = temp;
    }
    
    else{
        node* temp = new node(data);
        tail->next = temp;
        tail = temp;
    }
}

void insertAtAnyPosition(node* &head, node* &tail, int position, int value){
    if(position == 1){
        insertAtHead(head, tail, value);
        return;
    }
    
    int count = 1;
    node* temp = head;
    
    while(count < position - 1){
        temp = temp->next;
        count++;
    }
    
    if(temp->next == NULL){
        inserAtTail(head,tail,value);
        return;
    }
    
    node* insert = new node(value);
    insert->next = temp->next;
    temp->next = insert;
}

void deletionByPosition(node* &head, int position){
    if(head == NULL){
        return;
    }
    
    if(position == 1){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    
    int count = 1;
    node* temp = head;
    node* pre;
    
    while(count < position){
        pre = temp;
        temp = temp->next;
        count++;
    }
    
    pre->next = temp->next;
    temp->next = NULL;
    delete temp;
    return;
}

void deletionByValue(node* &head, int value){
    if(head == NULL){
        return;
    }
    
    if(head->data == value){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    
    node* temp = head;
    
    while(temp->next != NULL && temp->next->data != value){
        temp = temp->next;
    }
    
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return;
}

node* reverse(node* &head){
    if(head == NULL){
        return NULL;
    }
    
    if(head->next == NULL){
        return head;
    }
    
    node* cur = head;
    node* pre = NULL;
    node* temp;
    
    while(cur != NULL){
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    
    return pre;
}

node* middleElement(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    if(head->next->next == NULL){
        return head->next;
    }
    
    node* fast = head->next;
    node* slow =  head;
    
    while(fast != NULL){
        fast = fast->next;
        
        if(fast != NULL){
            fast = fast->next;
        }
        
        slow = slow->next;
    }
    
    return slow;
}

void removeDuplicate(node* &head){
    if(head == NULL || head->next == NULL){
        return;
    }
    
    map<int,bool> visited;
    node* temp = head;
    node* pre;
    
    while(temp != NULL){
        if(visited[temp->data] == true){
            pre->next = temp->next;
            delete temp;
            temp = pre->next;
            
        }
        else{
            visited[temp->data] = true;
            pre = temp;
            temp = temp->next;
        }
    }
}

void printLL(node* head){
    node* temp = head;
    
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    
    cout<<"Enter data, when you do not want inser data then enter -1 : "<<endl;
    int x; cin>>x;
    
    while(x != -1){
        inserAtTail(head,tail,x);
        cin>>x;
    }
    
    // insertAtAnyPosition(head, tail, 3, 10);
    
    //deletionByPosition(head, 3);
    
    // deletionByValue(head, 2);
    
    // node* rev = reverse(head);
    
    // node* middle = middleElement(head);
    // cout<<middle->data<<endl;
    
    removeDuplicate(head);
    
    printLL(head);
    
    return 0;
}