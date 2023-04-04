#include <iostream>
using namespace std;

int calculateHIndex(int *citation, int n);
////////////////////////////////////////////////
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int pivot = a[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (a[j] < pivot)
            {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i + 1], a[high]);

        int pi = i + 1;

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int calculateHIndex(int *a, int n)
{
    quickSort(a, 0, n - 1);

    int hIndex = n;
    while (hIndex > 0 && a[n - hIndex] < hIndex)
        hIndex--;

    return hIndex;
}
////////////////////////////////////////////////
int main()
{
	int* citation;
	int n;
	int i;
	cin >> n;
	//cout << n << endl;
	citation = new int[n];

	for (i = 0; i < n; i++)
		cin >> citation[i];

	cout << calculateHIndex(citation, n);
	return 0;


}
