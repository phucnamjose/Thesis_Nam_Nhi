#ifndef OBJECT_DETECT_H
#define OBJECT_DETECT_H

#include <qstring.h>
#include <qlist.h>


using namespace std;

typedef struct 
{
	int class_id;
	double x, y, angle;
	int num_id;
}position;


class Object
{
public:
	Object();
	~Object();
	const char *CLASS[2] = 
	{
		"JAPAN",
		"VIETNAM"
	};
	bool		addPosition(int class_id, double x, double y, double angle);
	bool		getPosition(position &get_point);
	bool		deletePosition(int num_id);
	bool		isNotEmpty();
private:
	QList <position> list_position;
};



#endif // OBJECT_H
