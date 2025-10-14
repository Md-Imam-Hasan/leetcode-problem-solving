class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0, temp=0;

        for(int i=1;i<chars.size();i++){
            if(chars[i]==chars[i-1]){
                temp++;
            }
            else{
                chars[ans++] = chars[i-1];
                if(temp>0){
                    string s = to_string(temp+1);
                    for(auto c:s) chars[ans++] = c;
                }
                temp=0;
            }
        }
        chars[ans++] = chars.back();
        if(temp>0){
            string s = to_string(temp+1);
            for(auto c:s) chars[ans++] = c;
        }
        return ans;
    }
};