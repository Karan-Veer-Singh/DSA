#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

bool possible(int a[], int books, int no_of_students, int mid)
{
    int student = 1;
    int pages = 0;

   for(int i = 0; i < books; i++)
   {
       if(pages + a[i] > mid)
       {
           student++;
           pages = a[i];

           if(student > no_of_students)
                return false;
       }
       else
       {
           pages += a[i];
       }
   }

   return true;
}


void search(int a[], int books, int no_of_students)
{
    int sum = 0;
    for(int x = 0; x < books; x++)
        sum += a[x];
   
    int start = a[books-1];
    int end = sum;
    int ans = INT_MAX;

    while(start <= end)
    {
        int mid = (start + end) / 2;

        if(possible(a, books, no_of_students, mid))
        {
            ans = min(ans,mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;           // to store number of test cases...

    for(int i = 1; i <= t; i++)
    {
        int books;
        cin >> books;             // to store number of books..

        int n;
        cin >> n;              // to store number of students..

        int a[books];           // to store number of pages in the books..

    // taking input..
        for(int i = 0; i < books; i++)
            cin >> a[i];

        search(a, books, n);
    }

    return 0;
}
