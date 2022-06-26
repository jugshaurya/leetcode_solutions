/* First non-repeating character in a stream of characters
* Problem Description
* Given a string A denoting a stream of lowercase alphabets. You have to make new string B.
* B is formed such that we have to find first non-repeating character each time a character is 
* inserted to the stream and append it at the end to B. If no non-repeating character is found then append '#'
* at the end of B.

Problem Constraints
1 <= length of the string <= 100000
*/

string Solution::solve(string A) {
    queue<int> q;
    vector<int> mp(26, 0);
    
    string ans;
    for(int i = 0; A[i] != '\0';i++) {
        char ch = A[i];
        if(mp[ch - 'a'] == 0){
            q.push(ch);
            mp[ch - 'a'] += 1;
            ans += q.front();
        } else {
            mp[ch - 'a'] += 1;
            while(!q.empty() and mp[q.front() - 'a'] > 1){
                q.pop();
            }
            if(q.empty()) ans += '#';
            else ans += q.front();
        }    
    }
    return ans;
}
