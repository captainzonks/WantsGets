#include "location.h"
#include "dot.h"

void location::update()
{
	produce();
	
	if (!line_.empty())
	{
		transfer(line_.front());
	}
}

void location::produce()
{
	if (wants_stored_ != storage_maximum_)
		wants_stored_ += production_speed_;
}

void location::transfer(dot& visitor)
{
	if (visitor.get_storage() != visitor.get_storage_max())
	{
		wants_stored_ -= transfer_speed_;
		visitor.increase_storage(transfer_speed_);
	}
}

void location::add_visitor(dot& visitor)
{
	line_.push(visitor);
}

void location::remove_visitor()
{
	line_.pop();
}
