class BMSService{
	vector<CinemaHalls> cinemas;
	vector<Movie> getMovies(string city, Date date);
	vector<CinemaHalls> getCinemaHalls(string city);
};

class CinemaHalls{
	int cinemaHallsId;
	string cinemaHallName;
	Address address;
	vector<Audi> audiList;
	map<Date,Movies> getMovies(vector<Date> dateList);
	map<Date,Shows> getShows(vector<Date> dateList);
};

class Address{
	int pincode;
	string street;
	string state;
	string city;
	string country;
};

class Audi{
	int audiId;
	string audiName;
	int totalSeats;
	vector<Show> shows;
};

class Show{
	int showId;
	Movie movie;
	Date startTime;
	Date endTime;
	CinemaHall cinemaPlayedAt;
	vector<Seat> seats;
};

class Seat{
	int seatId;
	SeatType seatType;
	SeatStatus seatStatus;
	Double price;
};

enum SeatType{
	DELUX, VIP, ECONOMY, OTHER;
};

enum SeatStatus{
	BOOKED, AVAILABLE, RESERVED, NOT_AVAILABLE;
};

class Movie{
	string movieName;
	int movieId;
	int durationInMins;
	string language;
	Genre genre;
	Date releaseDate;
	map<string,vector<Show>> cityShowMap;
};

enum Genre{
	SCI_FI, DRAMA, ROM_COM, FANTASY;
};

//Actors
class User{
	int userId;
	Search searchObj;
};

class SystemMember:public User{
	Account account;
	string name;
	string email;
	Address address;
};

class Member:public SystemMember{
	Booking makeBooking(Booking booking);
	vector<Booking> getBooking();
};

class Admin:public SystemMember{
	bool addMovie(Movie movie);
	bool addShow(Show show);
};

class Account{
	string userName;
	string password;
};

class Search{
	vector<Movie> seachMoviesByNames(string name);
	vector<Movie> searchMoviesByGenre(Genre genre);
	vector<Movie> searchMoviesByDate(Date releaseDate);
	vector<Movie> searchMoviesByLanguage(string language);
};

class Booking{
	string bookingId;
	Date bookingDate;
	Member member;
	Show show;
	Audi audi;
	BookingStatus bookingStatus;
	double totalAmount;
	vector<Seat> seats;
	Payment paymentObj;
	bool makePayment(Payment payment); //to tell whether payment is done successfully
};

enum BookingStatus{
	REQUESTED, PENDING, CONFIRMED, CANCELLED;
};

class Payment{
	double amount;
	Date paymentDate;
	int transactionId;
	PaymentStatus paymentStatus;
};

enum PaymentStatus{
	UNPAID, PENDING, COMPLETED, DECLINED, CANCELLED, REFUNED;
};