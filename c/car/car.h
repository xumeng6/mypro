#ifndef _CAR_H_
#define _CAR_H_

class Car{
public:
	void run();
	void stop();
	void print();
	void setProperty(int price, int carNum);
private:
	int m_price;
	int m_carNum;
};

#endif
