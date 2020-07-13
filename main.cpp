#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string conversion2(int a[], int k){
    string rozvoj = "";
    for(int i = k - 1; i >= 0; i--){
        char c = '0' + a[i];
        rozvoj = rozvoj + c;
    }
    return rozvoj;
}

void searchRepr2(int a[], int k){
    set<string> m_r;
    string rozvoj = conversion2(a, k);
    m_r.insert(rozvoj);
    auto i = m_r.rbegin();
    while ( i != m_r.rend()){
        string t = *i;
        for(int n = 0; n < k-2; n ++){
            if ( (t[n]=='2' || t[n]=='1') &&
                 (t[n+1]=='0') &&
                 (t[n+2]=='0' || t[n+2]=='1')){
                string b = t;
                b[n] = b[n]-1;
                b[n+1] = '2';
                b[n+2] = b[n+2]+1;
                if(m_r.find(b) == m_r.end()){
                    m_r.insert(b);
                }

             }
        }
        i++;
    }
   for (auto i=m_r.rbegin(); i!=m_r.rend(); ++i) {
        cout << (*i) << endl;
   }
   cout << "Total number of representations: " << m_r.size() << endl;
}

void conversion(int n, int k, int Gk, int Gk1) {
    if(n == 0 | n == 1 || n == 2){
        k = k-1;
    }
    int a[k-1];
    for(int i = 0; i < k-1; i++){
        a[i] = 0;
    }
    int previous = Gk;
    int size = k - 1;
    k = k - 2;
    int j = k;
    while(n > 0 && previous >= 0){
        if(previous <= n){
            a[j] += 1;
            n = n - previous;
            k = j;
        }
        if(n < previous){
            previous = Gk1 - 2*Gk;
            Gk1 = Gk;
            Gk = previous;
            j--;
        }
    }
    searchRepr2(a, size);
}

void raminacci(int n){
    int G0 = 1, G1 = 1, Gk = 0, k = 0;

    while(Gk <= n){
        Gk = G0 + 2*G1;
        cout << Gk << ", ";

        if (Gk <= n){
            G0 = G1;
            G1 = Gk;
            Gk = G0 + 2*G1;
        }
        k++;
    } cout << endl;
    cout << "\nInteger in Raminacci system: \n";

    conversion(n, k+2, G1, Gk);
}

int main()
{
    int G0 = 1, G1 = 1, n;
    cout << "Enter an integer: " << endl;
    cin >> n;

    cout << "Sequence: " << G0 << ", " << G1 << ", ";

    raminacci(n);

    return 0;
}
