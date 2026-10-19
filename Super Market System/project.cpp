#include <iostream>
#include<string>
#include<fstream>
using namespace std;
class Cnodeproduct
{
public:
    string Product_Name = "";
    int Product_Id = 0;
    int Product_Expired_Date = 0;
    int Product_Stock = 0;
    int Product_Price = 0;

    Cnodeproduct* pnext = NULL;


};
class CnodeCustomer
{
public:
    string Customer_Name = "";
    int Customer_Id = 0;
    int Customer_Phone_Number = 0;

    CnodeCustomer* pnext = NULL;


};

class CnodeOrder
{
public:

    int Product_Id = 0;
    int Order_Id = 0;
    int Customer_Id = 0;
    int Purchase_Day = 0;
    int Purchase_Month = 0;
    int Purchase_Year = 0;

    CnodeOrder* pnext = NULL;


};

class CListproduct {
public:
    Cnodeproduct* head = NULL;
    Cnodeproduct* tail = NULL;


    void attach(Cnodeproduct* new_node) {
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->pnext = new_node;
            tail = new_node;
        }
    }
    void displayListproduct() {
        Cnodeproduct* current = head;
        while (current) {
            cout << "product" << endl << "Product Name: " << current->Product_Name << ", product ID: " << current->Product_Id << ", Expired_Date: " << current->Product_Expired_Date << ", product Stock: " << current->Product_Stock << ", ProductvPrice: " << current->Product_Price << endl;
            current = current->pnext;
        }
    }
    void Delete(int x) {
        Cnodeproduct* pt = head;
        Cnodeproduct* pb = NULL;
        while (pt->Product_Id != x) {
            pb = pt;
            pt = pt->pnext;
        }
        if (pb != NULL) {
            pb->pnext = pt->pnext;
            pt->pnext = NULL;
            if (pt == tail) {
                pb == tail;
            }
        }
        else {
            head == pt->pnext;
            pt->pnext = NULL;
        }

        delete pt;

    }
    void writeToFileproduct(string filename) {
        Cnodeproduct* current = head;
        ofstream outputfile("Product.txt");
        if (outputfile.is_open())
        {
            while (current)
            {
                outputfile << current->Product_Name
                    << ","
                    << current->Product_Id
                    << ","
                    << current->Product_Expired_Date
                    << ","
                    << current->Product_Stock
                    << ","
                    << current->Product_Price
                    << endl;
                current = current->pnext;

            }
            outputfile.close();
        }
    }

};

class CListCustomer {
public:
    CnodeCustomer* head = NULL;
    CnodeCustomer* tail = NULL;


    void attach(CnodeCustomer* new_node) {
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->pnext = new_node;
            tail = new_node;
        }
    }
    void displayListCustomer() {
        CnodeCustomer* current = head;
        while (current) {
            cout << "Customer" << endl << " Customer Name: " << current->Customer_Name << ",Customer ID: " << current->Customer_Id << ", Customer Phone Number: " << current->Customer_Phone_Number << endl;
            current = current->pnext;
        }
    }
    void writeToFileCustomer(string filename) {
        CnodeCustomer* current = head;
        ofstream outputfile("Customer.txt");
        if (outputfile.is_open())
        {
            while (current != NULL)
            {
                outputfile << current->Customer_Name
                    << ","
                    << current->Customer_Id
                    << ","
                    << current->Customer_Phone_Number
                    << endl;
                current = current->pnext;

            }
            outputfile.close();
        }
    }
};

class CListOrder {
public:
    CnodeOrder* head = NULL;
    CnodeOrder* tail = NULL;


