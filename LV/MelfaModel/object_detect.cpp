#include  <object_detect.h>

// Constructor
Object::Object()
{

}

// Deconstructor
Object::~Object()
{

}

bool Object::addPosition(int class_id, double x, double y, double angle)
{
	// check
	for (int i = 0; i < list_position.size(); i++)
	{
		if (fabs(list_position.at(i).x - x) < 0.7 && fabs(list_position.at(i).y - y) < 0.7)
		{
			return false;
		}
	}
	position new_point;
	new_point.class_id = class_id;
	new_point.x = x;
	new_point.y = y;
	new_point.angle = angle;
	new_point.num_id = list_position.size();
	list_position.append(new_point);
	return true;

}
bool Object::getPosition(position &get_point, int num)
{
	if (list_position.size() > num)
	{
		get_point.class_id = list_position.at(num).class_id;
		get_point.x = list_position.at(num).x;
		get_point.y = list_position.at(num).y;
		get_point.angle = list_position.at(num).angle;
		get_point.num_id = list_position.at(num).num_id;
		return true;
	}
	else
	{
		return false;
	}
}

bool Object::deletePosition(int num_id)
{
	if (list_position.size() > 0)
	{
		list_position.pop_front();
		return true;
	}
	else
	{
		return false;
	}
}

bool Object :: isNotEmpty()
{
	if (list_position.size() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void	Object::clear()
{
	list_position.clear();
}

int		Object::size() 
{
	return list_position.size();
}