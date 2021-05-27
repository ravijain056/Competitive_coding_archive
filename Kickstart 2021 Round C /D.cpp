#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define mp make_pair
#define pb push_back

const int mod = 1e9+7;

unordered_map<string, string> eval_hash;
unordered_map<string, int> assigned_class;
int curevalhash = 1;
int tries;

string add(string A, string B) {
    int ptA = A.size(), ptB = B.size();
    
    if (ptA < ptB) {
        swap(A, B);
        swap(ptA, ptB);
    }
    
    int carry = 0;
    for(int i = 1; i <= ptB; i++) {
        int a = A[ptA - i] - '0', b = B[ptB - i] - '0';
        int c = a + b + carry;
        carry = c / 10;
        A[ptA - i] = (c % 10) + '0';
    }

    for(int i = ptB + 1; i <= ptA; i++) {
        int a = A[ptA - i] - '0';
        int c = a + carry;
        carry = c / 10;
        A[ptA - i] = (c % 10) + '0';
        if(carry == 0) 
            break;
    }
    
    if(carry != 0) A = string(1, '0' + carry) + A;
    return A;
}

string mul(string A, int b) {
    reverse(A.begin(), A.end());
    int carry = 0;
    for(int i = 0; i < A.size(); i++) {
        int a = A[i] - '0';
        int c = a * b + carry;
        carry = c / 10;
        c %= 10;
        A[i] = c + '0';
    }
    if(carry != 0) A.pb(carry + '0');
    while(A.back() == '0') A.pop_back();
    reverse(A.begin(), A.end());
    if (A == "") A = "0";
    return A;
}

string mul(string A, string B) {
    if((int)A.size() < (int)B.size()) swap(A, B);
    reverse(B.begin(), B.end());
    string ans = "0";
    for(int i = 0; i < B.size(); i++) ans = add(ans, mul(A+ string(i, '0'), B[i] - '0'));
    return ans;
}

string hashop(string A, string B) {
    A = A + "#" + B;
    if(eval_hash.find(A) == eval_hash.end()) {
        eval_hash[A] = to_string(curevalhash);
        curevalhash += tries;
    }
    return eval_hash[A];
}

pair<string, int> eval(string s, int i) {

    string A, B;
    if(s[i] == '(') {
        pair<string, int> Ai = eval(s, i+1);
        A = Ai.first;
        i = Ai.second;
    } else {
        while(s[i] >= '0' && s[i] <= '9') 
            A.pb(s[i++]);
    }
    char op = s[i++];
    if(s[i] == '(') {
        pair<string, int> Bi = eval(s, i+1);
        B = Bi.first;
        i = Bi.second;
    } else {
        while(s[i] >= '0' && s[i] <= '9') 
            B.pb(s[i++]);
    }
    string ans;
    if(op == '+') ans = add(A, B);
    else if(op == '*') ans = mul(A, B);
    else if(op == '#') ans = hashop(A, B);
    return mp(ans, i+1);
}

vi combine(vi a1, vi a2) {
    unordered_map<string, int> cl;
    int cur = 1;
    vi ans(a1.size());
    for(int i = 0; i < a1.size(); i++) {
        string c = to_string(a1[i]) + "," + to_string(a2[i]);
        if(cl.find(c) == cl.end())
            cl[c] = cur++;
        ans[i] = cl[c];
    }
    return ans;
}


int main() {

    #ifdef LOCAL_DEV
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(6) << fixed;

    int t;
    cin >> t;

    for(int ti = 1; ti <= t; ti++) {
        curevalhash = 1;
        int n;
        cin >> n;
        vector<string> inp(n);
        int curclass = 1;
        vi ans(n);
        tries = 10;
        
        for(int i = 0; i < n; i++) {
            cin >> inp[i];
            string s = inp[i];
            string a = (s[0] == '(') ? eval(s, 1).first : s;
            if(assigned_class.find(a) == assigned_class.end())
                assigned_class[a] = curclass++;
            ans[i] = assigned_class[a];
            //cout << s << "\n" << a << "\n";
        }

        while(tries--) {
            eval_hash.clear();
            assigned_class.clear();
            vi ans2(n);
            for(int i = 0; i < n; i++) {
                string s = inp[i];
                string a = (s[0] == '(') ? eval(s, 1).first : s;
                if(assigned_class.find(a) == assigned_class.end())
                    assigned_class[a] = curclass++;
                ans2[i] = assigned_class[a];
                //cout << s << "\n" << a << "\n";
            }
            ans = combine(ans, ans2);
        }

        cout << "Case #" << ti << ": " ; 
        for(int a : ans) cout << a << " ";
        cout << "\n";
    }

    return 0;
}
