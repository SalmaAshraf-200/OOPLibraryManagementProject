#include <iostream>
#include <algorithm>
using namespace std;

class Data
{
    private:
    string title;
    string author;
    bool availability;

    public:
        Data(){
            title="None";
            author="None";
            availability= true;
        }
        void setTitle(){
        string t;
        cout<<"Enter the title : ";
        getline(cin,t);
        title=t;
    }
    string getTitle(){
        return title;
    }

    void setAuthor(){
        string a;
        cout<<"Enter the author name : ";
        getline(cin,a);
        author=a;
    }
    string getAuthor(){
        return author;
    }
    
    void setAvailability(bool a){
        availability=a;
    }

    int getAvailability(){
        return availability;
    }
};

class Book : public Data
{
    private:
    long long ISBN;

    public:

    Book(){
        ISBN=0;
    }

    void setISBN(){
        long long i;
        cout<<"Enter the ISBN : ";
        cin>>i;
        ISBN=i;
    }
    long long getISBN(){
        return ISBN;
    }

    void display(){
        cout<<"Book Title = "<<getTitle()<<endl;
        cout<<"Book Author = "<<getAuthor()<<endl;
        cout<<"Book ISBN = "<<getISBN()<<endl;
        cout<<"Book availability = "<<getAvailability()<<endl;
    }
};

class Magazine : public Data
{
private:
    int issueNumber;
    string publisher;

    public:
    Magazine(){
        issueNumber=0;
        publisher="None";
    }

    void setIssueNumber(){
        int i;
        cout<<"Enter the Issue number : ";
        cin>>i;
        issueNumber=i;
    }
    int getIssueNumber(){
        return issueNumber;
    }

    void setPublisher(){
        string p;
        cout<<"Enter the publisher name : ";
        cin.ignore();
        getline(cin,p);
        publisher=p;
    }
    string getPublisher(){
        return publisher;
    }

    void display(){
        cout<<"Magazine Title = "<<getTitle()<<endl;
        cout<<"Magazine IssueNumber = "<<getIssueNumber()<<endl;
        cout<<"Magazine Publisher = "<<getPublisher()<<endl; 
        cout<<"Magazine availability = "<<getAvailability()<<endl;
    }
};

class DVD : public Data
{
    string director;
    string duration;

    public:
    DVD(){
        director="None";
        duration="";
    }
    
    void setDirector(){
        string d;
        cout<<"Enter the director name : ";
        getline(cin,d);
        director=d;
    }
    string getDirector(){
        return director;
    }

    void setDuration(){
        string du;
        cout<<"Enter the duration : ";
        cin>>du;
        duration=du;
    }
    string getDuration(){
        return duration;
    }

    void display(){
        cout<<"DVD Title = "<<getTitle()<<endl;
        cout<<"DVD Director = "<<getDirector()<<endl;
        cout<<"DVD Duration = "<<getDuration()<<endl;
        cout<<"DVD availability = "<<getAvailability()<<endl;
    }
};

class LibrarySystem :public Book , public Magazine , public DVD
{
    private:
    Book* books[100];
    int bookCount=0;
    Magazine* magazines[100];
    int magazineCount=0;
    DVD* dvd[100];
    int dvdCount=0;

    public:
    ~LibrarySystem(){
        for(int i=0;i<bookCount;i++){
            delete books[i];
        }
        for(int i=0;i<magazineCount;i++){
            delete magazines[i];
        }
        for(int i=0;i<dvdCount;i++){
            delete dvd[i];
        }
    }
    void addBook(){
        books[bookCount]=new Book;
        books[bookCount]->setTitle();
        string title ;
        title=books[bookCount]->getTitle();
        for(int i=0;i<bookCount;i++){
            if(title==books[i]->getTitle())
            {
                cout<<"<<This book already exists>>"<<endl;
                return;
            }
        }
        books[bookCount]->setAuthor();
        books[bookCount]->setISBN();
        bookCount++;
        cout<<"-----------------------------------------"<<endl;
        cout<<"<<The book has been added successfully>>"<<endl;
    }

