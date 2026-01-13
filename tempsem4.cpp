#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
using namespace::chrono;
void complexRec(int n, int& count,int&count1,int&count2,int&count3) {


   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           count1++;
       }
       p >>= 1;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       count2++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());count3++;
   } else {
       reverse(small.begin(), small.end());count3++;
   }
   count++;


   complexRec(n / 2,count,count1,count2,count3);
   complexRec(n / 2,count,count1,count2,count3);
   complexRec(n / 2,count,count1,count2,count3);
}
int main()
{
    int*count;
    int k=0;
    int l=0;
    int m=0;
    int n=0;
    count=&k;
    int*count1;
    count1=&l;
    int*count2;
    count2=&m;
    int*count3;
    count3=&n;

    auto start=high_resolution_clock::now();
    int a;
    cout<<" eneter any number ";
    cin>>a;
    complexRec(a,*count,*count1,*count2,*count3);
    auto end=high_resolution_clock::now();
    auto duration =duration_cast <milliseconds>(end-start);
    cout<<duration.count();
    cout<<"\n";
    cout<<"\ntotal recursion rounds\n";
    cout<<k;
    cout<<"\noprations in while & for\n";
    cout<<l;
    cout<<"\nooprations  in vectors\n";
    cout<<m;
    cout<<"\ntotal operation in if\n";
    cout<<n;
    cout<<"\n total operations= ";
    cout<<l+m+n;



}
