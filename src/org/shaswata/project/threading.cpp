 #include <iostream>
 #include <chrono>
 #include <thread>
  
static const int num_threads = 4;
  
//This function will be called from a thread
  
void call_from_thread(register int tid) {
	printf("Launched by thread: %d\n", tid);
	
	printf("Thread %d is going to sleep.\n", tid);
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	printf("Thread %d is aweaking from sleep.\n", tid);

	for(register int j=0; j < 21; j++) {
		if(j == 10) {
			printf("Thread %d is going to sleep.\n", tid);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			printf("Thread %d is aweaking from sleep.\n", tid);
		}
		std::cout << j << std::endl;
	}
	printf("Thread %d is going to sleep.\n", tid);
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	
	printf("Thread %d is aweaking from sleep.\n", tid);
}

int main() {
	std::thread t[num_threads+1];
	//Launch a group of threads
	for (register int i = 1; i <= num_threads; ++i) {
		t[i] = std::thread(call_from_thread, i);
	 }
	printf("Launched from the main\n");
	 //Join the threads with the main thread
	for (register int i = 1; i <= num_threads; ++i) {
		t[i].join();
	}	
	return 0;
 }