    void addMagazine(){
            magazines[magazineCount]=new Magazine;
            magazines[magazineCount]->setTitle();
            string title ;
            title=magazines[magazineCount]->getTitle();
            for(int i=0;i<magazineCount;i++){
            if(title==magazines[i]->getTitle())
            {
                cout<<"<<This magazine already exists>>"<<endl;
                return;
            }
        }
            magazines[magazineCount]->setIssueNumber();
            magazines[magazineCount]->setPublisher();
            magazineCount++;
            cout<<"-----------------------------------------"<<endl;
            cout<<"<<The Magazine has been added successfully>>"<<endl;
    }

    void addDVD(){
            dvd[dvdCount]=new DVD;
            dvd[dvdCount]->setTitle();
            string title ;
            title=dvd[dvdCount]->getTitle();
            for(int i=0;i<dvdCount;i++){
            if(title==dvd[i]->getTitle()){
                cout<<"<<This dvd already exists>>"<<endl;
                return;
            }
        }
            dvd[dvdCount]->setDirector();
            dvd[dvdCount]->setDuration();
            dvdCount++;
            cout<<"-----------------------------------------"<<endl;
            cout<<"<<The DVD has been added successfully>>"<<endl;
    }

    void displayItems(){
        cout<<"What item do you want to display?"<<endl;
        cout<<"1.Book"<<endl<<"2.Magazine"<<endl<<"3.DVD"<<endl;
        int n;
        cin>>n;
        switch (n)
        {
        case 1:
            if(bookCount==0)
            cout<<"<<The library is empty>>"<<endl;
            else{
                for(int i=0;i<bookCount;i++){
                    cout<<i+1<<"----->"<<endl;
                    books[i]->display();
                }
            }
            break;
        
        case 2:
            if(magazineCount==0)
            cout<<"<<The library is empty>>"<<endl;
            else{
                for(int i=0;i<magazineCount;i++){
                    cout<<i+1<<"----->"<<endl;
                    magazines[i]->display();
                }
            }
            break;

        case 3:
            if(dvdCount==0)
            cout<<"<<The library is empty>>"<<endl;
            else{
                for(int i=0;i<dvdCount;i++){
                    cout<<i+1<<"----->"<<endl;
                    dvd[i]->display();
               }
            }
            
            break;
        
        default:
            cout<<"<<Error>>"<<endl;
            break;
        }
    }

    void borrowItem(){
        cout<<"What item do you want to borrow?"<<endl;
        cout<<"1.Book"<<endl<<"2.Magazine"<<endl<<"3.DVD"<<endl;
        int n;
        cin>>n;
        if(n==1){
            if(bookCount==0)
            {
                cout<<"<<The library is empty>>"<<endl;
                return;
            }
    
            else{
                cout<<"(Available Books):"<<endl;
                for(int i=0;i<bookCount;i++){
                    cout<<"Book"<<i+1<<"-----> "<<endl;
                    books[i]->display();
                }
            cout<<"Enter the book name : ";
            string name;
            cin>>name;
            for(int i=0;i<bookCount;i++){
                if(books[i]->getTitle()==name)
                {
                    if(books[i]->getAvailability()==0){
                        cout<<"<<Not available>>"<<endl;
                        return;
                    }
                    else{
                        books[i]->setAvailability(0);
                        cout<<"<<Item borrowed>>"<<endl;
                        return;
                    }
                }
            }
              cout<<"<<Not found>>"<<endl;
            }
        }

        else if(n==2){
            if(magazineCount==0){
                cout<<"<<The library is empty>>"<<endl;
                return;
            }
                
            else{
                cout<<"(Available Magazines):"<<endl;
                for(int i=0;i<magazineCount;i++){
                    cout<<"Magazine"<<i+1<<"----->"<<endl;
                    magazines[i]->display();
                }
            cout<<"Enter the magazine name : ";
            string name;
            cin>>name;
            for(int i=0;i<magazineCount;i++){
                if(magazines[i]->getTitle()==name)
                {
                    if(magazines[i]->getAvailability()==0){
                        cout<<"<<Not available>>"<<endl;
                        return;
                    }
                    else{
                        magazines[i]->setAvailability(0);
                        cout<<"<<Item borrowed>>"<<endl;
                        return;
                    }
                }
            }
            cout<<"<<Not found>>"<<endl;
            }
        }

        else if(n==3){
            if(dvdCount==0){
                cout<<"<<The library is empty>>"<<endl;
                return;
            }
            
            else{
            cout<<"(Available dvds):"<<endl;
            for(int i=0;i<dvdCount;i++){
                    cout<<"DVD"<<i+1<<"----->"<<endl;
                    dvd[i]->display();
            }
            cout<<"Enter the dvd name : ";
            string name;
            cin>>name;
            for(int i=0;i<dvdCount;i++){
                if(dvd[i]->getTitle()==name)
                {
                    if(dvd[i]->getAvailability()==0){
                        cout<<"<<Not available>>"<<endl;
                        return;
                    }
                    else{
                        dvd[i]->setAvailability(0);
                        cout<<"<<Item borrowed>>"<<endl;
                        return;
                    }
                }
            }
            cout<<"<<Not found>>"<<endl;
            }
        }
        else{
            cout<<"<<Error>>"<<endl;
        }
    }

