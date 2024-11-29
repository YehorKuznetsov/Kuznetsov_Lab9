#include <iostream>
#include <vector>
using namespace std;

struct InventoryItem {
    int quantity{};
    double price{};
    vector<int> salesHistory;


    void addSale(int soldQuantity) {
        salesHistory.push_back(soldQuantity);
    }

    [[nodiscard]] double calculateProfit() const {
        double profit = 0.0;

        for(int soldQuantity : salesHistory) {
            profit += soldQuantity*price;
        }
        return profit;
    }
};

int main() {
    InventoryItem item;

    cout<<"Enter quantity: ";
    cin>>item.quantity;

    cout<<"Enter price: ";
    cin>>item.price;

    int numSales;
    cout<<"Enter number of sales for last month: ";
    cin>>numSales;

    for(int i = 0; i < numSales; i++) {
        int soldQuantity;
        cout<<"Sold quantity in sale #"<<i+1<<": ";
        cin>>soldQuantity;
        item.addSale(soldQuantity);
    }

    double profit = item.calculateProfit();
    cout<<"Total profit for last month is: "<<profit<<endl;
}
