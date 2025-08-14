#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int last = 0;
int n;
vector<int> bfs(vector<vector<int>> v, int end) {


    vector<int> res;
    queue<int> q;
    q.push(end);
    int flag = 0;
    map<int, int> ma;
    ma[end] = -1;
    while (!q.empty() && flag != 1) {
        int top = q.front();
        q.pop();
        for (auto c : v[top]) {
            if (ma.find(c) == ma.end()) {
                ma[c] = top;
                q.push(c);
                if (c == 1) {
                    flag = 1;
                    break;
                }
            }

        }

    }
    if (flag == 1) {
        int tek = 1;
        while (tek != -1) {
            res.push_back(tek);
            tek = ma[tek];
        }
        reverse(res.begin(), res.end());
    }
    return res;


}
int func1( vector<vector<int>> v, vector<pair<int, int>> v2, map<int, int> m) {
    vector<vector<int>> r;
    map<int, int> m2;
    int count = 1;
    for (auto c : v2) {
        r.push_back( bfs(v, c.first));
        m2[count] = c.second;
        count++;
    }
    
    vector<int> a(v.size(), 0);
    for (int i = 0;i<r.size();i++) {
        for (auto l : r[i]) {
            a[l] += ((m[l] + 1) * m2[i + 1]);
        }
        
    }
    int ma = -1;
    for (auto t : a) {
        if (t > ma) {
            ma = t;
        }
    }
    return ma;
   


}
int func2(vector<vector<int>> v, vector<pair<int, int>> v2, map<int, int> m) {
    vector<pair<int, int>> v3;
    for (auto i : v2) {
        v3.push_back({ (i.first + last) % (n - 1)+2,i.second });
    }
    vector<vector<int>> r;
    map<int, int> m2;
    int count = 1;
    for (auto c : v3) {
        r.push_back(bfs(v, c.first));
        m2[count] = c.second;
        count++;
    }

    vector<int> a(v.size(), 0);
    for (int i = 0; i < r.size(); i++) {
        for (auto l : r[i]) {
            a[l] += ((m[l] + 1) * m2[i + 1]);
        }

    }
    int ma = -1;
    for (auto t : a) {
        if (t > ma) {
            ma = t;
        }
    }
    last = ma;
    return ma;
}
int main() {
   
    cin >> n;
    vector<vector<int>> v(n + 1);
    map<int, int> m;
    int co = 1;
    for (int i = 1; i <= n; i++) {
        m[i] = -1;

    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);

    }

    m[1] = 0;

    int count = 1;
    for (int i = 1; i < v.size(); i++) {
        
        vector<int> v2;
        for (int j = 0; j < v[i].size(); j++) {
            if (m[v[i][j]] == -1) {
                m[v[i][j]] = count;
            }
            v2.push_back(v[i][j]);




        }
       
    
        count++;
        for (int k = 0; k < v2.size(); k++) {
            for (int j = 0; j < v[v2[k]].size(); j++) {
                
                if (m[v[v2[k]][j]] < 0) {
                    m[v[v2[k]][j]] = count;
                }
            }
        }


    }
   




    int q, t;
    cin >> q >> t;
    for (int i = 0; i < q; i++) {
      int k;
      cin >> k;
      vector<pair<int, int>> v2;
      for (int j = 0; j < k; j++) {
        int v, c;
        cin >> v >> c;
        v2.push_back({ v,c });
      }
      if (t == 1) {
          cout << func1(v, v2, m) << endl;
      }
      else {
          cout << func2(v, v2, m) << endl;
      }
      
      
    }

    return 0;
}