#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    string Book_Name;
    string Book_Writer;
    string ID;
    int Book_Price;
    Book* next;
    Book* prev;

    Book(string _Book_Name, string _Book_Writer, string _ID, int _Book_Price){
        Book_Name = _Book_Name;
        Book_Writer = _Book_Writer;
        ID = _ID;
        Book_Price = _Book_Price;
        prev = next = NULL;
    }
};

class Library{
public:
    Book* Head;
    Book* Tail;

    Library(){
        Head = Tail = NULL;
    }

   Book* Search(string ID){
       Book* current = Head;

       while(current != NULL){
       if(current->ID == ID){
            return current;
       }
       else{
        current = current->next;
       }
       }

       return NULL;
    }
    //Add node

    void Add(string Book_Name, string Book_Writer, string ID, int Book_Price ){
        Book* newBook = new Book(Book_Name , Book_Writer,ID,Book_Price);
        if(Head == NULL && Tail == NULL){
            Head = Tail = newBook;
        }else{

            newBook->prev = Tail;
            Tail->next = newBook;
            Tail = newBook;
        }
    }

    //Display node
    void Display(){
        Book* current = Head;
        if(current==NULL){
                 cout<<"there is no elements to display \n";}
    while(current !=NULL){
       cout<<current->Book_Name<<endl;
       current = current->next;
        }
    }
    //display details of the book selected by the user
    void Display_selected_book(string BookName){
        Book* current = Head;
        if(current==NULL){
                 cout<<"there is no elements to display \n";
        }
        while(current != NULL){
                if( current->Book_Name == BookName){
                        cout<<"Book Name is : "<<current->Book_Name<<endl;
                        cout<<"Book Writer is : "<<current->Book_Writer<<endl;
                        cout<<"ID : "<<current->ID<<endl;
                        cout<<"Book Price : "<<current->Book_Price<<endl;
                        break;
                }
                else{
                    current=current-> next;
                }
        }
    }
    void Delete(string ID){
       Book* pdelete = Search(ID);
       if(pdelete == NULL){
        cout<<"there is no elements to delete \n";
       }
       if(pdelete != NULL){
        //deleted node is the head
        if(pdelete == Head){
            if(pdelete == Tail){
                Head = Tail =NULL;
            }else{
                Head = Head->next;
                Head->prev = NULL;
            }
        }

        // deleted node is tail
        else if( pdelete == Tail)
        {

            Tail = Tail->prev;
            Tail->next = NULL;
        }

        // deleted node is not head or tail
        else{
                pdelete->prev->next = pdelete->next;
                pdelete->next->prev = pdelete->prev;

        }
       }
    }

    void insertAfter(string prevID , string newName, string newWriter,string newID, int newPrice ){
        Book* prevBook = Search(prevID);

        if(prevBook == Tail || prevBook == NULL){
            Add(newName, newWriter, newID, newPrice);
        }else{
            Book* newBook = new Book(newName, newWriter, newID, newPrice);

            newBook->prev = prevBook;
            newBook->next = prevBook->next;
            prevBook->next = newBook;
            newBook->next->prev = newBook;
        }
    }
    void Search_For_Book_Name(string name){
        int flag=0;
     Book* current = Head;

       while(current != NULL){
       if(current->Book_Name == name){
            cout<< "Found, if you want more details about the book please enter 2\n";
            flag=1;
            break;
       }
       else{
        current = current->next;
       }
       }
       if(flag==0){
             cout<<"there is no elements";
       }
    }

};
int main(){
    Library book;
    system("Color 0A");
    cout<<"Please write number of the choice you selected: \n 1-Add \n 2-Display \n 3-Delete \n 4-Inserts After \n 5-Search \n 6-Exit \n" ;
    int selected;
    while(true){
            cin>>selected;
        if(selected == 1){
            cout<<"Please Enter the book name\n";
            string name;
            cin.ignore();
            getline(cin,name);
            cout<<"Please Enter the writer name\n";
            string writer_name;
            cin.ignore();
            getline(cin,writer_name);
            cout<<"Please Enter the book ID\n";
            string ID;
            cin>>ID;
            cout<<"Please Enter the book Price with numbers\n";
            int price;
            cin>>price;
            book.Add(name,writer_name,ID,price);
        }else if(selected==2){
        book.Display();
        cout<<"Enter the Name of the book you selected for details\n";
        string name;
        cin.ignore();
        getline(cin,name);
        book.Display_selected_book(name);
        }else if(selected==3){
            cout<<"Please Enter the book ID\n";
            string ID_deleted;
            cin>>ID_deleted;
            book.Delete(ID_deleted);
        }else if(selected==4){
            cout<<"Please Enter the book ID you will insert after\n";
            string ID_last_book;
            cin>>ID_last_book;
            cout<<"Please Enter the book name\n";
            string name;
            cin.ignore();
            getline(cin,name);
            cout<<"Please Enter the writer name\n";
            string writer_name;
            cin.ignore();
            getline(cin,writer_name);
            cout<<"Please Enter the book ID\n";
            string ID;
            cin.ignore();
            getline(cin,ID);
            cout<<"Please Enter the book Price with numbers\n";
            int price;
            cin>>price;
            book.insertAfter(ID_last_book,name,writer_name,ID,price);
        }else if(selected==5){
            cout<<"Please Enter the book Name\n";
            string Book_Name;
            cin.ignore();
            getline(cin,Book_Name);
            book.Search_For_Book_Name(Book_Name);
        }else if(selected==6){
        break;
        }else{
        cout<<"it doesn't exist";
        }
    }
    return 0;
}
