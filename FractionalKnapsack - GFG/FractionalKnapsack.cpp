// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


bool cmp(Item a, Item b){
    return a.value * b.weight > b.value * a.weight;
}

class Solution{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n){
        // Your code here
        sort(arr, arr+n, cmp);
        
        double ans = 0;
        for(int i=0;i<n;i++){
            
            double pricePerUnit = (1.0 * arr[i].value) / arr[i].weight;
            
            if(arr[i].weight <= W){
                ans += arr[i].value;
                W -= arr[i].weight;
            }else{
                ans += pricePerUnit * W; 
                break;
            }
        }
        
        return ans;
    }
};
