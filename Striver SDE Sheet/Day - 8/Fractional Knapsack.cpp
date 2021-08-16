// Hari

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item a, Item b){
        double r1 = (double)a.value / (double)a.weight; // double as val may come in decimal.
        double r2 = (double)b.value / (double)b.weight; // double as val may come in decimal.
        return r1 > r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, comp);
        int currWt = 0;
        double finalVal = 0.0;
        
        for(int i = 0; i<n; i++){
            if(currWt+arr[i].weight <= W){
                finalVal += arr[i].value;
                currWt += arr[i].weight;
            }
            
            else {
                int remWt = W - currWt;
                finalVal += ((arr[i].value)/((double) arr[i].weight)) * (double)remWt;
                break;
            }
        }
        
        return finalVal;
        
        
    }
        
};
