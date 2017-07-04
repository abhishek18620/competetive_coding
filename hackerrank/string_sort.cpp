/* C program for Merge Sort */
#include <bits/stdc++.h>
#define pb push_back
#define f(i, j, k) for (int i = j; i < k; i++)
using namespace std;
vector<string> v, L, R;
// Merges two subvays of v[].
// First subvay is v[l..m]
// Second subvay is v[m+1..r]
void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    for (i = 0; i < n1; i++)
        L.pb(v[l + i]);
    for (j = 0; j < n2; j++)
        R.pb(v[m + 1 + j]);

    i = 0; // Initial index of first subvay
    j = 0; // Initial index of second subvay
    k = l; // Initial index of merged subvay
    while (i < n1 && j < n2)
    {
        if (L[i].length() < R[j].length())
        {
            v[k] = L[i];
            i++;
        }
        else if (L[i].length() > R[j].length())
        {
            v[k] = R[j];
            j++;
        }
        //both has same length
        else if (L[i] < R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
	are any */
    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
	are any */
    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-vay of v to be sorted */
void mergeSort(int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(l, m);
        mergeSort(m + 1, r);
        L.clear();
        R.clear();
        merge(l, m, r);
    }
}

/* Driver program to test above functions */
int main()
{
    int n;
    cin >> n;
    string s;
    f(i, 0, n)
    {
        cin >> s;
        v.pb(s);
    }
    mergeSort(0, n - 1);
    f(i, 0, n)
        cout<< v[i] << endl;
    int t;
    cin>>t;
    return 0;
}
