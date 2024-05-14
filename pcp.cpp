#include<iostream>
#include<string>
using namespace std;


//Function 1

struct Node{
    string value;
    Node* left;
    Node* right;
};

//Function 2

Node* Createnewnode(string value, Node* left=nullptr,Node* right=nullptr){

    Node* newNode=new Node;
    newNode->value=value;
    newNode->left=left;
    newNode-> right=right;
    return newNode;
}


//Function 3

int evaluatetree(Node* root){
    if (root==nullptr){
        return 0;
    }

    if (root->left==nullptr && root->right==nullptr){
        return stoi(root->value);
    }


    int left=evaluatetree(root->left);
    int right=evaluatetree(root->right);

    switch(root->value[0]){
        case '+': return left + right;         
        case '-': return left - right;         
        case '*': return left * right;         
        case '/': return left / right;         
        default: return 0;
    }


}


int main(){
    Node* root=Createnewnode("+",
    Createnewnode("*",Createnewnode("5"),Createnewnode("3")),
    Createnewnode("-",Createnewnode("7"),Createnewnode("3")));
    int result=evaluatetree(root);
    cout<<result<<endl;
}