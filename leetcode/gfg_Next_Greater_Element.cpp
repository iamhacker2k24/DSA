class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        
        vector <int > ans(arr.size(),-1) ;
        for (int i =0;i<arr.size();i++){
            for (int j =i+1;j<arr.size();j++){
                if(arr[j]>arr[i]){
                    // ans.push_back(arr[j]);
                    ans [i]=arr[j];
                    break;
                }
            }
        }
        return ans ;
    }
};