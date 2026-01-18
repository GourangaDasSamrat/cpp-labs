#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Product {
  int productId;
  string name;
  string category;
};

struct Order {
  int orderId;
  int productId;
  int quantity;
  string customerId;
  time_t orderDate;
};

int main() {
  vector<Product> products = {
    {101, "MacBook M4 Max", "Laptop"},
    {102, "iPhone 17 Pro max", "Smart Phone"},
    {103, "Apple watch ultra", "Smart watch"},
    {104, "iPad Pro M4", "Tablet"},
    {105, "MacBook Air M3", "Laptop"},
    {106, "Mac Mini M3", "Desktop"},
    {107, "iMac M3", "Desktop"},
    {108, "AirPods Pro 3rd Gen", "Wireless Earbuds"},
    {109, "AirPods Max 2", "Headphones"},
    {110, "Apple TV 4K", "Streaming Device"},
    {111, "Apple Pencil Pro", "Accessory"},
    {112, "Magic Keyboard", "Accessory"},
    {113, "Magic Mouse", "Accessory"},
    {114, "iPhone 17", "Smart Phone"},
    {115, "Apple Watch Series 10", "Smart Watch"},
  };

  deque<string> recentCustomers = {"C001", "C002", "C003"};
  recentCustomers.push_back("C004");
  recentCustomers.push_back("C005");

  list<Order> orderHistory;
  orderHistory.push_back({1, 101, 5, "C001", time(0)});
  orderHistory.push_back({2, 105, 1, "C002", time(0)});
  orderHistory.push_back({3, 110, 10, "C003", time(0)});

  set<string> categories;
  for (const auto& product : products)
    categories.insert(product.category);

  map<int, int> productStock = {
    {101, 10},
    {102, 8},
    {103, 38},
    {104, 4},
    {105, 20},
    {106, 12},
    {107, 6},
    {108, 25},
    {109, 9},
    {110, 14},
    {111, 30},
    {112, 7},
    {113, 18},
    {114, 22},
    {115, 5},
  };

  multimap<string, Order> customerOrders;
  for (const auto& order : orderHistory)
    customerOrders.insert({order.customerId, order});

  unordered_map<string, string> customerData = {
    {"C001", "Michel Marsh"},
    {"C002", "David Warner"},
    {"C003", "Bobby Fisher"},
    {"C004", "Josh Butler"},
    {"C005", "Pat Cummins"},
  };

  unordered_set<int> uniqueProductIDs;
  for (const auto& product : products)
    uniqueProductIDs.insert(product.productId);

  // ================= PRINT SECTION =================

  cout << "\n--- Products ---\n";
  for (const auto& p : products) {
    cout << p.productId << " | " << p.name << " | " << p.category << endl;
  }

  cout << "\n--- Recent Customers ---\n";
  for (const auto& c : recentCustomers) {
    cout << c << endl;
  }

  cout << "\n--- Order History ---\n";
  for (const auto& o : orderHistory) {
    cout << "OrderID: " << o.orderId << ", ProductID: " << o.productId
         << ", Qty: " << o.quantity << ", Customer: " << o.customerId
         << ", Date: " << ctime(&o.orderDate);
  }

  cout << "\n--- Categories ---\n";
  for (const auto& cat : categories) {
    cout << cat << endl;
  }

  cout << "\n--- Product Stock ---\n";
  for (const auto& ps : productStock) {
    cout << "ProductID: " << ps.first << ", Stock: " << ps.second << endl;
  }

  cout << "\n--- Customer Orders ---\n";
  for (const auto& co : customerOrders) {
    cout << "Customer: " << co.first << ", OrderID: " << co.second.orderId
         << ", ProductID: " << co.second.productId
         << ", Qty: " << co.second.quantity << endl;
  }

  cout << "\n--- Customer Data ---\n";
  for (const auto& cd : customerData) {
    cout << cd.first << " -> " << cd.second << endl;
  }

  cout << "\n--- Unique Product IDs ---\n";
  for (const auto& id : uniqueProductIDs) {
    cout << id << endl;
  }

  return 0;
}
