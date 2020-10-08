//----------------------------------------------------
// mutex.cc
//----------------------------------------------------

#include <unistd.h>
#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

//----------------------------------------------------

using namespace std;

//----------------------------------------------------

const int N = 16;

mutex m;

//----------------------------------------------------

void seccion_critica()
{
	cout << "[" << this_thread::get_id() << "]: ";
	for(int i = 0; i < 10; ++i)
		cout << i;
	cout << endl;
}

//----------------------------------------------------

void hebra()
{
	while(true)
	{
		m.lock();
		seccion_critica();
		m.unlock();
	}
}

//----------------------------------------------------

int main()
{
	alarm(1);

	thread t[N];
	
	for(auto& i: t)
		i = thread(hebra);

	for(auto& i: t)
		i.join();
}

//----------------------------------------------------
