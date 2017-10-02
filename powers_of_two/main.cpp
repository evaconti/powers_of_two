#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

// print_count() counts down, then up
void print_count(int n) {
	for (auto i = (1ull << n); i != 0; i >>= 1) {
		cout << i << '\n';
	}
	for (auto i = 1ull; i <= (1ull << n); i <<= 1) {
		cout << i << '\n';
	}
}

int main() {
	// answer should default to y to avoid unwanted program exit
	char answer = 'y';

	// do-while allows user to keep entering n until they're done
	do {
		cout << "What integral power of 2 would you like today? ";
		
		// makes user input into a string for ease of use
		string user_input;
		getline(cin, user_input);

		// sets a stream so it doesn't hang while waiting for input
		istringstream iss(user_input);
		int n = 0;
		iss >> n;

		constexpr auto max_size = sizeof(unsigned long long int) * 8 - 2;

		// if user enters string instead of integer
		if (iss.fail()) {
			cout << "Numbers only, please! Enter an integer between 0 and " << max_size << ".\n";
			continue;
		}
		
		// if user enters non-integral power (fraction, float, etc.)
		string junk;
		iss >> junk;
		if (!junk.empty()) {
			cout << "I saw the " << n << "! Ignoring the rest...\n";
		}
		
		// if user enters a number too big or too small
		if (n < 0 || n > max_size) {
			cout << "I can't handle " << n << "! Enter an integer between 0 and " << max_size << ".\n";
			continue;
		}
		
		print_count(n);

		cout << "Would you like another? y/n ";
		cin >> answer;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (answer == 'y');
}