#include <DumbLuck.h>

class WhereIsGravity : public DumbLuck::App
{
public:
	WhereIsGravity() {

	}

	~WhereIsGravity() {

	}
}; 

DumbLuck::App* DumbLuck::CreateApp()
{
	return new WhereIsGravity();
}