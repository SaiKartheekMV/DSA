#include <bits/stdc++.h>
using namespace std;

long long subArrayRanges(vector<int> &nums)
{
    int n = nums.size();
    vector<int> l1(n), r1(n), l2(n), r2(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            l1[i] = -1;
        }
        else
        {
            l1[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            r1[i] = n;
        }
        else
        {
            r1[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            l2[i] = -1;
        }
        else
        {
            l2[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            r2[i] = n;
        }
        else
        {
            r2[i] = st.top();
        }
        st.push(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long l1Choice = i - l1[i];
        long long r1Choice = r1[i] - i;

        long long totalMinimumContribution = nums[i] * l1Choice * r1Choice;

        long long l2Choice = i - l2[i];
        long long r2Choice = r2[i] - i;

        long long totalMaximumContribution = nums[i] * l2Choice * r2Choice;

        ans = ans + totalMaximumContribution - totalMinimumContribution;
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<subArrayRanges(nums)<<endl;
    return 0;
}