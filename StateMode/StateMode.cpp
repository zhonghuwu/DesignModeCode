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
		cout<<"ִ��״̬1��action1"<<endl;
		cout<<"��״̬1ת��Ϊ״̬2"<<endl;
	}
	virtual void action2()
	{
		cout<<"��״̬1�²���ִ��action2"<<endl;
	}
	virtual void getstate()
	{
		cout<<"״̬1"<<endl;
	}
};
class ConcreteState2:public State
{
public:
	ConcreteState2(){}
	virtual void action1()
	{
		cout<<"��״̬2�²���ִ��action1"<<endl;
	}
	virtual void action2()
	{
		cout<<"ִ��״̬2��action2"<<endl;
		cout<<"��״̬2ת��Ϊ״̬1"<<endl;
	}
	virtual void getstate()
	{
		cout<<"״̬2"<<endl;
	}
};

class Client
{
public:
	Client( )
	{
		cout<<"��ʼ�����״̬"<<endl;
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