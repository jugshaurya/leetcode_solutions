// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

Node* search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;
    
    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}


 // } Driver Code Ends
/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    
    Node* helper(Node *root, Node *x, Node* inorderSuccessorNode) {
    
      if(root == NULL) return NULL;
    
      if(root->data == x->data and root->right == NULL) return inorderSuccessorNode; 
      
      if(root->data == x->data) {
        Node* tmp = root->right;
        while(tmp->left != NULL) tmp = tmp->left;
        return tmp;
      }
    
      if(root->data > x->data){
        inorderSuccessorNode = root;
        return helper(root->left, x, inorderSuccessorNode);   
      }
    
      return helper(root->right, x, inorderSuccessorNode);
    }
    
    // using reverse inorder
    void helper2(Node *root, Node *x, int& prev, int& ans) {
        if(root == NULL) return;
        helper2(root->right, x, prev, ans);
        if(root->data == x->data) {
            ans = prev; 
            return;
        }
        prev = root->data;
        helper2(root->left, x, prev, ans);   
    }
    
    Node* inOrderSuccessor(Node *root, Node *x) {
    //   return helper(root, x, new Node(-1));
        int prev = -1;
        int ans;
        helper2(root, x, prev, ans);
        
        return new Node(ans);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int k;
        cin>>k;
        getchar();
        
        Node* kNode = search( head, k );
        Solution obj;
        Node* suc = obj.inOrderSuccessor(head, kNode);
        
        if( suc == NULL ) cout<< "-1";
        else cout<< suc->data;
        cout << endl;
    }
    
    return 1;
}  // } Driver Code Ends