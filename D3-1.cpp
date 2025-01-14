class Solution {
  public:
    void calculateSubsetSums(int index, int currentSum, vector<int>& arr, vector<int>& result) {
        // Base case: if we have processed all elements
        if (index == arr.size()) {
            result.push_back(currentSum);
            return;
        }

        // Include the current element in the subset
        calculateSubsetSums(index + 1, currentSum + arr[index], arr, result);

        // Exclude the current element from the subset
        calculateSubsetSums(index + 1, currentSum, arr, result);
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> result;
        calculateSubsetSums(0, 0, arr, result); // Start recursion from index 0 with sum 0
        return result;
    }
};
