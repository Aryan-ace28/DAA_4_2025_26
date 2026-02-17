#include<iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 4, 4, 4, 6, 7, 8, 9, 10};
    int arr1[10]={4,6,8,1,1,3,7,9,10,3};
    for (int i = 0; i < 10 ; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }
    int a;
    cout<<"enter the elements you want to operate on ";
    cin >> a;
    for(int i=0;i<10;i++){
        int target= a-arr[i];
    int l = 0, h = 9, mid;
    int lb = 10;
    while (l <= h) {
        mid = l + (h - l) / 2;
        if (arr1[mid] >= target) {
            lb = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    l = 0, h = 9;
    int ub = 10;
    while (l <= h) {
        mid = l + (h - l) / 2;
        if (arr1[mid] > target) {
                ub = mid;
            }
            if (arr1[mid] > target) {
                h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    for(int j=lb;j<ub;j++){
                    cout << "(" << arr[i] << "," << arr1[j] << ")" << endl;
}}
        
    

    return 0;
}