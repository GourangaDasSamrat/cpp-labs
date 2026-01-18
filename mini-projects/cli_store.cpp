#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// ---------------- COLORS ----------------
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

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

// ---------------- UI HELPERS ----------------
void line() {
  cout << CYAN << string(90, '=') << RESET << endl;
}

void title() {
  line();
  cout << BOLD << BLUE;
  cout
    << " █████╗ ██████╗ ██████╗ ██╗     ███████╗    ███████╗████████╗ ██████╗ ██████╗ ███████╗\n"
       "██╔══██╗██╔══██╗██╔══██╗██║     ██╔════╝    ██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗██╔════╝\n"
       "███████║██████╔╝██████╔╝██║     █████╗      ███████╗   ██║   ██║   ██║██████╔╝█████╗  \n"
       "██╔══██║██╔═══╝ ██╔═══╝ ██║     ██╔══╝      ╚════██║   ██║   ██║   ██║██╔══██╗██╔══╝  \n"
       "██║  ██║██║     ██║     ███████╗███████╗    ███████║   ██║   ╚██████╔╝██║  ██║███████╗\n"
       "╚═╝  ╚═╝╚═╝     ╚═╝     ╚══════╝╚══════╝    ╚══════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝\n";
  cout << RESET;
  line();
}

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
  line();
  cout << BOLD << YELLOW << "📦 PRODUCT LIST\n" << RESET;
  line();

  for (auto& p : products) {
    cout << GREEN << p.id << RESET << " | " << p.name << " | " << p.category
         << " | Stock: " << CYAN << stock[p.id] << RESET << endl;
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

  cout << GREEN << "✔ Product added successfully!\n" << RESET;
}

void updateStock() {
  int id, qty;
  cout << "Product ID: ";
  cin >> id;
  cout << "New Stock: ";
  cin >> qty;

  stock[id] = qty;
  cout << GREEN << "✔ Stock updated!\n" << RESET;
}

void viewAllOrders() {
  line();
  cout << BOLD << YELLOW << "📑 ALL ORDERS\n" << RESET;
  line();

  for (auto& o : orders) {
    cout << "Customer: " << CYAN << o.first << RESET
         << " | OrderID: " << o.second.orderId
         << " | ProductID: " << o.second.productId
         << " | Qty: " << o.second.quantity
         << " | Date: " << ctime(&o.second.date);
  }
}

void placeOrder(string cid) {
  int pid, qty;
  showProducts();

  cout << "Product ID: ";
  cin >> pid;
  cout << "Quantity: ";
  cin >> qty;

  if (stock[pid] < qty) {
    cout << RED << "❌ Not enough stock!\n" << RESET;
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
  cout << GREEN << "✔ Order placed successfully!\n" << RESET;
}

void viewMyOrders(string cid) {
  line();
  cout << BOLD << YELLOW << "🧾 YOUR ORDERS\n" << RESET;
  line();

  auto range = orders.equal_range(cid);
  if (range.first == range.second) {
    cout << RED << "No orders found.\n" << RESET;
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
  seedData();
  title();

  int choice;
  while (true) {
    cout << BOLD
         << "\n👑 1. Admin Login\n👤 2. Customer Login\n❌ 0. Exit\nChoice: "
         << RESET;
    cin >> choice;

    if (choice == 0)
      break;

    // ---------- ADMIN ----------
    if (choice == 1) {
      string pass;
      cout << "Enter Admin Password: ";
      cin >> pass;

      if (pass != ADMIN_PASSWORD) {
        cout << RED << "❌ Wrong password!\n" << RESET;
        continue;
      }

      int adminChoice;
      while (true) {
        cout << BOLD << CYAN << "\n--- ADMIN PANEL ---\n"
             << "1. Add Product\n"
             << "2. View Products\n"
             << "3. Update Stock\n"
             << "4. View All Orders\n"
             << "0. Logout\nChoice: " << RESET;
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
        cout << BOLD << CYAN << "\n--- CUSTOMER MENU ---\n"
             << "1. View Products\n"
             << "2. Place Order\n"
             << "3. View My Orders\n"
             << "0. Logout\nChoice: " << RESET;
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

  line();
  cout << GREEN << "✅ System Closed. Thank you!\n" << RESET;
  line();
  return 0;
}
