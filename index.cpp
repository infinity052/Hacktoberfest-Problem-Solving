#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hp;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(hp.count(target-nums[i])){
                res.push_back(hp[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            hp[nums[i]]=i;
        }
        return res;
    }
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            int target=-nums[i];
            int left=i+1;
            int right=nums.size()-1;
            
            while(left<right){
                int sum=nums[left]+nums[right];
                if(sum<target){
                    left++;
                }else if(sum>target){
                    right--;
                }else{
                    vector<int> triplet({nums[i],nums[left],nums[right]});
                    res.push_back(triplet);
                    while(left<right and nums[left]==triplet[1])
                        left++;
                   
                    right--;
                }
            }
            // duplicates for number 1
            while(i<nums.size()-1 and nums[i+1]==nums[i])
                i++;
        }
        
        return res;
    }
bool canJump(vector<int>& nums) {
        int reachable = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (i > reachable) return false;
            reachable = std::max(reachable, i + nums[i]);
        }
        return true;
    }
int maxArea(vector<int>& height) {
        int area=0,length=0,width=0,maxarea=0;
        int i=0,j=height.size()-1;
        while(i!=j){
            length=min(height[i],height[j]);
            width=j-i;
            area=length*width;
            maxarea=max(maxarea,area);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxarea;
    }
bool isValid(string s) {
        stack<char> str;
	for(int i=0;i<s.length();i++){
		char ch=s[i];
		if(ch=='(' or ch=='{' or ch=='[')
			str.push(ch);
		else{
			if(str.empty())
				return false;
			if(ch==')' and str.top()=='(')
				str.pop();
			else if(ch=='}' and str.top()=='{')
				str.pop();
			else if(ch==']' and str.top()=='[')
				str.pop();
			else
				return false;
		}
	}
	return str.empty();
    }
int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hp;
        int maxLen=0;
        int currLen=0;
        int left=0,right=0;
        while(right<s.length()){
            if(hp[s[right]]==0){
                hp[s[right]]++;
                right++;
                currLen=right-left;
                maxLen=max(maxLen,currLen);
            }
            else{
                hp[s[left]]=0;
                left++;
                currLen=right-left;
                maxLen=max(maxLen,currLen);
            }
        }
        return maxLen;
    }
 bool detectCapitalUse(string word) {
        int count=0;
        int index=-1;
        
        for(int i=0;i<word.length();i++){
            if(isupper(word[i])){
                if(count==0 and i!=0)
                    return false;
                count++;
                if(i==0)
                    index=0;
            }
            else{
                if(count>0 and index!=0)
                    return false;
            }
        }
        if(count==word.length() or count<=1)
            return true;
        else
            return false;
    }
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
       
        // to make sure n>=m
        if(m>n){
            vector<int> temp(nums1);
            nums1=nums2;
            nums2=temp;
            
            int len=m;
            m=n;
            n=len;
        }
        
        int iMin=0,iMax=m,halfLen=(m+n+1)/2;
        
        while(iMin<=iMax){
            int i=(iMin+iMax)/2;
            int j=halfLen-i;
            
            //2nd case
            if(i>iMin and nums1[i-1]>nums2[j]) {
                iMax=i-1;
            }
            //3rd case
            else if(i<iMax and nums2[j-1]>nums1[i]){
                iMin=i+1;
            }
            //perfect i
            else{
                int maxLeft=0;
                if(i==0)
                    maxLeft=nums2[j-1];
                else if(j==0)
                    maxLeft=nums1[i-1];
                else
                    maxLeft=max(nums1[i-1],nums2[j-1]);
                
                if((m+n)%2!=0){ //odd length
                    return maxLeft;
                }
                
                int minRight=0;
                if(i==m)
                    minRight=nums2[j];
                else if(j==n)
                    minRight=nums1[i];
                else
                    minRight=min(nums1[i],nums2[j]);
                
                //median
                return (maxLeft+minRight)/2.0;
            }
                
        }
        return 0.0;
        
    }
int main(){
  return 0;
}
