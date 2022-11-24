#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<bool> getLargest(int a, int b, int c) {
    bool flag1 = false, flag2 = false, flag3 = false;
    if (a == b && b == c) {
        cout << "all are same" << endl;
        flag1 = true;
        flag2 = true;
        flag3 = true;
    } else if (a > b) {
        if (a == c) {
            cout << "a and c are largest" << endl;
            flag1 = true;
            flag3 = true;
        }
        else if (a > c) {
            cout << "a is largest" << endl;
            flag1 = true;
        } else {
            cout << "c is largest" << endl;
            flag3 = true;
        }
    } else {
        if (a == b) {
            cout << "a and b are largest" << endl;
            flag1 = true;
            flag2 = true;
        }
        if (b == c) {
            cout << "b and c are largest" << endl;
            flag2 = true;
            flag3 = true;
        }
        else if (b > c) {
            cout << "b is largest" << endl;
            flag2 = true;
        } else {
            cout << "c is largest" << endl;
            flag3 = true;
        }
    }
    
    return {flag1, flag2, flag3};
}


int main() {
    vector<vector<bool>> testCases;
    vector<int> runtime;
    unordered_map<string, int> mp;
    
    
    int n;
    cout << "Number of testCases: ";
    cin >> n;
    
    for (int i = 0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        clock_t start = clock();
        testCases.push_back(getLargest(a, b, c));
        runtime.push_back(clock()-start);
        cout << runtime.back() << endl;
    }

    
    
    cout << endl << "Requirements Traceability Matrix" << endl;
    // cout << "\n";
    cout << "  \t";
    for (int i = 0; i<testCases[0].size(); i++) {
        cout << "R" << i+1 << "\t";
    }
    
    for (int i = 0; i<testCases.size(); i++) {
        vector<bool> test = testCases[i];
        
        string expr = to_string(test[0]) + to_string(test[1]) + to_string(test[2]);
        
        if (mp.find(expr) != mp.end()) {
            if (runtime[mp[expr]] > runtime[i]) {
                mp[expr] = i;
            }
        } else {
            mp[expr] = i;
        }
    } 
    
    
    cout << endl;
    vector<int> final_list;
    for (auto& x: mp) {
        final_list.push_back(x.second);
    }
    
    sort(final_list.begin(), final_list.end());
    
    for (int idx: final_list) {
        cout << "T" << idx << "\t";
        for (bool t: testCases[idx]) {
            cout << t << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
