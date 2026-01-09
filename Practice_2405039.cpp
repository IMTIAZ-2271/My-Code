#include <bits/stdc++.h>
using namespace std;

class Product
{
private:
    string productName;
    string productID;
    double price;
    int stockChanges[100];
    int numStockChanges;
    int curtotals;

public:
    Product()
    {
        productName = "";
        productID = "";
        price = 0.0;
        numStockChanges = 0;
        curtotals = 0;
        //cout << "Default constructor" << endl;
    }
    Product(const string productName, const string productID, const double price)
    {
        this->productName = productName;
        this->productID = productID;
        this->price = price;
        numStockChanges = 0;
        curtotals = 0;
    }
    void addStock(const int amount)
    {
        stockChanges[numStockChanges] = amount;
        curtotals += amount;
        numStockChanges++;
    }
    void reduceStock(const int amount)
    {
        stockChanges[numStockChanges] = amount;
        curtotals += amount;
        numStockChanges++;
    }
    const int getCurrentStock()
    {
        if (numStockChanges == 0)
        {
            return 0;
        }
        return curtotals;
    }
    const string getproductID()
    {
        return productID;
    }
    const string getproductname()
    {
        return productName;
    }
    const double getPrice()
    {
        return price;
    }
    const int getNumOfstockExchange()
    {
        return numStockChanges;
    }
    void display()
    {
        cout << "Product: " << productName << "(ID: " << productID << "), Price: Tk." << price << ", Stock: " << getCurrentStock() << endl;
    }
};

class Inventory
{
private:
    Product *products;
    int numProducts;
    int maxProducts;

public:
    Inventory()
    {
        //jcout << "Default constructor" << endl;
        numProducts = 0;
        maxProducts = 0;
        products = nullptr;
    }
    Inventory(int maxProducts)
    {
        numProducts = 0;
        this->maxProducts = maxProducts;
        products = new Product[maxProducts];
    }
    Inventory(Product *products, int numProducts, int maxProducts)
    {
        this->maxProducts = maxProducts;
        this->numProducts = numProducts;
        this->products = new Product[maxProducts];

        for (int i = 0; i < numProducts; i++)
        {
            this->products[i] = products[i];
        }
    }

    void addProduct( Product p)
    {
        if (numProducts >= maxProducts)
        {
            cout << "Inventory full. Cannot add any more product." << endl;
            return;
        }
        products[numProducts++] = p;
        cout << "Product added with ID: " << p.getproductID() << endl;
    }
    void updateProductStock(const string productID, const int amount)
    {
        for (int i = 0; i < numProducts; i++)
        {
            if (products[i].getproductID() == productID)
            {
                if (amount > 0)
                {
                    products[i].addStock(amount);
                }
                else
                {
                    products[i].reduceStock(amount);
                }
                return;
            }
        }
        return;
    }
    void listAllProducts()
    {
        if (numProducts == 0)
        {
            cout << "There is no product in the inventory" << endl;
            return;
        }
        for (int i = 0; i < numProducts; i++)
        {
            cout << "Product:" << products[i].getproductname() << " (ID: " << products[i].getproductID() << ")" << "," << " " << "Price: Tk." << products[i].getPrice() << ", Stock: " << products[i].getCurrentStock() << endl;
        }
    }
    Product getMostStockedProduct()
    {
        if(numProducts == 0)
        {
            cout << "There is no product in the inventory" << endl;
            return Product();
        }

        int MaxIdx = 0;
        for (int i = 1; i < numProducts; i++)
        {
            if (products[i].getCurrentStock() > products[MaxIdx].getCurrentStock())
            {
                MaxIdx = i;
            }
            else if (products[i].getCurrentStock() == products[MaxIdx].getCurrentStock())
            {
                if (products[i].getNumOfstockExchange() < products[MaxIdx].getNumOfstockExchange())
                {
                    MaxIdx = i;
                }
            }
        }
        return products[MaxIdx];
    }
    Inventory(Inventory &inv)
    {
        this->numProducts = inv.numProducts;
        this->maxProducts = inv.maxProducts;
        this->products = new Product[maxProducts];
        for (int i = 0; i < numProducts; i++)
        {
            this->products[i] = inv.products[i];
        }
    }
    ~Inventory()
    {
        delete[] products;
    }
};

int main()
{
    Inventory inv1(5);
    Product p1("Laptop", "P001", 50000);
    Product p2("Smartphone", "P002", 30000);
    Product p3("Tablet", "P003", 25000);
    Product p4("Smartwatch", "P004", 4000);
    Product p5("Headphones", "P005", 2000);
    Product p6("Charger", "P006", 1000);
    inv1.addProduct(p1);
    inv1.addProduct(p2);
    inv1.addProduct(p3);
    inv1.addProduct(p4);
    inv1.addProduct(p5);
    inv1.addProduct(p6);
    //cout << "Done" << endl;
    inv1.updateProductStock("P001", 50);
    inv1.updateProductStock("P001", -10);
    inv1.updateProductStock("P003", 70);
    inv1.updateProductStock("P002", 70);
    inv1.updateProductStock("P002", -5);
    inv1.updateProductStock("P003", -10);
    cout << "\nProducts in Inventory 1:\n";
    inv1.listAllProducts();
    cout << "\nMost Stocked Product in Inventory 1:\n";
    inv1.getMostStockedProduct().display();
    Inventory inv2 = inv1;
    inv2.updateProductStock("P003", 10);
    inv2.updateProductStock("P002", 10);
    inv2.updateProductStock("P002", -5);
    cout << "\nProducts in Inventory 2:\n";
    inv2.listAllProducts();
    cout << "\nMost Stocked Product in Inventory 1:\n";
    inv1.getMostStockedProduct().display();
    cout << "\nMost Stocked Product in Inventory 2:\n";
    inv2.getMostStockedProduct().display();
    return 0;
}