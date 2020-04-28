#ifndef DOT_H
#define DOT_H
#include <vector>

#include "wants.h"

class dot
{
public:

	void update();

	void set_want(wants const new_want) { my_want_ = new_want; }
	wants get_want() const { return my_want_; }
	bool get_fulfilled() const { return want_fulfilled_; }
	void set_fulfilled(bool const change) { want_fulfilled_ = change; }
	
	void increase_want();
	void decrease_want();
	
	std::vector<int&> get_my_location() const { return my_location_; }
	int get_speed() const { return speed_; }

	void move(std::vector<int>& destination);
	bool arrived(std::vector<int>& destination);

	int get_storage() const { return storage_; }
	void increase_storage(int const increase) { storage_ += increase; }
	int get_storage_max() const { return storage_max_; }
	
private:
	int x_ {};
	int y_ {};
	std::vector<int&> my_location_ { x_, y_ };

	int speed_ {};
	bool want_fulfilled_ { false };
	float want_change_ { 0.15f };

	wants my_want_ { wants::food };
	float want_meter_ { 100.0f };

	int storage_ {};
	int storage_max_ {};
	
};

#endif