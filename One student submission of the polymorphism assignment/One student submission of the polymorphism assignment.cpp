#include <iostream>
#include <string>
#include <vector>

class paymentMethod {
public:
	virtual void processPayment() = 0;
	virtual ~paymentMethod() = default;
};

class creditCard : public paymentMethod {
private:
	std::string cardHolder;
	std::string cardNumber;
	std::string experationDate;
public:
	creditCard(const std::string& holder, const std::string& number, const std::string& expire)
		: cardHolder(holder), cardNumber(number), experationDate(expire) {
	}

	void processPayment() override {
		std::cout << "processing credit card payment for " << cardHolder << std::endl;
	}
};

class payPal : public paymentMethod {
private:
	std::string email;
	std::string password;
public:
	payPal(const std::string& emailAddr, const std::string& pass)
		: email(emailAddr), password(pass) {
	}

	void processPayment() override {
		std::cout << "processing paypal payment for " << email << std::endl;
	}
};

void processAllPayments(std::vector<paymentMethod*>& methods) {
	for (paymentMethod* pMethod : methods) {
		pMethod->processPayment(); 
	}
}


int main() {

	std::vector<paymentMethod*> paymentArray;

	creditCard myCard("MR.President", "1234-5678-9012-3456", "03/32");
	paymentArray.push_back(&myCard);

	payPal* myPayPal = new payPal("email.email.com", "passwordlock");
	paymentArray.push_back(myPayPal);

	processAllPayments(paymentArray);

	delete myPayPal;

	return 0;
}