#include <iostream>

using namespace std;

class State
{
public:
	virtual void action1()=0;
	virtual void action2()=0;
	virtual void getstate()=0;
};

class ConcreteState1:public State
{
public:
	ConcreteState1(){}
	virtual void action1()
	{
		cout<<"执行状态1的action1"<<endl;
		cout<<"将状态1转换为状态2"<<endl;
	}
	virtual void action2()
	{
		cout<<"在状态1下不能执行action2"<<endl;
	}
	virtual void getstate()
	{
		cout<<"状态1"<<endl;
	}
};
class ConcreteState2:public State
{
public:
	ConcreteState2(){}
	virtual void action1()
	{
		cout<<"在状态2下不能执行action1"<<endl;
	}
	virtual void action2()
	{
		cout<<"执行状态2的action2"<<endl;
		cout<<"将状态2转换为状态1"<<endl;
	}
	virtual void getstate()
	{
		cout<<"状态2"<<endl;
	}
};

class Client
{
public:
	Client( )
	{
		cout<<"初始化类的状态"<<endl;
		cs1=new ConcreteState1();
		cs2=new ConcreteState2();
		state=cs1;
	}
	void action1()
	{
		state->action1();
		setState(cs2);
	}
	void action2()
	{
		state->action2();
		setState(cs1);
	}
	void setState(State *sp)
	{
		state=sp;
	}
	void getstate()
	{
		state->getstate();
	}
private:
	State *state;
	ConcreteState1 *cs1;
	ConcreteState2 *cs2;
};


int main()
{	
	Client ctest;
	ctest.action1();
	ctest.getstate();
	ctest.action2();
	ctest.getstate();

	system("pause");
	return 1;

}