class Customer{
	ShoppingCart cart;
	Search searchObj;
	int customerId;

	ShoppingCart getShoppingCart(customerId);
	void addItemsToShoppingCart(Item item);
	void updateItemFromShoppingCart(Item item);
	void removeItemFromShoppingCart(Item item);
};

class Guest:public Customer{
	Account createAccount(); //guest account can do everything a customer can do without creating an account
};

class User:public Customer{
	Account account;
}

class Seller:public User{
	void addProduct(Product product)
};

class Buyer:public User{
	Order orderObj;
	void addReview(ProductReview review);
	OrderStatus placeorder(ShoppingCart cart);
};

class Account{
	string name;
	string email;
	string phoneNumber;
	string userName;
	string password;
};

class Address{
	int pinCode;
	string street;
	string city;
	string state;
	string country;
	vector<Address> shippingAdress;
	AccountStatus accountStatus;
};

enum AccountStatus{
	ACTIVE,BLOCKED,INACTIVE;
}

class ShoppingCart{
	vector<Item> items;
	double cartValue;

	void addItem(Item item);
	void updateItem(Item item);
	void deleteItem(Item item);
	void checkOutItems();
	vector<Item> getItems();
	double getCartValue;
};

class Item{
	Product product;
	int qty;
};

class Product{
	int productId;
	string productDescription;
	string name;
	ProductCategory productCategory;
	Seller seller;
	double cost;
	vector<ProductReview> productReviews;
};

enum ProductCategory{
	ELECTRONICS,FURNITURE,GROCERY,CLOTHING,FOOTWEAR;
};

class ProductReview{
	string details;
	Buyer reviewer;
	int rating;
};

class Search{
	vector<Product> searchByName(string name);
	vector<Product> searchByCategory(ProductCategory productCategory);
};

class Order{
	int ordeId;
	vector<Item> orderItem;
	double orderValue;
	Buyer buyer;
	Date orderDate;
	NotificationService notificationService;
	vector<OrederLog> orderLog;
	OrderStatus placeorder();
	OrderStatus trackOrder();
	void addOrderLogs();
	PaymentStatus makePayment(PaymentType paymentType);

};

enum OrdeStatus{
	PACKED, SHIPPED, OUT_FOR_DELIVERY,DELIVERED,CANCELLED;
};

enum PaymentStatus{
	SUCCESS,ERROR,CANCELLED,REFUNDED;
};

enum PaymentType{
	CREDIT_CARD,DEBIT_CARD,UPI,NET_BANKING
};
class OrderLog{
	string orderDetail;
	Date createDate;
	OrderStatus status;
};

class NotificationService{
	bool sendNotification(NotificationDomain notificationDomain)
	{
		Notification notificationObject;
		MessageAttribute messageAttribute;
		switch(notificationDomain.getNotificationType()){
			case NotificationType.EMAIL:
				notificationObject = new EmailNotification();
				messageAttribute = new MessageAttribute(name and email addresses);
				break;
			case NotificationType.WHATSAPP:
				notificationObject = new WhatsappNotification();
				messageAttribute = new MessageAttribute(numbers);
				break;
			default:
				notificationObject = new SMSNotification();
				messageAttribute = new MessageAttribute(numbers);
				break;
		}
		return notificationObject.sendNotification(messageAttribute);
	}
};

class NotificationDomain{
	string notificationId;
	NotificationType notificationType;
	User user;
};
class MessageAttributes{
	string to;
	string from;
	string message;
};

class Notification{
	virtual bool sendNotification(MessageAttribute messageAttribute)=0;
};
class EmailNotification:public Notification{
	bool sendNotification(MessageAttribute messageAttribute);
};

class WhatsappNotification:public Notification{
	bool sendNotification(MessageAttribute messageAttribute);
};

class SMSNotification:public Notification{
	bool sendNotification(MessageAttribute messageAttribute);
};



