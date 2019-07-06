#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std ;
typedef long long ll ;
int main() {
   string s ;
   cin >> s ;
   int n = s.size() ;
   ll val = 0 ;
   for (int i=0; i<n; i++)
      if (s[i] == '0')
         val += 1LL << i ;
   if (val == 0) {
      cout << 0 << endl ;
      exit(0) ;
   }
   vector<char> seen(1LL<<n) ;
   seen[val] = 1 ;
   vector<ll> q ;
   q.push_back(val) ;
   ll mask = (1LL << n) - 1 ;
   for (int d=1; ; d++) {
      int hi = q.size() ;
      for (int qg=0; qg<hi; qg++) {
         val = q[qg] ;
         ll mod = (1LL << d) - 1 ;
         for (int s=0; s<=n; s++) {
            ll val2 = mask & (val ^ (mod << s)) ;
            if (seen[val2] == 0) {
               seen[val2] = 1 ;
               if (val2 == 0) {
                  cout << d << endl ;
                  exit(0) ;
               }
               q.push_back(val2) ;
            }
         }
      }
   }
   cout << "No solution" << endl ;
}
