// YOU ARE GIVEN A GROCERY LIST WHICH CONSISTS OF THREE PARAMETER ITEM, QUANTITY, PRICE.
// YOUR TASK IS TO FIND : HIGHER SELLING ITEM, TOTAL SELLING ITEM, AVG SELLING ITEM. (2 DECIMAL POINTS)


#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for setting decimal precision

using namespace std;

// Function to calculate and print the required results
void analyzeGroceryList(const vector<vector<string>>& items) {
    string highestPriceItem;
    double maxPrice = 0.0;
    double totalRevenue = 0.0;

    for (const auto& item : items) {
        string name = item[0];
        int quantity = stoi(item[1]);     // Convert quantity from string to int
        double price = stod(item[2]);     // Convert price from string to double

        // Update highest price item
        if (price > maxPrice) {
            maxPrice = price;
            highestPriceItem = name;
        }

        // Calculate revenue and add to total revenue
        totalRevenue += quantity * price;
    }

    // Calculate the average revenue per item
    double avgRevenue = totalRevenue / items.size();

    // Display results with 2 decimal points precision
    cout << fixed << setprecision(2);
    cout << "Highest Price Item: " << highestPriceItem << " ($" << maxPrice << ")" << endl;
    cout << "Total Selling Items: $" << totalRevenue << endl;
    cout << "Average Selling Items: $" << avgRevenue << endl;
}

int main() {
    // Example grocery list in 2D array format (vector of vector of strings)
    vector<vector<string>> groceryList = {
        {"Apples", "10", "2.5"},
        {"Bananas", "20", "1.2"},
        {"Oranges", "15", "3.0"},
        {"Milk", "5", "4.5"}
    };

    // Analyze and print the results
    analyzeGroceryList(groceryList);

    return 0;
}
