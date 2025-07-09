#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    //constant window
    //given an array .and find max sum of 4 consevative num
    int n;
    cin>>n;
    vector<int>s(n);

    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int l=0 ,r=3;
    int sum=accumulate(s.begin(),s.begin()+4,0);
    int maxsum=sum;
    while(r<=n-1)
    {
        sum-=s[l];
        l++;
        r++;
        sum+=s[r];
        maxsum=max(maxsum,sum);
    }

    /* most important
    given an array .find longest subarray sum len <=k
    ->ans: 1.brute force
           2.better
           3.optimal


     better :  (this is must if u told to find subarray)
         while(r<n)
         {
            sum=sum+arr[r];
            while(sum>k)
            {
              sum-=arr[l];
              l++;
            }

            if(sum<=k)
            {
               maxlen=max(maxlen,r-l+1);
            }
               r++;
         }
           cout<<maxlen;

           TC:o(2n) SC:

    optimal:
     */int right ,left ,maxLen=0,k,arr[n] ;
       for (int right = 0; right < n; ++right) {
            sum += arr[right];

        // Shrink from the left until sum < k
        while (sum >= k && left <= right) {
            sum -= arr[left];
            ++left;
        }

        // Now sum < k and subarray is valid
        maxLen = max(maxLen, right - left + 1);
    }

    /* find number of subarray <condition>
         
       pattern :(sum==k)
               num of sub array sum<k
               num of sub array sum<=(k-1)
               now subtract two num
    */

    /*
     finding shortest /min window /len <condition
    */

    return 0;
}
