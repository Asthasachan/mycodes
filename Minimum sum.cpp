//https://practice.geeksforgeeks.org/problems/minimum-sum4058/1#
string addstr(string s1,string s2){
        int n1 = s1.size();
        int n2 = s2.size();
        string res = "";
        int i = n1 - 1;
        int j = n2 - 1;
        int carry = 0;
        while(i>=0 || j>=0 || carry){
            int sum = carry;
            sum += (i>=0)? (s1[i--]-'0'):(0);
            sum += (j>=0)? (s2[j--]-'0'):(0);
            res = char(sum%10 + '0') + res;
            carry = sum/10;
        }
        return res;
    }
public:
    string solve(int arr[], int n) {
        if(n == 1){
            return to_string(arr[0]);
        }
        sort(arr,arr+n);
        if(arr[n-1] == 0) return "0";
        string n1,n2;
        for(int i=0;i<n;i++){
            if(arr[i] == 0) continue;
            else if(i&1){
                n1.push_back(arr[i]+'0');
            }
            else{
                n2.push_back(arr[i]+'0');
            }
        }
        return addstr(n1,n2);
    }
