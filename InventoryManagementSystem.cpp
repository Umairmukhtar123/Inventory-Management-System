#include <iostream>
using namespace std;

class Product {

private:
    int id, quantity;
    float price;
    string name;

public:

    void inputProduct() {

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Price: ";
        cin >> price;
    }

    void displayProduct() {

        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nQuantity: " << quantity;
        cout << "\nPrice: " << price << endl;
    }

    // Getter Functions
    int getID() {
        return id;
    }

    string getName() {
        return name;
    }

    // Setter Function
    void updateData(int q, float p) {

        quantity = q;
        price = p;
    }
};

// ================= INVENTORY CLASS =================
class Inventory : public Product {

protected:
    Product products[100];
    int count = 0;

public:

    // Add Product
    void addProduct() {

        products[count].inputProduct();
        count++;

        cout << "\nProduct Added!\n";
    }

    // Display All Products
    void showAll() {

        for(int i = 0; i < count; i++) {

            products[i].displayProduct();
        }
    }

    // Function Overloading
    // Search By ID
    void searchProduct(int id) {

        for(int i = 0; i < count; i++) {

            if(products[i].getID() == id) {

                products[i].displayProduct();
                return;
            }
        }

        cout << "\nProduct Not Found!\n";
    }

    // Search By Name
    void searchProduct(string name) {

        for(int i = 0; i < count; i++) {

            if(products[i].getName() == name) {

                products[i].displayProduct();
                return;
            }
        }

        cout << "\nProduct Not Found!\n";
    }

    // Update Product
    void updateProduct(int id) {

        int q;
        float p;

        for(int i = 0; i < count; i++) {

            if(products[i].getID() == id) {

                cout << "Enter New Quantity: ";
                cin >> q;

                cout << "Enter New Price: ";
                cin >> p;

                products[i].updateData(q, p);

                cout << "\nUpdated Successfully!\n";
                return;
            }
        }

        cout << "\nProduct Not Found!\n";
    }

    // Delete Product
    void deleteProduct(int id) {

        for(int i = 0; i < count; i++) {

            if(products[i].getID() == id) {

                for(int j = i; j < count - 1; j++) {

                    products[j] = products[j + 1];
                }

                count--;

                cout << "\nDeleted Successfully!\n";
                return;
            }
        }

        cout << "\nProduct Not Found!\n";
    }
};

// ================= ADMIN CLASS =================
class Admin : public Inventory {

public:

    void manageSystem() {

        cout << "\nAdmin Managing Inventory System...\n";
    }

    void backupData() {

        cout << "\nBackup Created Successfully!\n";
    }
};

// ================= USER CLASS =================
class User : public Inventory, public Product {

public:

    void checkStock() {

        cout << "\nStock Checked\n";
    }
};

// ================= MAIN FUNCTION =================
int main() {

    Admin system;

    int choice, id;
    string name;

    do {

        cout << "\n===== INVENTORY SYSTEM =====\n";

        cout << "1. Add Product\n";
        cout << "2. Show Products\n";
        cout << "3. Search By ID\n";
        cout << "4. Search By Name\n";
        cout << "5. Update Product\n";
        cout << "6. Delete Product\n";
        cout << "7. Manage System\n";
        cout << "8. Backup Data\n";
        cout << "9. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:

            system.addProduct();
            break;

        case 2:

            system.showAll();
            break;

        case 3:

            cout << "Enter ID: ";
            cin >> id;

            system.searchProduct(id);
            break;

        case 4:

            cout << "Enter Name: ";
            cin >> name;

            system.searchProduct(name);
            break;

        case 5:

            cout << "Enter ID: ";
            cin >> id;

            system.updateProduct(id);
            break;

        case 6:

            cout << "Enter ID: ";
            cin >> id;

            system.deleteProduct(id);
            break;

        case 7:

            system.manageSystem();
            break;

        case 8:

            system.backupData();
            break;

        case 9:

            cout << "\nProgram Ended\n";
            break;

        default:

            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 9);

    return 0;
}