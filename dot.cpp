#include "dot.h"

void dot::update()
{
	if (get_fulfilled())
		decrease_want();
	increase_want();
}

void dot::increase_want()
{
	want_meter_ *= want_change_;
}

void dot::decrease_want()
{
	want_meter_ /= want_change_;
}

void dot::move(std::vector<int>& destination)
{
	auto dx = destination.at(0) - my_location_.at(0);
	auto dy = destination.at(1) - my_location_.at(1);

	const auto r = round(sqrt(dx*dx + dy*dy));

	if (r < speed_)
	{
		my_location_.at(0) = destination.at(0);
		my_location_.at(1) = destination.at(1);
		return;
	}

	// normalize
	if (r > 0)
	{
		dx /= r;
		dy /= r;
	}

	my_location_.at(0) += speed_ * dx;
	my_location_.at(1) += speed_ * dy;

	if (arrived(destination))
		set_fulfilled(true);
	
}

bool dot::arrived(std::vector<int>& destination)
{
	if (my_location_.at(0) == destination.at(0) && my_location_.at(1) == destination.at(1))
		return true;
	return false;
}
