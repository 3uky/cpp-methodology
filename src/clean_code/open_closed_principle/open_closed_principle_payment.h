/* uncle bob use case of open closed principle violation and solution

// violation of open closed principle
// new payment method would lead to adding new case everywhere in usage
void checkOut(Receipt receipt) {
	Money total = Money.zero;
	for item : items {
		total += item.getPrice();
		receipt.addItem(item);
	}
	Payment p;
	if(credit)
		p = acceptCard(total);
	else	
		p = acceptCash(total);
  	receipt.addPayment(p);
}

// solution open closed principle version
// new payment method doesnt require modification of usage, pm could be initialized in some factory
void checkOut(Receipt receipt, IPaymentMethod pm) 
{
	Money total = Money.zero;
	for item : items {
		total += item.getPrice();
		receipt.addItem(item);
	}
	Payment p = pm.acceptPayment(total);
  	receipt.addPayment(p);
}

*/
