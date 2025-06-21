#include <bits/stdc++.h>
using namespace std;

void rotateby1(int *arr, int n)
{
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

// brute solution:
// void rotatebyD{   arr: 1 2 3 4 5 6 7
//    d=d%n;   d=3
//    int temp[d];
//    for(i=0 -> d)  temp[i]=arr[i];          temp=1 2 3
//    for(i=d -> <n) arr[i-d]=arr[i];         arr= 4 5 6 7 _ _ _
//    for(i=n-d -> <n) arr[i]=temp[i-(n-d)];     arr= 4 5 6 7 1 2 3
// }
void rotatebyD(int *arr, int n, int d){
    d = d % n;
    reverse(arr, arr + d);     // 3 2 1 4 5 6 7
    reverse(arr + d, arr + n); // 3 2 1 7 6 5 4

    reverse(arr, arr + n); // 4 5 6 7 1 2 3
}

int main(){
    int n = 5;
    int arr[] = {1, 3, 5, 7, 9};

    rotateby1(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    int d = 3;
    rotatebyD(arr, n, d);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}