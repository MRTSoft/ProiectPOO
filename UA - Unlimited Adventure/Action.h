#pragma once


class Action
{
public:
	Action() {};
	~Action() {};
protected:

private:
	enum actionType {ACTION_NONE, ACTION_MOVE, ACTION_ATTACK, ACTION_DIE};
	actionType mType;
};

