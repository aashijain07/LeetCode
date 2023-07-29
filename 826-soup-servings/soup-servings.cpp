class Solution {
public:
  map<pair<int,int>,double>mp;
    double f(int a,int b){
        if(a<= 0 && b<= 0) {
            return 0.5;
        }
        if(a<=0) {
            return 1.0;
        }
        if(b<=0) {
            return 0;
        }
        if(mp.find({a,b})!=mp.end())return mp[{a,b}];
        double ans=0;
         ans+=f(a-100,b);
        ans=ans+f(a-75,b-25)+f(a-50,b-50)+f(a-25,b-75);
        return mp[{a,b}]=0.25*ans;
    }
    double soupServings(int n) {
        if(n>=5000)return 1;
       return f(n,n);
    }
};