    void attach(CnodeOrder* new_node) {
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->pnext = new_node;
            tail = new_node;
        }
    }
    void displayListOrder() {
        CnodeOrder* current = head;
        while (current != NULL) {
            cout << "Order" << endl << "Order Id: " << current->Order_Id << ", Product ID: " << current->Product_Id << ", Customer ID: " << current->Customer_Id << ", Purchase Day: " << current->Purchase_Day << ", Purchase Month: " << current->Purchase_Month << ", Purchase Year: " << current->Purchase_Year << endl;
            current = current->pnext;
        }
    }


    void writeToFileOrder(string filename) {
        CnodeOrder* current = head;
        ofstream outputfile("Order.txt");
        if (outputfile.is_open())
        {
            while (current != NULL)
            {
                outputfile
                    << current->Order_Id
                    << ","
                    << current->Product_Id
                    << ","
                    << current->Customer_Id
                    << ","
                    << current->Purchase_Day
                    << ","
                    << current->Purchase_Month
                    << ","
                    << current->Purchase_Year
                    << endl;
                current = current->pnext;

            }
            outputfile.close();
        }
    }

};
void main()
{
    CListOrder O;
    CListCustomer C;
    CListproduct P;
    fstream file;
    string x;
    int it;
    file.open("Customer.txt");
    while (getline(file, x)) {
        string temp[3]; it = 0;
        for (int i = 0; i < x.length(); i++) {
            if (x[i] == ',') {
                it++;
            }
            else {
                temp[it] += x[i];
            }
        }
        CnodeCustomer* pnn = new CnodeCustomer;
        pnn->Customer_Name = temp[0];
        pnn->Customer_Id = stoi(temp[1]);
        pnn->Customer_Phone_Number = stof(temp[2]);
        pnn->pnext = NULL;
        C.attach(pnn);
    }
    file.close();

    C.displayListCustomer();
    cout << endl << "-----------------------------------" << endl;

    file.open("Product.txt");
    while (getline(file, x))
    {
        string temp[5]; it = 0;
        for (int i = 0; i < x.length(); i++) {
            if (x[i] == ',') {
                it++;
            }
            else {
                temp[it] += x[i];
            }
        }
        Cnodeproduct* pnn = new Cnodeproduct;
        pnn->Product_Name = temp[0];
        pnn->Product_Id = stoi(temp[1]);
        pnn->Product_Expired_Date = stof(temp[2]);
        pnn->Product_Stock = stof(temp[3]);
        pnn->Product_Price = stof(temp[4]);
        pnn->pnext = NULL;
        P.attach(pnn);
    }
    file.close();

    P.displayListproduct();
    cout << endl << "-----------------------------------" << endl;


    file.open("Order.txt");
    while (getline(file, x)) {
        string temp[6]; it = 0;
        for (int i = 0; i < x.length(); i++) {
            if (x[i] == ',') {
                it++;
            }
            else {
                temp[it] += x[i];
            }
        }
        CnodeOrder* pnn = new CnodeOrder;
        pnn->Order_Id = stoi(temp[0]);
        pnn->Product_Id = stoi(temp[1]);
        pnn->Customer_Id = stoi(temp[2]);
        pnn->Purchase_Day = stoi(temp[3]);
        pnn->Purchase_Month = stoi(temp[4]);
        pnn->Purchase_Year = stoi(temp[5]);
        pnn->pnext = NULL;
        O.attach(pnn);

    }
    file.close();
    O.displayListOrder();
    cout << endl << "-----------------------------------" << endl;

    O.writeToFileOrder("Order.txt");
    P.writeToFileproduct("Product.txt");
    C.writeToFileCustomer("Customer.txt");

    cout << endl;
    cout << "Enter Customer Name" << endl;

    string custname;
    int fc = 0;

    cin >> custname;

    CnodeCustomer* pt = C.head;



    while (pt != NULL) {

        if (pt->Customer_Name == custname) {

            fc = 0;
            break;
        }

        if (pt->Customer_Name != custname) {

            fc = 1;


        }
        pt = pt->pnext;
    }


    int custid, custphone;
    CnodeCustomer* pnn;
    if (fc == 1) {

        cout << "The Name Is Not Found" << endl;
        cout << "Please Enter The Customer Id" << endl;
        cin >> custid;
        cout << "Please Enter The Customer Phone Number" << endl;
        cin >> custphone;
        CnodeCustomer* pnn = new CnodeCustomer;
        pnn->pnext = NULL;
        pnn->Customer_Name = custname;
        pnn->Customer_Id = custid;
        pnn->Customer_Phone_Number = custphone;
        C.attach(pnn);
        C.writeToFileCustomer("Customer.txt");
        C.displayListCustomer();
    }

    string req;
    int quantity = 0, fp = 0, ctchip = 0, ctbis = 0, ctchoco = 0, ctjui = 0, ctsand = 0, ctmil = 0, ctegg = 0;
    int day, month, year;
    int chipsy = 0, biscuit = 0, chocolate = 0, juice = 0, sandwich = 0, milk = 0, egg = 0, max = -999999;
    int tot = 0, totchip = 0, totbisc = 0, totchoco = 0, totjuic = 0, totsandw = 0, totmilk = 0, totegg = 0;
    int opt;
    Cnodeproduct* ppp = P.head;
    if (fc == 0) {
        P.displayListproduct();
        cout << "__________________________________________________________________________________________" << endl;
        int fr = 1;
        while (fr == 1) {
            cout << "Enter Your Order" << endl;
            cin >> req;
            if (req == "x") {
                cout << "Do You Want To Display Order Or Display The Report Of The Sales" << endl << "1:Display Order" << endl << "2:Display Display The Report Of The Sales" << endl;
                cin >> opt;
                if (opt == 1) {
                    O.displayListOrder();
                    fr = 0;
                    break;
                }
                if (opt == 2) {
                    if (ctchip > max) {
                        max = ctchip;
                    }
                    if (ctbis > max) {
                        max = ctbis;
                    }
                    if (ctchoco > max) {
                        max = ctchoco;
                    }
                    if (ctjui > max) {
                        max = ctjui;
                    }
                    if (ctsand > max) {
                        max = ctsand;
                    }
                    if (ctchip == max) {
                        tot = totchip + totbisc + totchoco + totjuic + totsandw;
                        cout << "The Report Of The Sales Is" << endl;
                        cout << "The Most Popular Product Is Chipsy and It's Revenue :" << totchip << endl;
                        cout << "The Total Sales Revenue :" << tot << endl;
                    }
                    if (ctbis == max) {
                        tot = totchip + totbisc + totchoco + totjuic + totsandw;
                        cout << "The Report Of The Sales Is" << endl;
                        cout << "The Most Popular Product Is Biscuit and It's Revenue :" << totbisc << endl;
                        cout << "The Total Sales Revenue :" << tot << endl;
                    }
                    if (ctchoco == max) {
                        tot = totchip + totbisc + totchoco + totjuic + totsandw;
                        cout << "The Report Of The Sales Is" << endl;
                        cout << "The Most Popular Product Is Chocolate and It's Revenue :" << totchoco << endl;
                        cout << "The Total Sales Revenue :" << tot << endl;
                    }
                    if (ctjui == max) {
                        tot = totchip + totbisc + totchoco + totjuic + totsandw;
                        cout << "The Report Of The Sales Is" << endl;
                        cout << "The Most Popular Product Is Juice and It's Revenue :" << totjuic << endl;
                        cout << "The Total Sales Revenue :" << tot << endl;
                    }
                    if (ctsand > max) {
                        tot = totchip + totbisc + totchoco + totjuic + totsandw;
                        cout << "The Report Of The Sales Is" << endl;
                        cout << "The Most Popular Product Is Sandwich and It's Revenue :" << totsandw << endl;
                        cout << "The Total Sales Revenue :" << tot << endl;
                    }

                    break;
                
                
                }
            }

            while (ppp != NULL) {
                if (ppp->Product_Name == req) {
                    if (ppp->Product_Expired_Date < 2024) {
                        cout << "The Product Date Was Expired" << endl;
                        int productid = ppp->Product_Id;
                        P.Delete(productid);
                        P.writeToFileproduct("product.txt");
                        P.displayListproduct();
                        fp = 1;
                        break;

                    }
                }
                ppp = ppp->pnext;
            }

            if (fp == 1) {
                break;
            }
            cout << "Enter The Quantity" << endl;
            cin >> quantity;
            Cnodeproduct* pp = P.head;
            CnodeOrder* ptt = O.head;
            while (pp != NULL) {
                if (pp->Product_Name == req) {
                    if (pp->Product_Name == "chipsy") {
                        ctchip += quantity;
                        totchip += quantity * 5;
                    }
                    if (pp->Product_Name == "biscuit") {
                        ctbis += quantity;
                        totbisc += quantity * 4;
                    }
                    if (pp->Product_Name == "chocolate") {
                        ctchoco += quantity;
                        totchoco += quantity * 6;
                    }
                    if (pp->Product_Name == "juice") {
                        ctjui += quantity;
                        totjuic += quantity * 10;
                    }
                    if (pp->Product_Name == "sandwich") {
                        ctsand += quantity;
                        totsandw += quantity * 15;
                    }
                    if (pp->Product_Name == "milk") {
                        ctmil += quantity;
                        totmilk += quantity * 20;
                    }
                    if (pp->Product_Name == "egg") {
                        ctegg += quantity;
                        totegg += quantity * 8;
                    }
                    pp->Product_Stock -= quantity;
                    P.writeToFileproduct("Product.txt");
                    quantity = 0;
                    break;
                }

                pp = pp->pnext;
            }
            CnodeOrder* pnn = new CnodeOrder;
            while (ptt->pnext != NULL) {

                ptt = ptt->pnext;
            }
            pnn->Order_Id = ptt->Order_Id + 1; ;
            pnn->Product_Id = pp->Product_Id;
            pnn->Customer_Id = pt->Customer_Id;
            cout << "Enter Purchase Day." << endl;
            cin >> day;
            cout << "Enter Purchase Month." << endl;
            cin >> month;
            cout << "Enter Purchase Year." << endl;
            cin >> year;
            pnn->Purchase_Day = day;
            pnn->Purchase_Month = month;
            pnn->Purchase_Year = year;
            pnn->pnext = NULL;
            O.attach(pnn);
            O.writeToFileOrder("Order.txt");

        }

    }
 
}

