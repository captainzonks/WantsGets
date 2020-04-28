#ifndef LOCATION_H
#define LOCATION_H
#include <queue>
#include <vector>

#include "wants.h"

class dot;

class location
{
public:

	void update();

	void produce();
	void transfer(dot& visitor);

	void add_visitor(dot& visitor);
	void remove_visitor();
	
	wants get_wants_type() const { return wants_type_; }
	int get_storage_total() const { return wants_stored_; }

private:
	std::queue<dot> line_ {};
	
	std::vector<int> my_location_ {};
	int wants_stored_ {};
	int storage_maximum_ { 100 };
	int production_speed_ { 1 };
	int transfer_speed_ { 1 };

	wants wants_type_ { wants::food };
	
};

#endif