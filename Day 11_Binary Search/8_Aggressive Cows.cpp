#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;


bool possible(ll stalls[], ll no_of_stalls, ll mid, ll cows )
{
    ll last_cow = stalls[0];
    ll count = 1;

    for(ll i = 1; i < no_of_stalls; i++)
    {
        if( (stalls[i] - last_cow) >= mid )
        {
            last_cow = stalls[i];
            count++ ;

            if(count == cows)
                return true;
        }
    }
    return false;
}



void calculate(ll stalls[], ll no_of_stalls, ll cows)
{
    ll s = 0;                                         // minimum possible distance is 0..
    ll e = stalls[no_of_stalls-1] - stalls[0];        // maximum possibel distane is the distance between the last and first position..
    ll ans = 0;

    while(s <= e)
    {
        ll mid = (s + e) / 2;
        bool check = possible(stalls, no_of_stalls, mid, cows);
        
        if( check )
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    cout << ans;
}

int main()
{
    ll no_of_stalls;
    cin >> no_of_stalls;                // number of stalls...

    ll cows;
    cin >> cows;                // number of cows....

    ll stalls[no_of_stalls];      // to store indexes of the stalls...
    
    //taking input..
    for(ll i = 0; i < no_of_stalls; i++)
        cin >> stalls[i];

        sort(stalls, stalls+no_of_stalls);

    calculate(stalls, no_of_stalls, cows);
    
}
