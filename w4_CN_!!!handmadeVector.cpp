#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


// Header
template<typename U>
class vecSaya {
private:
    int panjang; //zero-indexed
    int maxpanjang;
    U* fpointer;
public:
    vecSaya();
    vecSaya(int n);
    void dorong(U);
    void cetak();
    int ukuran();
    U* awal();
    U* akhir();
    U& operator[](int index);
};

// Implementation
template<typename U>
vecSaya<U>::vecSaya() {
    fpointer = new U[5];
    maxpanjang = 5;
    panjang = 0;
}

template<typename U>
vecSaya<U>::vecSaya(int n) {
    fpointer = new U[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        fpointer[i] = 0;
    }
    maxpanjang = 2*n;
    panjang = n;
}

template<typename U>
void vecSaya<U>::dorong(U el) {
    if (panjang >= maxpanjang) {
        cout << "Relocate invoked" << endl;
        // Array is full, relocate
        U* newpointer = new U[2 * maxpanjang];
        // Copy all the inside to a new container
        for (int i=0; i < panjang; i++) {
            newpointer[i] = fpointer[i];
        }
        maxpanjang *= 2;
        fpointer = newpointer;
    }
    *(fpointer+panjang) = el;
    panjang++;
}

template<typename U>
void vecSaya<U>::cetak() {
    cout << "vecSaya, ukuran: " << panjang << ". Max panjang: " << maxpanjang << endl;
    for (int i = 0; i < panjang; i++) {
        cout << fpointer[i] << "  ";
    }
    cout << endl;
}

template<typename U>
int vecSaya<U>::ukuran() {
    return panjang;
}

template<typename U>
U* vecSaya<U>::awal() {
    return fpointer;
}

template<typename U>
U* vecSaya<U>::akhir() {
    return fpointer+panjang;
}

template<typename U>
U& vecSaya<U>::operator[] (int index){
    return fpointer[index];
}


/*
 * Complete the 'closestNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vecSaya<int> closestNumbers(vecSaya<int> arr) {
    sort(arr.awal(),arr.akhir());
    int min=arr[arr.ukuran()-1];
    arr.cetak();
    for(int i=1; i<arr.ukuran(); i++){
        if(abs(arr[i]-arr[i-1])<min){
            min=abs(arr[i]-arr[i-1]);
        }
    }
    vecSaya<int> result;
    for(int i=1; i<arr.ukuran(); i++){
        if(abs(arr[i]-arr[i-1])==min){
            result.dorong(arr[i-1]);
            result.dorong(arr[i]);
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vecSaya<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vecSaya<int> result = closestNumbers(arr);

    for (size_t i = 0; i < result.ukuran(); i++) {
        fout << result[i];

        if (i != result.ukuran() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
