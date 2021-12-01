#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

queue<int> gradingStudents(queue<int> grades) {
    int newel=0;
    for(int i=0; i<grades.size(); i++){
        if(grades.front()<38){newel=grades.front();}
        else if (5-(grades.front()%5)<3){
            newel=grades.front()+(5-(grades.front()%5));
        } else {newel=grades.front();}
        
        grades.push(newel);
        grades.pop();
    }
    cout<<endl;
    return grades;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    queue<int> grades;

    for (int i = 0; i < grades_count; i++) {
        string grades_item_temp;
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades.push(grades_item);
    }

    queue<int> result = gradingStudents(grades);

    int i=0;
    while (!result.empty()) {
        fout << result.front();

        if (i != grades.size() - 1) {
            fout << "\n";
        }
        result.pop();
        i++;
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
