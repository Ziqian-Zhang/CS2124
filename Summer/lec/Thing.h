#ifndef THING_H
#define THING_H
class Thing {
	int x;
public:
	Thing(int newx=0) :x(newx) {}
	int getx()const;
	void setx(int newx);
};
#endif