    void returnItem(){
    cout<<"What item do you want to return?"<<endl;
        cout<<"1.Book"<<endl<<"2.Magazine"<<endl<<"3.DVD"<<endl;
        int n;
        cin>>n;
        if(n==1){
            if(bookCount==0)
            {
                cout<<"<<The library is empty>>"<<endl;
                return;
            }
            else{
            cout<<"Enter the book name:";
            string name;
            cin>>name;
            for(int i=0;i<bookCount;i++){
                if(books[i]->getTitle()==name)
                {
                    if(books[i]->getAvailability()==1){
                        cout<<"<<This book already exists>>"<<endl;
                        return;
                    }
                    else{
                        books[i]->setAvailability(1);
                        cout<<"<<Item returned>>"<<endl;
                        return;
                    }
                }
            }
            }
            cout<<"<<Not found>>"<<endl;
        }
        else if(n==2){
            if(magazineCount==0){
                cout<<"<<The library is empty>>"<<endl;
                return;
            }
            cout<<"Enter the magazine name:";
            string name;
            cin>>name;
            for(int i=0;i<magazineCount;i++){
                if(magazines[i]->getTitle()==name)
                {
                    if(magazines[i]->getAvailability()==1){
                        cout<<"<<Not available>>";
                        return;
                    }
                    else{
                    magazines[i]->setAvailability(1);
                    cout<<"<<Item returned>>"<<endl;
                    return;
                    }
                }
                
            }
            cout<<"<<Not found>>"<<endl;
        }
        else if(n==3){
            if(dvdCount==0){
                cout<<"<<The library is empty>>"<<endl;
                return;
            }
            cout<<"Enter the dvd name:";
            string name;
            cin>>name;
            for(int i=0;i<dvdCount;i++){
                if(dvd[i]->getTitle()==name)
                {
                    if(dvd[i]->getAvailability()==1){
                        cout<<"<<This book already exists>>"<<endl;
                        return;
                    }
                    else{
                    dvd[i]->setAvailability(1);
                    cout<<"<<Item returned>>"<<endl;
                    return;
                    }
                }
            }
            cout<<"<<Not found>>"<<endl;
        }
        else{
            cout<<"<<Error>>"<<endl;
        }
    }
};


int main(){
    int n=1;
    LibrarySystem ob;
    while(n){
        cout<<"-----------------------------------------"<<endl;
        cout<<"Welcome to the Library Management System"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. Add Magazine"<<endl;
        cout<<"3. Add DVD"<<endl;
        cout<<"4. Borrow Item"<<endl;
        cout<<"5. Return Item"<<endl;
        cout<<"6. Display Available Items"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Please select an option: ";
        int n;
        cin>>n;
        cin.ignore();
        
        switch (n)
        {
        case 1:
            ob.addBook();
            break;

        case 2:
            ob.addMagazine();
            break;
        
        case 3:
            ob.addDVD();
            break;

        case 4:
            cout<<"-----------------------------------------"<<endl;
            ob.borrowItem();
            break;

        case 5:
            cout<<"-----------------------------------------"<<endl;
            ob.returnItem();
            break;

        case 6:
            cout<<"-----------------------------------------"<<endl;
            ob.displayItems();
            break;

        case 7:
            cout<<"-----------------------------------------"<<endl;
            cout<<"<<Exit>>";
            return 0;
        
        default:
            cout<<"<<Error>>"<<endl;
            break;
        }
    }

    return 0;
}
