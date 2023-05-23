class KthLargest {
private:
    vector<int> kLargest;
public:
    /**
    solution.cpp: In static member function 'static KthLargest*      __DriverSolution__::__helperConstructor__(const string&, const std::vector<std::__cxx11::basic_string<char> >&)':
    Line 99: Char 41: error: cannot bind non-const lvalue reference of type 'std::vector<int>&' to an rvalue of type 'std::vector<int>'
    **/
    // KthLargest(int k, vector<int>& nums) {
    KthLargest(int k, vector<int> nums) {
        kLargest = vector<int>();
        if(nums.size() > 0){
            sort(nums.begin(), nums.end());
            //(nums.size(), k , nums.size()-1-k) = (1, 1, 18446744073709551615)??
            //push until kLargest has k elements or nums has been iterated
            for(vector<int>::reverse_iterator rit = nums.rbegin(); rit < nums.rbegin() + k && rit != nums.rend(); rit++){
                kLargest.push_back(*rit);
            }
        }
        //keep insert 
        for(int i = kLargest.size(); i < k; i++){
            kLargest.push_back(INT_MIN);
        }
    }
    
    int add(int val) {
        int k = kLargest.size();
        kLargest.push_back(val);
        
        for(int i = 0; i < k; i++){
            if(val >= kLargest[i]){
                kLargest.insert(kLargest.begin()+i, val);
                break;
            }
        }
        kLargest.resize(k);
        return kLargest[k-1];
    }
};