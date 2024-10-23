#include <bits/stdc++.h>
using namespace std;

#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define forn(i, n) forsn(i, 0, n)
#define dforn(i, n) dforsn(i, 0, n)
#define fore(i, s, n) forsn(i, s, n)

#define pb push_back
#define mp make_pair
#define snd second
#define fst first

struct Customer
{
    int arr;
    int leave;
    int i;
};

int RoomAlloc()
{
    int n;
    cin >> n;
    vector<Customer> customers(n);
    forn(i, n)
    {
        cin >> customers[i].arr >> customers[i].leave;
        customers[i].i = i;
    }

    sort(customers.begin(), customers.end(), [](Customer a, Customer b)
         { return a.arr < b.arr; });

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rooms_q;
    vector<int> rooms_cust(n);
    int rooms_count = 0;

    forn(i, n)
    {
        int arrive = customers[i].arr;
        int leave = customers[i].leave;
        int cust_num = customers[i].i;

        // If the next room available is free for the next customer
        if (!rooms_q.empty() && rooms_q.top().first < arrive)
        {
            rooms_cust[cust_num] = rooms_q.top().second;
            rooms_q.pop();
        }
        else
        {
            rooms_count++;
            rooms_cust[cust_num] = rooms_count;
        }

        rooms_q.push({leave, rooms_cust[cust_num]});
    }

    cout << rooms_count << "\n";

    for (auto room : rooms_cust)
    {
        cout << room << " ";
    }

    return 0;
}

int main()
{
    RoomAlloc();
    return 0;
}

// There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.
// You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.
// What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?
// Input
// The first input line contains an integer n: the number of customers.
// Then there are n lines, each of which describes one customer. Each line has two integers a and b: the arrival and departure day.
// Output
// Print first an integer k: the minimum number of rooms required.
// After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered 1,2,\ldots,k. You can print any valid solution.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le a \le b \le 10^9

// Example
// Input:
// 3
// 1 2
// 2 4
// 4 4

// Output:
// 2
// 1 2 1
