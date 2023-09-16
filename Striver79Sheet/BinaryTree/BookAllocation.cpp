//  https://takeuforward.org/data-structure/allocate-minimum-number-of-pages/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countStudents(vector<int>& arr, int pages) {

    int students = 1;
    int n = arr.size();
    long long pagesStudent = 0;

    for (int i=0;i<n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        } else {
            students++;
            pagesStudent = arr[i];
        }
    }

    return students;

}

int findPages(vector<int>& arr, int n, int m) {
    if (n<m) {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = 0;
    for (int i=0;i<arr.size(); i++) {
        high+= arr[i];
    }

    while (low<= high) {
        int mid = (low+high)>>1;

        int students = countStudents(arr, mid);

        if (students == m) {
            return mid;
        }

        if (students > m) {
            low = mid+1;
        } else {
            high = mid -1;
        }
    }

    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
