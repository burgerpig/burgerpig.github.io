#include<iostream>
#include<queue>

using namespace std;

void heapsort(vector<double> &arr) 
{
    int n = arr.size();

    for (int p = n / 2 - 1; p >= 0; p--) {
        int l = 2 * p + 1;
        int r = 2 * p + 2;
        int s = (r >= n) ? l :
                (arrq
        if (l < n) s = arr[l] <;
        if (r < n && arr[p] < arr[r]) s = r;
    }
}

int main(int argc, char *argv[])
{
    int n = 0;
    cin >> n;

    vector<double> arr(n, 0);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    heapsort(arr);

    for (const auto &x: arr)
        cout << x << " ";
    cout << endl;


    return 0;
}
