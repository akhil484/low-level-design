class Library{
	string name;
	Address location;
	vector<Bookitem> books;
};

class Address{
	int pincode;
	string street;
	string state;
	string city;
	string country;
};

class Book{
	string uniqueIdNumber;
	string title;
	vector<Author> authors;
	Booktype booktype;
};

//A book can have different copies
class Bookitem:public Book{
	string barCode;
	Date publicationDate;
	Rack racklocation;
	BookStatus bookStatus;
	BookFormat bookformat;
	Date issueDate;
};

enum Booktype{
	FANTASY, DRAMA, SCI_FI, ROMANTIC;
};

enum BookStatus{
	ISSUED, AVAILABLE, RESERVED, LOST;
};

enum BookFormat{
	HARDCOVER, PAPERBACK, NEWSPAPER, JOURNAL;
};

class Rack{
	//to find exact physical location of a book in the library
	int number;
	string location;
};

class Person{
	string FirstName;
	string LastName;
};

class Author:public Person{
	vector<Book> booksPublished;
};

class SystemUser:public person{
	string email;
	Account account;
	string phoneNumber;
};

class Member:public SystemUser{
	int totalBooksissued;
	Search searchobj;
	BookIssueService bookissueService;
};

class librarian: public SystemUser{
	Search searchobj;
	BookIssueService bookissueService;

	void AddBookItem(Bookitem bookitem);
	void deleteBookItem(string barcode);
	void editBookItem(Bookitem bookitem);
};

class Account{
	string userName;
	string password;
	int accountId;
};

class Search{
	vector<Bookitem> getBookByTitle(string title);
	vector<Bookitem> getBookByAuthor(Author author);
	vector<Bookitem> getBookByPublicationDate(Date publicationdate);
	vector<Bookitem> getBookByType(Booktype booktype);
};

class BookIssueService{
	FineService fineSerivce; // to charge fine after due date
	BookReservationDetail getReservationDetail(Bookitem bookitem); //if book is reserved by someone else
	void updateReservationDetail(BookReservationDetail bookreservationDetail);
	BookReservationDetail reserveBook(Bookitem book, SystemUser user);
	BookIssueDetail issueBook(Bookitem book, SystemUser user);
	BookIssueDetail renewBook(Bookitem book, SystemUser user);
	BookReservationDetail returnBook(Bookitem book, SystemUser user);
};

class BookLending{
	Date issueDate;
	Bookitem book;
	SystemUser user;
};

class BookReservationDetail:public BookLending{
	ReservationStatus reservationStatus;
};

class BookIssueDetail:public BookLending{
	Date dueDate;
};

class FineService{
	int calculateFine(Bookitem book, SystemUser user, int days,);
};


