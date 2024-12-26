#include <iostream>
using namespace std;
void displaySeats(char seats[][15]);
void initializeSeatsArray(char seats[][15]);
void getPriceForEachRow(int priceOfEachRow[]);
void bookSeatNumber(char seats[][15], int priceofEachRow[], int * totalSeats, int * sale);
int calculatePrice(int priceofEachRow[], int row);
void seeDetails(int totalSeats, int sale);

int main()
{
    int totalSeats = 225;
    int sale = 0;
    int * totalSeatsPointer = &totalSeats;
    int * salePointer = &sale;
    char seats[15][15];
    int priceOfEachRow[15] ;
    int flag = 1;
 //= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}
    getPriceForEachRow(priceOfEachRow);

    initializeSeatsArray(seats);

    displaySeats(seats);

    while (flag)
    {
        cout << " For Booking Seats Enter(1) \n For Displaying Seats Enter(2) \n To See Detail of the Sales Enter(3) \n For Exiting Program Enter(0)" << "\n";
        cin >> flag;
        if (flag == 1)
        {
            bookSeatNumber(seats, priceOfEachRow, totalSeatsPointer,salePointer);
        }
        else if (flag == 2)
        {
            displaySeats(seats);
        }
        else if (flag == 3)
        {
            seeDetails(totalSeats, sale);
        }
        else if (flag == 0)
        {
            flag = 0;
        }
        else
        {
            cout << "Invalid Input";
        }
    }

    return 0;
}

// Funtion Bodies
void getPriceForEachRow(int priceOfEachRow[])
{
    for (int i = 0; i < 15; i = i + 1)
    {
        cout << "Enter The Price for Row " << i << "\n";
        cin >> priceOfEachRow[i];
    }
}
void initializeSeatsArray(char seats[][15])
{
    // Filling Arrays
    for (int i = 0; i < 15; i = i + 1)
    {
        for (int j = 0; j < 15; j = j + 1)
        {
            seats[i][j] = 'N';
        }
    }
}
void displaySeats(char seats[][15])
{
    // displaying arrays
    cout << 0 << "\t" << 1 << "\t" << 2 << "\t" << 3 << "\t" << 4 << "\t" << 5 << "\t" << 6 << "\t" << 7 << "\t" << 8 << "\t" << 9 << "\t" << 10 << "\t" << 11 << "\t" << 12 << "\t" << 13 << "\t" << 14 << "\t" << "\n";
    for (int i = 0; i < 15; i = i + 1)
    {
        for (int j = 0; j < 15; j = j + 1)
        {
            cout << seats[i][j] << "\t";
        }
        cout << "Row " << i << "  " << "\n";
    }
    cout << "\n";
}
void bookSeatNumber(char seats[][15], int priceOfEachRow[], int * totalSeats, int * sale)
{
    int row, column;
    int flag = 1;
    int totalBill = 0;
    while (flag)
    {
        cout << "Enter The Column no. ";
        cin >> column;
        cout << "\n";
        cout << "Enter The Row no. ";
        cin >> row;
        if ((row > 15 && row < 0) || (column > 15 && column < 0))
        {
            cout << "Invalid Row OR Column" << "\n";
        }
        else
        {
            char seatMark = seats[row][column]; // 
            cout<<seatMark;
            if (seatMark == 'B')
            {
                cout << "Seat Aleady Booked"<<"\n";
            }
            else
            {
                totalBill = totalBill + calculatePrice(priceOfEachRow, row);
                seats[row][column] = 'B';
                *totalSeats = *totalSeats - 1;
                *sale = *sale + totalBill;
            }
        }

        cout << "Do you want to book another Seat? Yes(1) | No(0) ";
        cin >> flag;
    }
    cout << "Your Total bill is = " << totalBill<<"\n";
}
int calculatePrice(int priceofEachRow[], int row)
{
    return priceofEachRow[row];
}
void seeDetails(int totalSeats, int sale)
{
    cout<< "Total Sale = "<< sale << "\n";
    cout<< "Seats left = " << totalSeats <<"\n";
}
