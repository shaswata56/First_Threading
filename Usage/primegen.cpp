//  This prime generator use 4 thread
//  to generate prime numbers between 
//  2 to 40000000(forty million)

 #include <iostream>
 #include <chrono>
 #include <thread>
 #include <cmath>
 
static const int num_threads = 4;

int isPrime(long long n){
    long long i;

    if (n==2)
        return 1;

    if (n%2==0)
        return 0;

    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)
            return 0;

    return 1;
}
  
//This function will be called from a thread
  
void call_from_thread(register int tid, int y, int x) {
	printf("Launched by thread: %d\n", tid);

	for(register long long j=y; j <= x; j++) {
		if(isPrime(j) == 1) printf("%lld\n", j);
	}
	
	printf("Thread %d is going to sleep.\n", tid);
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int main() {
	std::thread t[num_threads+1];
	//Launch a group of threads
	t[1] = std::thread(call_from_thread, 1, 0, 10000000);
	t[2] = std::thread(call_from_thread, 2, 10000001, 20000000);
	t[3] = std::thread(call_from_thread, 3, 20000001, 30000000);
	t[4] = std::thread(call_from_thread, 4, 30000001, 40000000);
	printf("Launched from the main\n");
	 //Join the threads with the main thread
	t[1].join();
	t[2].join();
	t[3].join();
	t[4].join();
		
	return 0;
 }
