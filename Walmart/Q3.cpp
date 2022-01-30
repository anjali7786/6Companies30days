#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool winnerOfGame(string colors) {
       
        if(colors.size()<=2)
            return false;
        
        int cnt=0,ans=0;
        for(int i=0;i<colors.size();i++)
        {
            if(colors[i]=='A')
                cnt++;
            else
            {
                if(cnt>2)
                    ans+=cnt-2;
                cnt=0;
            }
        }
       if(cnt>2)
            ans+=cnt-2;

        int cnt2=0,ans2=0;
        for(int i=0;i<colors.size();i++)
        {
            if(colors[i]=='B')
                cnt2++;
            else
            {
                if(cnt2>2)
                    ans2+=cnt2-2;
                cnt2=0;
            }
        }
       if(cnt2>2)
            ans2+=cnt2-2;

        // cout<<ans<<" "<<ans2<<endl;
        if(ans>ans2)
            return true;
        return false;
        
    }
};