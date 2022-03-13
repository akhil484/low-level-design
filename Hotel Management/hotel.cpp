class Hotel{
	int id;
	string name;
	Location hotellocation;
	vector<Room> roomlist;
};

class Location{
	int id;
	string area;
	string country;
	string city;
	string street;
};

class Room
{
	string roomNumber;
	RoomStyle roomStyle;
	RoomStatus roomStatus;
	Double bookingPrice;
	vector<RoomKey> roomKeys;
	vector<HouseKeepingLog> houseKeepingLogs;
};

enum RoomStyle{
	STANDARD, DELUX, FAMILY_SUITE
};

enum RoomStatus{
	AVAILABLE, RESERVED, NOT_AVAILABLE, OCCUPIED, SERVICE_IN_PROGRESS
};

class RoomKey{
	string keyId;
	string barCode; //for electronic code
	time_t issuedAt;
	bool isActive;
	bool isMaster;

	void assignRoom(Room room);
};

class HouseKeepingLog{
	string description;
	time_t startDate;
	int duration;
	HouseKeeper housekeeper;
	void addRoom(Room room);
};

class Person{
protected:
	string name;
	Account accountDetail;
	string phone;
};

class Account{
	string username;
	string password;
	AccountStatus accountStatus;
};

enum AccountStatus{
	ACTIVE, BLOCKED,CLOSED;
}

class HouseKeeper: public Person{
	vector<Room> getRoomsServiced(time_t date);
};

class Guest:public Person{
	Search searchObj;
	Booking bookingObj;
	vector<RoomBooking> getAllRoomBookings();
};

class Receptionist:public Person
{
	Search searchObj;
	Booking bookingObj;
	vector<RoomBooking> checkInGuest(Guest guest, RoomBooking bookingInfo);
	vector<RoomBooking> checkOutGuest(Guest guest, RoomBooking bookingInfo);
};

class admin:public Person
{
	void addRoom(Room roomDetail);
	void deleteRoom(string roomId);
	void editRoom(Room roomDetail);
};

class Search{
	vector<Room> searchRoom(RoomStyle roomStyle, time_t startDate, int duration);
};

class Booking{
	RoomBooking createBooking(Guest guestInfo);
	RoomBooking cancelBooking(int bookingId);
};

class RoomBooking{
	string bookingId;
	time_t startDate;
	int durationInDays;
	BookingStatus bookingStatus;
	vector<Guest> guestList;
	vector<Room> roomInfo;
	BaseRoomCharge totalRoomCharges;

};

class BaseRoomCharge{
	virtual double getCost()=0;
};

class RoomCharge:public BaseRoomCharge{
	double cost;
	double getCost(){
		return cost;
	}
	void setCost(double cost)
	{
		this.cost=cost;
	}
};

class RoomServiceCharge:public BaseRoomCharge{
	double cost;
	BaseRoomCharge baseRoomCharge;
	double getCost(){
		baseRoomCharge.setCost(baseRoomCharge.getCost()+cost);
		return baseRoomCharge.getCost();
	}
};

class InRoomPurchaseCharge:public BaseRoomCharge{
	double cost;
	BaseRoomCharge baseRoomCharge;
	double getCost(){
		baseRoomCharge.setCost(baseRoomCharge.getCost()+cost);
		return baseRoomCharge.getCost();
	}
};