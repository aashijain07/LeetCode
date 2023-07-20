class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] >= 0){
                st.push(arr[i]);
            }
            else{
                if(st.empty() || st.top() < 0){
                    st.push(arr[i]);
                }
                else{
                    while(!st.empty() && st.top() > 0 && st.top() < abs(arr[i])){
                        st.pop();
                    }

                    if(st.empty() || st.top() < 0){
                        st.push(arr[i]);
                    }
                    else if(st.top() == abs(arr[i])){
                        st.pop();
                    }
                }
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};