#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// ---------------- STRUCTS ----------------

struct Product {
  int id;
  string name;
  string category;
};

struct Order {
  int orderId;
  int productId;
  int quantity;
  string customerId;
  time_t date;
};

// ---------------- GLOBAL DATA ----------------

vector<Product> products;
map<int, int> stock;
multimap<string, Order> orders;
unordered_map<string, string> customers;

int orderCounter = 1;
const string ADMIN_PASSWORD = "admin2026";

// ---------------- SEED DATA ----------------

void seedData() {
  products.push_back({101, "MacBook M4 Max", "Laptop"});
  products.push_back({102, "iPhone 17 Pro Max", "Smart Phone"});
  products.push_back({103, "Apple Watch Ultra", "Smart Watch"});
  products.push_back({104, "iPad Pro M4", "Tablet"});
  products.push_back({105, "Mac Mini M3", "Desktop"});

  stock[101] = 10;
  stock[102] = 8;
  stock[103] = 5;
  stock[104] = 6;
  stock[105] = 4;

  customers["C001"] = "Alex";
  customers["C002"] = "John";
}

// ---------------- FUNCTIONS ----------------

void showProducts() {
  cout << "\n--- PRODUCTS ---\n";
  for (auto& p : products) {
    cout << p.id << " | " << p.name << " | " << p.category
         << " | Stock: " << stock[p.id] << endl;
  }
}

void addProduct() {
  Product p;
  cout << "Product ID: ";
  cin >> p.id;
  cin.ignore();

  cout << "Product Name: ";
  getline(cin, p.name);

  cout << "Category: ";
  getline(cin, p.category);

  int qty;
  cout << "Initial Stock: ";
  cin >> qty;

  products.push_back(p);
  stock[p.id] = qty;

  cout << "Product added successfully!\n";
}

void updateStock() {
  int id, qty;
  cout << "Product ID: ";
  cin >> id;
  cout << "New Stock: ";
  cin >> qty;

  stock[id] = qty;
  cout << "Stock updated!\n";
}

void viewAllOrders() {
  cout << "\n--- ALL ORDERS ---\n";
  for (auto& o : orders) {
    cout << "Customer: " << o.first << " | OrderID: " << o.second.orderId
         << " | ProductID: " << o.second.productId
         << " | Qty: " << o.second.quantity
         << " | Date: " << ctime(&o.second.date);
  }
}

void placeOrder(string cid) {
  int pid, qty;
  showProducts();

  cout << "Enter Product ID: ";
  cin >> pid;
  cout << "Quantity: ";
  cin >> qty;

  if (stock[pid] < qty) {
    cout << "Not enough stock!\n";
    return;
  }

  stock[pid] -= qty;

  Order o;
  o.orderId = orderCounter++;
  o.productId = pid;
  o.quantity = qty;
  o.customerId = cid;
  o.date = time(0);

  orders.insert({cid, o});
  cout << "Order placed successfully!\n";
}

void viewMyOrders(string cid) {
  cout << "\n--- YOUR ORDERS ---\n";
  auto range = orders.equal_range(cid);

  if (range.first == range.second) {
    cout << "No orders found.\n";
    return;
  }

  for (auto it = range.first; it != range.second; it++) {
    cout << "OrderID: " << it->second.orderId
         << " | ProductID: " << it->second.productId
         << " | Qty: " << it->second.quantity
         << " | Date: " << ctime(&it->second.date);
  }
}

// ---------------- MAIN ----------------

int main() {
  seedData();  // load default data

  int choice;
  while (true) {
    cout << "\n1. Admin Login\n2. Customer Login\n0. Exit\nChoice: ";
    cin >> choice;

    if (choice == 0)
      break;

    // ---------- ADMIN ----------
    if (choice == 1) {
      string pass;
      cout << "Enter Admin Password: ";
      cin >> pass;

      if (pass != ADMIN_PASSWORD) {
        cout << "❌ Wrong password! Access denied.\n";
        continue;
      }

      int adminChoice;
      while (true) {
        cout << "\n--- ADMIN PANEL ---\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Update Stock\n";
        cout << "4. View All Orders\n";
        cout << "0. Logout\nChoice: ";
        cin >> adminChoice;

        if (adminChoice == 0)
          break;
        else if (adminChoice == 1)
          addProduct();
        else if (adminChoice == 2)
          showProducts();
        else if (adminChoice == 3)
          updateStock();
        else if (adminChoice == 4)
          viewAllOrders();
      }
    }

    // ---------- CUSTOMER ----------
    else if (choice == 2) {
      string cid;
      cout << "Enter Customer ID: ";
      cin >> cid;

      if (customers.find(cid) == customers.end()) {
        cout << "New customer name: ";
        cin.ignore();
        getline(cin, customers[cid]);
      }

      int custChoice;
      while (true) {
        cout << "\n--- CUSTOMER MENU ---\n";
        cout << "1. View Products\n";
        cout << "2. Place Order\n";
        cout << "3. View My Orders\n";
        cout << "0. Logout\nChoice: ";
        cin >> custChoice;

        if (custChoice == 0)
          break;
        else if (custChoice == 1)
          showProducts();
        else if (custChoice == 2)
          placeOrder(cid);
        else if (custChoice == 3)
          viewMyOrders(cid);
      }
    }
  }

  cout << "System Closed.\n";
  return 0;
}
