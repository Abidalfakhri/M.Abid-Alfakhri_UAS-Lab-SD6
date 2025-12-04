#include <iostream>
#include <vector>
using namespace std;


int intersearch(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }
        int pos = low + ((double)(x - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    vector<int> kursi(n);
    for (int i = 0; i < n; i++) {
        cin >> kursi[i];
    }
    int cari;
    cin >> cari;
    int index = intersearch
(kursi, cari);

    cout << "Mencari Kursi No: " << cari << endl;

    if (index != -1) {
        cout << "Status: TERSEDIA" << endl;
        cout << "Posisi Index: " << index << endl;
        cout << "Nomor Kursi: " << kursi[index] << endl;
    } else {
        cout << "Status: TIDAK TERSEDIA" << endl;
        int nearestLeft = -1, nearestRight = -1;
        for (int i = 0; i < n; i++) {
            if (kursi[i] < cari) nearestLeft = kursi[i];
            if (kursi[i] > cari) {
                nearestRight = kursi[i];
                break;
            }
        }

        cout << "Opsi kursi terdekat: ";
        if (nearestLeft != -1) cout << nearestLeft << " ";
        if (nearestRight != -1) cout << nearestRight << " ";
        cout << endl;
    }

    return 0;
}