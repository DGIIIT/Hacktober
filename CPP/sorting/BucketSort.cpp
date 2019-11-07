#include<iostream>
using namespace std;
 class node{
 public:
 float data;
 node* next;
 node(float data){
 this->data=data;
 next=NULL;
 }
 };
void insert_ll(node** bucket,int position,float element){
   node* newNode=new node(element);
   node*q;
   if(bucket[position]==NULL){
     bucket[position]=newNode;
     bucket[position]->next=NULL;
   }
   else{
   node* temp=bucket[position];
   node* q=NULL;
   if(bucket[position]->data>element){
   node* newNode=new node(element);
   newNode->next=bucket[position];
   bucket[position]=newNode;
   return;
 }
 while(temp!=NULL){
 if(temp->data>element){
 node* newNode=new node(element);
 q->next=newNode;
 newNode->next=temp;
 return;
 }
 q=temp;
 temp=temp->next;
 }
 node* newNode=new node(element);
 q->next=newNode;
 newNode->next=temp;
   }
}
void bucketSort(float*arr,node** bucket,int n){
   for(int i=0;i<n;i++){
      insert_ll(bucket,n*arr[i],arr[i]);
   }
   cout<<"\nAfter sorting:";
   for(int i=0;i<n;i++){
     while(bucket[i]!=NULL){
       cout<<bucket[i]->data<<" ";
       bucket[i]=bucket[i]->next;
   }
   }
}
int main(){
int n;
cout<<"Enter limit:";
cin>>n;
cout<<"\nEnter array elements:";
float* arr=new float[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
node** bucket=new node*[n];
for(int i=0;i<n;i++){
  bucket[i]=new node(0);
  bucket[i]=NULL;
}
bucketSort(arr,bucket,n);
}

