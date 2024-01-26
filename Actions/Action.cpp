#include "Action.h"
Action::~Action() {}
void Action::Undo() {}
void Action::Redo() {}
bool Action::canBeRecorded() {
	return false;
}