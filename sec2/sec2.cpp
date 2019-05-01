#include <iostream>
#include <ctime>
using namespace std;

class Time{
	public:
	void init(int h, int m, int s);
	void displace();
	private:
	int hour, minute, sec;
};

void Time::init(int h, int m, int s){
	hour = h;
	minute = m;
	sec = s;
}

void Time::displace(){
	if (hour >12)
		cout << "Current time (12h format): " << hour-12 << ":" << minute << ":" << sec << " pm" << endl;
	else{
		cout << "Current time (12h format): " << hour << ":" << minute << ":" << sec << " am" << endl;
	}
	cout << "Current time (24h format): " << hour << ":" << minute << ":" << sec << endl;
}

int main() {
	Time t;
	t.init(13, 26, 20);
	t.displace();
	return 0;
}