/*
 * main.cpp
 *  
 *  Use this program in conjunction with valgrind to find all the memory leaks
 *  While you are at it use the 'profile code coverage' tool  to see which lines  
 *  of code you wrote that are never called
 *  
 *  See 11_finding_memory_leaks_with_eclipse_and_valgrind_on_linux.pdf for more info
 */

#include <chrono>
#include <thread>
#include <iostream>

int myfunc(){
	return 7;
}
//enable this to show what am accelerated mem leak looks like in a mem tracker program
void leak_all_mem(){
	
	int* i=0;
	while(true){
		i = new int[10];
		//call this is you want to slow things way down 
		//std::this_thread::sleep_for(std::chrono::nanoseconds(1));	
	}
}

//just a small leak, cant even see it in your mem program
void leak_a_lot_of_mem(){
	//enable this to show what am accelerated mem leak looks like
	int* i=0;
	int j=100;
	while(j>0){
		j--;
		i = new int[10];
		//call this is you want to slow things way down 
		//std::this_thread::sleep_for(std::chrono::nanoseconds(1));
	}
}

//what happens when you run out of stack space?
int i=0;
void stack_overflow(){
	std::cout<<i++<<std::endl;
	stack_overflow();
}

//leak 4 bytes, a single int
void mem_leak(){
	int* i=new int;
	i++;
}

int main(){
	mem_leak();
	leak_a_lot_of_mem();
	stack_overflow();
}






