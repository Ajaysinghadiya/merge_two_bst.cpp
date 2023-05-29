



// } Driver Code Ends
/*
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
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
    //Merge two sorted vectors
    vector<int>mergeVec(vector<int >&v1, vector<int >&v2){
        
        int i=0, j=0;
        int n= v1.size();
        int m = v2.size();
        int k=0;
        vector<int >v3(n+m);
        while(i < n && j < m ){
            if(v1[i]>v2[j]){
                v3[k++]=v2[j];
                j++;
            }
            else{
                v3[k++]=v1[i];
                i++;
            }
        }
        while(i<n){
            v3[k++]=v1[i];
            i++;
        }
        while(j<m){
            v3[k++]=v2[j];
            j++;
        }
        return v3;
    }
    
    
    // convert from inorder to bst
    Node* BalancedBST(vector<int> &vec, int s, int e){
        // int n= vec.size();
        int mid = s+(e-s)/2;
        if(s>e){
            return NULL;
        }
        Node* New_root = new Node(vec[mid]);
        New_root->left=BalancedBST(vec, s, mid-1);
        New_root->right = BalancedBST(vec, mid+1, e);
        return New_root;
    }
    
    
    
    // Store the inorer in vector
    void Inorder(Node*root, vector<int >&v){//Store the sorted vector
        if(root==NULL){
            return;
        }
        Inorder(root->left, v);
        v.push_back(root->data);
        Inorder(root->right, v);
    }
    
    
    
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int >v1;
       vector<int >v2;
       Inorder(root1, v1);//Inorder of 1st bst
       Inorder(root2, v2);//Inorder of 2nd bst
       
       vector<int >ans=mergeVec(v1, v2);//merging two sorted vecors
       
       int s=0;
       int e = ans.size()-1;
       
       //convert the inorder into bst
       
       Node*temp = BalancedBST(ans, s, e);
       
       vector<int >answer;
       Inorder(temp, answer);//store the merged bst in a vector in the form of inorder 
       return answer;
    }
};













//{ Driver Code Starts.
int main() {

 
