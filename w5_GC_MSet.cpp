#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */

string gridChallenge(vector<string> grid) {
    vector<multiset<int>> vset;

    // Change them into ascii code
    for(int row=0; row<grid.size(); row++){
        multiset<int> cont;
        for(int digit=0; digit<grid[0].length(); digit++){
            cont.insert((int)grid[row][digit]);
        }
        vset.push_back(cont);
    }
    
    // Print
    // for(int row=0; row<vset.size(); row++){
    //     auto iter=vset[row].begin();
    //     for(; iter!=vset[row].end(); iter++){
    //         cout<<*iter<<", ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    
    // Check for right to left, is it ascending?
    bool ascending=true;
    
    for(int row=1; row<vset.size(); row++){
        auto it=vset[row].begin();
        auto before=vset[row-1].begin();
        for(; it!=vset[row].end();){
            if((int)*it-(int)*before<0){
                ascending=false;
            }
            it++; before++;
        }
    }
    
    if(ascending==false){
        return "NO";
    } else {
        return "YES";
    }    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
