#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std ;

struct user {
    string username ;
    string password ;
    long int wallet ; 
} ;

bool dorostbodan(string line) ;
void showitem(int products) ;
void showall(int product) ;
void buy(int products , long int *wallet) ;
void help() ;
void helpboss() ;
void helporder() ;
void swapfile() ;
void add(string type , string price , string amount ,int *product) ;
void multadd(int *product) ;
string mainremove(int *product) ;
string proremove(string type , int *product) ;
string ctrlz(string back , int *product) ;
void rename(int product) ;
void prorename(int *product) ;
void reprice(int *product) ;
void increasewallet(long int *mina , long int *javad , long int *reza) ; 
void showallcredit(long int mina , long int javad , long int reza) ;


int main() {

    //admin users 

    user moein ;
    moein.username = "1" ;
    moein.password = "2" ; 

    user danny ;
    danny.username = "porteghal1234" ;
    danny.password = "sole1234" ;

    //users 

    user mina1 ;
    mina1.username = "3" ;
    mina1.password = "4" ;
    mina1.wallet = 1000 ;

    user javad2 ;
    javad2.username = "javad1234" ;
    javad2.password = "shop1234" ;
    javad2.wallet = 500 ;

    user reza3 ; 
    reza3.username = "reza1234" ;
    reza3.password = "rezi1234" ;
    reza3.wallet = 2000 ;

    //checking the first products

    remove("log.txt") ;
    ifstream file ;
    file.open("anbar.txt" , ios::in) ;
    string line ;
    getline(file , line) ; //gerftan esm avalie table

    int products = 0 ;
    while(getline(file , line , '$')) {
        int size_line = line.size() ;
        bool anjamdadan = false ;
        for(int i=0 ; i<size_line ; i++) {
            if(line[i] != ' ') {
                anjamdadan = true ;
                break ;
            }
        }
        if(!anjamdadan) {
            continue ;
        }
        bool dorost = dorostbodan(line) ;
        products++ ; //tedad mahsol avalie
        if(!dorost) {
            return 0 ;
        }
    }

    file.close() ;

    string back ; //ctrlz
    ofstream log ;
    log.open("log.txt" , ios::app) ;

    while(1) {
        string username , password ;
        cout<< "enter your username" << '\n' ;
        cin>> username ;
        cout<< "enter your password" << '\n' ; 
        cin>> password ;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//admin users      
        if(moein.username == username && moein.password == password) {
            string back ;
            while(1) {
                cout<< '\n' << "[$] please enter your order" << '\n' << "$ " ;
                string order ;
                cin>> order ;

                int size_order = order.size() ;
                for(int i=0 ; i<size_order ; i++) {
                    order[i] = tolower(order[i]) ;
                }

                if(order == "add") {
                    log << "[$] Log : (" << '\n' << "user : moein" << '\n' << "order : add" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    string type , price , amount  ;
                    cin>> type >> price ;
                    getline(cin , amount) ;
                    add(type , price , amount , &products) ;
                    
                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "multadd") {
                    log << "[$] Log : (" << '\n' << "user : moein" << '\n' << "order : multadd" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    multadd(&products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "remove") {
                    log << "[$] Log : (" << '\n' << "user : moein" << '\n' << "order : remove" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    back = mainremove(&products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "ctrlz") {
                    log << "[$] Log : (" << '\n' << "user : moein" << '\n' << "order : ctrlz" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    back = ctrlz(back , &products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "rename") {
                    log << "[$] Log : (" << '\n' << "user : moein" << '\n' << "order : rename" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    rename(products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if (order == "prorename") {
                    prorename(&products) ;
                }
                else if (order == "price") {
                    log << "[$] Log : (" << '\n' << "user : moein" << '\n' << "order : price" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    reprice(&products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "credit") {
                    log << "[$] Log : (" << '\n' << "user : moein" << '\n' << "order : credit" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;
                    
                    increasewallet(&mina1.wallet , &javad2.wallet , &reza3.wallet) ; 
                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "showcredits") {
                    showallcredit(mina1.wallet , javad2.wallet , reza3.wallet) ;
                }
                else if(order == "show") {
                    showall(products) ;
                }
                else if(order == "help") {
                    helpboss() ;
                }   
                else if(order == "logout") {
                    cout<< "[$] see you later" << '\n' ;
                    break ;
                }
                else {
                    cout<< "[$] if you want help write : help" << '\n' ;
                }
            }
        }
        else if (danny.username == username && danny.password == password) {
            string back ;
            while(1) {
                cout<< '\n' << "[$] please enter your order" << '\n' << "$ ";
                string order ;
                cin>> order ;

                int size_order = order.size() ;
                for(int i=0 ; i<size_order ; i++) {
                    order[i] = tolower(order[i]) ;
                }

                if(order == "add") {
                    log << "[$] Log : (" << '\n' << "user : danny" << '\n' << "order : add" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    string type , price , amount  ;
                    cin>> type >> price >> amount ;
                    add(type , price , amount , &products) ;
                    
                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "multadd") {
                    log << "[$] Log : (" << '\n' << "user : danny" << '\n' << "order : multadd" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    multadd(&products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "remove") {
                    log << "[$] Log : (" << '\n' << "user : danny" << '\n' << "order : remove" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    back = mainremove(&products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "ctrlz") {
                    log << "[$] Log : (" << '\n' << "user : danny" << '\n' << "order : ctrlz" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    back = ctrlz(back , &products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "rename") {
                    log << "[$] Log : (" << '\n' << "user : danny" << '\n' << "order : rename" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    rename(products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if (order == "prorename") {
                    prorename(&products) ;
                }
                else if (order == "price") {
                    log << "[$] Log : (" << '\n' << "user : danny" << '\n' << "order : price" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    reprice(&products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "credit") {
                    log << "[$] Log : (" << '\n' << "user : danny" << '\n' << "order : credit" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;
                    
                    increasewallet(&mina1.wallet , &javad2.wallet , &reza3.wallet) ; 
                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "showcredits") {
                    showallcredit(mina1.wallet , javad2.wallet , reza3.wallet) ;
                }
                else if(order == "show") {
                    showall(products) ;
                }
                else if(order == "help") {
                    helpboss() ;
                }   
                else if(order == "logout") {
                    cout<< "[$] see you later" << '\n' ;
                    break ;
                }
                else {
                    cout<< "[$] if you want help write : help" << '\n' ;
                }
            }
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//normal users
        else if(mina1.username == username && mina1.password == password) {
            while(1) {
                cout<< '\n' << "[#] please enter your order" << '\n' << "# " ;
                string order ;
                cin>> order ;
                
                if(order == "show") {
                    log << "[#] Log : (" << '\n' << "user : mina" << '\n' << "order : show item" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    showitem(products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "buy") {
                    log << "[#] Log : (" << '\n' << "user : mina" << '\n' << "order : buy" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;
                    
                    buy(products , &mina1.wallet) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "balance") {
                    cout<< "your wallet = " << mina1.wallet << " $" << '\n' ; 
                }
                else if(order == "help") {
                    helporder() ;
                }
                else if(order == "logout") {
                    cout<< "[#] see you later" << '\n' ;
                    break ;
                }
                else {
                    cout<< "[#] if you are need help write : help" << '\n' ;
                }
            }
        }
        else if(javad2.username == username && javad2.password == password) {
            while(1) {
                cout<< '\n' << "[#] please enter your order" << '\n' << "# " ;
                string order ;
                cin>> order ;
                
                if(order == "show") {
                    log << "[#] Log : (" << '\n' << "user : javad" << '\n' << "order : show item" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    showitem(products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "buy") {
                    log << "[#] Log : (" << '\n' << "user : javad" << '\n' << "order : buy" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;
                    
                    buy(products , &javad2.wallet) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "balance") {
                    cout<< "your wallet = " << javad2.wallet << " $" << '\n' ; 
                }
                else if(order == "help") {
                    helporder() ;
                }
                else if(order == "logout") {
                    cout<< "[#] see you later" << '\n' ;
                    break ;
                }
                else {
                    cout<< "[#] if you are need help write : help" << '\n' ;
                }
            }
        }
        else if(reza3.username == username && reza3.password == password) {
            while(1) {
                cout<< '\n' << "[#] please enter your order" << '\n' << "# " ;
                string order ;
                cin>> order ;
                
                if(order == "show") {
                    log << "[#] Log : (" << '\n' << "user : reza" << '\n' << "order : show item" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;

                    showitem(products) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "buy") {
                    log << "[#] Log : (" << '\n' << "user : reza" << '\n' << "order : buy" << '\n' ;
                    log.flush() ;
                    auto start = chrono::high_resolution_clock::now() ;
                    
                    buy(products , &reza3.wallet) ;

                    auto end = chrono::high_resolution_clock::now() ;
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start) ;
                    log << "run time : " << duration.count() << " (microsecond)" << '\n' << ") " << '\n' ;
                    log.flush() ;
                }
                else if(order == "balance") {
                    cout<< "your wallet = " << reza3.wallet << " $" << '\n' ; 
                }
                else if(order == "help") {
                    helporder() ;
                }
                else if(order == "logout") {
                    cout<< "[#] see you later" << '\n' ;
                    break ;
                }
                else {
                    cout<< "[#] if you are need help write : help" << '\n' ;
                }
            }
        }

        else {
            cout<< "your username or password is wrong please try again" << '\n' << '\n'; 
        }
    }

    return 0 ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//baraie check kardan vorodi ha
bool dorostbodan(string line) {
    ofstream log ;
    log.open("log.txt" , ios::app) ;
    
    int size_l = line.size() ;
    for(int i=0 ; i<size_l-1 ; i++) {
    line[i] = tolower(line[i]) ;
    }
    line += ' ' ;

    for(int i=0 , j=0 ; i<3 ; ) {
         
        if(line[0] < 97 || line[0]  >122) {
        j++ ;
        }
        if(j==size_l) {
            return true ;
        }

        if(i == 0) {
            while(line[j] != ' ') {
                if(line[j] < 97 || line[j]  >122) {
                    cout<< "your name of product is not logical" << '\n';
                    log << "name is not logical" << '\n' ;
                    return false ;
                }
                j++ ;
            }
            i++ ;
        }
        j++ ;

        if(i == 1) {
            while(line[j] != ' ') {
                if(line[j] < 48 || line[j] > 57) {
                    cout<< "your price of product is not logical" << '\n' ;
                    log << "price is not logical" << '\n' ;
                    return false ;
                }
                j++ ;
            }
            i++ ;
        }
        j++ ;

        if(i == 2) {
            while(line[j] != ' ') {
                if(line[j] < 48 || line[j] > 57) {
                    cout<< "your amount of product is not logical" << '\n' ;
                    log << "amount is not logical" << '\n' ;
                    return false ;
                }
                j++ ;
            }
            i++ ;
        }
    }

    return true ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void showitem(int products) {
    ofstream log ;
    log.open("log.txt" , ios::app) ;

    string type , line ;
    getline(cin , type) ;
    int size_type = type.size() ;
    bool bodan = false ;
    for(int i=0 ; i<size_type ; i++) {
        type[i] = tolower(type[i]) ;
        if(type[i] != ' ') {
            line += type[i] ;
        }
    }
    type = line ;
    if(type == "") {
        showall(products) ;
        log << "show all is successful" << '\n' ;
        log.flush() ;
        return ;
    }

    ifstream file ;
    file.open("anbar.txt" , ios::in) ;

    file >> line ;
    line = "" ;
 
    for(int i=0 ; i<products ; i++) {
        file >> line ;
        if(line == type) {
            cout<< line << "( " ;
            file >> line ;
            cout<< " price : " << line ;
            file >> line ;
            cout<< " , inventory : " << line << " )" << '\n' ;
            file.close() ;
            log << "show item is successful" << '\n' ;
            log.flush() ;
            return ; 
        }
        else {
            getline(file , line , '$') ;
        }            
    }
    
    cout<< "[#] this item is not exist" << '\n' ;
    log << "item is not exist" << '\n' ;
    log.flush() ;
    return ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void showall(int product) {
    ifstream file ;
    file.open("anbar.txt") ;

    string line ;
    file >> line ;
    cout<< "[$] inventory :" << '\n' ;
    for(int i=0 ; i<product ; i++) {
        file >> line ;
        cout<< line << "( price : " ;
        file >> line ;
        cout<< line << " , amount : " ;
        file >> line ;
        cout<< line << " )" << '\n' ;
        getline(file , line , '$') ; 
    }
    cout<< '\n' ;
    file.close() ;
    return ; 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void buy(int products , long int *wallet) {
    ofstream log ;
    log.open("log.txt" , ios::app) ;

    string type ;
    cin>> type ;
    int size_type = type.size() ;
    for(int i=0 ; i<size_type ; i++) {
        type[i] = tolower(type[i]) ;
    }
    ifstream file ;
    file.open("anbar.txt" , ios::in) ;
    string line ;
    file >> line ;

    string tempp ;

    for(int i=0 ; i<products ; i++) {
        file >> line ;
        tempp += line ;
        if(type == line) {
            tempp += ' ' ;
            file >> line ;
            tempp += line ;
            tempp += ' ' ;
            int price = stoi(line) ;

            file >> line ;
            int inventory = stoi(line) ;

            if(price <= *wallet && inventory != 0) {
                *wallet -= price ; 
                remove("temp.txt") ;
                ofstream temp ;
                temp.open("temp.txt" , ios::app) ;
                temp << tempp ;
                line = to_string(inventory-1) ;
                temp << line ;
                getline(file , line) ;
                temp << line ;
                file.close() ;
                temp.close() ;
                swapfile() ;
                cout<< "[~] done" << '\n' ;
                log << "buy is successful" << '\n' ;
                return ;
            }
            else if(price > *wallet) {
                cout<< "[#] sorry but you need more money" << '\n' ;
                log << "not enough money" << '\n' ;
                log.flush() ;
                return ;
            }
            else {
                cout<< "[#] sorry our inventory is not enough for you order" << '\n' ;
                log << "inventory not enough" << '\n' ;
                log.flush() ;
                return ;
            }
        }
        else {
            getline(file , line , '$') ;
            tempp += line + '$' + ' ' ;
        }
    }
    cout<< "[#] this product is not exist" << '\n' ;
    log << "product not exist" << '\n' ;
    log.flush() ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void help() {
    cout<< "show (product name)" << '\n' ;
    cout<< "buy (product name)" << '\n' ;
    cout<< "balance" << '\n' ;
    cout<< "help (name of order)" << '\n' ;
    cout<< "if you are want to logout write : logout" << '\n' ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void helporder() {
    string type , line ;
    getline(cin , type) ;
    int size_type = type.size() ;
    bool bodan = false ;
    for(int i=0 ; i<size_type ; i++) {
        type[i] = tolower(type[i]) ;
        if(type[i] != ' ') {
            line += type[i] ;
        }
    }
    type = line ;
    if(type == "") {
        help() ;
        return ;
    }

    cout<< '\n' ;

    if(type == "show") {
        cout<< "if you are want to see information of our ptoducts please write : show (product name)" << '\n' ;
        return  ;
    }
    else if(type == "buy") {
        cout<< "if you are want to buy from us please write : buy (product name)" << '\n' ;
        return ;
    }
    else if(type == "balance") {
        cout<< "if you are want to see your wallet please write : balance" << '\n' ;
        return ;
    }
    else {
        cout<< "this order is not exist" << '\n' ;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void helpboss() {
    cout<< "add (product name) (price) (amount) : if you are want to add some products write" << '\n' ;
    cout<< "remove (product name) (amount) : if you are want to remove some products write" << '\n' ;
    cout<< "ctrlz : if you are want to back your product write" << '\n' ;
    cout<< "rename (last name) (new name) : if you are want to rename some products write :" << '\n' ;
    cout<< "prorename (last name) (new name) : if you are want to rename some products write" << '\n' ;
    cout<< "price (product name) (new price) : if you are want to set a new price for a product write" << '\n' ;
    cout<< "credit (user name) (amount+) : if you are want to increase the wallet of the users wrire" << '\n' ;
    cout<< "showcredits : if you are want to see wallet of customers write" << '\n' ;
    cout<< "showall : if you are want to see all of the inventory write" ;
    cout<< "logout : if you are want to logout write" << '\n' ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void swapfile() {
    remove("anbar.txt") ;
    ifstream temp ;
    temp.open("temp.txt" , ios::in) ;

        ofstream file ;
    file.open("anbar.txt" , ios::out | ios::app) ;

    string line = "****saker****" ;
    file << line << '\n' ;
    getline(temp , line) ;
    file << line ;
    remove("temp.txt") ;
    file.flush() ;
    file.close() ;
    temp.close() ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add(string type , string price , string amount , int *product) {
    ofstream log ;
    log.open("log.txt" , ios::app) ;
    string check = type + ' ' + price + ' ' + amount ;
    int size_type = type.size() ;
    for(int i=0 ; i<size_type ; i++) {
        type[i] = tolower(type[i]) ;
    }

    string line ;
    bool yeksho = false ;
    int size_amount = amount.size() ;
    for(int i=0 ; i<size_amount ; i++) {
        if(amount[i] != ' ') {
            line += amount ;
            yeksho = true ;
        }
    }
    amount = line ;
    if(!yeksho) {
        amount = "1" ;
    }
    
    if(!dorostbodan(check)) {
        log.flush() ;
        return ;
    }

    log << "add is successful" << '\n' ;
    log.flush() ;

    ifstream file ;
    file.open("anbar.txt") ;
    string tempp ;
    file >> line ;
    for(int i=0 ; i<*product ; i++) {
        file >> line ;
        if(type == line) {
            tempp += line ;
            file >> line ;
            tempp += ' ' + price ;
            file >> line ;
            int totalamount = stoi(amount) + stoi(line) ;
            line = to_string(totalamount) ;
            tempp += ' ' + line ;
            getline(file , line) ;
            tempp += line ;
            ofstream temp ;
            temp.open("temp.txt") ;
            temp << tempp ;
            temp.flush() ;
            file.close() ;
            temp.close() ;
            swapfile() ;
            cout<< "[$] done" << '\n' ;
            return ;
        }
        else {
            tempp += line ;
            getline(file , line , '$') ;
            tempp += line + '$' + ' ' ;
            line = "" ;
        }
    }
    file.close() ;

    file.open("anbar.txt") ;
    line = "" ;
    file >> line ;
    string bofer; 
    getline(file , bofer) ;
    string inventury ; 
    getline(file , inventury) ;
    file.close() ;

    remove("anbar.txt") ;
    ofstream file1 ;
    file1.open("anbar.txt" , ios::app) ;
    int size_inventury = inventury.size() ;
    
    if(inventury[size_inventury-1] != ' ') {
        inventury += ' ' ;
    }

    file1 << line << '\n' ;
    file1 << inventury ;
    file1 << type << ' ' << price << ' ' << amount << ' ' << '$' ; //
    file1.flush() ;
    *product += 1 ;
    cout<< "[$] done" << '\n' ; 
    return ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void multadd(int *product) {
    fstream temp ;
    temp.open("temp.txt" , ios::out) ;

    string line , tempp ;
    getline(cin , line) ;
    temp << line + ' ' ;
    temp.close() ;


    temp.open("temp.txt" , ios::in) ;
    int num = -1 ;
    getline(temp , line , ' ') ;
    line = " " ;
    while(line != "") {
        getline(temp , line , ' ') ;
        num++ ;
    }
    num = num / 2 ;
    temp.close() ;

    temp.open("temp.txt" , ios::in) ;
    string type , price ;
    for(int i=0 ; i<num ; i++) {
        temp >> type ;
        temp >> price ;
        add(type , price , "1" , product) ;
    }
    remove("temp.txt") ; 
    temp.close() ;

    return ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string mainremove(int *product) {
    ofstream log ;
    log.open("log.txt" , ios::app) ;

    string type ;
    string amount , line ;
    cin>> type ;
    int size_type = type.size() ;
    for(int i=0 ; i<size_type ; i++) {
        type[i] = tolower(type[i]) ;
    }
    getline(cin , amount) ;
    int size_amount = amount.size() ;
    bool bodan = false ;
    for(int i=0 ; i<size_amount ; i++) {
        if(amount[i] != ' ') {
            line += amount[i] ;
            if(amount[i] < 48 || amount[i] > 57) {
                log << "amount is not logical" << '\n' ;
                cout<< "your amount is not logical" << '\n' ;
                log.flush() ;
                return "";
            }
            bodan = true ;
        }
    }
    if(bodan == false) {
        amount = "1" ;
    }
    
    ifstream file ;
    file.open("anbar.txt") ;
    ofstream temp ;
    temp.open("temp.txt" , ios::app) ;

    string tempp , back ;
    file >> line ;
    for(int i=0 ; i<*product ; i++) {
        file >> line ;
        if(line == type) {
            tempp += line ;
            back += line + ' ';
            file >> line ;
            tempp += ' ' + line ;
            back += line + ' ';
            file >> line ;
            back += line ;
            int kamamount = stoi(amount) ;
            int beforamount = stoi(line) ;
            int nowamount = beforamount - kamamount ;
            if(nowamount < 0) {
                cout<< "[$] done" << '\n' ;
                log << "remove is successful" << '\n' ;
                log.flush() ;
                cout<< "[$] done" << '\n' ;
                return proremove(type , product) ;
            }
            line = to_string(nowamount) ;
            tempp += ' ' + line ;
            line = "" ;
            getline(file , line) ;
            tempp += line ;
            temp << tempp ;
            temp.flush() ;
            swapfile() ;
            log << "remove is successful" << '\n' ;
            log.flush() ;
            cout<< "[$] done" << '\n' ;
            return back ;
        }
        else {
            tempp += line ;
            getline(file , line , '$') ;
            tempp += line + '$' + ' ' ;
            line = "" ;
        }
    }
    cout<< "this product is not exist" << '\n' ;
    log << "product is not exist" << '\n' ;
    log.flush() ;
    return "" ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string proremove(string type , int *product) {
    int size_type = type.size() ;
    for(int i=0 ; i<size_type ; i++) {
        type[i] = tolower(type[i]) ;
    }
    ifstream file ;
    file.open("anbar.txt") ;
    ofstream temp ;
    temp.open("temp.txt" , ios::app) ;
    string line ;
    file >> line ;
    string tempp , back ;
    for(int i=0 ; i<*product ; i++) {
        file >> line ;
        if(line == type) {
            back = line ;
            getline(file , line , '$') ;
            back += line ;
            line = "" ;
            file >> line ; 
            tempp += line ;
            getline(file , line) ;
            tempp += line ;
            temp << tempp ;
            temp.flush() ;
            swapfile() ;
            *product -= 1 ;
            return back ;
        }
        else {
            tempp += line ;
            getline(file , line , '$') ;
            tempp += line + '$' + ' ' ;
        }
    }
    return "" ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ctrlz(string back , int *product) {
    int i=0 ;
    back += ' ' ; 
    string type , price , amount ;
    if(back[0]==' ') {i++ ;} ;
    while(back[i]!=' ') {
        type += back[i] ;
        i++ ;
    }
    i++ ;
    while(back[i]!=' ') {
        price += back[i] ;
        i++ ;
    }
    i++ ;
    while(back[i]!=' ') {
        amount += back[i] ;
        i++ ;
    }
    string empty = proremove(type , product) ;
    add(type , price , amount , product) ;
    return empty ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rename(int product) {
    ofstream log ;
    log.open("log.txt" , ios::app) ;

    string last , now ;
    cin>> last >> now ;
    int size_last = last.size() ;
    int size_now = now.size() ;

    for(int i=0 ; i<size_last ; i++) {
        last[i] = tolower(last[i]) ;
    }
    for(int i=0 ; i<size_now ; i++) {
        now[i] = tolower(now[i]) ;
        if(now[i] > 122 || now[i] < 97) {
            cout<< "[$] your rename name is not logical" << '\n' ;
            log << "your rename is not logical" << '\n' ;
            log.flush() ;
            return ;
        } 
    }

    ifstream file ;
    file.open("anbar.txt") ;
    ofstream temp ;
    temp.open("temp.txt" , ios::app | ios::out) ;

    string line , tempp ; 
    file >> line ;

    for(int i=0 ; i<product ; i++) {
        file >> line ;
        if(last == line) {
            tempp += now ;
            line = "" ;
            getline(file , line) ;
            tempp += line ;
            temp << tempp ;
            file.close() ;
            temp.close() ;
            swapfile() ;
            cout<< "[$] done" ;
            log << "rename is successful" << '\n' ;
            log.flush() ;
            return ;
        }
        else {
            tempp += line ;
            getline(file , line , '$') ;
            tempp += line + '$' + ' ' ;
        }
    }
    
    cout<< "[$] this product not exist" << '\n' ;
    log <<  "product is not exist" << '\n' ;
    log.flush() ;
    return ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void prorename(int *product) {
    string main , rename ;
    cin>> main >> rename ;

    int size_main = main.size() ;
    for(int i=0 ; i<size_main ; i++) {
        main[i] = tolower(main[i]) ;
    }
    int size_rename = rename.size() ;
    for(int i=0 ; i<size_rename ; i++) {
        rename[i] = tolower(rename[i]) ;
    }

    string price , amount ;
    string information = proremove(main , product) ;
    int i=size_main+1 ; 
                    
    if(information[0] == ' ') {
        i++ ;
    }
                    
    while(information[i] != ' ') {
        price += information[i] ;
        i++ ;
    }
    i++ ;
    while(information[i] != ' ') {
        amount += information[i] ;
        i++ ;
    }
    add(rename , price , amount , product) ;
    cout<< "[$] done" << '\n' ;
    return ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void reprice(int *product) {
    ofstream log ;
    log.open("log.txt" , ios::app) ;

    string type , price ;
    cin>> type >> price ;
    int size_type = type.size() ;
    for(int i=0 ; i<size_type ; i++) {
        type[i] = tolower(type[i]) ;
    }

    int size_price = price.size() ;
    for(int i=0 ; i<size_price ; i++) {
        if(price[i] > 57 || price[i] < 48) {
            cout<< "[$] this price is not logical" ;
            log << "price is not logical" << '\n' ;
            log.flush() ;
            return ;
        }
    }

    ifstream file ;
    file.open("anbar.txt") ;
    ofstream temp ; 
    temp.open("temp.txt" , ios::out | ios::app) ;
    string line , tempp ;

    file >> line ;
    for(int i=0 ; i<*product ; i++) {
        file >> line ;
        if(type == line) {
            tempp += line + ' ' ;
            file >> line ;
            tempp += price + ' ' ;
            file >> line ;
            tempp += line ;//
            line = "" ;
            getline(file , line) ;
            tempp += line ;
            temp << tempp ;
            temp.flush() ;
            file.close() ;
            temp.close() ;
            swapfile() ;
            cout<< "[$] done" ;
            log << "reprice is successful" << '\n' ;
            log.flush() ;
            return ;
        }
        else {
            tempp += line ;
            line = "" ;
            getline(file , line , '$') ;
            tempp += line + '$' + ' ' ;
        }
    }
    cout<< "[$] this product is not exist" ;
    log << "product is not exist" << '\n' ;
    log.flush() ;
    return ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void increasewallet(long int *mina , long int *javad , long int *reza) {
    ofstream log ;
    log.open("log.txt" , ios::app) ;

    string type , amount ;
    long int increase ;
    cin>> type >> amount ;
    int size_amount = amount.size() ;
    for(int i=0 ; i<size_amount ; i++) {
        if(amount[i] > 57 || amount[i] < 48) {
            cout<< "[$] this amount is not logical" ;
            log << "amount is not logical" << '\n' ;
            log.flush() ;
            return ;
        }
    }
    increase = stoi(amount) ;
    int size_type = type.size() ;
    for(int i=0 ; i<size_type ; i++) {
        type[i] = tolower(type[i]) ;
    }

    if(type == "mina") {
        *mina += increase ;
        cout<< "[$] done" << '\n' ;
    }
    else if(type == "javad") {
        *javad += increase ;
        cout<< "[$] done" << '\n' ;
    }
    else if(type == "reza") {
        *reza += increase ;
        cout<< "[$] done" << '\n' ;
    }
    else {
        cout<< "[$] this person is not exist" ;
        log << "person is not exist" << '\n' ;
        log.flush() ;
        return ;
    }
    log << "credit is successful" << '\n' ;
    log.flush() ;
    return ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void showallcredit(long int mina , long int javad , long int reza) {
    cout<< "mina wallet = " << mina << '\n' ;
    cout<< "javad wallet = " << javad << '\n' ;
    cout<< "reza wallet = " << reza << '\n' ;
    return ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////