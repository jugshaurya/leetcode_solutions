/*
https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1
*/
int minDiff(Node *root, int K){
        
        if(root==NULL) return 1e9;
        
        if(root->data ==  K){
            return 0;
        }
        
        if(root->data < K){
            
            int rightAns = minDiff(root->right, K);
            return min(abs(K - root->data), rightAns);
        }
        
        int leftAns = minDiff(root->left, K);
        return min(abs(K - root->data), leftAns);
    }
};
